#include "villagethumpnails.h"



VillageThumpnails::VillageThumpnails(mongocxx::database *_db)
    :DBClass (_db)
{

    addStyleClass(Bootstrap::Grid::Large::col_lg_3
                  +Bootstrap::Grid::Medium::col_md_3
                  +Bootstrap::Grid::Small::col_sm_4
                  +Bootstrap::Grid::ExtraSmall::col_xs_6);



//

    auto container = addWidget(cpp14::make_unique<ContainerWidget>());
    container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
    container->setHeight(300);
    container->setRandomBackGroundColor(75,125,0.5);
    container->setWidth(WLength("100%"));
    container->addWidget(cpp14::make_unique<WText>("Villa ThumpNails"));
}



VillaPage::VillaPage(mongocxx::database *_db)
    :DBClass (_db)
{

    setMargin(30,Side::Top|Side::Bottom);
    setContentAlignment(AlignmentFlag::Center);


    auto rContainer = addWidget(cpp14::make_unique<ContainerWidget>());
    rContainer->setContainerType(ContainerType::ROW);
    rContainer->setMaximumSize(1024,WLength::Auto);

    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        auto text = container->addWidget(cpp14::make_unique<WText>("<h3>Villalar</h3>"));
    }


    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));

    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
    rContainer->addWidget(cpp14::make_unique<VillageThumpnails>(this->db()));
}
