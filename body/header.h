#ifndef HEADER_H
#define HEADER_H

#include "wtinclude.h"

using namespace Wt;

class Header : public WContainerWidget
{
public:
    Header();

private:
    WContainerWidget* mMenuWidgets;

};

#endif // HEADER_H
