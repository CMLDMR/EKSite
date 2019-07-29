#include "dbclass.h"
#include <random>

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


