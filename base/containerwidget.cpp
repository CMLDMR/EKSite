#include "containerwidget.h"
#include <QString>
#include <random>

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

void ContainerWidget::setRandomBackGroundColor(int beginColor, int endColor)
{
    auto StyleString = QString::fromStdString(this->attributeValue(Style::style).toUTF8());

    std::cout << "STYLE: " << StyleString.toStdString() << std::endl;

    if( StyleString.contains("background") ){

        int firstIndex = StyleString.indexOf("background");

        int firstIndexAfter = StyleString.indexOf(";",firstIndex);

        StyleString.remove(firstIndex,firstIndexAfter-firstIndex);

        setAttributeValue(Style::style,StyleString.toStdString()+Style::background::color::rgb(this->getRandomRGB(beginColor,endColor)
                                                                                 ,this->getRandomRGB(beginColor,endColor)
                                                                                 ,this->getRandomRGB(beginColor,endColor)));

    }else{
        setAttributeValue(Style::style,StyleString.toStdString()+Style::background::color::rgb(this->getRandomRGB(beginColor,endColor)
                                                                                 ,this->getRandomRGB(beginColor,endColor)
                                                                                 ,this->getRandomRGB(beginColor,endColor)));
    }
    StyleString = QString::fromStdString(this->attributeValue(Style::style).toUTF8());

    std::cout << "STYLE ->: " << StyleString.toStdString() << std::endl;

}

int ContainerWidget::getRandomRGB(int beginColor, int endColor)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist( beginColor , endColor );
    return dist(rd);
}
