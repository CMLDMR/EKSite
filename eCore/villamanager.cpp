#include "villamanager.h"



eCore::VillaManager::VillaManager(eCore::DB *_db)
:eCore::ListItem<VillaItem>(_db)
{


    this->Header()->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
    this->Header()->setWidth(WLength("100%"));
    this->Header()->addWidget(cpp14::make_unique<WText>("ERK Site"));
    this->Header()->setContentAlignment(AlignmentFlag::Center);


    this->UpdateList(eCore::VillaItem());
}

void eCore::VillaManager::onList(const QVector<eCore::VillaItem> &mlist)
{

    this->Content()->clear();



    for( auto item : mlist )
    {
        auto container = this->Content()->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->addWidget(cpp14::make_unique<WText>("Villa"));
    }





}
