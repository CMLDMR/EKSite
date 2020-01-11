#include "evillapage.h"


eWidget::eVillaPage::eVillaPage(const VillaItem &villaItem, eCore::DB *_db, const bool &initPublicLink )
    :VillaItem (villaItem),mDB(_db),ContainerWidget (villaItem.adi ())
{
    if( initPublicLink )
    {
        this->initPublic ();
    }else{
        this->initAdmin ();
    }
}

void eWidget::eVillaPage::initPublic()
{
    Header ()->clear ();
    {
        auto iconContainer = Header()->addWidget (cpp14::make_unique<ContainerWidget>());
        auto iconPath = mDB->downloadFileWeb (this->fotoOid ().c_str ());
        iconContainer->setBackGroundImg (iconPath);
        iconContainer->addStyleClass ("boxShadow boxRadius");
        iconContainer->setHeight (350);
    }



    Content ()->clear ();
    Content ()->addStyleClass ("boxShadow boxRadius");
    Content ()->setMargin (30,Side::Top);

    auto kisiContainer = Content ()->addWidget (cpp14::make_unique<WContainerWidget>());
    kisiContainer->addStyleClass (Bootstrap::Grid::Large::col_lg_2+
                                  Bootstrap::Grid::Medium::col_md_3+
                                  Bootstrap::Grid::Small::col_sm_4+
                                  Bootstrap::Grid::ExtraSmall::col_xs_6);
    kisiContainer->setContentAlignment (AlignmentFlag::Center);
    kisiContainer->addWidget (cpp14::make_unique<WText>("<b>Kişi</b> <i>"+std::to_string (this->kisiSayisi ())+"</i>"));
    kisiContainer->setMargin (15,Side::Top|Side::Bottom);


    auto havuzContainer = Content ()->addWidget (cpp14::make_unique<WContainerWidget>());
    havuzContainer->addStyleClass (Bootstrap::Grid::Large::col_lg_3+
                                   Bootstrap::Grid::Medium::col_md_3+
                                   Bootstrap::Grid::Small::col_sm_4+
                                   Bootstrap::Grid::ExtraSmall::col_xs_6);
    havuzContainer->setContentAlignment (AlignmentFlag::Center);
    havuzContainer->addWidget (cpp14::make_unique<WText>("<b>"+this->havuz ()+"</b>"));
    havuzContainer->setMargin (15,Side::Top|Side::Bottom);



    auto yerContainer = Content ()->addWidget (cpp14::make_unique<WContainerWidget>());
    yerContainer->addStyleClass (Bootstrap::Grid::Large::col_lg_3+
                                   Bootstrap::Grid::Medium::col_md_3+
                                   Bootstrap::Grid::Small::col_sm_4+
                                   Bootstrap::Grid::ExtraSmall::col_xs_6);
    yerContainer->setContentAlignment (AlignmentFlag::Center);
    yerContainer->addWidget (cpp14::make_unique<WText>("<b>"+this->yeri ()+"</b>"));
    yerContainer->setMargin (15,Side::Top|Side::Bottom);


    auto tanimContainer = Content ()->addWidget (cpp14::make_unique<WContainerWidget>());
    tanimContainer->addStyleClass (Bootstrap::Grid::col_full_12);
    tanimContainer->setContentAlignment (AlignmentFlag::Center);
    tanimContainer->addWidget (cpp14::make_unique<WText>("<b>"+this->tanim ()+"</b>",TextFormat::UnsafeXHTML));
    tanimContainer->setMargin (15,Side::Top|Side::Bottom);


    Footer ()->clear ();
    Footer ()->setMargin (30,Side::Top);
    Footer ()->addStyleClass ("boxShadow boxRadius");

    for( auto item : this->fotoList () )
    {
        auto iconPath = this->mDB->downloadFileWeb (item.to_string ().c_str ());
        auto iconContainer = Footer ()->addWidget (cpp14::make_unique<ContainerWidget>());
        iconContainer->addStyleClass (Bootstrap::Grid::Large::col_lg_3+
                                      Bootstrap::Grid::Medium::col_md_3+
                                      Bootstrap::Grid::Small::col_sm_4+
                                      Bootstrap::Grid::ExtraSmall::col_xs_6);
        iconContainer->setBackGroundImg (iconPath);
        iconContainer->setHeight (150);
        iconContainer->addStyleClass (Bootstrap::ImageShape::img_thumbnail);

        iconContainer->decorationStyle ().setCursor (Cursor::PointingHand);
        iconContainer->clicked ().connect ([=](){

            auto bigImage = wApp->root ()->addWidget (cpp14::make_unique<ContainerWidget>(this->adi ()));
            bigImage->setPositionScheme (PositionScheme::Fixed);
            bigImage->setWidth (WLength("100%"));
            bigImage->setHeight (WLength("100%"));
            bigImage->setBackGroundImg (iconPath);
            bigImage->setZIndex (10000);
            bigImage->setOffsets (0,Side::Top|Side::Left);
            bigImage->clicked ().connect ([=](){
                wApp->root ()->removeWidget(bigImage);
            });
        });
    }




}

void eWidget::eVillaPage::initAdmin()
{

}

void eWidget::eVillaPage::errorOccured(const std::string &errorText)
{

}
