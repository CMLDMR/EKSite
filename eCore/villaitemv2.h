#ifndef VILLAITEM_H
#define VILLAITEM_H

#include "eCore/item.h"



namespace eCore {


namespace VillaKey {
static const std::string Collection{"villa"};
static const std::string adi{"adi"};
static const std::string konum{"konum"};
static const std::string havuz{"havuz"};
static const std::string il{"il"};
static const std::string ilce{"ilce"};
static const std::string kisi{"kisi"};
static const std::string aciklama{"aciklama"};
static const std::string yayinda{"yayinda"};
}

class VillaItem : public Item
{
public:
    VillaItem();

    VillaItem& setName( const std::string& value );
    VillaItem& setKonum( const std::string& value );
    VillaItem& setHavuz( const std::string& value );
    VillaItem& setil( const std::string& value );
    VillaItem& setilce( const std::string& value );
    VillaItem& setKisi( const int& value );
    VillaItem& setAciklama( const std::string& value );
    VillaItem& setYayinda( const bool& value );
};


class VillaView : private VillaItem
{
public:
    explicit VillaView(const VillaItem& item );


    bool yayinda() const;
    std::string adi () const;
    std::string konum () const;
    std::string havuz () const;
    std::string il () const;
    std::string ilce () const;
    int kisi () const;
    std::string aciklama () const;
};


}


#endif // VILLAITEM_H
