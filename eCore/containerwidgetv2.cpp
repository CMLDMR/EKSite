#include "containerwidgetv2.h"
#include <random>

#include <QString>


eCore::ContainerWidget::ContainerWidget()
    :WContainerWidget()
{
    addStyleClass(Bootstrap::Grid::container_fluid);

    mHeader = addWidget(cpp14::make_unique<WContainerWidget>());
    mHeader->addStyleClass(Bootstrap::Grid::row);

    mContent = addWidget(cpp14::make_unique<WContainerWidget>());
    mContent->addStyleClass(Bootstrap::Grid::row);

    mFooter = addWidget(cpp14::make_unique<WContainerWidget>());
    mFooter->addStyleClass(Bootstrap::Grid::row);

}

WContainerWidget *eCore::ContainerWidget::Header()
{
    return mHeader;
}

WContainerWidget *eCore::ContainerWidget::Content()
{
    return mContent;
}

WContainerWidget *eCore::ContainerWidget::Footer()
{
    return mFooter;
}

void eCore::ContainerWidget::setRandomBackGroundColor(int beginColor, int endColor, double alpha)
{
    auto StyleString = QString::fromStdString(this->attributeValue(Style::style).toUTF8());


    if( StyleString.contains("background") ){

        int firstIndex = StyleString.indexOf("background");

        int firstIndexAfter = StyleString.indexOf(";",firstIndex);

        StyleString.remove(firstIndex,firstIndexAfter-firstIndex);

        setAttributeValue(Style::style,StyleString.toStdString()+Style::background::color::rgba(this->getRandomRGB(beginColor,endColor)
                                                                                 ,this->getRandomRGB(beginColor,endColor)
                                                                                 ,this->getRandomRGB(beginColor,endColor)
                                                                                 ,alpha));

    }else{
        setAttributeValue(Style::style,StyleString.toStdString()+Style::background::color::rgba(this->getRandomRGB(beginColor,endColor)
                                                                                 ,this->getRandomRGB(beginColor,endColor)
                                                                                 ,this->getRandomRGB(beginColor,endColor)
                                                                                 ,alpha));
    }
    StyleString = QString::fromStdString(this->attributeValue(Style::style).toUTF8());
}

void eCore::ContainerWidget::showMessage(std::string title, std::string msg, std::string btnText, Icon icon)
{
    auto messageBox = this->addChild(
                   Wt::cpp14::make_unique<Wt::WMessageBox>
                   (title,
                    msg,
                    icon, StandardButton::Ok));
       if( btnText != "Tamam" )
       {
           auto btn = messageBox->button(StandardButton::Ok);
           btn->setText(btnText);
       }


           messageBox->buttonClicked().connect([=] {
               this->removeChild(messageBox);
           });

           messageBox->show();
}



int eCore::ContainerWidget::getRandomRGB(int beginColor, int endColor)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist( beginColor , endColor );
    return dist(rd);
}
