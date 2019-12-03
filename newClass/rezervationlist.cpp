#include "rezervationlist.h"


void RezervationList::onList(const QVector<eCore::RezervationItem> &mlist)
{

    std::cout << "onList: " << std::endl;
//    this->clear();

    for( const auto& item : mlist )
    {
//        this->Content()->addWidget(cpp14::make_unique<WText>(item.oid().value().to_string()));
//        this->Content()->addWidget(cpp14::make_unique<WBreak>());
    }
}
