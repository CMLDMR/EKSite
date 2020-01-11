#include "villamanager.h"
#include "eWidget/evillawidget.h"
VillaManager::VillaManager(DB *_db , const bool& _adminPage)
    :eCore::ListItem<VillaItem> (_db),
      ContainerWidget ("Villalar"),
      mAdminPage(_adminPage)
{
    setContentAlignment (AlignmentFlag::Center);
    Content ()->setMaximumSize (1024,WLength::Auto);
}

void VillaManager::onList(const QVector<VillaItem> *mlist)
{
    if( this->mAdminPage )
    {
        this->initAdminList (mlist);
    }else{
        this->initPublicList (mlist);
    }
}

void VillaManager::errorOccured(const std::string &errorText)
{
    this->showPopUpMessage (errorText,"hata");
}

void VillaManager::initAdminList( const QVector<VillaItem> *mlist )
{
    Content ()->clear ();
    for( auto item : *mlist )
    {
        auto container = Content ()->addWidget (cpp14::make_unique<eWidget::eVillaWidget>(item));
        container->addStyleClass (Bootstrap::Grid::Large::col_lg_3+
                                  Bootstrap::Grid::Medium::col_md_3+
                                  Bootstrap::Grid::Small::col_sm_4+
                                  Bootstrap::Grid::ExtraSmall::col_xs_6);

        container->ClickedVilla ().connect ([=]( const bsoncxx::oid& oid ){

            std::cout << oid.to_string () << std::endl;
        });
    }
}

void VillaManager::initPublicList( const QVector<VillaItem> *mlist )
{
    Content ()->clear ();
    for( auto item : *mlist )
    {
        auto container = Content ()->addWidget (cpp14::make_unique<eWidget::eVillaThumpWidget>(item,this->getDB ()));
        container->addStyleClass (Bootstrap::Grid::col_full_12);
        container->addStyleClass (Bootstrap::Grid::Large::col_lg_3+
                                  Bootstrap::Grid::Medium::col_md_3+
                                  Bootstrap::Grid::Small::col_sm_4+
                                  Bootstrap::Grid::ExtraSmall::col_xs_6);
        container->ClickedVilla ().connect ([=]( const bsoncxx::oid& oid ){

            std::cout << oid.to_string ()<< std::endl;
        });
    }
}
