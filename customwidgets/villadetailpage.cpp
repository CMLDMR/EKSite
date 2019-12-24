#include "villadetailpage.h"
#include "base/villaitem.h"

#include "rezervationdialog.h"
#include <QDate>


VillaDetailPage::VillaDetailPage(mongocxx::database *_db, const std::string &_villaOid)
    :DBClass (_db)
{
    mVillaCollection = this->db()->collection("villa");
    mVillaItem = VillaItem::Load_Villa(&mVillaCollection,bsoncxx::oid{_villaOid});

    setPadding(50,Side::Top);

    setAttributeValue(Style::style,Style::background::url(this->downloadFile(mVillaItem->villaImgOidList().first()))+
                      Style::background::size::cover+
                      Style::background::repeat::norepeat);
    setContentAlignment(AlignmentFlag::Center);

    auto container = addWidget(cpp14::make_unique<ContainerWidget>());
    container->setRandomBackGroundColor(200,225,0.90);
    container->setWidth(WLength("100%"));
    container->addStyleClass(Bootstrap::Grid::row);
    container->setMaximumSize(1024,WLength::Auto);
    container->setPadding(15,Side::Top);

    {
        auto titleContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
        titleContainer->addStyleClass(Bootstrap::Grid::col_full_12);
        titleContainer->setContentAlignment(AlignmentFlag::Center);
        titleContainer->addWidget(cpp14::make_unique<WText>("<h3>"+mVillaItem->villaName()+"</h3>"));
    }


    // FOTO Container
    {
        auto fotoContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
        fotoContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_9+Bootstrap::ImageShape::img_thumbnail);
        fotoContainer->setRandomBackGroundColor(240,255,0.90);

        auto contentContainer = fotoContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        contentContainer->addStyleClass(Bootstrap::Grid::row);
        for( auto item : mVillaItem->villaImgOidList() )
        {

            auto fotourl = this->downloadFile(item);
            auto fContainer = contentContainer->addWidget(cpp14::make_unique<ContainerWidget>());
            fContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
            fContainer->setHeight(150);
            auto _fContainer = fContainer->addWidget(cpp14::make_unique<ContainerWidget>());

            _fContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
            _fContainer->setAttributeValue(Style::style,Style::background::url(fotourl)+
                                           Style::background::size::cover+
                                           Style::background::repeat::norepeat+
                                           Style::background::position::center_center);
            _fContainer->setWidth(WLength("100%"));
            _fContainer->setHeight(WLength("100%"));

            _fContainer->clicked().connect([=](){
                auto ff = wApp->instance()->root()->addWidget(cpp14::make_unique<ContainerWidget>());
                ff->setPositionScheme(PositionScheme::Fixed);
                ff->setOffsets(0,Side::Top|Side::Left);
                ff->setZIndex(1000);
                ff->setWidth(WLength("100%"));
                ff->setHeight(WLength("100%"));
                ff->setAttributeValue(Style::dataoid,item);
                ff->setRandomBackGroundColor(25,35,0.8);

                {
                    auto cContainer = ff->addWidget(cpp14::make_unique<ContainerWidget>());
                    cContainer->setWidth(WLength("100%"));
                    cContainer->setHeight(WLength("90%"));
                    cContainer->setPositionScheme(PositionScheme::Relative);
                    cContainer->setAttributeValue(Style::style,Style::background::url(fotourl)+
                                                   Style::background::size::contain+
                                                   Style::background::repeat::norepeat+
                                                   Style::background::position::center_center);

                }

                {
                    auto cContainer = ff->addWidget(cpp14::make_unique<ContainerWidget>());
                    cContainer->setWidth(WLength("100%"));
                    cContainer->setHeight(WLength("10%"));
                    cContainer->setPositionScheme(PositionScheme::Relative);
                    cContainer->setRandomBackGroundColor(20,25,0.75);
                    auto KapatBtn = cContainer->addWidget(cpp14::make_unique<WPushButton>("Kapat"));
                    KapatBtn->addStyleClass(Bootstrap::Button::Primary);
                    KapatBtn->setWidth(200);
                    KapatBtn->clicked().connect([=](){
                        wApp->instance()->root()->removeWidget(ff);
                    });

                }




                ff->clicked().connect([=](){

                    auto index = mVillaItem->villaImgOidList().indexOf(ff->attributeValue(Style::dataoid).toUTF8());
                    index++;

                    index = index % mVillaItem->villaImgOidList().count();
                    auto _furl = mVillaItem->villaImgOidList().at(index);

                    ff->setAttributeValue(Style::dataoid,_furl);

                    ff->clear();

                    auto _fotourl = this->downloadFile(_furl);

                    {
                        auto cContainer = ff->addWidget(cpp14::make_unique<ContainerWidget>());
                        cContainer->setWidth(WLength("100%"));
                        cContainer->setHeight(WLength("90%"));
                        cContainer->setPositionScheme(PositionScheme::Relative);
                        cContainer->setAttributeValue(Style::style,Style::background::url(_fotourl)+
                                                       Style::background::size::contain+
                                                       Style::background::repeat::norepeat+
                                                       Style::background::position::center_center);

                    }

                    {
                        auto cContainer = ff->addWidget(cpp14::make_unique<ContainerWidget>());
                        cContainer->setWidth(WLength("100%"));
                        cContainer->setHeight(WLength("10%"));
                        cContainer->setPositionScheme(PositionScheme::Relative);
                        cContainer->setRandomBackGroundColor(20,25,0.75);
                        auto KapatBtn = cContainer->addWidget(cpp14::make_unique<WPushButton>("Kapat"));
                        KapatBtn->setWidth(200);
                        KapatBtn->addStyleClass(Bootstrap::Button::Primary);
                        KapatBtn->clicked().connect([=](){
                            wApp->instance()->root()->removeWidget(ff);
                        });
                    }

                });
            });

        }
    }

    // Content Container
    {
        auto fotoContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
        fotoContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3);

        auto contentContainer = fotoContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        contentContainer->addStyleClass(Bootstrap::Grid::row);
        contentContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);

        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::col_full_12);
            sContainer->addWidget(cpp14::make_unique<WText>(WString("<h3>Günlük {1}₺</h3><h6>'den Başlayan Fiyatlarla</h6>").arg(mVillaItem->villaAcilisFiyat())));
        }

        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                      Bootstrap::Grid::Medium::col_md_6+
                                      Bootstrap::Grid::Small::col_sm_6+
                                      Bootstrap::Grid::ExtraSmall::col_xs_6);
            sContainer->addWidget(cpp14::make_unique<WText>(WString("<h5>{1}</h5>").arg(mVillaItem->villaIl())));
        }
        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                      Bootstrap::Grid::Medium::col_md_6+
                                      Bootstrap::Grid::Small::col_sm_6+
                                      Bootstrap::Grid::ExtraSmall::col_xs_6);
            sContainer->addWidget(cpp14::make_unique<WText>(WString("<h5>{1}</h5>").arg(mVillaItem->villaIlce())));
        }

        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::col_full_12);
            sContainer->addWidget(cpp14::make_unique<WText>(WString("<h5>{1}</h5>").arg(mVillaItem->villaKonum())));
        }

        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                      Bootstrap::Grid::Medium::col_md_6+
                                      Bootstrap::Grid::Small::col_sm_6+
                                      Bootstrap::Grid::ExtraSmall::col_xs_6);
            sContainer->addWidget(cpp14::make_unique<WText>(WString("<h5>{1} Kişi</h5>").arg(mVillaItem->villaKisiAdet())));
        }

        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                      Bootstrap::Grid::Medium::col_md_6+
                                      Bootstrap::Grid::Small::col_sm_6+
                                      Bootstrap::Grid::ExtraSmall::col_xs_6);
            sContainer->addWidget(cpp14::make_unique<WText>(WString("<h5>{1}</h5>").arg(mVillaItem->villaHavuz())));
        }

        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::col_full_12);
            auto title = sContainer->addWidget(cpp14::make_unique<WPushButton>("Reservasyon Yap"));
            title->addStyleClass(Bootstrap::Button::Primary);
        }

    }


    // Açıklama Alanı
    {
        auto fotoContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
        fotoContainer->addStyleClass(Bootstrap::Grid::col_full_12);

        auto contentContainer = fotoContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        contentContainer->addStyleClass(Bootstrap::Grid::row);
        contentContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        contentContainer->setWidth(WLength("100%"));
        contentContainer->setMargin(20,Side::Top);


        {
            auto titleContainer = contentContainer->addWidget(cpp14::make_unique<ContainerWidget>());
            titleContainer->addStyleClass(Bootstrap::Grid::col_full_12);
            titleContainer->setRandomBackGroundColor(20,25,0.5);
            auto text = titleContainer->addWidget(cpp14::make_unique<WText>("<h4>Villa Hakkında</h4>"));
            text->setAttributeValue(Style::style,Style::color::color(Style::color::White::Snow));

        }

        {
            auto titleContainer = contentContainer->addWidget(cpp14::make_unique<ContainerWidget>());
            titleContainer->addStyleClass(Bootstrap::Grid::col_full_12);
            titleContainer->setOverflow(Overflow::Hidden);
            contentContainer->addWidget(cpp14::make_unique<WText>(mVillaItem->villaAciklama(),TextFormat::UnsafeXHTML));
        }

    }



    // Reservasyon Takvimi
    {
        auto fotoContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
        fotoContainer->addStyleClass(Bootstrap::Grid::col_full_12);

        auto contentContainer = fotoContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        contentContainer->addStyleClass(Bootstrap::Grid::row);
        contentContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        contentContainer->setWidth(WLength("100%"));
        contentContainer->setMargin(20,Side::Top);

        {
            auto titleContainer = contentContainer->addWidget(cpp14::make_unique<ContainerWidget>());
            titleContainer->addStyleClass(Bootstrap::Grid::col_full_12);
            auto text = titleContainer->addWidget(cpp14::make_unique<WText>(WString("<h4>Reservasyon Takvimi {1}</h4>").arg(QDate::currentDate().year())));
            text->setAttributeValue(Style::style,Style::color::color(Style::color::White::Snow));
            titleContainer->addStyleClass(Bootstrap::ContextualBackGround::bg_primary);
            titleContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        }

        {
            auto titleContainer = contentContainer->addWidget(cpp14::make_unique<ContainerWidget>());
            titleContainer->addStyleClass(Bootstrap::Grid::col_full_12);
            titleContainer->setOverflow(Overflow::Hidden);
            titleContainer->setContentAlignment(AlignmentFlag::Left);


            auto res_Container = titleContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            res_Container->setWidth(WLength("100%"));
            res_Container->setMargin(25,Side::Top|Side::Bottom);
            res_Container->setContentAlignment(AlignmentFlag::Center);
            res_Container->addStyleClass(Bootstrap::Grid::row);
            res_Container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
            res_Container->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(100),this->getRandom(100),this->getRandom(100)));

            {
                auto container = res_Container->addWidget(cpp14::make_unique<WContainerWidget>());
                container->addStyleClass(Bootstrap::Grid::col_full_12);
                container->setContentAlignment(AlignmentFlag::Center);
                container->addStyleClass(Bootstrap::ContextualBackGround::bg_primary);
                container->addWidget(cpp14::make_unique<WText>("Rezervasyon Yap"));
            }


            auto _container = res_Container->addWidget(cpp14::make_unique<WContainerWidget>());
            _container->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
            _container->setHeight(WLength("100%"));
            auto layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto dateEditGiris = layout->addWidget(cpp14::make_unique<WDateEdit>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            dateEditGiris->setPlaceholderText("Giriş Tarihi Seçiniz");


            auto __container = res_Container->addWidget(cpp14::make_unique<WContainerWidget>());
            __container->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
            __container->setHeight(WLength("100%"));
            auto layout_ = __container->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto dateEditCikis = layout_->addWidget(cpp14::make_unique<WDateEdit>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            dateEditCikis->setPlaceholderText("Çıkış Tarihi Seçiniz");




            auto ___container = res_Container->addWidget(cpp14::make_unique<WContainerWidget>());
            ___container->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
            ___container->setHeight(WLength("100%"));
            auto layout__ = ___container->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto kisiSayisiCombo = layout__->addWidget(cpp14::make_unique<WComboBox>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);

            for( int i = 1 ; i <= mVillaItem->villaKisiAdet() ; i++ )
            {
                kisiSayisiCombo->addItem(WString("{1} Kişi").arg(i));
            }


            auto ____container = res_Container->addWidget(cpp14::make_unique<WContainerWidget>());
            ____container->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
            ____container->setHeight(WLength("100%"));
            auto layout___ = ____container->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto rzBtn = layout___->addWidget(cpp14::make_unique<WPushButton>("Rezerve Yap"),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            rzBtn->addStyleClass(Bootstrap::Button::Primary);
            rzBtn->clicked().connect([=](){
                auto rezerveDialog = wApp->instance()->root()->addChild(cpp14::make_unique<RezervationDialog>(this->db()));
                rezerveDialog->setEndJulianDate(dateEditCikis->date().toJulianDay());
                rezerveDialog->setBeginJulianDate(dateEditGiris->date().toJulianDay());
                rezerveDialog->setKisiSayisi(kisiSayisiCombo->currentIndex()+1);
                rezerveDialog->show();
            });

            auto ay_Container = titleContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            ay_Container->setWidth(WLength("100%"));
            ay_Container->setMargin(15,Side::Top);

            {
                auto container = ay_Container->addWidget(cpp14::make_unique<WContainerWidget>());
                container->addStyleClass(Bootstrap::Grid::container_fluid);
                container->setWidth(WLength("100%"));

                auto _dContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
                _dContainer->setMargin( 2 , Side::Left );
                _dContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                _dContainer->setWidth( WLength("1%") );
                _dContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::Green::Teal));
                _dContainer->addWidget(cpp14::make_unique<WText>(" "));
                container->addWidget(cpp14::make_unique<WText>("Rezerve Edilebilir"));

            }

            {
                auto container = ay_Container->addWidget(cpp14::make_unique<WContainerWidget>());
                container->addStyleClass(Bootstrap::Grid::container_fluid);
                container->setWidth(WLength("100%"));

                auto _dContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
                _dContainer->setMargin( 2 , Side::Left );
                _dContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                _dContainer->setWidth( WLength("1%") );
                _dContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::Red::Salmon));
                _dContainer->addWidget(cpp14::make_unique<WText>(" "));
                container->addWidget(cpp14::make_unique<WText>("Rezerve Edilemez"));

            }



            for( auto ay = 1 ; ay <= 12 ; ay++ )
            {
                if( QDate::currentDate().month() <= ay )
                {
                    auto ayContainer = ay_Container->addWidget(cpp14::make_unique<WContainerWidget>());
                    ayContainer->setWidth(WLength("100%"));
                    ayContainer->setMargin(15,Side::Top);

                    QDate date(QDate::currentDate().year(),ay,1);

                    {
                        auto _dContainer = ayContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                        _dContainer->setMargin( 2 , Side::Left );
                        _dContainer->addStyleClass(Bootstrap::ContextualBackGround::bg_info);
                        _dContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                        _dContainer->setWidth( WLength("6%") );
                        _dContainer->setMinimumSize(57,WLength::Auto);
                        auto text = _dContainer->addWidget(cpp14::make_unique<WText>(WString("{1}").arg(date.toString("MMMM").toStdString())));
                        text->setAttributeValue(Style::style,Style::color::color(Style::color::Grey::DarkSlateGray));
                    }

                    for( auto day = 1 ; day <= date.daysInMonth() ; day++ )
                    {
                        auto _dContainer = ayContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                        _dContainer->setContentAlignment(AlignmentFlag::Center);
                        _dContainer->setMargin(2,Side::Left);
                        _dContainer->addStyleClass(Bootstrap::ContextualBackGround::bg_primary);
                        _dContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                        _dContainer->setWidth( WLength("2.80%") );
                        _dContainer->setMinimumSize(25,WLength::Auto);
                        auto text = _dContainer->addWidget(cpp14::make_unique<WText>(WString("{1}").arg(day)));
                        text->setAttributeValue(Style::style,Style::color::color(Style::color::White::Snow));
                        if( QDate::currentDate().toJulianDay() > QDate(QDate::currentDate().year(),ay,day).toJulianDay() )
                        {
                            _dContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::Red::Salmon));
                        }else{
                            _dContainer->setAttributeValue(Style::style,Style::background::color::color(Style::color::Green::Teal));
                        }
                    }
                }

            }



        }
    }
}
