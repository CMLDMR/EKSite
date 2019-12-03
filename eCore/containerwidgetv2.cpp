#include "containerwidgetv2.h"



ContainerWidgetV2::ContainerWidgetV2()
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

WContainerWidget *ContainerWidgetV2::Header()
{
    return mHeader;
}

WContainerWidget *ContainerWidgetV2::Content()
{
    return mContent;
}

WContainerWidget *ContainerWidgetV2::Footer()
{
    return mFooter;
}

void ContainerWidgetV2::showMessage(std::string title, std::string msg, std::string btnText, Icon icon)
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

void ContainerWidgetV2::init()
{

}

