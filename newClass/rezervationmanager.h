#ifndef REZERVATIONMANAGER_H
#define REZERVATIONMANAGER_H

#include "rezervationlist.h"
#include "eCore/containerwidgetv2.h"

namespace Rezervation {

class RezervationManager : public eCore::ContainerWidget , public RezervationList
{
public:
    RezervationManager( eCore::DB* _db );

    virtual void onList(const QVector<eCore::RezervationItem> &mlist) override;

};


class RezervationListWidget : public eCore::ContainerWidget
{
public:
    RezervationListWidget(const eCore::RezervationItem &item);


    Signal<bool> &RezervationStatusChanged();

private:
    const eCore::RezervationItem rItem;

    Signal<bool> _rezervationStatusChanged;
};

}



#endif // REZERVATIONMANAGER_H
