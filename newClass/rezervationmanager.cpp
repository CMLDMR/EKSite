#include "rezervationmanager.h"

Rezervation::RezervationManager::RezervationManager(eCore::DB *_db)
    : eCore::ContainerWidgetV2() , RezervationList( _db )
{
    this->Header()->clear();

    this->Header()->addWidget(cpp14::make_unique<WText>("<h3>Rezervasyonlar</h3>"))->addStyleClass(Bootstrap::ContextualBackGround::bg_primary
                                                                                                   +Bootstrap::Grid::col_full_12);

    auto onayliContainer = this->Header()->addWidget(cpp14::make_unique<ContainerWidgetV2>());
    onayliContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                   Bootstrap::Grid::Medium::col_md_6+
                                   Bootstrap::Grid::Small::col_sm_6+
                                   Bootstrap::Grid::ExtraSmall::col_xs_6);

    onayliContainer->setRandomBackGroundColor(50,125);
    onayliContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
    onayliContainer->addWidget(cpp14::make_unique<WText>("Onaylanmış Rezervasyonlar"))
            ->setAttributeValue(Style::style,Style::color::color(Style::color::White::Snow)+Style::font::weight::bold);
    onayliContainer->decorationStyle().setCursor(Cursor::PointingHand);
    onayliContainer->clicked().connect([&](){
        this->UpdateList(eCore::RezervationItem().setOnay(true));
    });


    auto onaysizContainer = this->Header()->addWidget(cpp14::make_unique<ContainerWidgetV2>());
    onaysizContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                   Bootstrap::Grid::Medium::col_md_6+
                                   Bootstrap::Grid::Small::col_sm_6+
                                   Bootstrap::Grid::ExtraSmall::col_xs_6);

    onaysizContainer->setRandomBackGroundColor(50,125);
    onaysizContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
    onaysizContainer->addWidget(cpp14::make_unique<WText>("Bekleyen Rezervasyonlar"))
            ->setAttributeValue(Style::style,Style::color::color(Style::color::White::Snow)+Style::font::weight::bold);
    onaysizContainer->decorationStyle().setCursor(Cursor::PointingHand);
    onaysizContainer->clicked().connect([&](){
        this->UpdateList(eCore::RezervationItem().setOnay(false));
    });


}

void Rezervation::RezervationManager::onList(const QVector<eCore::RezervationItem> &mlist)
{
    this->Content()->clear();

    for( const auto& item : mlist )
    {
        this->Content()->addWidget(cpp14::make_unique<RezervationListWidget>(item));
    }
}


Rezervation::RezervationListWidget::RezervationListWidget(const eCore::RezervationItem &item)
    : rItem(item)
{
    this->Content()->addWidget(cpp14::make_unique<WText>(rItem.saat()));
}
