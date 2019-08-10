#ifndef TCITEM_H
#define TCITEM_H

#include "itembase.h"

namespace TC {

namespace KEY {
static const std::string collection{"tcCollection"};
static const std::string tcno{"tcno"};
static const std::string telefon{"telefon"};
static const std::string adsoyad{"adsoyad"};
static const std::string adress{"adres"};
static const std::string email{"email"};
}

class TCItem : public ItemBase
{
public:
    static boost::optional<TCItem> Create_TC(mongocxx::database* _db,
                                      const std::string &tcno,
                                      const std::string &telefon,
                                      const std::string &adsoyad,
                                      const std::string &adres,
                                      const std::string &email);

    static QVector<TCItem*> GetList(mongocxx::database* _db , const bsoncxx::document::view &filter );


private:
    TCItem(mongocxx::database* _db);
    TCItem(mongocxx::database* _db , bsoncxx::document::value value );


};


}


#endif // TCITEM_H
