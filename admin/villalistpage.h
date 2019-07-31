#ifndef VILLALISTPAGE_H
#define VILLALISTPAGE_H

#include "base/dbclass.h"
#include "base/containerwidget.h"


class VillaListPage : public ContainerWidget , public DBClass
{
public:
    VillaListPage(mongocxx::database* _db);


    void initVillaList();

    void initVilla(const std::string &villaOid);

    Signal<std::string> &ClickVilla();
private:
    ContainerWidget* rContainer;
    mongocxx::collection villaCollection;

    Signal<std::string> _ClickVilla;


};

#endif // VILLALISTPAGE_H
