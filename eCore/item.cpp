#include "item.h"
#include <iostream>


eCore::Item::Item(const std::string &collection)
    :mDoc(document{}),mCollection(collection)
{
    mDoc.clear ();
}


eCore::Item::Item(const bsoncxx::document::view mView, const std::string &_Collection)
    :mCollection(_Collection)
{
    this->setDocumentView (mView);
}

eCore::Item::~Item()
{
    mDoc.clear ();
}

void eCore::Item::operator=(const bsoncxx::builder::basic::document &value)
{
    mDoc.clear ();

    for( auto item : value.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
}

void eCore::Item::operator=(const bsoncxx::document::view &view)
{
    mDoc.clear ();
    for( auto item : view )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
}


void eCore::Item::setDocumentView(const bsoncxx::document::view &view)
{
    mDoc.clear ();
    for( auto item : view )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
}

boost::optional<bsoncxx::types::value> eCore::Item::element(std::string key) const
{
    try {
        return mDoc.view ()[key].get_value ();
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() + " Key: " + key;
        std::cout << str << std::endl;
        return boost::none;
    }
}

bsoncxx::document::view eCore::Item::view() const
{
    return mDoc.view ();
}

boost::optional<bsoncxx::oid> eCore::Item::oid() const
{
    try {
        return this->view ()["_id"].get_oid ().value;
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        std::cout << str << std::endl;
        return boost::none;
    }
}

boost::optional<bsoncxx::builder::basic::document> eCore::Item::ItemFilter() const
{

    auto oid = this->oid ();

    if( oid )
    {
        auto doc = document{};

        try {
            doc.append (kvp("_id",oid.value ()));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            std::cout << str << std::endl;
            return boost::none;
        }
    }else{
        return boost::none;
    }

}


eCore::Item::Item(const Item &other) : mCollection(other.getCollection ())
{
    this->setDocumentView (other.view ());
}

eCore::Item::Item(Item &&other)
{
    this->setDocumentView (other.view ());

}

eCore::Item& eCore::Item::operator=(const Item &value)
{
    mDoc.clear ();

    for( auto item : value.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
    return *this;
}

eCore::Item &eCore::Item::operator=(Item &&other)
{
    mDoc.clear ();
    for( auto item : other.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
    return *this;
}

void eCore::Item::printView() const
{
    std::cout << this->getCollection () << " " <<bsoncxx::to_json (this->view ()) << std::endl;
}

void eCore::Item::clear()
{
    this->mDoc.clear ();
}

eCore::Item &eCore::Item::setOid(const std::string &oid)
{
    this->append("_id",bsoncxx::oid{oid});
    return *this;




}


std::string eCore::Item::getCollection() const
{
    return mCollection;
}

void eCore::Item::removeElement(const std::string &key)
{
    auto tempDoc = document{};

    for( auto item : mDoc.view () )
    {
        if( key != item.key ().to_string() )
        {
            try {
                tempDoc.append( kvp( item.key ().to_string() , item.get_value () ) );

            } catch (bsoncxx::exception &e) {
                std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
                std::cout << str << std::endl;
            }
        }
    }
    mDoc.clear ();

    for( auto item : tempDoc.view () )
    {
        mDoc.append(kvp(item.key ().to_string(),item.get_value ()));
    }

}

