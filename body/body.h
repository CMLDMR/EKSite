#ifndef BODY_H
#define BODY_H

#include "wtinclude.h"

#include <base/dbclass.h>
#include <base/containerwidget.h>

using namespace Wt;

class Body : public WContainerWidget , public DBClass
{
public:
    Body(mongocxx::database* _db);


    void initMain();

    void initLogin();

    void initAdminPanel();

    void initVillaDetail(const std::string &villaOid );
};

#endif // BODY_H
