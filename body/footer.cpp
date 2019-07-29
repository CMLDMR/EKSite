#include "footer.h"

Footer::Footer()
{

    setHeight(75);
    setAttributeValue(Style::style,Style::background::color::rgba(125,125,125));
    setWidth(WLength("100%"));
    setContentAlignment(AlignmentFlag::Center);
    mMenuWidgets = addWidget(cpp14::make_unique<WContainerWidget>());
    mMenuWidgets->setHeight(WLength("100%"));
    mMenuWidgets->setAttributeValue(Style::style,Style::background::color::rgba(25,25,25));
    mMenuWidgets->setMaximumSize(1024,WLength::Auto);
    mMenuWidgets->setContentAlignment(AlignmentFlag::Center);
    mMenuWidgets->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
    mMenuWidgets->setWidth(WLength("100%"));
    mMenuWidgets->setMaximumSize(1024,WLength::Auto);

    auto layout = mMenuWidgets->setLayout(cpp14::make_unique<WVBoxLayout>());
    auto text = layout->addWidget(cpp14::make_unique<WText>("copyright ERK (c) 2019"),0,AlignmentFlag::Middle|AlignmentFlag::Center);
    text->setAttributeValue(Style::style,Style::color::rgb("255,255,255"));


}
