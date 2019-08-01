#ifndef DBCLASS_H
#define DBCLASS_H

#include "mongoheaders.h"

#include <QUuid>
#include <QImage>
#include <QDebug>
#include <QVector>

#define con qDebug()



class QString;



class DBClass
{
public:
    DBClass(mongocxx::database* _db);



    mongocxx::database *db() const;

    mongocxx::collection collection(std::string coll);

    int getRandom(int begin = 0 , int end = 255 );


    int count(const std::string &collection , const bsoncxx::builder::basic::document &view);


    const std::string downloadFile(const std::string &oid , const bool &forceFilename = false);

    const std::string downloadFileName( const std::string &oid );

    const bsoncxx::types::value uploadfile( QString filepath );



private:
    mongocxx::database* mDB;
};

#endif // DBCLASS_H
