#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include "wtinclude.h"
#include "bootstrap.h"
#include "inlinestyle.h"

class ContainerWidget : public WContainerWidget
{
public:
    ContainerWidget();

    enum class ContainerType{
        ROW,
        CONTAINERFLUID
    };

    void setContainerType(ContainerType type);
};

#endif // CONTAINERWIDGET_H
