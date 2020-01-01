#ifndef ADMIN_H
#define ADMIN_H

#include "eCore/containerwiget.h"
#include "eCore/db.h"

class Admin : public ContainerWidget , public eCore::DB
{
public:
    Admin(eCore::DB* _db);
};

#endif // ADMIN_H
