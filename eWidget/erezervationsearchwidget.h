#ifndef EREZERVATIONSEARCHWIDGET_H
#define EREZERVATIONSEARCHWIDGET_H
#include "eCore/containerwiget.h"
namespace eWidget{

class eRezervationSearchWidget : public ContainerWidget
{
public:
    eRezervationSearchWidget();
};



class eRezervationCalenderWidget : public ContainerWidget
{
public:
    eRezervationCalenderWidget( const std::string villaOid );
};


class eRezervationMakeWidget : public ContainerWidget
{
public:
    eRezervationMakeWidget( const std::string& villaOid );
};

}

#endif // EREZERVATIONSEARCHWIDGET_H
