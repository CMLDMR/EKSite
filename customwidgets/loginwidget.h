#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include "wtinclude.h"

#include <base/dbclass.h>


class LoginWidget : public WContainerWidget , public DBClass
{
public:
    LoginWidget(mongocxx::database* _db);


    Signal<NoClass> &ClickMainMenu();

    Signal<NoClass> &LoginSucces();

private:

    Signal<NoClass> _ClickMainMenu;

    Signal<NoClass> _LoginSucces;


    WLineEdit* mUserNameLineEdit;
    WLineEdit* mPasswordLineEdit;
};

#endif // LOGINWIDGET_H
