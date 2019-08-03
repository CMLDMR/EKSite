#include "villadetailpage.h"
#include "base/villaitem.h"





VillaDetailPage::VillaDetailPage(mongocxx::database *_db, const std::string &_villaOid)
    :DBClass (_db)
{
    mVillaCollection = this->db()->collection("villa");
    mVillaItem = VillaItem::Load_Villa(&mVillaCollection,bsoncxx::oid{_villaOid});

    setPadding(50,Side::Top);
    setRandomBackGroundColorRGB(0,20,185,95,240,255,0.85);

    setAttributeValue(Style::style,Style::background::url(this->downloadFile(mVillaItem->villaImgOidList().first()))+
                      Style::background::size::cover+
                      Style::background::repeat::norepeat);
    setContentAlignment(AlignmentFlag::Center);

    auto container = addWidget(cpp14::make_unique<ContainerWidget>());
    container->setRandomBackGroundColor(200,225,0.90);
    container->setWidth(WLength("100%"));
    container->setContainerType(ContainerType::ROW);
    container->setMaximumSize(1024,WLength::Auto);
    container->setPadding(15,Side::Top);

    {
        auto titleContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
        titleContainer->addStyleClass(Bootstrap::Grid::col_full_12);
        titleContainer->setContentAlignment(AlignmentFlag::Center);
        auto text = titleContainer->addWidget(cpp14::make_unique<WText>("<h3>"+mVillaItem->villaName()+"</h3>"));

    }


    // FOTO Container
    {
        auto fotoContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
        fotoContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_9+Bootstrap::ImageShape::img_thumbnail);
        fotoContainer->setRandomBackGroundColor(240,255,0.90);

        auto contentContainer = fotoContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        contentContainer->setContainerType(ContainerType::ROW);
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
        contentContainer->setContainerType(ContainerType::ROW);
        contentContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);

        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::col_full_12);
            auto title = sContainer->addWidget(cpp14::make_unique<WText>(WString("<h3>Günlük {1}₺</h3><h6>'den Başlayan Fiyatlarla</h6>").arg(mVillaItem->villaAcilisFiyat())));
        }

        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                      Bootstrap::Grid::Medium::col_md_6+
                                      Bootstrap::Grid::Small::col_sm_6+
                                      Bootstrap::Grid::ExtraSmall::col_xs_6);
            auto title = sContainer->addWidget(cpp14::make_unique<WText>(WString("<h5>{1}</h5>").arg(mVillaItem->villaIl())));
        }
        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                      Bootstrap::Grid::Medium::col_md_6+
                                      Bootstrap::Grid::Small::col_sm_6+
                                      Bootstrap::Grid::ExtraSmall::col_xs_6);
            auto title = sContainer->addWidget(cpp14::make_unique<WText>(WString("<h5>{1}</h5>").arg(mVillaItem->villaIlce())));
        }

        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::col_full_12);
            auto title = sContainer->addWidget(cpp14::make_unique<WText>(WString("<h5>{1}</h5>").arg(mVillaItem->villaKonum())));
        }

        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                      Bootstrap::Grid::Medium::col_md_6+
                                      Bootstrap::Grid::Small::col_sm_6+
                                      Bootstrap::Grid::ExtraSmall::col_xs_6);
            auto title = sContainer->addWidget(cpp14::make_unique<WText>(WString("<h5>{1} Kişi</h5>").arg(mVillaItem->villaKisiAdet())));
        }

        {
            auto sContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            sContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                      Bootstrap::Grid::Medium::col_md_6+
                                      Bootstrap::Grid::Small::col_sm_6+
                                      Bootstrap::Grid::ExtraSmall::col_xs_6);
            auto title = sContainer->addWidget(cpp14::make_unique<WText>(WString("<h5>{1}</h5>").arg(mVillaItem->villaHavuz())));
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
        contentContainer->setContainerType(ContainerType::ROW);
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
            auto text = contentContainer->addWidget(cpp14::make_unique<WText>(mVillaItem->villaAciklama(),TextFormat::UnsafeXHTML));
        }

    }
}
