#include "villaitem.h"
#include <iostream>

using namespace std;



const std::string VillaItem::VILLANAME = "VILLANAME";
const std::string VillaItem::VILLAKONUM = "VILLAKONUM";
const std::string VillaItem::VILLAHAVUZ = "VILLAHAVUZ";
const std::string VillaItem::VILLAIL = "VILLAIL";
const std::string VillaItem::VILLAILCE = "VILLAILCE";
const std::string VillaItem::VILLAKISI = "VILLAKISI";
const std::string VillaItem::VILLAIMGLIST = "VILLAIMGLIST";
const std::string VillaItem::VILLAACIKLAMA = "VILLAACIKLAMA";


VillaItem VillaItem::Create_EmptyVilla(mongocxx::collection &collection)
{
    VillaItem item(collection);
    return item;
}

document VillaItem::villaDocument()
{
    auto insDoc = document{};

    auto imgArray = bsoncxx::builder::basic::array{};

    for( auto item : this->villaImgOidList() )
    {
        imgArray.append(bsoncxx::oid{item});
    }

    try {
        insDoc.append(kvp(VILLAIMGLIST,imgArray));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << e.what() << std::endl;
        return document{};
    }

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
    ,mCollection(_collection)
{
    try {
        auto ins = this->insert_one(this->villaDocument().view());
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
                return 0;
            }

        }else{
            return 0;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return 0;
    }
}

bool VillaItem::setVillaKisiAdet(int villaKisiAdet)
{
    auto setDoc = document{};

    try {
        setDoc.append(kvp("$set",make_document(kvp(VILLAKISI,villaKisiAdet))));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }

    try {
        auto upt = this->update_one(this->villaFilter().view(),setDoc.view());
        if( upt.has_value() )
        {
            if( upt.value().modified_count() )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }
}

QVector<std::string> VillaItem::villaImgOidList()
{
    QVector<std::string> imglist;
    try {
        auto val = this->find_one(this->villaFilter().view());
        if( val.has_value() )
        {
            try {
                auto array =  val.value().view()[VILLAIMGLIST].get_array().value;

                for( auto path : array )
                {
                    imglist.push_back(path.get_oid().value.to_string());
                }

            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
            }

        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
    }

    return imglist;
}

bool VillaItem::appendImgOid(const bsoncxx::types::value &value)
{

    auto setDoc = document{};

    try {
        setDoc.append(kvp("$push",make_document(kvp(VILLAIMGLIST,value))));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }

    try {
        auto upt = this->update_one(this->villaFilter().view(),setDoc.view());
        if( upt.has_value() )
        {
            if( upt.value().modified_count() )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {

    }
}


bsoncxx::oid VillaItem::villaOid() const
{
    return mVillaOid;
}


mongocxx::collection &VillaItem::collection()
{
    return mCollection;
}





VillaItem VillaItem::operator=(VillaItem &item)
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



bool VillaItem::operator==(VillaItem &item)
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

bool VillaItem::operator!=(VillaItem &item)
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

std::string VillaItem::villaIlce()
{
    try {
        auto val = this->find_one(this->villaFilter().view());
        if( val.has_value() )
        {
            try {
                return val.value().view()[VILLAILCE].get_utf8().value.to_string();
            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                return "";
            }

        }else{
            return "";
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return "";
    }

}

bool VillaItem::setVillaIlce(const std::string &villaIlce)
{
    auto setDoc = document{};

    try {
        setDoc.append(kvp("$set",make_document(kvp(VILLAILCE,villaIlce))));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }

    try {
        auto upt = this->update_one(this->villaFilter().view(),setDoc.view());
        if( upt.has_value() )
        {
            if( upt.value().modified_count() )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }
}

std::string VillaItem::villaIl()
{
    try {
        auto val = this->find_one(this->villaFilter().view());
        if( val.has_value() )
        {
            try {
                return val.value().view()[VILLAIL].get_utf8().value.to_string();
            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                return "";
            }

        }else{
            return "";
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return "";
    }
}

bool VillaItem::setVillaIl(const std::string &villaIl)
{
    auto setDoc = document{};

    try {
        setDoc.append(kvp("$set",make_document(kvp(VILLAIL,villaIl))));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }

    try {
        auto upt = this->update_one(this->villaFilter().view(),setDoc.view());
        if( upt.has_value() )
        {
            if( upt.value().modified_count() )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }
}

std::string VillaItem::villaHavuz()
{
    try {
        auto val = this->find_one(this->villaFilter().view());
        if( val.has_value() )
        {
            try {
                return val.value().view()[VILLAHAVUZ].get_utf8().value.to_string();
            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                return "";
            }

        }else{
            return "";
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return "";
    }
}

bool VillaItem::setVillaHavuz(const std::string &villaHavuz)
{
    auto setDoc = document{};

    try {
        setDoc.append(kvp("$set",make_document(kvp(VILLAHAVUZ,villaHavuz))));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }

    try {
        auto upt = this->update_one(this->villaFilter().view(),setDoc.view());
        if( upt.has_value() )
        {
            if( upt.value().modified_count() )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }
}

std::string VillaItem::villaKonum()
{
    try {
        auto val = this->find_one(this->villaFilter().view());
        if( val.has_value() )
        {
            try {
                return val.value().view()[VILLAKONUM].get_utf8().value.to_string();
            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                return "";
            }

        }else{
            return "";
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return "";
    }
}

bool VillaItem::setVillaKonum(const std::string &villaKonum)
{
    auto setDoc = document{};

    try {
        setDoc.append(kvp("$set",make_document(kvp(VILLAKONUM,villaKonum))));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }

    try {
        auto upt = this->update_one(this->villaFilter().view(),setDoc.view());
        if( upt.has_value() )
        {
            if( upt.value().modified_count() )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }
}

std::string VillaItem::villaName()
{
    try {
        auto val = this->find_one(this->villaFilter().view());
        if( val.has_value() )
        {
            try {
                return val.value().view()[VILLANAME].get_utf8().value.to_string();
            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                return "";
            }

        }else{
            return "";
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return "";
    }
}

bool VillaItem::setVillaName(const std::string &villaName)
{
    auto setDoc = document{};

    try {
        setDoc.append(kvp("$set",make_document(kvp(VILLANAME,villaName))));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }

    try {
        auto upt = this->update_one(this->villaFilter().view(),setDoc.view());
        if( upt.has_value() )
        {
            if( upt.value().modified_count() )
            {
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }
}
