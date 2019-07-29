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


    try {
        mClient = new mongocxx::client(mongocxx::uri(_url));
    } catch (mongocxx::exception &e) {
        con << e.what();
    }



    db = mClient->database("EKSite");



    try {
        auto ins = this->db.collection("villa").insert_one(make_document(kvp("sd",23)).view());

        con << ins.value().result().inserted_count();

    } catch (mongocxx::exception &e) {
        con << e.what();
    }



    con << "QUERY DATABASE";
    try {
        auto cursor = this->db.collection("villa").find(document{}.view());


        for( auto doc : cursor )
        {
            qDebug() << bsoncxx::to_json(doc).c_str() << "dd";
        }

    } catch (mongocxx::exception &e) {

    }

    con << "QUERY DATABASE ENDED";



    Wt::WApplication *app = Wt::WApplication::instance();
    app->setLoadingIndicator(std::make_unique<WOverlayLoadingIndicator>());
    app->loadingIndicator()->setMessage("Yükleniyor...");


    p_wtTheme = std::make_shared<Wt::WBootstrapTheme>();

    p_wtTheme->setVersion(Wt::WBootstrapTheme::Version::v3);

    p_wtTheme.get()->setResponsive(true);

    Wt::WApplication::instance()->setTheme(p_wtTheme);


    WApplication::instance()->addMetaHeader("viewport","width=device-width, initial-scale=1.0");



    root()->setContentAlignment(AlignmentFlag::Center);


    root()->addWidget(cpp14::make_unique<Header>());
    root()->addWidget(cpp14::make_unique<Body>(&db));
    root()->addWidget(cpp14::make_unique<Footer>());








}

MainApplication::~MainApplication()
{

}
