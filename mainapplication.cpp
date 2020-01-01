#include "mainapplication.h"
#include <Wt/WOverlayLoadingIndicator.h>
#include "../url.h"


#include <eCore/containerwiget.h>
#include <body/mainpage.h>


MainApplication::MainApplication(const Wt::WEnvironment &env)
    :WApplication(env)
{

    try {
        mClient = new mongocxx::client(mongocxx::uri(_url));
    } catch (mongocxx::exception &e) {
        std::cout << "DB Error: " << e.what () << std::endl;
    }

    db = mClient->database("EKSite");
    mDB = new eCore::DB(&db);


    this->initConfigration();
    auto body = root()->addWidget(cpp14::make_unique<ContainerWidget>());

    root ()->addWidget (cpp14::make_unique<MainPage>(mDB));

    body->showPopUpMessage (WString("Test Mesajı").toUTF8 ());

}

MainApplication::~MainApplication()
{

}

void MainApplication::initConfigration()
{

//    wApp->addMetaHeader(MetaHeaderType::Meta,"Content-Type","text/html; charset=utf-8");

    wApp->addMetaHeader("description","ERK Realty Show","text/html; charset=utf-8");

    wApp->addMetaHeader(MetaHeaderType::Meta,"Content-Type","text/html; charset=windows-1254");


//    Wt::WApplication *app = Wt::WApplication::instance();
//    app->setLoadingIndicator(std::make_unique<WOverlayLoadingIndicator>());
//    app->loadingIndicator()->setMessage("Yükleniyor...");




    p_wtTheme = std::make_shared<Wt::WBootstrapTheme>();

    p_wtTheme->setVersion(Wt::WBootstrapTheme::Version::v3);

    p_wtTheme.get()->setResponsive(true);

    Wt::WApplication::instance()->setTheme(p_wtTheme);

    WApplication::instance()->addMetaHeader("viewport","width=device-width, initial-scale=1.0");

    root()->setContentAlignment(AlignmentFlag::Center);

    WApplication::useStyleSheet(WLink("css/mcxx.css"));

}
