#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QObject>
#include <QWidget>

#include "base/dbclass.h"
#include "base/containerwidget.h"
#include "base/userclass.h"

class AdminPanel : public ContainerWidget , public DBClass , public UserClass
{
public:
    AdminPanel(mongocxx::database* _db);


    void initMainPage();

    void initVillaPage();

    void initRezervationPage();


private:
    ContainerWidget* rContainer;


};

#endif // ADMINPANEL_H
