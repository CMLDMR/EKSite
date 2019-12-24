#include "villaitemv2.h"



eCore::VillaItem::VillaItem()
    :Item(VillaKey::Collection)
{

}

eCore::VillaItem &eCore::VillaItem::setName(const std::string &value)
{
    this->append(VillaKey::adi,value);
    return *this;
}

eCore::VillaItem &eCore::VillaItem::setKonum(const std::string &value)
{
    this->append(VillaKey::konum,value);
    return *this;
}

eCore::VillaItem &eCore::VillaItem::setHavuz(const std::string &value)
{
    this->append(VillaKey::havuz,value);
    return *this;
}

eCore::VillaItem &eCore::VillaItem::setil(const std::string &value)
{
    this->append(VillaKey::il,value);
    return *this;
}

eCore::VillaItem &eCore::VillaItem::setilce(const std::string &value)
{
    this->append(VillaKey::ilce,value);
    return *this;
}

eCore::VillaItem &eCore::VillaItem::setKisi(const int &value)
{
    this->append(VillaKey::kisi,value);
    return *this;
}

eCore::VillaItem &eCore::VillaItem::setAciklama(const std::string &value)
{
    this->append(VillaKey::aciklama,value);
    return *this;
}

eCore::VillaItem &eCore::VillaItem::setYayinda(const bool &value)
{
    this->append(VillaKey::yayinda,value);
    return *this;
}




std::string eCore::VillaView::adi() const
{
    auto val = this->element(VillaKey::adi);
    if( val )
    {
        return val.value().get_utf8().value.to_string();
    }
    return "";
}

std::string eCore::VillaView::konum() const
{
    auto val = this->element(VillaKey::konum);
    if( val )
    {
        return val.value().get_utf8().value.to_string();
    }
    return "";
}

std::string eCore::VillaView::havuz() const
{
    auto val = this->element(VillaKey::havuz);
    if( val )
    {
        return val.value().get_utf8().value.to_string();
    }
    return "";
}

std::string eCore::VillaView::il() const
{
    auto val = this->element(VillaKey::il);
    if( val )
    {
        return val.value().get_utf8().value.to_string();
    }
    return "";
}

std::string eCore::VillaView::ilce() const
{
    auto val = this->element(VillaKey::ilce);
    if( val )
    {
        return val.value().get_utf8().value.to_string();
    }
    return "";
}

int eCore::VillaView::kisi() const
{
    auto val = this->element(VillaKey::adi);
    if( val )
    {
        return val.value().get_int32().value;
    }
    return 0;
}

std::string eCore::VillaView::aciklama() const
{
    auto val = this->element(VillaKey::aciklama);
    if( val )
    {
        return val.value().get_utf8().value.to_string();
    }
    return "";
}

eCore::VillaView::VillaView(const eCore::VillaItem &item)
{
    this->setDocumentView(item.view());
}

bool eCore::VillaView::yayinda() const
{
    auto val = this->element(VillaKey::yayinda);
    if( val )
    {
        return val.value().get_bool().value;
    }
    return false;
}
