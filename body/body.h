#ifndef BODY_H
#define BODY_H

#include "eCore/containerwiget.h"
#include "eCore/db.h"

class Body : public ContainerWidget , public eCore::DB
{
public:
    Body(eCore::DB* _db);
};

#endif // BODY_H
