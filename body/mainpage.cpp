#include "mainpage.h"

MainPage::MainPage(eCore::DB *_db)
    :eCore::DB(_db)
{

    Header ()->addWidget (cpp14::make_unique<WText>("Test"));

    this->showPopUpMessage ("Test Mesajı","msg");
}
