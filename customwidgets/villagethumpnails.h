#ifndef VILLAGETHUMPNAILS_H
#define VILLAGETHUMPNAILS_H

#include "base/containerwidget.h"
#include "base/dbclass.h"

class VillaItem;

class VillageThumpnails : public ContainerWidget , public DBClass
{
public:
    VillageThumpnails( mongocxx::database* _db , const bsoncxx::oid &_villaOid );

    const bsoncxx::oid &VillaOid() const;

    std::string VillaOidString() const;

    Signal<std::string> &ClickVilla();

private:
    const bsoncxx::oid &villaOid;


    mongocxx::collection mVillaCollection;

    VillaItem *mVillaItem;

    Signal<std::string> _ClickVilla;
};



class VillaPage : public ContainerWidget , public DBClass
{
public:
    VillaPage( mongocxx::database* _db ) ;


    Signal<std::string> &ClickVilla();

private:
    Signal<std::string> _ClickVilla;

};

#endif // VILLAGETHUMPNAILS_H
