#include "rezervatonitem.h"

const std::string eCore::RezervationItem::Collection{"rezervasyon"};



eCore::RezervationItem::RezervationItem() : eCore::Item(Collection)
{
    this->clear();
}

eCore::RezervationItem::RezervationItem(const eCore::RezervationItem &other) : eCore::Item(other.Collection)
{
    this->setDocumentView(other.view());
}

eCore::RezervationItem::RezervationItem(eCore::RezervationItem &&other) : eCore::Item(other.Collection)
{
    this->setDocumentView(other.view());
}

eCore::RezervationItem &eCore::RezervationItem::operator=(const eCore::RezervationItem &other)
{
    this->setDocumentView(other.view());
    return *this;
}

eCore::RezervationItem &eCore::RezervationItem::operator=(eCore::RezervationItem &&other)
{
    this->setDocumentView(other.view());
    return *this;
}

eCore::RezervationItem &eCore::RezervationItem::setBeginJulianDate(const int64_t beginDate)
{
    this->append(RezervationKey::beginDate,beginDate);
    return *this;
}

int64_t eCore::RezervationItem::beginJulianDate() const
{
    auto val = this->element(RezervationKey::beginDate);
    if( val )
    {
        return val.value().get_int64().value;
    }
    return -1;
}

eCore::RezervationItem& eCore::RezervationItem::setEndJulianDate(const int64_t endDate)
{
    this->append(RezervationKey::endDate,endDate);
    return *this;
}

int64_t eCore::RezervationItem::endJulianDate() const
{
    auto val = this->element(RezervationKey::endDate);
    if( val )
    {
        return val.value().get_int64().value;
    }
    return -1;
}

eCore::RezervationItem& eCore::RezervationItem::setVillaOid(const std::string &villaOid)
{
    this->append(RezervationKey::villaOid,bsoncxx::oid{villaOid});
    return *this;
}

std::string eCore::RezervationItem::villaOid() const
{
    auto val = this->element(RezervationKey::villaOid);
    if( val )
    {
        return val.value().get_oid().value.to_string();
    }
    return "";
}

eCore::RezervationItem& eCore::RezervationItem::setMusteriOid(const std::string &musteriOid)
{
    this->append(RezervationKey::musteriOid,bsoncxx::oid{musteriOid});
    return *this;
}

std::string eCore::RezervationItem::musteriOid() const
{
    auto val = this->element(RezervationKey::musteriOid);
    if( val )
    {
        return val.value().get_oid().value.to_string();
    }
    return "";
}

eCore::RezervationItem& eCore::RezervationItem::setKisiSayisi(int32_t kisiSayisi)
{
    this->append(RezervationKey::kisiSayisi,kisiSayisi);
    return *this;
}

int32_t eCore::RezervationItem::kisiSayisi() const
{
    auto val = this->element(RezervationKey::kisiSayisi);
    if( val )
    {
        return val.value().get_int32().value;
    }
    return 0;
}

std::string eCore::RezervationItem::tarih() const
{
    auto val = this->oid();
    if( val )
    {
        return QDateTime::fromTime_t(val.value().get_time_t()).date().toString("dd/MM/yyyy").toStdString();
    }
    return "";
}

std::string eCore::RezervationItem::saat() const
{
    auto val = this->oid();
    if( val )
    {
        return QDateTime::fromTime_t(val.value().get_time_t()).time().toString("hh:mm").toStdString();
    }
    return "";
}

eCore::RezervationItem &eCore::RezervationItem::setOnay(const bool &onay)
{
    this->append(RezervationKey::onayli,onay);
    return *this;
}

bool eCore::RezervationItem::onay() const
{
    auto val = this->element(RezervationKey::onayli);
    if( val )
    {
        return val.value().get_bool().value;
    }
    return false;
}


