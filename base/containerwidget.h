#ifndef CONTAINERWIDGET_H
#define CONTAINERWIDGET_H

#include "wtinclude.h"
#include "bootstrap.h"
#include "inlinestyle.h"
#include "mongoheaders.h"

#include <QFileInfo>
#include <QFile>
#include <QDir>

class ContainerWidget : public WContainerWidget
{
public:
    ContainerWidget();

    enum class ContainerType{
        ROW,
        CONTAINERFLUID
    };

    void setContainerType(ContainerType type);

    void setRandomBackGroundColor(int beginColor = 150 , int endColor = 255 , double alpha = 1.0);

    void showMessage( std::string title , std::string msg , std::string btnText = "OK");
    void showMessage( std::string title , std::string msg , bsoncxx::exception &e , Wt::Icon icon = Icon::Warning);
    void showMessage( std::string title , std::string msg , mongocxx::exception &e , Wt::Icon icon = Icon::Warning);


private:

    int getRandomRGB(int beginColor = 0 , int endColor = 0);
};

#endif // CONTAINERWIDGET_H
