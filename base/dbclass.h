#ifndef DBCLASS_H
#define DBCLASS_H

#include "mongoheaders.h"
#include <QDebug>

#define con qDebug()

class DBClass
{
public:
    DBClass(mongocxx::database* _db);



    mongocxx::database *db() const;

    mongocxx::collection collection(std::string coll);

    int getRandom(int begin = 0 , int end = 255 );


    int count(const std::string &collection , const bsoncxx::builder::basic::document &view);

private:
    mongocxx::database* mDB;
};

#endif // DBCLASS_H
