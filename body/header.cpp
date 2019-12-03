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
        auto _container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        _container->setId("_container");
        _container->addStyleClass(Bootstrap::Grid::col_full_12);
        _container->setRandomBackGroundColor(50,255,1);
//        _container->setPositionScheme(PositionScheme::Relative);
        _container->setContentAlignment(AlignmentFlag::Center);


        auto __container = _container->addWidget(cpp14::make_unique<ContainerWidget>());
        __container->setId("__container");
//        container->addStyleClass(Bootstrap::Grid::col_full_12);
        __container->setRandomBackGroundColor(50,255,1);
//        __container->setPositionScheme(PositionScheme::Relative);
        __container->setContentAlignment(AlignmentFlag::Center);

        auto container = __container->addWidget(cpp14::make_unique<ContainerWidget>());
        container->setId("container");
        container->setMaximumSize(1280,WLength::Auto);

//        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setRandomBackGroundColor(50,255,1);
        container->setPositionScheme(PositionScheme::Relative);
        container->setContentAlignment(AlignmentFlag::Center);

        auto nContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
        nContainer->setWidth(WLength("100%"));
        nContainer->setMaximumSize(1280,WLength::Auto);
        nContainer->setPositionScheme(PositionScheme::Absolute);
        nContainer->setZIndex(10);
        nContainer->setMargin(WLength::Auto,AllSides);

        nContainer->setOverflow(Overflow::Visible);

        auto navigation = nContainer->addWidget(cpp14::make_unique<WNavigationBar>());
        navigation->setTitle("ERK Reality",
                     "http://127.0.0.1.80");
        navigation->setResponsive(true);
        navigation->removeStyleClass("navbar-default");


//        // Setup a Left-aligned menu.
//        auto leftMenu = Wt::cpp14::make_unique<Wt::WMenu>();
//        auto leftMenu_ = navigation->addMenu(std::move(leftMenu));

//        auto searchResult = Wt::cpp14::make_unique<Wt::WText>("Buy or Sell... Bye!");
//        auto searchResult_ = searchResult.get();

//        leftMenu_->addItem("Konaklama", Wt::cpp14::make_unique<Wt::WText>("There is no better place!"));
//        leftMenu_->addItem("Satılık", Wt::cpp14::make_unique<Wt::WText>("Layout contents"))
//            ->setLink(Wt::WLink(Wt::LinkType::InternalPath, "/layout"));
//        leftMenu_->addItem("Uçuşlar", std::move(searchResult));

//        leftMenu_->addItem("Araç Kiralama", Wt::cpp14::make_unique<Wt::WText>("There is no better place!"));
//        leftMenu_->addItem("Transfer", Wt::cpp14::make_unique<Wt::WText>("There is no better place!"));
//        leftMenu_->addItem("Ev Sahibi Olun", Wt::cpp14::make_unique<Wt::WText>("There is no better place!"));


//        // Setup a Right-aligned menu.
//        auto rightMenu = Wt::cpp14::make_unique<Wt::WMenu>();
//        auto rightMenu_ = navigation->addMenu(std::move(rightMenu), Wt::AlignmentFlag::Right);
//        rightMenu_->setMargin(15,Side::Right);

//        // Create a popup submenu for the Help menu.
//        auto popupPtr = Wt::cpp14::make_unique<Wt::WPopupMenu>();
//        auto popup = popupPtr.get();
//        popup->addItem("Kullanıcı Sözleşmelesi");
//        popup->addItem("İletişim");
//        popup->addSeparator();
//        popup->addItem("Hakkında");

//        popup->itemSelected().connect([=] (Wt::WMenuItem *item) {
//            auto messageBox = popup->addChild(
//                    Wt::cpp14::make_unique<Wt::WMessageBox>
//                    ("Help",
//                     Wt::WString("<p>Showing Help: {1}</p>").arg(item->text()),
//                     Wt::Icon::Information,
//                     Wt::StandardButton::Ok));

//            messageBox->buttonClicked().connect([=] {
//                popup->removeChild(messageBox);
//            });

//            messageBox->show();
//        });

//        auto item = Wt::cpp14::make_unique<Wt::WMenuItem>("Hakkında");
//        item->setMenu(std::move(popupPtr));
//        rightMenu_->addItem(std::move(item));
    }
}


