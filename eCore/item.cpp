#include "item.h"


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

eCore::Item& eCore::Item::operator=(const bsoncxx::builder::basic::document &value)
{
    mDoc.clear ();

    for( auto item : value.view () )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
    return *this;
}

eCore::Item& eCore::Item::operator=(const bsoncxx::document::view &view)
{
    mDoc.clear ();
    for( auto item : view )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
    return *this;
}


eCore::Item& eCore::Item::setDocumentView(const bsoncxx::document::view &view)
{
    mDoc.clear ();
    for( auto item : view )
    {
        this->append(item.key ().to_string().c_str (),item.get_value ());
    }
    return *this;
}

boost::optional<bsoncxx::types::value> eCore::Item::element(std::string key) const
{
    try {
        return mDoc.view ()[key].get_value ();
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() + " Key: " + key;
        const_cast<eCore::Item*>(this)->errorOccured (str);
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
        const_cast<eCore::Item*>(this)->errorOccured (str);
        return boost::none;
    }
}

boost::optional<bsoncxx::types::value> eCore::Item::element(std::string key)
{
    try {
        return mDoc.view ()[key].get_value ();
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what() + " Key: " + key;
        errorOccured (str);
        return boost::none;
    }
}

boost::optional<bsoncxx::oid> eCore::Item::oid()
{
    try {
        return this->view ()["_id"].get_oid ().value;
    } catch (bsoncxx::exception &e) {
        std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
        errorOccured (str);
        return boost::none;
    }
}

boost::optional<bsoncxx::builder::basic::document> eCore::Item::ItemFilter()
{

    auto oid = this->oid ();

    if( oid )
    {
        auto doc = document{};

        try {
            doc.append (kvp("_id",oid.value ()));
        } catch (bsoncxx::exception &e) {
            std::string str = "ERROR: " + std::to_string(__LINE__) + " " + __FUNCTION__ + " " + e.what();
            errorOccured (str);
            return boost::none;
        }
        return std::move(doc);
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

void eCore::Item::errorOccured(const std::string &errorText)
{

}

void eCore::Item::printView() const
{
    std::cout << __LINE__ << " " << __FUNCTION__ << " Coll: " <<this->getCollection () << " : " <<bsoncxx::to_json (this->view ()) << std::endl;
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
                errorOccured (str);
            }
        }
    }
    mDoc.clear ();

    for( auto item : tempDoc.view () )
    {
        mDoc.append(kvp(item.key ().to_string(),item.get_value ()));
    }

}




eCore::FindOptions::FindOptions()
    :Item("none")
{

}



eCore::FindOptions &eCore::FindOptions::setLimit(const int &limit)
{
    this->append("limit",bsoncxx::types::b_int64{limit});
    return *this;
}






eCore::FindOptions &eCore::FindOptions::setSkip(const int &skip)
{
    this->append("skip",bsoncxx::types::b_int64{skip});
    return *this;
}






eCore::FindOptions &eCore::FindOptions::setProjection(const eCore::Item &projItem)
{
    this->append("projection",projItem);
    return *this;
}






eCore::FindOptions &eCore::FindOptions::setSort(const eCore::Item &sortItem)
{
    this->append("sort",sortItem);
    return *this;
}






int eCore::FindOptions::limit() const
{
    auto val = this->element ("limit");

    if( val )
    {
        return static_cast<int>(val.value ().get_int64 ().value);
    }else{
        return 20;
    }
}





int eCore::FindOptions::skip() const
{
    auto val = this->element ("skip");

    if( val )
    {
        return static_cast<int>(val.value ().get_int64 ().value);
    }else{
        return 0;
    }
}






eCore::Item eCore::FindOptions::sort() const
{
    auto val = this->element ("sort");
    if( val )
    {
        return eCore::Item(val.value ().get_document (),"none");
    }
    return eCore::Item("none");
}






eCore::Item eCore::FindOptions::projection() const
{    auto val = this->element ("projection");
     if( val )
     {
         eCore::Item item(val.value ().get_document ().value,"none");
         return item;
     }
     return eCore::Item("none");
}


