#ifndef VILLAITEM_H
#define VILLAITEM_H


#include "mongoheaders.h"



class VillaItem : public mongocxx::collection
{
public:
    static VillaItem Create_EmptyVilla(mongocxx::collection &collection);

    document villaView();

    ~VillaItem();



    std::string villaName() const;
    void setVillaName(const std::string &villaName);

    std::string villaKonum() const;
    void setVillaKonum(const std::string &villaKonum);

    std::string villaHavuz() const;
    void setVillaHavuz(const std::string &villaHavuz);

    std::string villaIl() const;
    void setVillaIl(const std::string &villaIl);

    std::string villaIlce() const;
    void setVillaIlce(const std::string &villaIlce);

    int villaKisiAdet();
    void setVillaKisiAdet(int villaKisiAdet);

    VillaItem operator=(const VillaItem &item);


    bool operator==(const VillaItem &item);
    bool operator!=(const VillaItem &item);

    const mongocxx::collection &collection() const;


    bsoncxx::oid villaOid() const;
    void setVillaOid(const bsoncxx::oid &villaOid);


    static const std::string VILLANAME;
    static const std::string VILLAKONUM;
    static const std::string VILLAHAVUZ;
    static const std::string VILLAIL;
    static const std::string VILLAILCE;
    static const std::string VILLAKISI;




private:
    VillaItem(mongocxx::collection &_collection);


    bsoncxx::oid mVillaOid;

    std::string mVillaName;
    std::string mVillaKonum;
    std::string mVillaHavuz;
    std::string mVillaIl;
    std::string mVillaIlce;
    int mVillaKisiAdet;


    const mongocxx::collection &mCollection;

    document villaFilter();
};

#endif // VILLAITEM_H
