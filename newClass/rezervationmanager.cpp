#include "rezervationmanager.h"

RezervationManager::RezervationManager(eCore::DB *_db)
    : ContainerWidgetV2() , RezervationList( _db )
{
    this->Header()->addWidget(cpp14::make_unique<WText>("Header TEST"));

    this->UpdateList(eCore::RezervationItem());
}

void RezervationManager::onList(const QVector<eCore::RezervationItem> &mlist)
{
    this->Content()->clear();

    for( const auto& item : mlist )
    {
        this->Content()->addWidget(cpp14::make_unique<WText>(item.tarih()));
        this->Content()->addWidget(cpp14::make_unique<WBreak>());
    }
}
