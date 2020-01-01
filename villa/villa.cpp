#include "villa.h"


VillaItem::VillaItem()
    :eCore::Item(villaKey::Collection)
{

}

VillaItem::VillaItem(const VillaItem &other)
    :eCore::Item(villaKey::Collection)
{
    this->setDocumentView (other.view ());
}

VillaItem::VillaItem(VillaItem &&other)
:eCore::Item(villaKey::Collection)
{
    this->setDocumentView (other.view ());
}

VillaItem &VillaItem::operator=(const VillaItem &other)
{
    this->setDocumentView (other.view ());
    return *this;
}

VillaItem &VillaItem::operator=(VillaItem &&other)
{
    this->setDocumentView (other.view ());
    return *this;
}

VillaItem &VillaItem::setAdi(const std::string &adi)
{
    this->append(villaKey::adi,adi);
    return *this;
}

VillaItem &VillaItem::setYeri(const std::string &yeri)
{
    this->append(villaKey::yeri,yeri);
    return *this;
}

VillaItem &VillaItem::setFotoOid(const std::string &fotoOid)
{
    this->append(villaKey::fotoOid,bsoncxx::oid{fotoOid});
    return *this;
}

VillaItem &VillaItem::setTanim(const std::string &tanim)
{
    this->append(villaKey::tanim,tanim);
    return *this;
}

const std::string VillaItem::adi() const
{
    auto val = this->element (villaKey::adi);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

const std::string VillaItem::yeri() const
{
    auto val = this->element (villaKey::yeri);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

const std::string VillaItem::fotoOid() const
{
    auto val = this->element (villaKey::fotoOid);
    if( val )
    {
        return val.value ().get_oid ().value.to_string ();
    }
    return "";
}

const std::string VillaItem::tanim() const
{
    auto val = this->element (villaKey::tanim);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

void VillaItem::errorOccured(const std::string &errorText)
{

}

VillaThump::VillaThump(const bsoncxx::document::view &view)
{
    this->setDocumentView (view);
}
