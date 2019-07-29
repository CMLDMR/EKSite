#ifndef DBCLASS_H
#define DBCLASS_H

#include "mongoheaders.h"

class DBClass
{
public:
    DBClass(mongocxx::database* _db);



    mongocxx::database *db() const;

    mongocxx::collection collection(std::string coll);

private:
    mongocxx::database* mDB;
};

#endif // DBCLASS_H
