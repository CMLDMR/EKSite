#ifndef RESERVATIONWIDGET_H
#define RESERVATIONWIDGET_H

#include <QObject>
#include "wtinclude.h"

#include "base/dbclass.h"

class ReservationWidget : public WContainerWidget , public DBClass
{
public:
    explicit ReservationWidget(mongocxx::database* _db);


    WContainerWidget* rContainer;
};

#endif // RESERVATIONWIDGET_H
