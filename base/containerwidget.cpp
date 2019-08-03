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

void ContainerWidget::setRandomBackGroundColor(int beginColor, int endColor, double alpha)
{
    auto StyleString = QString::fromStdString(this->attributeValue(Style::style).toUTF8());

//    std::cout << "STYLE: " << StyleString.toStdString() << std::endl;

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

//    std::cout << "STYLE ->: " << StyleString.toStdString() << std::endl;

}

void ContainerWidget::setRandomBackGroundColorRGB(int bRed, int eRed, int bGreen, int eGreen, int bBlue, int eBlue, double alpha)
{
    auto StyleString = QString::fromStdString(this->attributeValue(Style::style).toUTF8());

//    std::cout << "STYLE: " << StyleString.toStdString() << std::endl;

    if( StyleString.contains("background") ){

        int firstIndex = StyleString.indexOf("background");

        int firstIndexAfter = StyleString.indexOf(";",firstIndex);

        StyleString.remove(firstIndex,firstIndexAfter-firstIndex);

        setAttributeValue(Style::style,StyleString.toStdString()+Style::background::color::rgba(this->getRandomRGB(bRed,eRed)
                                                                                 ,this->getRandomRGB(bGreen,eGreen)
                                                                                 ,this->getRandomRGB(bBlue,eBlue)
                                                                                 ,alpha));

    }else{
        setAttributeValue(Style::style,StyleString.toStdString()+Style::background::color::rgba(this->getRandomRGB(bRed,eRed)
                                                                                 ,this->getRandomRGB(bGreen,eGreen)
                                                                                 ,this->getRandomRGB(bBlue,eBlue)
                                                                                 ,alpha));
    }
    StyleString = QString::fromStdString(this->attributeValue(Style::style).toUTF8());
}

void ContainerWidget::showMessage( std::string title, std::string msg, std::string btnText )
{
    auto messageBox = this->addChild(
                   Wt::cpp14::make_unique<Wt::WMessageBox>
                   (title,
                    msg,
                    Wt::Icon::Information, StandardButton::Ok));
       if( btnText != "OK" )
       {
           auto btn = messageBox->button(StandardButton::Ok);
           btn->setText(btnText);
       }


           messageBox->buttonClicked().connect([=] {
               this->removeChild(messageBox);
           });

           messageBox->show();
}

void ContainerWidget::showMessage( std::string title, std::string msg, bsoncxx::exception &e, Icon icon )
{
    auto messageBox = this->addChild(
                Wt::cpp14::make_unique<Wt::WMessageBox>
                (title,
                 WString("{1} : {2}").arg(msg.c_str()).arg(e.what()).toUTF8(),
                 icon, Wt::StandardButton::Ok));

        messageBox->buttonClicked().connect([=] {
            this->removeChild(messageBox);
        });

        messageBox->show();
}


void ContainerWidget::showMessage( std::string title, std::string msg, mongocxx::exception &e, Icon icon )
{
    auto messageBox = this->addChild(
                Wt::cpp14::make_unique<Wt::WMessageBox>
                (title,
                 WString("{1} : {2}").arg(msg.c_str()).arg(e.what()).toUTF8(),
                 icon, Wt::StandardButton::Ok));

        messageBox->buttonClicked().connect([=] {
            this->removeChild(messageBox);
        });

        messageBox->show();
}



int ContainerWidget::getRandomRGB(int beginColor, int endColor)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist( beginColor , endColor );
    return dist(rd);
}
