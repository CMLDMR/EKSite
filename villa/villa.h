#ifndef VILLA_H
#define VILLA_H


#include "eCore/item.h"
#include "eCore/containerwiget.h"

namespace villaKey {

static const std::string Collection{"villa"};
static const std::string adi{"adi"};
static const std::string yeri{"yeri"};
static const std::string fotoOid{"fotoOid"};
static const std::string tanim{"tanim"};
}

class VillaItem : public eCore::Item
{
public:
    VillaItem();
    VillaItem( const VillaItem& other );
    VillaItem( VillaItem&& other );

    VillaItem& operator=( const VillaItem& other );
    VillaItem& operator=( VillaItem&& other );

    VillaItem& setAdi( const std::string& adi );
    VillaItem& setYeri( const std::string& yeri );
    VillaItem& setFotoOid( const std::string& fotoOid );
    VillaItem& setTanim( const std::string& tanim );

    const std::string adi() const;
    const std::string yeri() const;
    const std::string fotoOid() const;
    const std::string tanim() const;

    void errorOccured(const std::string &errorText) override;
};



class VillaThump : public ContainerWidget , public VillaItem
{
public:
    explicit VillaThump( const bsoncxx::document::view& view);
};
#endif // VILLA_H
