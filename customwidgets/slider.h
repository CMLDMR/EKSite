#ifndef SLIDER_H
#define SLIDER_H


#include "wtinclude.h"

using namespace Wt;

class SliderItem;

class Slider : public WContainerWidget
{
public:
    Slider();

    void addItem(std::unique_ptr<SliderItem> item);


private:
    WStackedWidget* mStack;
};


class SliderItem : public WContainerWidget
{
public:
    SliderItem(const std::string &imgurl , const std::string &title);
};

#endif // SLIDER_H
