#ifndef REZERVATONITEM_H
#define REZERVATONITEM_H

#include "eCore/item.h"
#include <QDateTime>



namespace eCore {
namespace RezervationKey {
static const std::string beginDate{"beginJulianDate"};
static const std::string endDate{"endJulianDate"};
static const std::string kisiSayisi{"kisiSayisi"};
static const std::string musteriOid{"musteriOid"};
static const std::string villaOid{"villaOid"};
static const std::string onayli{"onayli"};
} // namespace Key

class RezervationItem : public eCore::Item
{
public:

    static const std::string Collection;

    RezervationItem();

    RezervationItem& setBeginJulianDate( const std::int64_t beginDate );
     std::int64_t beginJulianDate() const;

    RezervationItem &setEndJulianDate( const std::int64_t endDate );
     std::int64_t endJulianDate() const;

     RezervationItem setVillaOid( const std::string& villaOid );
     std::string villaOid() const;

     RezervationItem setMusteriOid( const std::string& musteriOid );
     std::string musteriOid() const;

     RezervationItem setKisiSayisi( std::int32_t kisiSayisi );
     std::int32_t kisiSayisi() const;

     std::string tarih() const;
     std::string saat() const;
};
}



#endif // REZERVATONITEM_H
