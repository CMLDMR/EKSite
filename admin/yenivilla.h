#ifndef YENIVILLA_H
#define YENIVILLA_H

#include "eCore/containerwiget.h"
#include "villa/villa.h"
#include "eCore/db.h"

class YeniVilla : public ContainerWidget , public VillaItem
{
public:
    YeniVilla(eCore::DB* _db);

    WContainerWidget* mFotoContainerWidget;

    Signal<NoClass> &ClickBack();

private:
    Signal<NoClass> _ClickBack;

    WContainerWidget* ekFotoContainer;

    eCore::DB* mDB;
};

#endif // YENIVILLA_H
