#ifndef VILLADETAILPAGE_H
#define VILLADETAILPAGE_H

#include "base/containerwidget.h"
#include "base/dbclass.h"

class VillaItem;

class VillaDetailPage : public ContainerWidget , public DBClass
{
public:
    VillaDetailPage(mongocxx::database* _db , const std::string &_villaOid );




private:
    VillaItem* mVillaItem;

    mongocxx::collection mVillaCollection;
};

#endif // VILLADETAILPAGE_H
