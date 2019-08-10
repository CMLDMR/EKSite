#ifndef ITEMBASE_H
#define ITEMBASE_H

#include "dbclass.h"
#include <boost/optional.hpp>
#include <utility>
#include <iostream>
#include <QVector>

class ItemBase : private bsoncxx::builder::basic::document , public DBClass
{
public:
    explicit ItemBase(mongocxx::database* _db , const std::string &_collection );
    ItemBase(mongocxx::database* _db , const std::string &_collection , bsoncxx::document::value value );

    bsoncxx::document::view View() const;

    boost::optional<bsoncxx::document::element> Element( const std::string &key ) const;

    boost::optional<bsoncxx::document::element> operator[]( const std::string &key ) const;

    template<typename T>
    bool addElement( const std::string &key , const T &value ){
        return this->setElement(key,value);
    }

    bool deleteDocument();

    bool isValid() const;

private:

    bool mIsValid;

    bsoncxx::oid mOid;

    const std::string &collection;

    template<typename T>
    bool setElement( const std::string &key , const T& value )
    {
        bool succed = true;

        auto f = this->view().find(key);
        if( *f ){

            auto doc = document{};

            for( auto _f : this->view() )
            {
                if( key != _f.key() )
                {
                    try {
                        doc.append(kvp(_f.key(),_f.get_value()));
                    } catch (bsoncxx::exception &e) {
                        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                        succed = false;
                    }
                }
            }

            if( succed ){
                this->clear();

                for( auto _f : doc.view() )
                {
                    try {
                        append(kvp(_f.key(),_f.get_value()));
                    } catch (bsoncxx::exception &e) {
                        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                        succed = false;
                    }
                }

                try {
                    append(kvp(key,value));
                } catch (bsoncxx::exception &e) {
                    std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                    succed = false;
                }
            }


        }else{
            try {
                append(kvp(key,value));
            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                succed = false;
            }
        }

        if( succed )
        {
            auto filter = document{};

            try {
                filter.append(kvp("_id",mOid));
            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                succed = false;
            }

            auto setDoc = document{};

            try {
                setDoc.append(kvp("$set",this->extract()));
            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                succed = false;
            }


            if( succed ){
                try {
                    auto upt = this->db()->collection(collection).update_one(filter.view(),setDoc.view());
                    if( upt )
                    {
                        if( upt.value().modified_count() )
                        {

                        }else{
                            succed = false;
                        }
                    }else{
                        succed = false;
                    }
                } catch (mongocxx::exception &e) {
                    std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
                    succed = false;
                }
            }

        }
        return succed;
    }
};

#endif // ITEMBASE_H
