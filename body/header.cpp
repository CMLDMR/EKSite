#include "header.h"

Header::Header()
{
//    setHeight(75);
    setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::Black));
    setWidth(WLength("100%"));
    setContentAlignment(AlignmentFlag::Center);


    auto rContainer = addWidget(cpp14::make_unique<ContainerWidget>());
    rContainer->setContainerType(ContainerWidget::ContainerType::ROW);
    rContainer->setContentAlignment(AlignmentFlag::Center);

    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setHeight(125);
        container->setRandomBackGroundColor(75,150,0.5);
    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setRandomBackGroundColor(255,255,1);

        container->setContentAlignment(AlignmentFlag::Center);

        auto nContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
        nContainer->setWidth(WLength("100%"));
        nContainer->setMaximumSize(1280,WLength::Auto);
        auto layout = nContainer->setLayout(cpp14::make_unique<WVBoxLayout>());

        auto navigation = layout->addWidget(cpp14::make_unique<WNavigationBar>(),0,AlignmentFlag::Middle|AlignmentFlag::Justify);
        navigation->setTitle("ERK Reality",
                     "https://www.google.com/search?q=corpy+inc");
        navigation->setResponsive(true);
        navigation->removeStyleClass("navbar-default");


        // Setup a Left-aligned menu.
        auto leftMenu = Wt::cpp14::make_unique<Wt::WMenu>();
        auto leftMenu_ = navigation->addMenu(std::move(leftMenu));

        auto searchResult = Wt::cpp14::make_unique<Wt::WText>("Buy or Sell... Bye!");
        auto searchResult_ = searchResult.get();

        leftMenu_->addItem("Home", Wt::cpp14::make_unique<Wt::WText>("There is no better place!"));
        leftMenu_->addItem("Layout", Wt::cpp14::make_unique<Wt::WText>("Layout contents"))
            ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/layout"));
        leftMenu_->addItem("Sales", std::move(searchResult));

        // Setup a Right-aligned menu.
        auto rightMenu = Wt::cpp14::make_unique<Wt::WMenu>();
        auto rightMenu_ = navigation->addMenu(std::move(rightMenu), Wt::AlignmentFlag::Right);
        rightMenu_->setMargin(15,Side::Right);

        // Create a popup submenu for the Help menu.
        auto popupPtr = Wt::cpp14::make_unique<Wt::WPopupMenu>();
        auto popup = popupPtr.get();
        popup->addItem("Contents");
        popup->addItem("Index");
        popup->addSeparator();
        popup->addItem("About");

        popup->itemSelected().connect([=] (Wt::WMenuItem *item) {
            auto messageBox = popup->addChild(
                    Wt::cpp14::make_unique<Wt::WMessageBox>
                    ("Help",
                     Wt::WString("<p>Showing Help: {1}</p>").arg(item->text()),
                     Wt::Icon::Information,
                     Wt::StandardButton::Ok));

            messageBox->buttonClicked().connect([=] {
                popup->removeChild(messageBox);
            });

            messageBox->show();
        });

        auto item = Wt::cpp14::make_unique<Wt::WMenuItem>("Help");
        item->setMenu(std::move(popupPtr));
        rightMenu_->addItem(std::move(item));

    }

//    mMenuWidgets = addWidget(cpp14::make_unique<WContainerWidget>());
//    mMenuWidgets->setHeight(WLength("100%"));
//    mMenuWidgets->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::Black));
//    mMenuWidgets->setMaximumSize(1024,WLength::Auto);
//    mMenuWidgets->addStyleClass(Bootstrap::Grid::row);


//    {
//        auto container = mMenuWidgets->addWidget(cpp14::make_unique<WContainerWidget>());
//        container->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_2+Bootstrap::Grid::Small::col_sm_3+Bootstrap::Grid::ExtraSmall::col_xs_4);
//        container->setHeight(WLength("100%"));
//        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
//        auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
//        _container->setWidth(WLength("100%"));
//        _container->decorationStyle().setCursor(Cursor::PointingHand);
//        _container->setMargin(WLength::Auto,Side::Top|Side::Bottom);
//        auto text = _container->addWidget(cpp14::make_unique<WText>("ERK Reality Show"));
//        text->setAttributeValue(Style::style,Style::color::rgb("255,255,255")+Style::font::size::s16px);
//        text->addStyleClass(Bootstrap::Label::info);
//    }

//    {
//        auto container = mMenuWidgets->addWidget(cpp14::make_unique<WContainerWidget>());
//        container->addStyleClass(Bootstrap::Grid::Offset::Large::col_lg_6+Bootstrap::Grid::Offset::Medium::col_md_6+Bootstrap::Grid::Offset::Small::col_sm_3);
//        container->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_2+Bootstrap::Grid::Small::col_sm_3+Bootstrap::Grid::ExtraSmall::col_xs_4);
//        container->setHeight(WLength("100%"));
//        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
//        auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
//        _container->setWidth(WLength("100%"));
//        _container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
//        _container->decorationStyle().setCursor(Cursor::PointingHand);
//        _container->setMargin(WLength::Auto,Side::Top|Side::Bottom);
//        auto text = _container->addWidget(cpp14::make_unique<WText>("Giriş Yap"));
//        text->setAttributeValue(Style::style,Style::color::rgb("0,0,0"));
//        _container->clicked().connect(this,[=](){
//            _ClickGiris.emit(NoClass());
//        });
//    }

//    {
//        auto container = mMenuWidgets->addWidget(cpp14::make_unique<WContainerWidget>());
//        container->addStyleClass(Bootstrap::Grid::Large::col_lg_2+Bootstrap::Grid::Medium::col_md_2+Bootstrap::Grid::Small::col_sm_3+Bootstrap::Grid::ExtraSmall::col_xs_4);
//        container->setHeight(WLength("100%"));
//        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
//        auto _container = layout->addWidget(cpp14::make_unique<WContainerWidget>(),0,AlignmentFlag::Justify|AlignmentFlag::Middle);
//        _container->setWidth(WLength("100%"));
//        _container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
//        _container->decorationStyle().setCursor(Cursor::PointingHand);
//        _container->setMargin(WLength::Auto,Side::Top|Side::Bottom);
//        auto text = _container->addWidget(cpp14::make_unique<WText>("Üye Ol"));
//        text->setAttributeValue(Style::style,Style::color::rgb("0,0,0"));
//    }

}

//Signal<NoClass> &Header::ClickGiris()
//{
//    return _ClickGiris;
//}
