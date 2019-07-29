#include "reservationwidget.h"

ReservationWidget::ReservationWidget(mongocxx::database *_db)
    :DBClass (_db)
{

    rContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    rContainer->setHeight(500);
    rContainer->setWidth(WLength("100%"));

    auto rezerveContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    rezerveContainer->setMargin(10,Side::Top);
    rezerveContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
    rezerveContainer->setAttributeValue(Style::style,Style::background::color::rgb("200,225,255"));
    rezerveContainer->setWidth(WLength("100%"));
    rezerveContainer->setHeight(WLength("100%"));

    auto layout = rezerveContainer->setLayout(cpp14::make_unique<WVBoxLayout>());


    auto text = layout->addWidget(cpp14::make_unique<WText>("Rezervasyon Alanı"),0,AlignmentFlag::Center|AlignmentFlag::Top);
//    text->setAttributeValue(Style::style,Style::color::rgb("255,255,255"));

    auto adsoyad = layout->addWidget(cpp14::make_unique<WLineEdit>(),0,AlignmentFlag::Justify|AlignmentFlag::Top);
    adsoyad->setPlaceholderText("İsim Soyisim Giriniz");

    auto tcnoLineEdit = layout->addWidget(cpp14::make_unique<WLineEdit>(),0,AlignmentFlag::Justify|AlignmentFlag::Top);
    tcnoLineEdit->setPlaceholderText("Telefon Numarası Giriniz");

    auto ilComboBox = layout->addWidget(cpp14::make_unique<WComboBox>());
    ilComboBox->addItem(WString("Antalya"));
    ilComboBox->addItem(WString("Muğla"));

    auto ilceComboBox = layout->addWidget(cpp14::make_unique<WComboBox>());
    ilceComboBox->addItem(WString("Serik(Belek)"));
    ilceComboBox->addItem(WString("Kaş"));
    ilceComboBox->addItem(WString("Kemer"));
    ilceComboBox->addItem(WString("Manavgat(Side)"));
    ilceComboBox->addItem(WString("Manavgat(Çolaklı)"));
    ilceComboBox->addItem(WString("Alanya(Polatlı)"));
    ilceComboBox->addItem(WString("Fethiye(Ölü Deniz)"));
    ilceComboBox->addItem(WString("Ula(Akyaka)"));
    ilceComboBox->addItem(WString("Marmaris"));

//    auto villaComboBox = layout->addWidget(cpp14::make_unique<WComboBox>());

//    for( int i = 0 ; i < 10 ; i++ )
//    {
//        villaComboBox->addItem(WString("Villa {1}").arg(i));
//    }


    Wt::WCalendar *c1 = layout->addWidget(Wt::cpp14::make_unique<Wt::WCalendar>(),0,AlignmentFlag::Center);


    auto mSaveBtn = layout->addWidget(cpp14::make_unique<WPushButton>("Rezervasyonu Kaydet"));
    mSaveBtn->addStyleClass(Bootstrap::Button::Primary);


    layout->addStretch(1);
}
