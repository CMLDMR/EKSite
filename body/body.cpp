#include "body.h"
#include "admin/admin.h"
Body::Body(DB *_db)
    :ContainerWidget ("Villacım ( Saturday Night )"),eCore::DB (_db)
{
    auto villaManagerPage = this->Content ()->addWidget (cpp14::make_unique<VillaManager>(this->getDB ()));
    villaManagerPage->UpdateList ();
    this->initFooter ();
}

void Body::initFooter()
{

    Footer ()->setMargin (50,Side::Top);
    Footer ()->setHeight (100);
    auto footerPanel = Footer ()->addWidget (cpp14::make_unique<WContainerWidget>());
    footerPanel->addStyleClass (Bootstrap::Grid::col_full_12);
    footerPanel->setAttributeValue (Style::style,Style::background::color::color (Style::color::Grey::LightSlateGray));
    footerPanel->addWidget (cpp14::make_unique<WText>("<b>copyRight 2020 (c)</b>",TextFormat::UnsafeXHTML));

    footerPanel->addWidget (cpp14::make_unique<WBreak>());

    auto girisText = footerPanel->addWidget (cpp14::make_unique<WText>("...",TextFormat::UnsafeXHTML));


    girisText->clicked ().connect ([=](){

        auto mDialog = this->createDialog ("Giriş");

        auto vLayout = mDialog->contents ()->setLayout (cpp14::make_unique<WVBoxLayout>());

        auto kullaniciAdilineEdit = vLayout->addWidget (cpp14::make_unique<WLineEdit>());
        kullaniciAdilineEdit->setPlaceholderText ("Kullanıcı Adını Giriniz");

        auto sifrenizilineEdit = vLayout->addWidget (cpp14::make_unique<WLineEdit>());
        sifrenizilineEdit->setPlaceholderText ("Şifrenizi Giriniz");
        sifrenizilineEdit->setEchoMode (EchoMode::Password);

        auto grsBtn = vLayout->addWidget (cpp14::make_unique<WPushButton>("Giriş"));
        grsBtn->addStyleClass (Bootstrap::Button::Primary);

        grsBtn->clicked ().connect ([=](){

            this->remogeDialog (mDialog);

            this->Footer ()->clear ();
            Content ()->clear ();
            auto adminPage = Content ()->addWidget (cpp14::make_unique<Admin>(this->getDB ()));
            adminPage->addStyleClass (Bootstrap::Grid::col_full_12);

        });



    });

}
