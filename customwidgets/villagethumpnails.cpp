#include "villagethumpnails.h"
#include "base/villaitem.h"


VillageThumpnails::VillageThumpnails(mongocxx::database *_db , const bsoncxx::oid &_villaOid )
    :DBClass (_db),
      villaOid(_villaOid)
{
    mVillaCollection = this->db()->collection("villa");

    mVillaItem = VillaItem::Load_Villa(&mVillaCollection,villaOid);

    addStyleClass(Bootstrap::Grid::Large::col_lg_3
                  +Bootstrap::Grid::Medium::col_md_3
                  +Bootstrap::Grid::Small::col_sm_4
                  +Bootstrap::Grid::ExtraSmall::col_xs_6);

    decorationStyle().setCursor(Cursor::PointingHand);





    {
        auto container = addWidget(cpp14::make_unique<ContainerWidget>());
        container->setOverflow(Overflow::Hidden);
        container->setPositionScheme(PositionScheme::Relative);
        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setHeight(200);
        container->setRandomBackGroundColor(75,125,0.5);
        container->setWidth(WLength("100%"));
        {
            auto textContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
            textContainer->setPositionScheme(PositionScheme::Absolute);
            textContainer->setOffsets(0,Side::Top|Side::Left);
            textContainer->setWidth(WLength("100%"));
            textContainer->setContentAlignment(AlignmentFlag::Center);
            textContainer->setRandomBackGroundColor(75,85,0.75);
            auto text = textContainer->addWidget(cpp14::make_unique<WText>(mVillaItem->villaName()));
            text->setAttributeValue(Style::style,Style::font::size::s14px+
                                    Style::color::color(Style::color::White::Snow)+
                                    Style::font::family::tahoma);
        }
        {
            auto textContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
            textContainer->setPositionScheme(PositionScheme::Absolute);
            textContainer->setOffsets(0,Side::Left);
            textContainer->setOffsets(WLength("0%"),Side::Bottom);
//            textContainer->setWidth(WLength("75%"));
            textContainer->setContentAlignment(AlignmentFlag::Center);
            textContainer->setRandomBackGroundColor(75,85,0.75);
//            textContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
            auto text = textContainer->addWidget(cpp14::make_unique<WText>(WString("Günlük {1}₺").arg(mVillaItem->villaAcilisFiyat())));
            text->setAttributeValue(Style::style,Style::font::size::s16px+
                                    Style::color::color(Style::color::White::Snow)+
                                    Style::font::family::tahoma+
                                    Style::font::weight::lighter);
            text->setMargin(3,AllSides);
        }

//        {
//            auto textContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
//            textContainer->setPositionScheme(PositionScheme::Absolute);
//            textContainer->setOffsets(0,Side::Left);
//            textContainer->setOffsets(WLength("0%"),Side::Bottom);
////            textContainer->setWidth(WLength("75%"));
//            textContainer->setContentAlignment(AlignmentFlag::Center);
//            textContainer->setRandomBackGroundColor(75,85,0.75);
////            textContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
//            auto text = textContainer->addWidget(cpp14::make_unique<WText>(WString("{1} Kişilik").arg(mVillaItem->villaKisiAdet())));
//            text->setAttributeValue(Style::style,Style::font::size::s16px+
//                                    Style::color::color(Style::color::White::Snow)+
//                                    Style::font::family::tahoma+
//                                    Style::font::weight::lighter);
//            text->setMargin(3,AllSides);
//        }

        container->setMargin(10,Side::Top|Side::Bottom);

        if( mVillaItem->villaImgOidList().count() )
        {
            auto firstOid = mVillaItem->villaImgOidList().first();
            auto filePath = this->downloadFile(firstOid);
            container->setAttributeValue(Style::style,Style::background::url(filePath)+
                                         Style::background::size::cover+
                                         Style::background::repeat::norepeat);
        }
    }

    {
        auto container = addWidget(cpp14::make_unique<ContainerWidget>());
        container->setWidth(WLength("100%"));
        container->setContentAlignment(AlignmentFlag::Left);
        auto text = container->addWidget(cpp14::make_unique<WText>(mVillaItem->villaIl()+" / " + mVillaItem->villaKonum()));
    }

    {
        auto container = addWidget(cpp14::make_unique<ContainerWidget>());
        container->setWidth(WLength("100%"));
        container->setContentAlignment(AlignmentFlag::Left);
        auto text = container->addWidget(cpp14::make_unique<WText>(WString("{1} Kişilik").arg(mVillaItem->villaKisiAdet())));
    }




}



VillaPage::VillaPage(mongocxx::database *_db)
    :DBClass (_db)
{

    setMargin(30,Side::Top|Side::Bottom);
    setContentAlignment(AlignmentFlag::Center);


    auto rContainer = addWidget(cpp14::make_unique<ContainerWidget>());
    rContainer->setContainerType(ContainerType::ROW);
    rContainer->setMaximumSize(1024,WLength::Auto);

    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        auto text = container->addWidget(cpp14::make_unique<WText>("<h3>Villalar</h3>"));
    }


    auto projectDoc = document{};

    try {
        projectDoc.append(kvp("_id",true));
    } catch (bsoncxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
    }


    mongocxx::options::find findOptions;

    findOptions.projection(projectDoc.view());

    try {
        auto cursor = this->db()->collection("villa").find(make_document(kvp(VillaItem::VILLAYAYINDA,true)),findOptions);

        for( auto doc : cursor )
        {

            try {
                rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db(),doc["_id"].get_oid().value));
            } catch (bsoncxx::exception &e) {
                std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
            }

        }


    } catch (mongocxx::exception &e) {
        std::cout << "ERROR: " << __LINE__ << " " << __FUNCTION__ << " " << e.what() << std::endl;
    }


//    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
//    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
//    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
//    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));

//    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
//    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
//    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
//    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
}
