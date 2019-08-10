#include "rezerveitem.h"
#include <iostream>


boost::optional<REZERVE::RezerveItem> REZERVE::RezerveItem::Create_Rezervasyon(mongocxx::database *_db,
                                                             const bsoncxx::oid &villaOid,
                                                             const int64_t &beginDate,
                                                             const int64_t &endDate,
                                                             const int &kisiSayi,
                                                             const bsoncxx::oid &musteriOid)
{

    RezerveItem item(_db);

    if( !item.isValid() )
    {
        return boost::none;
    }

    item.mVillaOid = villaOid;
    item.mBeginDate = beginDate;
    item.mEndDate = endDate;
    item.mKisiSayisi = kisiSayi;
    item.mMusteriOid = musteriOid;
    if( item.updateRezerveItem() ){
        return item;
    }else{
        return boost::none;
    }
}

REZERVE::RezerveItem::RezerveItem(mongocxx::database *_db)
    :DBClass (_db)
{
    mIsValid = true;

    try {
        auto val = this->db()->collection(KEY::collection).insert_one(document{}.view());

        if( val )
        {
            mOid = val.value().inserted_id().get_oid().value;
        }else{
            mIsValid = false;
        }

    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        mIsValid = false;
    }
}

REZERVE::RezerveItem::RezerveItem(mongocxx::database *_db, const bsoncxx::oid &rezerveOid)
    :DBClass (_db)
{

}

bsoncxx::oid REZERVE::RezerveItem::musteriOid() const
{
    return mMusteriOid;
}

bool REZERVE::RezerveItem::setMusteriOid(const bsoncxx::oid &musteriOid)
{
    mMusteriOid = musteriOid;
    if( this->updateRezerveItem() )
    {
        return true;
    }else{
        return false;
    }
}

int REZERVE::RezerveItem::kisiSayisi() const
{
    return mKisiSayisi;
}

bool REZERVE::RezerveItem::setKisiSayisi(int kisiSayisi)
{
    mKisiSayisi = kisiSayisi;
    if( this->updateRezerveItem() )
    {
        return true;
    }else{
        return false;
    }
}

std::int64_t REZERVE::RezerveItem::endDate() const
{
    return mEndDate;
}

bool REZERVE::RezerveItem::setEndDate(const std::int64_t &endDate)
{
    mEndDate = endDate;
    if( this->updateRezerveItem() )
    {
        return true;
    }else{
        return false;
    }
}

std::int64_t REZERVE::RezerveItem::beginDate() const
{
    return mBeginDate;
}

bool REZERVE::RezerveItem::setBeginDate(const std::int64_t &beginDate)
{
    mBeginDate = beginDate;
    if( this->updateRezerveItem() )
    {
        return true;
    }else{
        return false;
    }
}

bsoncxx::oid REZERVE::RezerveItem::villaOid() const
{
    return mVillaOid;
}

bool REZERVE::RezerveItem::setVillaOid(const bsoncxx::oid &villaOid)
{
    mVillaOid = villaOid;
    if( this->updateRezerveItem() )
    {
        return true;
    }else{
        return false;
    }
}

bsoncxx::oid REZERVE::RezerveItem::oid() const
{
    return mOid;
}

bsoncxx::builder::basic::document REZERVE::RezerveItem::filter()
{

    auto filter_ = document{};

    try {
        filter_.append(kvp("_id",mOid));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
    }

    return filter_;
}

bool REZERVE::RezerveItem::updateRezerveItem()
{
    bool updated = true;

    auto setDoc = document{};


    if( updated )
    {
        try {
            setDoc.append(kvp(KEY::villaOid,mVillaOid));
        } catch (bsoncxx::exception &e) {
            std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
            updated = false;
        }
    }

    if( updated )
    {
        try {
            setDoc.append(kvp(KEY::beginDate,mBeginDate));
        } catch (bsoncxx::exception &e) {
            std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
            updated = false;
        }
    }

    if( updated )
    {
        try {
            setDoc.append(kvp(KEY::endDate,mEndDate));
        } catch (bsoncxx::exception &e) {
            std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
            updated = false;
        }
    }

    if( updated )
    {
        try {
            setDoc.append(kvp(KEY::kisiSayisi,mKisiSayisi));
        } catch (bsoncxx::exception &e) {
            std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
            updated = false;
        }
    }

    if( updated )
    {
        try {
            setDoc.append(kvp(KEY::musteriOid,mMusteriOid));
        } catch (bsoncxx::exception &e) {
            std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
            updated = false;
        }
    }

    if( updated )
    {
        auto uptDoc = document{};
        try {
            uptDoc.append(kvp("$set",uptDoc));
        } catch (bsoncxx::exception &e) {
            std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
            updated = false;
        }

        try {
            auto upt = this->db()->collection(KEY::collection).update_one(filter().view(),uptDoc.view());
            if( upt )
            {
                if( upt.value().modified_count() )
                {
                }else{
                    updated = false;
                }
            }else{
                updated = false;
            }
        } catch (bsoncxx::exception &e) {
            std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
            updated = false;
        }
    }
    return updated;

}

bool REZERVE::RezerveItem::isValid() const
{
    return mIsValid;
}
