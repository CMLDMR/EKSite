#include "mainapplication.h"
#include <Wt/WOverlayLoadingIndicator.h>
#include "body.h"
#include "header.h"
#include "footer.h"
#include "../url.h"

MainApplication::MainApplication(const Wt::WEnvironment &env)
    :WApplication(env)
{
    wApp->addMetaHeader(MetaHeaderType::Meta,"Content-Type","text/html; charset=utf-8");

    wApp->addMetaHeader("description","ERK Realty Show","text/html; charset=utf-8");


    mClient = new mongocxx::client(mongocxx::uri(_url));


    db = mClient->database("db");



    Wt::WApplication *app = Wt::WApplication::instance();
    app->setLoadingIndicator(std::make_unique<WOverlayLoadingIndicator>());
    app->loadingIndicator()->setMessage("Yükleniyor...");


//    p_wtTheme = std::make_shared<Wt::WBootstrapTheme>();

//    p_wtTheme->setVersion(Wt::WBootstrapTheme::Version::v3);

//    p_wtTheme.get()->setResponsive(true);

//    Wt::WApplication::instance()->setTheme(p_wtTheme);


    WApplication::instance()->addMetaHeader("viewport","width=device-width, initial-scale=1.0");



    root()->setContentAlignment(AlignmentFlag::Center);


    root()->addWidget(cpp14::make_unique<Header>());
    root()->addWidget(cpp14::make_unique<Body>(&db));
    root()->addWidget(cpp14::make_unique<Footer>());








}

MainApplication::~MainApplication()
{

}
