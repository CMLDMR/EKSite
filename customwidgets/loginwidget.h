#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include "wtinclude.h"

#include <base/dbclass.h>


class LoginWidget : public WContainerWidget , public DBClass
{
public:
    LoginWidget(mongocxx::database* _db);


    Signal<NoClass> &ClickMainMenu();

private:

    Signal<NoClass> _ClickMainMenu;
};

#endif // LOGINWIDGET_H
