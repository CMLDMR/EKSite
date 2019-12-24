#ifndef VILLAMANAGER_H
#define VILLAMANAGER_H

#include "eCore/listitem.h"
#include "eCore/villaitemv2.h"
#include "eCore/containerwidgetv2.h"

namespace eCore {


class VillaManager : public eCore::ContainerWidget , public eCore::ListItem<VillaItem>
{
public:
    explicit VillaManager(DB* _db );

    void onList(const QVector<eCore::VillaItem> &mlist) override;
};



}


#endif // VILLAMANAGER_H
