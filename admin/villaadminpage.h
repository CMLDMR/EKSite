#ifndef VILLAADMINPAGE_H
#define VILLAADMINPAGE_H

#include "base/containerwidget.h"
#include "base/dbclass.h"

class VillaAdminPage : public ContainerWidget , public DBClass
{
public:
    VillaAdminPage(mongocxx::database* _db);


private:
    ContainerWidget* rContainer;

private:
    ContainerWidget* VillaDetailContainer;
    ContainerWidget* VillaList;

    WStackedWidget* stackedWidget;

    WContainerWidget* mVillalarContainer;
    WContainerWidget* mYeniVilla;
};

#endif // VILLAADMINPAGE_H
