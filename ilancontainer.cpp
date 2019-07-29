#include "ilancontainer.h"



IlanContainer::IlanContainer()
{

    decorationStyle().setCursor(Cursor::PointingHand);

    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->setAttributeValue(Style::style,Style::background::url("img/ilanthump.jpg")+Style::background::size::cover+Style::background::repeat::norepeat+Style::background::position::center_center);
    container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
    container->setMargin(5,AllSides);
    container->setHeight(250);
    container->setWidth(WLength("100%"));
    container->setOverflow(Overflow::Hidden);
    container->setPadding(0,Side::Bottom);

    auto vLayout = container->setLayout(cpp14::make_unique<WVBoxLayout>());


    {
        auto colorContainer = vLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Top);
        colorContainer->addStyleClass(Bootstrap::Grid::row);
//        colorContainer->setAttributeValue(Style::style,Style::background::color::rgba(100,100,100));

        auto layout = colorContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

        auto ilan = layout->addWidget(cpp14::make_unique<WText>("Kiralık Villa"),0,AlignmentFlag::Right|AlignmentFlag::Top);
        ilan->setAttributeValue(Style::style,Style::color::rgb("255,255,255")+Style::font::size::s14px+Style::font::weight::bold);
        ilan->addStyleClass(Bootstrap::Label::Primary);
    }

    {
        auto colorContainer = vLayout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Bottom);
        colorContainer->addStyleClass(Bootstrap::Grid::row);
        colorContainer->setAttributeValue(Style::style,Style::background::color::rgba(100,100,100,0.2));

        {
            auto tContainer = colorContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            tContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_3+Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::ExtraSmall::col_xs_6);
            auto ilan = tContainer->addWidget(cpp14::make_unique<WText>(WString("3+1")));
            ilan->setAttributeValue(Style::style,Style::color::rgb("75,75,75")+Style::font::size::s12px+Style::font::weight::bold);
        }

        {
            auto tContainer = colorContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            tContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_3+Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::ExtraSmall::col_xs_6);
            auto ilan = tContainer->addWidget(cpp14::make_unique<WText>(WString("Havuz")));
            ilan->setAttributeValue(Style::style,Style::color::rgb("75,75,75")+Style::font::size::s12px+Style::font::weight::bold);
        }

        {
            auto tContainer = colorContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            tContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_3+Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::ExtraSmall::col_xs_6);
            auto ilan = tContainer->addWidget(cpp14::make_unique<WText>(WString("8Kişi")));
            ilan->setAttributeValue(Style::style,Style::color::rgb("75,75,75")+Style::font::size::s12px+Style::font::weight::bold);
        }



    }


}
