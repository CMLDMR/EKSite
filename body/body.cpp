#include "body.h"
#include "admin/admin.h"
Body::Body(DB *_db)
    :ContainerWidget ("ERKSite Real Estate"),eCore::DB (_db)
{



    auto girisText = this->Footer ()->addWidget (cpp14::make_unique<WText>("Giriş"));
    girisText->addStyleClass (Bootstrap::Grid::col_full_12);


    girisText->clicked ().connect ([=](){
        Content ()->clear ();
        auto adminPage = Content ()->addWidget (cpp14::make_unique<Admin>(this->getDB ()));
        adminPage->addStyleClass (Bootstrap::Grid::col_full_12);
    });

}
