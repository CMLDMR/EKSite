#include "mainapplication.h"
#include <Wt/WOverlayLoadingIndicator.h>
#include "body.h"
#include "header.h"
#include "footer.h"
#include "../url.h"
#include <mongocxx/pool.hpp>

MainApplication::MainApplication(const Wt::WEnvironment &env)
    :WApplication(env)
{
    wApp->addMetaHeader(MetaHeaderType::Meta,"Content-Type","text/html; charset=utf-8");

    wApp->addMetaHeader("description","ERK Realty Show","text/html; charset=utf-8");


    con << "COnnection";
    try {
        mClient = new mongocxx::client(mongocxx::uri(_url));
    } catch (mongocxx::exception &e) {
        con << e.what();
    }



















    Wt::WApplication *app = Wt::WApplication::instance();
    app->setLoadingIndicator(std::make_unique<WOverlayLoadingIndicator>());
    app->loadingIndicator()->setMessage("Yükleniyor...");


    con << "BootStrap Theme";
    p_wtTheme = std::make_shared<Wt::WBootstrapTheme>();

    p_wtTheme->setVersion(Wt::WBootstrapTheme::Version::v3);

    p_wtTheme.get()->setResponsive(true);

    con << "Set Theme";
    Wt::WApplication::instance()->setTheme(p_wtTheme);


    con << "Add MetaHEader";
    WApplication::instance()->addMetaHeader("viewport","width=device-width, initial-scale=1.0");



    con << "Content Aligment";

    root()->setContentAlignment(AlignmentFlag::Center);








    con << "get DB";
    db = mClient->database("EKSite");
//    db = client->database("EKSite");



//    try {
//        auto ins = this->db.collection("villa").insert_one(make_document(kvp("sd",23)).view());

//        con << ins.value().result().inserted_count();

//    } catch (mongocxx::exception &e) {
//        con << e.what();
//    }




    con << "QUERY DATABASE";
    try {
        auto cursor = this->db.collection("villa").find_one(document{}.view());
    } catch (mongocxx::exception &e) {

    }
    con << "QUERY DATABASE ENDED";






    con << "header";
    auto header = root()->addWidget(cpp14::make_unique<Header>());
    auto body = root()->addWidget(cpp14::make_unique<Body>(&db));
    auto footer = root()->addWidget(cpp14::make_unique<Footer>());


    footer->ClickAdmin().connect(body,&Body::initLogin);






    con << "end of main";

}

MainApplication::~MainApplication()
{

}
