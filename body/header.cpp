#include "header.h"

Header::Header()
{
    setHeight(75);
    setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::Black));
    setWidth(WLength("100%"));
    setContentAlignment(AlignmentFlag::Center);
    mMenuWidgets = addWidget(cpp14::make_unique<WContainerWidget>());
    mMenuWidgets->setHeight(WLength("100%"));
    mMenuWidgets->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::Black));
    mMenuWidgets->setMaximumSize(1024,WLength::Auto);
    mMenuWidgets->addStyleClass(Bootstrap::Grid::row);


    {
        auto container = mMenuWidgets->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_2+Bootstrap::Grid::Small::col_sm_3+Bootstrap::Grid::ExtraSmall::col_xs_4);
        container->setHeight(WLength("100%"));
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
        _container->setWidth(WLength("100%"));
        _container->decorationStyle().setCursor(Cursor::PointingHand);
        _container->setMargin(WLength::Auto,Side::Top|Side::Bottom);
        auto text = _container->addWidget(cpp14::make_unique<WText>("ERK Reality Show"));
        text->setAttributeValue(Style::style,Style::color::rgb("255,255,255")+Style::font::size::s16px);
        text->addStyleClass(Bootstrap::Label::info);
    }

    {
        auto container = mMenuWidgets->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Offset::Large::col_lg_6+Bootstrap::Grid::Offset::Medium::col_md_6+Bootstrap::Grid::Offset::Small::col_sm_3);
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_2+Bootstrap::Grid::Small::col_sm_3+Bootstrap::Grid::ExtraSmall::col_xs_4);
        container->setHeight(WLength("100%"));
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
        _container->setWidth(WLength("100%"));
        _container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        _container->decorationStyle().setCursor(Cursor::PointingHand);
        _container->setMargin(WLength::Auto,Side::Top|Side::Bottom);
        auto text = _container->addWidget(cpp14::make_unique<WText>("Giriş Yap"));
        text->setAttributeValue(Style::style,Style::color::rgb("0,0,0"));
    }

    {
        auto container = mMenuWidgets->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_2+Bootstrap::Grid::Small::col_sm_3+Bootstrap::Grid::ExtraSmall::col_xs_4);
        container->setHeight(WLength("100%"));
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
        _container->setWidth(WLength("100%"));
        _container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        _container->decorationStyle().setCursor(Cursor::PointingHand);
        _container->setMargin(WLength::Auto,Side::Top|Side::Bottom);
        auto text = _container->addWidget(cpp14::make_unique<WText>("Üye Ol"));
        text->setAttributeValue(Style::style,Style::color::rgb("0,0,0"));
    }

}
