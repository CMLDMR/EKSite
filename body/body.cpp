#include "body.h"

#include "customwidgets/slider.h"
#include "customwidgets/reservationwidget.h"
#include "customwidgets/loginwidget.h"
#include "customwidgets/placethumpnails.h"
#include "admin/adminpanel.h"
#include "customwidgets/villagethumpnails.h"
#include "customwidgets/villadetailpage.h"

#include "eCore/villamanager.h"

Body::Body(DB *_db)
    :eCore::ContainerWidget(),
     eCore::DB(_db)
{
    setContentAlignment(AlignmentFlag::Center);
    setMaximumSize(WLength(1280),WLength::Auto);
    this->initMain();
}

void Body::initMain()
{
//    addWidget(cpp14::make_unique<Slider>());
//    addWidget(cpp14::make_unique<PlaceThumpnails>(this->db()));
//    this->Content()->addWidget(cpp14::make_unique<VillaPage>(this->db()))->ClickVilla().connect(this,&Body::initVillaDetail);

    this->Content()->addWidget(cpp14::make_unique<eCore::VillaManager>(this->getDB()));
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
