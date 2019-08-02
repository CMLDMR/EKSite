#ifndef VILLAGETHUMPNAILS_H
#define VILLAGETHUMPNAILS_H

#include "base/containerwidget.h"
#include "base/dbclass.h"

class VillageThumpnails : public ContainerWidget , public DBClass
{
public:
    VillageThumpnails( mongocxx::database* _db );
};



class VillaPage : public ContainerWidget , public DBClass
{
public:
    VillaPage( mongocxx::database* _db ) ;


};

#endif // VILLAGETHUMPNAILS_H
