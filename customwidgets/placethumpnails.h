#ifndef PLACETHUMPNAILS_H
#define PLACETHUMPNAILS_H

#include "base/containerwidget.h"
#include "base/dbclass.h"

class PlaceThumpnails : public ContainerWidget , public DBClass
{
public:
    PlaceThumpnails(mongocxx::database* _db);
};



class Thumpnails : public ContainerWidget , public DBClass
{
public:
    Thumpnails( mongocxx::database* _db , std::string bolge , std::string il , std::string imgUrl );
};



#endif // PLACETHUMPNAILS_H
