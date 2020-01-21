#ifndef EVILLAPAGE_H
#define EVILLAPAGE_H
#include "eCore/containerwiget.h"
#include "villa/villa.h"

namespace eWidget{

class eVillaPage : public ContainerWidget , public VillaItem
{
public:
    eVillaPage(const VillaItem& villaItem , eCore::DB *_db , const bool& initPublicLink = true );

    void initPublic();

    void initAdmin();

    void initRezervasion();

    void errorOccured(const std::string &errorText) override;

private:
    eCore::DB* mDB;
};

}



#endif // EVILLAPAGE_H
