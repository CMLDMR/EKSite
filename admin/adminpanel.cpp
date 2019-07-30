#include "adminpanel.h"


#include "admin/villaadminpage.h"



AdminPanel::AdminPanel(mongocxx::database *_db)
    :DBClass (_db)
{
    setContainerType(ContainerWidget::ContainerType::CONTAINERFLUID);
    setContentAlignment(AlignmentFlag::Center);
    rContainer = addWidget(cpp14::make_unique<ContainerWidget>());
    rContainer->setContainerType(ContainerWidget::ContainerType::ROW);
    rContainer->setMargin(50,Side::Top|Side::Bottom);
    rContainer->setMaximumSize(1024,WLength::Auto);


    this->initMainPage();




}

void AdminPanel::initMainPage()
{
    rContainer->clear();

    //TİTLE : Admin Panel
    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);

        auto text = container->addWidget(cpp14::make_unique<WText>("Admin Panel"));

    }


    // MENU 1: Villalar
    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());

        container->addStyleClass(Bootstrap::Grid::Large::col_lg_2
                                 +Bootstrap::Grid::Medium::col_md_2
                                 +Bootstrap::Grid::Small::col_sm_4
                                 +Bootstrap::Grid::ExtraSmall::col_xs_6
                                 +Bootstrap::ImageShape::img_thumbnail);
        container->setRandomBackGroundColor();
        container->setHeight(100);
        container->decorationStyle().setCursor(Cursor::PointingHand);
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        layout->addStretch(1);
        auto text = layout->addWidget(cpp14::make_unique<WText>("Villalar"));
        layout->addStretch(1);

        container->clicked().connect(this,&AdminPanel::initVillaPage);
    }

    // MENU 2: Resevasyonlar
    {

        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());


        container->addStyleClass(Bootstrap::Grid::Large::col_lg_2
                                 +Bootstrap::Grid::Medium::col_md_2
                                 +Bootstrap::Grid::Small::col_sm_4
                                 +Bootstrap::Grid::ExtraSmall::col_xs_6
                                 +Bootstrap::ImageShape::img_thumbnail
                                 +Bootstrap::Grid::Offset::Large::col_lg_1
                                 +Bootstrap::Grid::Offset::Medium::col_md_1
                                 +Bootstrap::Grid::Offset::Small::col_sm_1);
        container->setRandomBackGroundColor();
        container->decorationStyle().setCursor(Cursor::PointingHand);
        container->setHeight(100);
        auto layout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        layout->addStretch(1);
        auto text = layout->addWidget(cpp14::make_unique<WText>("Reservasyonlar"));
        layout->addStretch(1);
    }
}

void AdminPanel::initVillaPage()
{
    rContainer->clear();
    rContainer->addWidget(cpp14::make_unique<VillaAdminPage>(this->db()));
}
