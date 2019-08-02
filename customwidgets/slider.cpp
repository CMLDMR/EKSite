#include "slider.h"
#include "base/containerwidget.h"


Slider::Slider()
{

    setMargin(0,Side::Top);
    setPadding(0,AllSides);
    setWidth(WLength("100%"));
    setHeight(WLength(600));
    setPositionScheme(PositionScheme::Relative);

    mStack = addWidget(cpp14::make_unique<WStackedWidget>());
    mStack->setHeight(WLength("100%"));
    mStack->setWidth(WLength("100%"));

    mStack->setTransitionAnimation(WAnimation(AnimationEffect::Fade,TimingFunction::EaseInOut,1000));


    this->addItem(std::make_unique<SliderItem>("img/1.jpg","Kiralık Villalar"));
    this->addItem(std::make_unique<SliderItem>("img/2.jpg","Satılık Villalar"));
    this->addItem(std::make_unique<SliderItem>("img/3.jpg","Kiralık Daire"));
    this->addItem(std::make_unique<SliderItem>("img/4.jpg","Kiralık Apart"));
    this->addItem(std::make_unique<SliderItem>("img/5.jpg","Kiralık Araç"));

    mStack->clicked().connect([=](){
        auto count = mStack->count();
        auto current = mStack->currentIndex();
        current++;
        current = current % count;
        mStack->setCurrentIndex(current);
        mStack->currentWidget()->setHeight(WLength("100%"));
    });


    // ARAMA WİDGET
    {
        auto container = addWidget(cpp14::make_unique<ContainerWidget>());
        container->setPositionScheme(PositionScheme::Absolute);
        container->setWidth(WLength("100%"));
        container->setHeight(75);
        container->setOffsets(0,Side::Left|Side::Right);
        container->setOffsets(50,Side::Bottom);

        container->setZIndex(10);

        auto mContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
        mContainer->setContainerType(ContainerWidget::ContainerType::CONTAINERFLUID);
        mContainer->setHeight(WLength("100%"));
        mContainer->setContentAlignment(AlignmentFlag::Center);

        auto rContainer = mContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        rContainer->setContainerType(ContainerWidget::ContainerType::ROW);
        rContainer->setWidth(WLength("100%"));
        rContainer->setHeight(WLength("100%"));
        rContainer->setMaximumSize(WLength(1024),WLength::Auto);

        rContainer->setRandomBackGroundColor(240,255,0.45);

        {
            auto _container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            _container->addStyleClass(Bootstrap::Grid::Large::col_lg_2);
            _container->setHeight(WLength("100%"));
            auto layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto comboBox = layout->addWidget(cpp14::make_unique<WComboBox>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            comboBox->addItem("Tümü");
            comboBox->addItem("Belek");
            comboBox->addItem("Kadriye");
            comboBox->addItem("Kaş");
            comboBox->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        }

        {
            auto _container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            _container->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
            _container->setHeight(WLength("100%"));
            auto layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto dateEdit = layout->addWidget(cpp14::make_unique<WDateEdit>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            dateEdit->setPlaceholderText("Giriş Tarihi Seçiniz");
        }

        {
            auto _container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            _container->addStyleClass(Bootstrap::Grid::Large::col_lg_3);
            _container->setHeight(WLength("100%"));
            auto layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto dateEdit = layout->addWidget(cpp14::make_unique<WDateEdit>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            dateEdit->setPlaceholderText("Çıkış Tarihi Seçiniz");
        }

        {
            auto _container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            _container->addStyleClass(Bootstrap::Grid::Large::col_lg_2);
            _container->setHeight(WLength("100%"));
            auto layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto comboBox = layout->addWidget(cpp14::make_unique<WComboBox>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);

            for( int i = 1 ; i <= 15 ; i++ )
            {
                comboBox->addItem(WString("{1} Kişi").arg(i));
            }
            comboBox->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        }

        {
            auto _container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
            _container->addStyleClass(Bootstrap::Grid::Large::col_lg_2);
            _container->setHeight(WLength("100%"));
            auto layout = _container->setLayout(cpp14::make_unique<WVBoxLayout>());

            auto searchBtn = layout->addWidget(cpp14::make_unique<WPushButton>("Ara"),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
            searchBtn->addStyleClass(Bootstrap::Button::Primary);
        }

    }

}

void Slider::addItem(std::unique_ptr<SliderItem> item)
{
//    item->setHeight(WLength("100%"));
    mStack->addWidget(std::move(item));
}

SliderItem::SliderItem(const std::string &imgurl, const std::string &title)
{

    setPositionScheme(PositionScheme::Absolute);
    setWidth(WLength("100%"));
    setMinimumSize(WLength::Auto,600);
    setAttributeValue(Style::style,Style::background::url(imgurl)+Style::background::size::cover+Style::background::repeat::norepeat+Style::background::position::center_center);

    auto layout = setLayout(cpp14::make_unique<WVBoxLayout>());

    auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Center|AlignmentFlag::Middle);
//    container->setPositionScheme(PositionScheme::Absolute);

//    container->setOffsets(WLength("50%"),Side::Left);
//    container->setOffsets(WLength("50%"),Side::Top);

    container->setAttributeValue(Style::style,Style::background::color::rgba(55,55,55));
    container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);

    auto text = container->addWidget(cpp14::make_unique<WText>(title));
    text->setAttributeValue(Style::style,Style::color::color(Style::color::White::Snow)+Style::font::size::s16px);

}
