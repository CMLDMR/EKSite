#include "villalistpage.h"
#include "base/villaitem.h"
#include "admin/villaaddpage.h"

VillaListPage::VillaListPage(mongocxx::database *_db)
    :DBClass (_db)
{


    villaCollection = this->db()->collection("villa");


    rContainer = addWidget(cpp14::make_unique<ContainerWidget>());
    rContainer->setContainerType(ContainerType::ROW);


}

void VillaListPage::initVillaList()
{


    rContainer->clear();

    auto filter = document{};



    auto projectView = document{};

    try {
        projectView.append(kvp("_id",true));
    } catch (bsoncxx::exception &e) {

    }

    mongocxx::options::find findOptions;

    findOptions.projection(projectView.view());


    try {

        auto cursor = this->villaCollection.find(filter.view(),findOptions);



        for( auto doc : cursor )
        {
            try {

                auto villaItem = VillaItem::Load_Villa(this->villaCollection,doc["_id"].get_oid().value);

                auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
                container->setRandomBackGroundColor(220,230);
                container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                container->setMargin(5,Side::Top);
                container->addStyleClass(Bootstrap::Grid::col_full_12);
                container->decorationStyle().setCursor(Cursor::PointingHand);
                container->setAttributeValue(Style::dataoid,villaItem.villaOid().to_string());
                container->clicked().connect([=](){
                    this->initVilla(container->attributeValue(Style::dataoid).toUTF8());
                });

                auto iContainer = container->addWidget(cpp14::make_unique<ContainerWidget>());
                iContainer->setContainerType(ContainerType::ROW);

                auto YayindaContainer = iContainer->addWidget(cpp14::make_unique<ContainerWidget>());
                YayindaContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_1
                                             +Bootstrap::Grid::Medium::col_md_1
                                             +Bootstrap::Grid::Small::col_sm_2
                                             +Bootstrap::Grid::ExtraSmall::col_xs_3);
                YayindaContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                if( villaItem.villaYayinda() )
                {
                    auto Nametext = YayindaContainer->addWidget(cpp14::make_unique<WText>("Yayında"));
                }else{
                    auto Nametext = YayindaContainer->addWidget(cpp14::make_unique<WText>("Değil"));
                }

                auto NameContainer = iContainer->addWidget(cpp14::make_unique<ContainerWidget>());
                NameContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3
                                             +Bootstrap::Grid::Medium::col_md_3
                                             +Bootstrap::Grid::Small::col_sm_6
                                             +Bootstrap::Grid::ExtraSmall::col_xs_6);
                NameContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                auto Nametext = NameContainer->addWidget(cpp14::make_unique<WText>(villaItem.villaName()));

                auto KisiContainer = iContainer->addWidget(cpp14::make_unique<ContainerWidget>());
                KisiContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_2
                                             +Bootstrap::Grid::Medium::col_md_2
                                             +Bootstrap::Grid::Small::col_sm_4
                                             +Bootstrap::Grid::ExtraSmall::col_xs_3);
                KisiContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                auto Kisitext = KisiContainer->addWidget(cpp14::make_unique<WText>(WString("{1} Kişi").arg(villaItem.villaKisiAdet())));

                auto KonumContainer = iContainer->addWidget(cpp14::make_unique<ContainerWidget>());
                KonumContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3
                                             +Bootstrap::Grid::Medium::col_md_3
                                             +Bootstrap::Grid::Small::col_sm_6
                                             +Bootstrap::Grid::ExtraSmall::col_xs_6);
                KonumContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                auto Konumtext = KonumContainer->addWidget(cpp14::make_unique<WText>(villaItem.villaKonum()));

                auto HavuzContainer = iContainer->addWidget(cpp14::make_unique<ContainerWidget>());
                HavuzContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_3
                                             +Bootstrap::Grid::Medium::col_md_3
                                             +Bootstrap::Grid::Small::col_sm_6
                                             +Bootstrap::Grid::ExtraSmall::col_xs_6);
                HavuzContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                auto Havuztext = HavuzContainer->addWidget(cpp14::make_unique<WText>(WString("{1}").arg(villaItem.villaHavuz())));





                auto IlContainer = iContainer->addWidget(cpp14::make_unique<ContainerWidget>());
                IlContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                             +Bootstrap::Grid::Medium::col_md_6
                                             +Bootstrap::Grid::Small::col_sm_6
                                             +Bootstrap::Grid::ExtraSmall::col_xs_6);
                IlContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                auto iltext = IlContainer->addWidget(cpp14::make_unique<WText>(WString("{1}").arg(villaItem.villaIl())));

                auto IlceContainer = iContainer->addWidget(cpp14::make_unique<ContainerWidget>());
                IlceContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                             +Bootstrap::Grid::Medium::col_md_6
                                             +Bootstrap::Grid::Small::col_sm_6
                                             +Bootstrap::Grid::ExtraSmall::col_xs_6);
                IlceContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                auto IlceText = IlceContainer->addWidget(cpp14::make_unique<WText>(WString("{1}").arg(villaItem.villaIlce())));

            } catch (bsoncxx::exception &e) {

            }
        }
    } catch (mongocxx::exception &e) {

    }
}

void VillaListPage::initVilla(const std::string &villaOid)
{
    rContainer->clear();

    addWidget(cpp14::make_unique<VillaAddPage>(this->db()))->LoadVilla(villaOid);
}

Signal<std::string> &VillaListPage::ClickVilla()
{
    return _ClickVilla;
}
