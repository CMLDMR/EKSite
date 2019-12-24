#ifndef BODY_H
#define BODY_H

#include "wtinclude.h"

#include <base/dbclass.h>
#include <eCore/containerwidgetv2.h>
#include "eCore/db.h"

using namespace Wt;

class Body : public eCore::ContainerWidget , public eCore::DB
{
public:
    Body(DB* _db );


    void initMain();

    void initLogin();

    void initAdminPanel();

    void initVillaDetail(const std::string &villaOid );
};

#endif // BODY_H
