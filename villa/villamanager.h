#ifndef VILLAMANAGER_H
#define VILLAMANAGER_H


#include "eCore/containerwiget.h"
#include "eCore/listitem.h"
#include "villa.h"
#include "eWidget/evillawidget.h"
#include "eWidget/evillapage.h"

class VillaManager : public ContainerWidget, public eCore::ListItem<VillaItem>
{
public:
    explicit VillaManager( eCore::DB* _db , const bool& _adminPage = false );

    virtual void onList(const QVector<VillaItem> *mlist) final;

    virtual void errorOccured(const std::string &errorText) final;


private:

    bool mAdminPage;

    void initAdminList(const QVector<VillaItem>*);

    void initPublicList(const QVector<VillaItem>*);
};

#endif // VILLAMANAGER_H
