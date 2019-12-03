#ifndef REZERVATIONLIST_H
#define REZERVATIONLIST_H

#include "eCore/listitem.h"
#include "rezervatonitem.h"

namespace Rezervation {

class RezervationList :  public eCore::ListItem<eCore::RezervationItem>
{
public:
    RezervationList(DB *_db) : eCore::ListItem<eCore::RezervationItem>(_db) {}

    virtual void onList(const QVector<eCore::RezervationItem> &mlist) override;
};

}



#endif // REZERVATIONLIST_H
