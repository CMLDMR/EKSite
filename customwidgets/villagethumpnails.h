#ifndef VILLAGETHUMPNAILS_H
#define VILLAGETHUMPNAILS_H

#include "base/containerwidget.h"
#include "base/dbclass.h"

class VillaItem;

class VillageThumpnails : public ContainerWidget , public DBClass
{
public:
    VillageThumpnails( mongocxx::database* _db , const bsoncxx::oid &_villaOid );


private:
    const bsoncxx::oid &villaOid;


    mongocxx::collection mVillaCollection;

    VillaItem *mVillaItem;
};



class VillaPage : public ContainerWidget , public DBClass
{
public:
    VillaPage( mongocxx::database* _db ) ;


};

#endif // VILLAGETHUMPNAILS_H
