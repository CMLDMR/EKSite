#ifndef MAINPAGE_H
#define MAINPAGE_H


#include "wtinclude.h"
#include <eCore/db.h>
#include <body/mainpage.h>

using namespace Wt;



class MainApplication : public WApplication
{
public:
    explicit MainApplication(const WEnvironment& env);
    ~MainApplication();
    std::shared_ptr<Wt::WBootstrapTheme> p_wtTheme;



    void initConfigration();

    mongocxx::client* mClient;

    mongocxx::database db;

    eCore::DB* mDB;


};

#endif // MAINPAGE_H
