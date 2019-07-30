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

    void setRandomBackGroundColor(int beginColor = 150 , int endColor = 255);


private:

    int getRandomRGB(int beginColor = 0 , int endColor = 0);
};

#endif // CONTAINERWIDGET_H
