#include "tcitem.h"



boost::optional<TC::TCItem> TC::TCItem::Create_TC(mongocxx::database *_db,
                                                  const std::string &tcno,
                                                  const std::string &telefon,
                                                  const std::string &adsoyad,
                                                  const std::string &adres,
                                                  const std::string &email)
{
    TCItem item(_db);

    if( !item.isValid() )
    {
        return boost::none;
    }




    if( !item.addElement(KEY::tcno,tcno) ){
        item.deleteDocument();
        return boost::none;
    }

    if( !item.addElement(KEY::email,email) ){
        item.deleteDocument();
        return boost::none;
    }

    if( !item.addElement(KEY::telefon,telefon) ){
        item.deleteDocument();
        return boost::none;
    }

    if( !item.addElement(KEY::adsoyad,adsoyad) ){
        item.deleteDocument();
        return boost::none;
    }

    if( !item.addElement(KEY::adress,adres) ){
        item.deleteDocument();
        return boost::none;
    }

    return std::move(item);

}

QVector<TC::TCItem*> TC::TCItem::GetList(mongocxx::database *_db, const bsoncxx::document::view &filter)
{
    QVector<TC::TCItem*> list;
    try {
        auto cursor = _db->collection(KEY::collection).find(filter);
        for( auto doc : cursor )
        {
            TCItem *item = new TCItem(_db,bsoncxx::document::value(doc));
            list.push_back(std::move(item));
        }
    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
    }
    return list;
}

TC::TCItem::TCItem(mongocxx::database *_db)
    :ItemBase(_db,KEY::collection)
{


}

TC::TCItem::TCItem(mongocxx::database *_db, bsoncxx::document::value value)
    :ItemBase(_db,KEY::collection,value)
{

}

