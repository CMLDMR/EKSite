#include "villaitem.h"
#include <iostream>


using namespace std;



const std::string VillaItem::VILLANAME = "VILLANAME";
const std::string VillaItem::VILLAKONUM = "VILLAKONUM";
const std::string VillaItem::VILLAHAVUZ = "VILLAHAVUZ";
const std::string VillaItem::VILLAIL = "VILLAIL";
const std::string VillaItem::VILLAILCE = "VILLAILCE";
const std::string VillaItem::VILLAKISI = "VILLAKISI";


VillaItem VillaItem::Create_EmptyVilla(mongocxx::collection &collection)
{
    VillaItem item(collection);
    return item;
}

document VillaItem::villaView()
{
    auto insDoc = document{};

    try {
        insDoc.append(kvp(VILLANAME,this->villaName()));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << e.what() << std::endl;
        return document{};
    }

    try {
        insDoc.append(kvp(VILLAKONUM,this->villaKonum()));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << e.what() << std::endl;
        return document{};
    }

    try {
        insDoc.append(kvp(VILLAHAVUZ,this->villaHavuz()));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << e.what() << std::endl;
        return document{};
    }

    try {
        insDoc.append(kvp(VILLAIL,this->villaIl()));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << e.what() << std::endl;
        return document{};
    }

    try {
        insDoc.append(kvp(VILLAILCE,this->villaIlce()));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << e.what() << std::endl;
        return document{};
    }

    try {
        insDoc.append(kvp(VILLAKISI,this->villaKisiAdet()));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << e.what() << std::endl;
        return document{};
    }

    return insDoc;
}

VillaItem::VillaItem(mongocxx::collection &_collection)
    :mongocxx::collection (_collection)
    ,mVillaName{""}
    ,mVillaKonum{""}
    ,mVillaHavuz{""}
    ,mVillaIl{""}
    ,mVillaIlce{""}
    ,mVillaKisiAdet(0)
    ,mCollection(_collection)
{

    try {
        auto ins = this->insert_one(this->villaView().view());
        if( ins.has_value() )
        {
            this->setVillaOid(ins.value().inserted_id().get_oid().value);
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << e.what() << std::endl;
    }
}

bsoncxx::builder::basic::document VillaItem::villaFilter()
{
    auto filter = document{};

    try {
        filter.append(kvp("_id",this->villaOid()));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
    }

    return filter;
}

VillaItem::~VillaItem()
{

    std::cout<< "Desturctor Villa Item oid: " << this->villaOid().to_string() << std::endl;

}

void VillaItem::setVillaOid(const bsoncxx::oid &villaOid)
{
    mVillaOid = villaOid;
}

int VillaItem::villaKisiAdet()
{


    try {
        auto val = this->find_one(this->villaFilter().view());
        if( val.has_value() )
        {
            try {
                return val.value().view()[VILLAKISI].get_int32().value;
            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
            }

        }else{
            return -1;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return -1;
    }


    return mVillaKisiAdet;
}

void VillaItem::setVillaKisiAdet(int villaKisiAdet)
{
    mVillaKisiAdet = villaKisiAdet;
}

bsoncxx::oid VillaItem::villaOid() const
{
    return mVillaOid;
}


const mongocxx::collection& VillaItem::collection() const
{
    return mCollection;
}





VillaItem VillaItem::operator=(const VillaItem &item)
{
    VillaItem _item(item.collection());

    _item.setVillaIl(item.villaIl());
    _item.setVillaKisiAdet(item.villaKisiAdet());
    _item.setVillaIlce(item.villaIlce());
    _item.setVillaName(item.villaName());
    _item.setVillaHavuz(item.villaHavuz());
    _item.setVillaKonum(item.villaKonum());
    _item.setVillaOid(item.villaOid());
    return _item;
}



bool VillaItem::operator==(const VillaItem &item)
{
    if( this->villaIl() != item.villaIl() )
        return false;

    if( this->villaIlce() != item.villaIlce() )
        return false;

    if( this->villaName() != item.villaName() )
        return false;

    if( this->villaHavuz() != item.villaHavuz() )
        return false;

    if( this->villaKonum() != item.villaKonum() )
        return false;

    if( this->villaOid() != item.villaOid() )
        return false;

    if( this->villaKisiAdet() != item.villaKisiAdet() )
        return false;

    return true;

}

bool VillaItem::operator!=(const VillaItem &item)
{
    if( this->villaIl() == item.villaIl() )
        return false;

    if( this->villaIlce() == item.villaIlce() )
        return false;

    if( this->villaName() == item.villaName() )
        return false;

    if( this->villaHavuz() == item.villaHavuz() )
        return false;

    if( this->villaKonum() == item.villaKonum() )
        return false;

    if( this->villaOid() == item.villaOid() )
        return false;

    if( this->villaKisiAdet() == item.villaKisiAdet() )
        return false;

    return true;
}

std::string VillaItem::villaIlce() const
{
    return mVillaIlce;
}

void VillaItem::setVillaIlce(const std::string &villaIlce)
{
    mVillaIlce = villaIlce;
}

std::string VillaItem::villaIl() const
{
    return mVillaIl;
}

void VillaItem::setVillaIl(const std::string &villaIl)
{
    mVillaIl = villaIl;
}

std::string VillaItem::villaHavuz() const
{
    return mVillaHavuz;
}

void VillaItem::setVillaHavuz(const std::string &villaHavuz)
{
    mVillaHavuz = villaHavuz;
}

std::string VillaItem::villaKonum() const
{
    return mVillaKonum;
}

void VillaItem::setVillaKonum(const std::string &villaKonum)
{
    mVillaKonum = villaKonum;
}

std::string VillaItem::villaName() const
{
    return mVillaName;
}

void VillaItem::setVillaName(const std::string &villaName)
{
    mVillaName = villaName;
}
