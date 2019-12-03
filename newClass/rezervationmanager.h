#ifndef REZERVATIONMANAGER_H
#define REZERVATIONMANAGER_H

#include "rezervationlist.h"
#include "eCore/containerwidgetv2.h"

class RezervationManager : public ContainerWidgetV2 , public RezervationList
{
public:
    RezervationManager( eCore::DB* _db );

    virtual void onList(const QVector<eCore::RezervationItem> &mlist) override;
};

#endif // REZERVATIONMANAGER_H
