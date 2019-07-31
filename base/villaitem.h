#ifndef VILLAITEM_H
#define VILLAITEM_H


#include "mongoheaders.h"


#include <QVector>


class VillaItem : public mongocxx::collection
{
public:
    static VillaItem Create_EmptyVilla(mongocxx::collection &collection);

    document villaDocument();

    ~VillaItem();

    std::string villaName();
    bool setVillaName(const std::string &villaName);

    std::string villaKonum();
    bool setVillaKonum(const std::string &villaKonum);

    std::string villaHavuz();
    bool setVillaHavuz(const std::string &villaHavuz);

    std::string villaIl();
    bool setVillaIl(const std::string &villaIl);

    std::string villaIlce();
    bool setVillaIlce(const std::string &villaIlce);

    int villaKisiAdet();
    bool setVillaKisiAdet(int villaKisiAdet);


    QVector<std::string> villaImgOidList();
    bool appendImgOid( const bsoncxx::types::value &value );

    VillaItem operator=(VillaItem &item);


    bool operator==(VillaItem &item);
    bool operator!=(VillaItem &item);

    mongocxx::collection &collection();


    bsoncxx::oid villaOid() const;
    void setVillaOid(const bsoncxx::oid &villaOid);


    static const std::string VILLANAME;
    static const std::string VILLAKONUM;
    static const std::string VILLAHAVUZ;
    static const std::string VILLAIL;
    static const std::string VILLAILCE;
    static const std::string VILLAKISI;
    static const std::string VILLAIMGLIST;
    static const std::string VILLAACIKLAMA;




private:
    VillaItem(mongocxx::collection &_collection);


    bsoncxx::oid mVillaOid;


    mongocxx::collection &mCollection;

    document villaFilter();
};

#endif // VILLAITEM_H
