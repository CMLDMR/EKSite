#include "dbclass.h"

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
