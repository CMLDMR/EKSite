#ifndef DB_H
#define DB_H


#include <iostream>
#include <QString>
#include <QtGlobal>



#include "../url.h"
#include "mongoheaders.h"
#include <boost/optional.hpp>

namespace eCore {

class Item;

class DB
{
public:
    explicit DB();
    explicit DB( mongocxx::database* _db );
    explicit DB( DB* _db );

    DB( const DB &db);

    virtual ~DB();

    DB& operator=(const DB& otherDB);



    DB* getDB() {
        return this;
    }





    mongocxx::database* db();

    std::string downloadFile(const QString &fileOid , bool forceFilename = false);
    std::string downloadFileWeb( const QString &fileOid , bool forceFilename = false );
    bsoncxx::types::value uploadfile(QString filepath );
    bsoncxx::types::value uploadfile(QString filepath ) const;

    mongocxx::stdx::optional<mongocxx::result::insert_one> insertItem(const Item &item);
    mongocxx::stdx::optional<mongocxx::result::update> updateItem( const Item &item);
    mongocxx::stdx::optional<bsoncxx::document::value> findOneItem(const Item &item );
    mongocxx::stdx::optional<bsoncxx::document::value> findOneItem(const Item &item , const Item &findOptions );
    mongocxx::stdx::optional<mongocxx::cursor> find( const Item &item , const mongocxx::options::find findOptions );
    mongocxx::stdx::optional<mongocxx::cursor> find( const Item &item , const int &limit = 20 , const int &skip = 0  );
    mongocxx::stdx::optional<mongocxx::result::delete_result> deleteItem( const Item &item );


    int64_t countItem( const Item &item );

private:




private:


    bool mConstructWithNewClient;
    mongocxx::database* mDB;
};

}

#endif // DB_H
