#ifndef ITEM_H
#define ITEM_H


#include <iostream>
#include <QString>
#include <QVector>
#include <QtGlobal>
#include "db.h"

#include "mongoheaders.h"
#include <boost/optional.hpp>




namespace eCore {


class Item
{
public:
    explicit Item(const std::string &collection);
    Item(const Item& other);
    Item( Item &&other );
    virtual ~Item();

    Item& operator=(const Item &value);
    Item& operator=( Item &&other );

    virtual void errorOccured(const std::string& errorText ) ;

    Item(const bsoncxx::document::view mView , const std::string &_Collection);
    Item& operator=(const document &value);
    Item& operator=(const bsoncxx::document::view &view);
    eCore::Item& setDocumentView( const bsoncxx::document::view &view);
    bsoncxx::document::view view() const;
    boost::optional<bsoncxx::types::value> element(std::string key) const;
    boost::optional<bsoncxx::oid> oid() const;

    boost::optional<bsoncxx::types::value> element(std::string key);
    boost::optional<bsoncxx::oid> oid();

    boost::optional<document> ItemFilter();

    void printView() const;

    void clear();

    Item& setOid( const std::string &oid );

    std::string getCollection() const;

    void removeElement( const std::string &key );

    template<typename T>
    void pushArray(std::string key ,const T &value){

        auto arr = array{};

        auto existArray = this->element (key);

        if( existArray )
        {
            this->removeElement ( key );

            for( auto item : existArray.value ().get_array ().value )
            {
                try {
                    arr.append (item.get_value ());
                } catch (bsoncxx::exception &e) {
                    std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                    errorOccured (str);
                }
            }
        }

        try {
            arr.append (value);
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }

        try {
            mDoc.append (kvp(key,arr));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }
    }


    void pullArray( const std::string& key , const bsoncxx::types::value &value )
    {
        auto arr = array{};
        auto existArray = this->element (key);
        if( existArray )
        {
            this->removeElement ( key );
            for( auto item : existArray.value ().get_array ().value )
            {
                if( value != item.get_value ())
                {
                    try {
                        arr.append (item.get_value ());
                    } catch (bsoncxx::exception &e) {
                        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                        errorOccured (str);
                    }
                }
            }
        }
        try {
            mDoc.append (kvp(key,arr));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }
    }

    template<typename T>
    Item& append( const std::string &key ,const T &value ){
        this->removeElement (key);
        try {
            mDoc.append (kvp(key,value));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }
        return *this;
    }


    template<>
    Item& append( const std::string &key ,const Item &value ){
        this->removeElement (key);
        try {
            mDoc.append (kvp(key,value.view ()));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
        }
        return *this;
    }



private:
    document mDoc;
    const std::string mCollection;
};




class FindOptions : public Item
{
public:
    explicit FindOptions();


    FindOptions& setLimit( const int &limit );
    FindOptions& setSkip( const int &skip );

    FindOptions& setSort( const Item& sortItem);
    FindOptions& setProjection( const Item& projItem);

    int limit() const;
    int skip() const;

    Item sort() const;
    Item projection() const;


};


}


#endif // ITEM_H
