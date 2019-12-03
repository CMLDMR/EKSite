#ifndef CONTAINERWIDGETV2_H
#define CONTAINERWIDGETV2_H


#include "wtinclude.h"
#include "bootstrap.h"
#include "inlinestyle.h"


namespace eCore {

class ContainerWidgetV2 : public WContainerWidget
{
public:
    ContainerWidgetV2();


    WContainerWidget *Header() ;

    WContainerWidget *Content() ;

    WContainerWidget *Footer() ;

    void setRandomBackGroundColor(int beginColor = 150 , int endColor = 255 , double alpha = 1.0);




    void showMessage( std::string title , std::string msg , std::string btnText = "Tamam" , Wt::Icon icon = Icon::Warning);

    void init();


private:
    WContainerWidget* mHeader;
    WContainerWidget* mContent;
    WContainerWidget* mFooter;

    int getRandomRGB(int beginColor = 0 , int endColor = 255);


};

}









#endif // CONTAINERWIDGET_H
