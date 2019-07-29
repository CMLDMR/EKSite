#ifndef HEADER_H
#define HEADER_H

#include "wtinclude.h"

using namespace Wt;

class Header : public WContainerWidget
{
public:
    Header();


    Signal<NoClass> &ClickGiris();

private:
    WContainerWidget* mMenuWidgets;


    Signal<NoClass> _ClickGiris;

};

#endif // HEADER_H
