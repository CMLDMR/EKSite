#include "body.h"
#include "ilancontainer.h"
#include "customwidgets/slider.h"
#include "customwidgets/reservationwidget.h"
#include "customwidgets/loginwidget.h"
#include "customwidgets/placethumpnails.h"
#include "admin/adminpanel.h"
#include "customwidgets/villagethumpnails.h"
#include "customwidgets/villadetailpage.h"

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
//    addWidget(cpp14::make_unique<PlaceThumpnails>(this->db()));
    addWidget(cpp14::make_unique<VillaPage>(this->db()))->ClickVilla().connect(this,&Body::initVillaDetail);
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

void Body::initVillaDetail(const std::string &villaOid)
{
    clear();
    addWidget(cpp14::make_unique<VillaDetailPage>(this->db() ,villaOid));
}
