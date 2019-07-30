#include "body.h"
#include "ilancontainer.h"
#include "customwidgets/slider.h"
#include "customwidgets/reservationwidget.h"
#include "customwidgets/loginwidget.h"

Body::Body(mongocxx::database *_db)
    :DBClass (_db)
{
    setContentAlignment(AlignmentFlag::Center);
    this->initMain();
}

void Body::initMain()
{
    clear();
    {
        auto container = addWidget(cpp14::make_unique<WContainerWidget>());
        container->setHeight(400);
        container->setMargin(0,Side::Top);
        container->setWidth(WLength("100%"));
        container->addWidget(cpp14::make_unique<Slider>());
        container->setPadding(0,AllSides);
    }


    auto container = addWidget(cpp14::make_unique<WContainerWidget>());
    container->setMaximumSize(1024,WLength::Auto);

    container->addStyleClass(Bootstrap::Grid::container_fluid);

    auto rContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::row);

    {
        auto rrContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        rrContainer->addStyleClass(Bootstrap::Grid::Large::col_lg_6+Bootstrap::Grid::Medium::col_md_6+Bootstrap::Grid::Small::col_sm_6+Bootstrap::Grid::ExtraSmall::col_xs_12);
//            rrContainer->setHeight(400);
        auto _rezervationContaner = rrContainer->addWidget(cpp14::make_unique<ReservationWidget>(this->db()));
    }


    for( int i = 0 ; i < 12 ; i++ )
    {
        auto ilan = rContainer->addWidget(cpp14::make_unique<IlanContainer>());
        ilan->addStyleClass(Bootstrap::Grid::Large::col_lg_3+Bootstrap::Grid::Medium::col_md_3+Bootstrap::Grid::Small::col_sm_4+Bootstrap::Grid::ExtraSmall::col_xs_6);
    }
}

void Body::initLogin()
{
    clear();
    addWidget(cpp14::make_unique<LoginWidget>(this->db()))->LoginSucces().connect(this,&Body::initAdminPanel);
}

void Body::initAdminPanel()
{
    clear();
}
