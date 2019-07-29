#include "slider.h"

Slider::Slider()
{
//    setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::LightGray));
//    addStyleClass(Bootstrap::ImageShape::img_thumbnail);
    mStack = addWidget(cpp14::make_unique<WStackedWidget>());
    mStack->setHeight(WLength("100%"));
    mStack->setWidth(WLength("100%"));
    setWidth(WLength("100%"));
    setHeight(WLength("100%"));
//    setPositionScheme(PositionScheme::Relative);
    mStack->setTransitionAnimation(WAnimation(AnimationEffect::Fade,TimingFunction::EaseInOut,1000));


    this->addItem(std::make_unique<SliderItem>("img/1.jpg","Kiralık Villalar"));
    this->addItem(std::make_unique<SliderItem>("img/2.jpg","Satılık Villalar"));
    this->addItem(std::make_unique<SliderItem>("img/3.jpg","Kiralık Daire"));
    this->addItem(std::make_unique<SliderItem>("img/4.jpg","Kiralık Apart"));
    this->addItem(std::make_unique<SliderItem>("img/5.png","Kiralık Araç"));

    mStack->clicked().connect([=](){
        auto count = mStack->count();
        auto current = mStack->currentIndex();
        current++;
        current = current % count;
        mStack->setCurrentIndex(current);
    });


}

void Slider::addItem(std::unique_ptr<SliderItem> item)
{
    mStack->addWidget(std::move(item));
}

SliderItem::SliderItem(const std::string &imgurl, const std::string &title)
{

    setWidth(WLength("100%"));
    setHeight(WLength("100%"));
    setAttributeValue(Style::style,Style::background::url(imgurl)+Style::background::size::cover+Style::background::repeat::norepeat+Style::background::position::center_center);

    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->setPositionScheme(PositionScheme::Relative);

    container->setOffsets(0,Side::Left);
    container->setOffsets(WLength("50%"),Side::Top);

    container->setAttributeValue(Style::style,Style::background::color::rgba(55,55,55));
    container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);

    auto text = container->addWidget(cpp14::make_unique<WText>(title));
    text->setAttributeValue(Style::style,Style::color::color(Style::color::White::Snow)+Style::font::size::s16px);

}
