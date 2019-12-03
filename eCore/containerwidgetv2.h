#ifndef CONTAINERWIDGETV2_H
#define CONTAINERWIDGETV2_H


#include "wtinclude.h"
#include "bootstrap.h"
#include "inlinestyle.h"

class ContainerWidgetV2 : public WContainerWidget
{
public:
    ContainerWidgetV2();


    WContainerWidget *Header() ;

    WContainerWidget *Content() ;

    WContainerWidget *Footer() ;



    void showMessage( std::string title , std::string msg , std::string btnText = "Tamam" , Wt::Icon icon = Icon::Warning);

    void init();


private:
    WContainerWidget* mHeader;
    WContainerWidget* mContent;
    WContainerWidget* mFooter;

};







#endif // CONTAINERWIDGET_H
