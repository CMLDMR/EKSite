#include "body.h"
#include "ilancontainer.h"
#include "customwidgets/slider.h"
#include "customwidgets/reservationwidget.h"
#include "customwidgets/loginwidget.h"
#include "admin/adminpanel.h"

Body::Body(mongocxx::database *_db)
    :DBClass (_db)
{
    setContentAlignment(AlignmentFlag::Center);
    this->initMain();
}

void Body::initMain()
{
    clear();

    addWidget(cpp14::make_unique<Slider>());

}

void Body::initLogin()
{
    clear();
    addWidget(cpp14::make_unique<LoginWidget>(this->db()))->LoginSucces().connect(this,&Body::initAdminPanel);
}

void Body::initAdminPanel()
{
    clear();
    addWidget(cpp14::make_unique<AdminPanel>(this->db()));
}
