#ifndef BODY_H
#define BODY_H

#include "eCore/containerwiget.h"
#include "eCore/db.h"
#include "villa/villamanager.h"

class Body : public ContainerWidget , public eCore::DB
{
public:
    explicit Body(eCore::DB* _db);
};

#endif // BODY_H
