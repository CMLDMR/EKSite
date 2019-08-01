#include "dbclass.h"
#include <random>
#include <iostream>

#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QByteArray>
#include <QString>
#include <fstream>

DBClass::DBClass(mongocxx::database *_db)
    :mDB(_db)
{

}

mongocxx::database *DBClass::db() const
{
    return mDB;
}

mongocxx::collection DBClass::collection(std::string coll)
{
    return this->mDB->collection(coll);
}

int DBClass::getRandom(int begin, int end)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist( begin , end );
    return dist(rd);
}

int DBClass::count(const std::string &collection, const bsoncxx::builder::basic::document &view)
{
    try {
        auto _count = this->db()->collection(collection).count(view.view());
        return _count;
    } catch (mongocxx::exception &e) {
        std::cout << "Error: " << __LINE__ << " " << e.what() << std::endl;
        return 0;
    }
}

const std::string DBClass::downloadFile(const std::string &oid, const bool &forceFilename)
{

    QDir dir;

    if( !dir.exists("docroot") )
    {
        dir.mkdir("docroot");
    }

    if( !dir.cd("docroot") )
    {
        return "img/error.jpg";
    }

    if( !dir.exists("tempfile") )
    {
        dir.mkdir("tempfile");
    }


    if( QFile::exists( QString("docroot/tempfile/%1.indexed").arg(oid.c_str()) ) )
        {
            QFile file(QString("docroot/tempfile/%1.indexed").arg(oid.c_str()));
            if( file.open(QIODevice::ReadOnly) )
            {
                QString fileName = QString::fromUtf8(file.readAll());
                file.close();
                return fileName.toStdString();
            }
        }else{
            std::cout << "FILE NOT FOUND: " << QString("docroot/tempfile/%1.indexed").arg(oid.c_str()).toStdString() << std::endl;
        }




        auto doc = bsoncxx::builder::basic::document{};

        try {
            doc.append(bsoncxx::builder::basic::kvp("key",bsoncxx::oid{oid}));
        } catch (bsoncxx::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
            return "img/error.jpg";
        }

        mongocxx::gridfs::downloader downloader;

        try {
            downloader = this->db()->gridfs_bucket().open_download_stream(bsoncxx::types::value(bsoncxx::types::b_oid{bsoncxx::oid{oid}}));
        } catch (mongocxx::gridfs_exception &e) {
            std::cout << "ERROR: " << __LINE__ << " " << __FILE__ << " " << e.what() << std::endl;
            return "img/error.jpg";
        }




        auto file_length = downloader.file_length();
        auto bytes_counter = 0;

        QFileInfo info( downloader.files_document()["filename"].get_utf8().value.to_string().c_str() );

        QString fullFilename;

        if( forceFilename )
        {
            fullFilename = QString("tempfile/%1").arg(downloader.files_document()["filename"].get_utf8().value.to_string().c_str());
        }else{
            fullFilename = QString("tempfile/%2.%1").arg(info.suffix())
                        .arg(downloader.files_document()["_id"].get_oid().value.to_string().c_str());
        }


        auto buffer_size = std::min(file_length, static_cast<std::int64_t>(downloader.chunk_size()));
        auto buffer = bsoncxx::stdx::make_unique<std::uint8_t[]>(static_cast<std::size_t>(buffer_size));

        std::ofstream out;

        out.open("docroot/"+fullFilename.toStdString(),std::ios::out | std::ios::app | std::ios::binary);


        if( out.is_open() )
        {
            while ( auto length_read = downloader.read(buffer.get(), static_cast<std::size_t>(buffer_size)) ) {
                auto bufferPtr = buffer.get();
                out.write( reinterpret_cast<char*>( bufferPtr ) , length_read );
                bytes_counter += static_cast<std::int32_t>( length_read );
            }
            out.close();
        }

        else{
            std::cout << "Error Can Not Open File: " <<"docroot/"+fullFilename.toStdString() << std::endl;
            return "img/error.jpg";
        }


        QFile file(QString("docroot/tempfile/%1.indexed").arg(oid.c_str()));
        if( file.open(QIODevice::ReadWrite) )
        {
            file.write(fullFilename.toUtf8());
            file.close();
        }else{
            std::cout << "FILE CAN NOT CREATED: " << file.fileName().toStdString() << fullFilename.toStdString() << std::endl;
        }

        std::cout << "FILE FORCED : " << forceFilename <<" FILE FILL: " << fullFilename.toStdString() <<" TOTHIS FILE: " << file.fileName().toStdString() << std::endl;

        return fullFilename.toStdString();
}

const std::string DBClass::downloadFileName(const std::string &oid)
{


    mongocxx::gridfs::downloader downloader;

    try {
        downloader = this->db()->gridfs_bucket().open_download_stream(bsoncxx::types::value(bsoncxx::types::b_oid{bsoncxx::oid{oid}}));
    } catch (mongocxx::gridfs_exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FILE__ << " " << e.what() << std::endl;
        return "";
    }

    return downloader.files_document()["filename"].get_utf8().value.to_string();

}

void DBClass::deleteGridFSFile(const std::string &oid)
{
    this->db()->gridfs_bucket().delete_file(bsoncxx::types::value(bsoncxx::types::b_oid{bsoncxx::oid{oid}}));
}

const bsoncxx::types::value DBClass::uploadfile(QString filepath)
{
    QFile file( filepath );
        if( file.open( QIODevice::ReadOnly ) )
        {
            QFileInfo info(filepath);
            auto uploader = this->db()->gridfs_bucket().open_upload_stream(info.fileName().toStdString().c_str());
            QByteArray ar = file.readAll();
            uploader.write((std::uint8_t*)ar.data(),ar.size());
            auto res = uploader.close();
            file.close();
            return res.id();
        }else{


        }
}


