#include "itembase.h"

ItemBase::ItemBase(mongocxx::database *_db, const std::string &_collection)
    :DBClass(_db),collection(std::move(_collection)),mIsValid(true)
{
    try {
        auto ins = this->db()->collection(collection).insert_one(document{}.view());
        if( ins )
        {
            if( ins.value().result().inserted_count() )
            {
                mOid = ins.value().inserted_id().get_oid().value;
            }else{
                mIsValid = false;
            }
        }else{
            mIsValid = false;
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        mIsValid = false;
    }
}

ItemBase::ItemBase(mongocxx::database *_db, const std::string &_collection, bsoncxx::document::value value)
    :DBClass(_db),collection(std::move(_collection)),mIsValid(true)
{
    for( auto it = value.view().cbegin() ; it != value.view().cend() ; ++it )
    {
        if( it->key().to_string() != "_id" )
        {
            try {
                append(kvp(it->key(),it->get_value()));
            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                mIsValid = false;
            }
        }else{
            mOid = it->get_oid().value;
        }

    }
}

bsoncxx::document::view ItemBase::View() const
{
    return this->view();
}



boost::optional<bsoncxx::document::element> ItemBase::Element(const std::string &key) const
{
    try {
        return this->view()[key];
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return boost::none;
    }
}

boost::optional<bsoncxx::document::element> ItemBase::operator[](const std::string &key) const
{
    try {
        return this->view()[key];
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return boost::none;
    }
}

bool ItemBase::deleteDocument()
{
    auto filter = document{};

    try {
        filter.append(kvp("_id",mOid));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
        return false;
    }


    try {
        auto del = this->db()->collection(collection).delete_one(filter.view());
        if( del )
        {
            if( del.value().deleted_count() )
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

bool ItemBase::isValid() const
{
    return mIsValid;
}








