#include "villaadminpage.h"

VillaAdminPage::VillaAdminPage(mongocxx::database *_db)
    :DBClass (_db)
{
    setContentAlignment(AlignmentFlag::Center);
    rContainer = addWidget(cpp14::make_unique<ContainerWidget>());
    rContainer->setContainerType(ContainerType::ROW);

    // MENU 1: Yeni Villa Ekle
    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6);
        auto layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        layout->addStretch(1);

        auto bContainer = layout->addWidget(cpp14::make_unique<ContainerWidget>());
        bContainer->setWidth(100);
        bContainer->setHeight(75);
        bContainer->setRandomBackGroundColor();
        bContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        layout->addStretch(1);

        auto vLayout = bContainer->setLayout(cpp14::make_unique<WVBoxLayout>());
        vLayout->addStretch(1);
        auto text = vLayout->addWidget(cpp14::make_unique<WText>("Yeni Villa Ekle"));
        vLayout->addStretch(1);
    }


    // MENU 2: Villalar
    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6);
        auto layout = container->setLayout(cpp14::make_unique<WHBoxLayout>());
        layout->addStretch(1);

        auto bContainer = layout->addWidget(cpp14::make_unique<ContainerWidget>());
        bContainer->setWidth(100);
        bContainer->setHeight(75);
        bContainer->setRandomBackGroundColor();
        bContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        layout->addStretch(1);

        auto vLayout = bContainer->setLayout(cpp14::make_unique<WVBoxLayout>());
        vLayout->addStretch(1);
        auto text = vLayout->addWidget(cpp14::make_unique<WText>("Villalar"));
        vLayout->addStretch(1);
    }


    // CONTENT STACKWIDGET
    {

    }
}
