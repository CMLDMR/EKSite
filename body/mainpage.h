#ifndef MAINPAGE_H
#define MAINPAGE_H

#include "eCore/db.h"
#include "eCore/containerwiget.h"

class MainPage : public ContainerWidget , public eCore::DB
{
public:
    explicit MainPage(eCore::DB* _db );
};

#endif // MAINPAGE_H
