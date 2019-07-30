#include "villaadminpage.h"

#include "villaaddpage.h"

VillaAdminPage::VillaAdminPage(mongocxx::database *_db)
    :DBClass (_db)
{
    setContentAlignment(AlignmentFlag::Center);
    rContainer = addWidget(cpp14::make_unique<ContainerWidget>());
    rContainer->setContainerType(ContainerType::ROW);

    // MENU 1: Yeni Villa Ekle
    {
        mYeniVilla = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        mYeniVilla->addStyleClass(Bootstrap::Grid::Large::col_lg_6);
        auto layout = mYeniVilla->setLayout(cpp14::make_unique<WHBoxLayout>());
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
        mVillalarContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        mVillalarContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6);
        auto layout = mVillalarContainer->setLayout(cpp14::make_unique<WHBoxLayout>());
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
        stackedWidget = rContainer->addWidget(cpp14::make_unique<WStackedWidget>());
        stackedWidget->addStyleClass(Bootstrap::ImageShape::img_thumbnail
                                     +Bootstrap::Grid::col_full_12);
        stackedWidget->setAttributeValue(Style::style,Style::background::color::rgb(this->getRandom(150),this->getRandom(150),this->getRandom(150)));

        {
            auto mVillaAddPage = cpp14::make_unique<VillaAddPage>(this->db());

            stackedWidget->addWidget(std::move(mVillaAddPage));
        }

        {
            auto mVillaAddPage = cpp14::make_unique<VillaAddPage>(this->db());

            stackedWidget->addWidget(std::move(mVillaAddPage));
        }

    }

    mYeniVilla->clicked().connect([=](){
        stackedWidget->setCurrentIndex(0,WAnimation(AnimationEffect::Fade,TimingFunction::EaseInOut,1000));
    });

    mVillalarContainer->clicked().connect([=](){
        stackedWidget->setCurrentIndex(1,WAnimation(AnimationEffect::Fade,TimingFunction::EaseInOut,1000));
    });
}
