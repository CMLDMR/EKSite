#ifndef BODY_H
#define BODY_H

#include "wtinclude.h"

#include <base/dbclass.h>

using namespace Wt;

class Body : public WContainerWidget , public DBClass
{
public:
    Body(mongocxx::database* _db);


    void initMain();

    void initLogin();
};

#endif // BODY_H
