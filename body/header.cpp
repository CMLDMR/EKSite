#include "header.h"

HeaderPage::HeaderPage()
{
    setWidth(WLength("100%"));
    this->Header()->setContentAlignment(AlignmentFlag::Center);
    this->Header()->setHeight(WLength(100));
    this->Header()->setAttributeValue(Style::style,Style::background::color::color(Style::color::Grey::Black));
}


