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

VillaItem &VillaItem::setKisiSayisi(const int &kisiSayisi)
{
    this->append(villaKey::kisiSayi,bsoncxx::types::b_int32{kisiSayisi});
    return *this;
}

VillaItem &VillaItem::setHavuz(const std::string &havuz)
{
    this->append(villaKey::havuz,havuz);
    return *this;
}

VillaItem &VillaItem::setFotoList(const QVector<bsoncxx::oid> list)
{
    for( auto itemOid : list )
    {
        this->pushArray(villaKey::fotoList,itemOid);
    }
    return *this;
}

VillaItem &VillaItem::addFotoList(const bsoncxx::oid &fotoOid)
{
    this->pushArray(villaKey::fotoList,fotoOid);
    return *this;
}

VillaItem &VillaItem::setYayinda(const bool &yayinda)
{
    this->append(villaKey::yayinda,yayinda);
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

const std::string VillaItem::havuz() const
{
    auto val = this->element (villaKey::havuz);
    if( val )
    {
        return val.value ().get_utf8 ().value.to_string();
    }
    return "";
}

const bool VillaItem::yayinda() const
{
    auto val = this->element (villaKey::yayinda);
    if( val )
    {
        return val.value ().get_bool ().value;
    }
    return false;
}

const QVector<bsoncxx::oid> VillaItem::fotoList() const
{
    QVector<bsoncxx::oid> list;
    auto val = this->element (villaKey::fotoList);
    if( val )
    {
        auto array = val.value ().get_array ().value;
        for( auto item : array )
        {
            list.push_back (item.get_oid ().value);
        }
    }
    return list;
}

 int VillaItem::kisiSayisi() const
{
    auto val = this->element (villaKey::kisiSayi);
    if( val )
    {
        return val.value ().get_int32 ().value;
    }
    return 0;
}

void VillaItem::errorOccured(const std::string &errorText)
{

}

VillaThump::VillaThump(const bsoncxx::document::view &view)
{
    this->setDocumentView (view);
}
