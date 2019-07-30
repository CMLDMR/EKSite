#include "containerwidget.h"

ContainerWidget::ContainerWidget()
{

}

void ContainerWidget::setContainerType(ContainerWidget::ContainerType type)
{
    switch (type) {

    case ContainerType::ROW:
        addStyleClass(Bootstrap::Grid::row);
        break;

    case ContainerType::CONTAINERFLUID:
        addStyleClass(Bootstrap::Grid::container_fluid);
        break;
    default:

        break;

    }
}
