#include "placethumpnails.h"



PlaceThumpnails::PlaceThumpnails(mongocxx::database *_db)
    :DBClass (_db)
{
    setContainerType(ContainerType::CONTAINERFLUID);
    addStyleClass(Bootstrap::ImageShape::img_thumbnail);
    //    setRandomBackGroundColor(0,255,0.5);
    //    setHeight(300);
    setWidth(WLength("100%"));
    setContentAlignment(AlignmentFlag::Center);




    {
        auto rContainer = addWidget(cpp14::make_unique<ContainerWidget>());
        rContainer->setContainerType(ContainerType::CONTAINERFLUID);
//        rContainer->setWidth(WLength("100%"));
//        rContainer->setRandomBackGroundColor(25,45,0.5);
        rContainer->setContentAlignment(AlignmentFlag::Center);
        rContainer->setMaximumSize(1150,WLength::Auto);

        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);
//        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);


        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());

        auto text = layout->addWidget(cpp14::make_unique<WText>("Bölgeler"),0,AlignmentFlag::Left|AlignmentFlag::Middle);
        text->setAttributeValue(Style::style,Style::font::size::s20px
                                +Style::font::family::tahoma
                                +Style::color::color(Style::color::Grey::Black)
                                +Style::font::weight::lighter);
    }

    {
        auto rContainer = addWidget(cpp14::make_unique<ContainerWidget>());
        rContainer->setContainerType(ContainerType::ROW);
        rContainer->setMaximumSize(1024,WLength::Auto);
        rContainer->addWidget(cpp14::make_unique<Thumpnails>(this->db(),"Belek","Antalya","img/1.jpg"));
        rContainer->addWidget(cpp14::make_unique<Thumpnails>(this->db(),"Kadriye","Antalya","img/3.jpg"));
        rContainer->addWidget(cpp14::make_unique<Thumpnails>(this->db(),"Kaş","Antalya","img/5.jpg"));
    }

}

Thumpnails::Thumpnails(mongocxx::database *_db, std::string bolge, std::string il, std::string imgUrl)
    :DBClass (_db)
{
    addStyleClass(Bootstrap::Grid::Large::col_lg_4);
    setHeight(300);
    setContentAlignment(AlignmentFlag::Center);
    setMargin(25,Side::Top|Side::Bottom);


    auto imgContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    imgContainer->setWidth(WLength("80%"));
    imgContainer->setHeight(WLength("100%"));
    imgContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);


    imgContainer->setAttributeValue(Style::style,Style::background::url(imgUrl)
                      +Style::background::size::cover
                      +Style::background::repeat::norepeat
                      +Style::background::position::center_center);

    auto layout = imgContainer->setLayout(cpp14::make_unique<WVBoxLayout>());
    layout->addStretch(1);
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>(bolge),0,AlignmentFlag::Center|AlignmentFlag::Bottom);
        text->setAttributeValue(Style::style,Style::color::color(Style::color::White::Linen)
                                +Style::font::size::s16px
                                +Style::font::weight::bold);
//        text->setMargin(25,Side::Bottom);
    }
    {
        auto text = layout->addWidget(cpp14::make_unique<WText>(il),0,AlignmentFlag::Center|AlignmentFlag::Bottom);
        text->setAttributeValue(Style::style,Style::color::color(Style::color::White::Linen)
                                +Style::font::size::s12px
                                +Style::font::weight::lighter);
        text->setMargin(10,Side::Bottom);
    }

}
