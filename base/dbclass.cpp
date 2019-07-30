#include "dbclass.h"
#include <random>
#include <iostream>

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


