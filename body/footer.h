#ifndef FOOTER_H
#define FOOTER_H

#include "wtinclude.h"

using namespace Wt;

class Footer : public WContainerWidget
{
public:
    Footer();

    Signal<NoClass> &ClickAdmin();

private:
    WContainerWidget* mMenuWidgets;

    Signal<NoClass> _ClickAdmin;
};

#endif // FOOTER_H
