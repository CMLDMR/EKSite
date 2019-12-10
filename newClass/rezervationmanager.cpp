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


    this->Content()->setMargin(20,Side::Top);

}

void Rezervation::RezervationManager::onList(const QVector<eCore::RezervationItem> &mlist)
{

    this->Content()->clear();

    for( const auto& item : mlist )
    {
        auto _rItem = this->Content()->addWidget(cpp14::make_unique<RezervationListWidget>(item));
        _rItem->addStyleClass(Bootstrap::Grid::Large::col_lg_3+
                              Bootstrap::Grid::Medium::col_md_3+
                              Bootstrap::Grid::Small::col_sm_4+
                              Bootstrap::Grid::ExtraSmall::col_xs_6);
        _rItem->RezervationStatusChanged().connect([&]( const bool changed ){

            auto uptItem = item;
            uptItem.setOnay(changed);

            if( this->UpdateItem(uptItem) )
            {
                this->UpdateList(eCore::RezervationItem().setOnay(!changed));
            }

        });

    }
}


Rezervation::RezervationListWidget::RezervationListWidget(const eCore::RezervationItem &item)
    : rItem(item)
{
    addStyleClass(Bootstrap::ImageShape::img_thumbnail);

    {
        if( this->rItem.onay() )
        {

            auto onayText = this->Header()->addWidget(cpp14::make_unique<WText>("Onaylanmış"));
            onayText->addStyleClass(Bootstrap::Label::Success);
            onayText->setAttributeValue(Style::style,Style::font::weight::bold+Style::font::size::s14px);
            this->Header()->addWidget(cpp14::make_unique<WBreak>());
            auto iptalBtn = this->Footer()->addWidget(cpp14::make_unique<WPushButton>("İptal Et"));
            iptalBtn->addStyleClass(Bootstrap::Button::Danger);

            iptalBtn->clicked().connect([=](){
                _rezervationStatusChanged.emit(false);
            });

        }else{
            auto onayText = this->Header()->addWidget(cpp14::make_unique<WText>("Beklemede"));
            onayText->addStyleClass(Bootstrap::Label::Warning);
            onayText->setAttributeValue(Style::style,Style::font::weight::bold+Style::font::size::s14px);
            auto iptalBtn = this->Footer()->addWidget(cpp14::make_unique<WPushButton>("Onayla"));
            iptalBtn->addStyleClass(Bootstrap::Button::Primary);

            iptalBtn->clicked().connect([=](){
                _rezervationStatusChanged.emit(true);
            });
        }
    }
    {
        auto container = this->Content()->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                 Bootstrap::Grid::Medium::col_md_6+
                                 Bootstrap::Grid::Small::col_sm_6+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);
        auto vLayout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        vLayout->addWidget(cpp14::make_unique<WText>("Başlangıç Tarihi"),0,AlignmentFlag::Center);
        vLayout->addWidget(cpp14::make_unique<WText>(QDate::fromJulianDay(this->rItem.beginJulianDate()).toString("dd/MM/yyyy").toStdString()),0,AlignmentFlag::Center);
    }

    {
        auto container = this->Content()->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                 Bootstrap::Grid::Medium::col_md_6+
                                 Bootstrap::Grid::Small::col_sm_6+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);
        auto vLayout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        vLayout->addWidget(cpp14::make_unique<WText>("Bitiş Tarihi"),0,AlignmentFlag::Center);
        vLayout->addWidget(cpp14::make_unique<WText>(QDate::fromJulianDay(this->rItem.endJulianDate()).toString("dd/MM/yyyy").toStdString()),0,AlignmentFlag::Center);
    }

    {
        auto container = this->Content()->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                 Bootstrap::Grid::Medium::col_md_6+
                                 Bootstrap::Grid::Small::col_sm_6+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);
        auto vLayout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        auto dayText = vLayout->addWidget(cpp14::make_unique<WText>(WString("{1} Gün").arg(this->rItem.endJulianDate() - this->rItem.beginJulianDate())),0,AlignmentFlag::Center);
        dayText->addStyleClass(Bootstrap::ContextualBackGround::bg_info);
    }

    {
        auto container = this->Content()->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6+
                                 Bootstrap::Grid::Medium::col_md_6+
                                 Bootstrap::Grid::Small::col_sm_6+
                                 Bootstrap::Grid::ExtraSmall::col_xs_6);
        auto vLayout = container->setLayout(cpp14::make_unique<WVBoxLayout>());
        vLayout->addWidget(cpp14::make_unique<WText>(WString("{1} Kişi").arg(rItem.kisiSayisi())),0,AlignmentFlag::Center);
    }


}

Signal<bool> &Rezervation::RezervationListWidget::RezervationStatusChanged()
{
    return _rezervationStatusChanged;
}
