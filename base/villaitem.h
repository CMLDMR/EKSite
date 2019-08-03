#ifndef VILLAITEM_H
#define VILLAITEM_H


#include "mongoheaders.h"


#include <QVector>


class VillaItem : private mongocxx::collection
{
public:
    static VillaItem Create_EmptyVilla(mongocxx::collection &collection);

    static VillaItem* Load_Villa(mongocxx::collection *collection , bsoncxx::oid _villaOid );

    static VillaItem Load_Villa(mongocxx::collection &collection , bsoncxx::oid _villaOid );

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

    std::string villaAciklama();
    bool setVillaAciklama(const std::string &villaAciklama);

    /// TODO: Implentation Edilmedim.
    int villaAcilisFiyat();
    bool setVillaAcilisFiyat( const int &acilisFiyat );

    bool villaYayinda();
    bool setVillaYayinda(const bool &yayinda);


    QVector<std::string> villaImgOidList();
    bool appendImgOid( const bsoncxx::types::value &value );
    bool setImgOidList(const QVector<bsoncxx::types::value> &oidList );
    bool deleteImgOid( const bsoncxx::oid &fileOid );

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
    static const std::string VILLAYAYINDA;




private:
    VillaItem(mongocxx::collection &_collection);
    VillaItem(mongocxx::collection &_collection , bsoncxx::oid villaOid );


    bsoncxx::oid mVillaOid;


    mongocxx::collection &mCollection;

    document villaFilter();
};

#endif // VILLAITEM_H
