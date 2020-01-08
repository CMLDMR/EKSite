#include "admin.h"

#include "yenivilla.h"

Admin::Admin(eCore::DB* _db)
    :eCore::DB (_db),
      ContainerWidget ("Admin")
{

    auto ekle = Header ()->addWidget (cpp14::make_unique<WPushButton>("Yeni Villa Ekle"));

    ekle->clicked ().connect ([=](){
        Header ()->clear ();
        Content ()->clear ();
        auto yeniVillaWidget = Content ()->addWidget (cpp14::make_unique<YeniVilla>(this->getDB ()));
        yeniVillaWidget->ClickBack ().connect (this,&Admin::initVillalar);
    });

    this->initVillalar ();

}

void Admin::initVillalar()
{
    Content ()->clear ();
    auto villalarWidget = Content ()->addWidget (cpp14::make_unique<VillaManager>(this->getDB (),true));
    villalarWidget->UpdateList (VillaItem(),100,0);
}
