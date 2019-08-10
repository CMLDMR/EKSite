#ifndef REZERVEITEM_H
#define REZERVEITEM_H

#include "dbclass.h"
#include <boost/optional.hpp>

namespace REZERVE {

namespace KEY {
static const std::string collection{"rezervasyon"};
static const std::string villaOid{"villaOid"};
static const std::string beginDate{"beginJulianDate"};
static const std::string endDate{"endJulianDate"};
static const std::string kisiSayisi{"kisiSayisi"};
static const std::string musteriOid{"musteriOid"};
}

class RezerveItem : public DBClass
{
public:
    boost::optional<RezerveItem> Create_Rezervasyon(mongocxx::database* _db,
                                                    const bsoncxx::oid& villaOid,
                                                    const std::int64_t &beginDate,
                                                    const std::int64_t &endDate,
                                                    const int &kisiSayi,
                                                    const bsoncxx::oid &musteriOid);

    bool isValid() const;

    bsoncxx::oid oid() const;

    bsoncxx::oid villaOid() const;
    bool setVillaOid(const bsoncxx::oid &villaOid);

    std::int64_t beginDate() const;
    bool setBeginDate(const std::int64_t &beginDate);

    std::int64_t endDate() const;
    bool setEndDate(const std::int64_t &endDate);

    int kisiSayisi() const;
    bool setKisiSayisi(int kisiSayisi);

    bsoncxx::oid musteriOid() const;
    bool setMusteriOid(const bsoncxx::oid &musteriOid);

private:
    explicit RezerveItem(mongocxx::database* _db);
    RezerveItem(mongocxx::database* _db , const bsoncxx::oid& rezerveOid);

    bool mIsValid;
    bsoncxx::oid mOid;
    bsoncxx::oid mVillaOid;

    std::int64_t mBeginDate;
    std::int64_t mEndDate;
    int mKisiSayisi;
    bsoncxx::oid mMusteriOid;


    document filter();

    bool updateRezerveItem();
};

}


#endif // REZERVEITEM_H
