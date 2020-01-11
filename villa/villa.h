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
static const std::string kisiSayi{"kisiSayisi"};
static const std::string havuz{"havuz"};
static const std::string fotoList{"fotoList"};
static const std::string yayinda{"yayinda"};
}

class VillaItem : public eCore::Item
{
public:
    VillaItem( );
    VillaItem( const VillaItem& other );
    VillaItem( VillaItem&& other );

    VillaItem& operator=( const VillaItem& other );
    VillaItem& operator=( VillaItem&& other );

    VillaItem& setAdi( const std::string& adi );
    VillaItem& setYeri( const std::string& yeri );
    VillaItem& setFotoOid( const std::string& fotoOid );
    VillaItem& setFotoOid( const bsoncxx::oid& fotoOid );
    VillaItem& setTanim( const std::string& tanim );
    VillaItem& setKisiSayisi( const int& kisiSayisi );
    VillaItem& setHavuz( const std::string &havuz );
    VillaItem& setFotoList( const QVector<bsoncxx::oid> list );
    VillaItem& addFotoList( const bsoncxx::oid& fotoOid );
    VillaItem& setYayinda( const bool& yayinda );


    const std::string adi() const;
    const std::string yeri() const;
    const std::string fotoOid() const;
    const std::string tanim() const;
    int kisiSayisi() const;
    const std::string havuz() const;
    const bool yayinda() const;

    const QVector<bsoncxx::oid> fotoList() const;


    void errorOccured(const std::string &errorText) override;
};



class VillaThump : public ContainerWidget , public VillaItem
{
public:
    explicit VillaThump( const bsoncxx::document::view& view);
};
#endif // VILLA_H
