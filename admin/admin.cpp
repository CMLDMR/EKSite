#include "admin.h"

#include "yenivilla.h"

Admin::Admin(eCore::DB* _db)
    :eCore::DB (_db),
      ContainerWidget ("Admin")
{

    auto ekle = Header ()->addWidget (cpp14::make_unique<WPushButton>("Yeni Villa Ekle"));

    ekle->clicked ().connect ([=](){
        Content ()->clear ();
        Content ()->addWidget (cpp14::make_unique<YeniVilla>());
    });

}
