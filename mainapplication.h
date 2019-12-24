#ifndef MAINPAGE_H
#define MAINPAGE_H


#include "wtinclude.h"
#include "base/dbclass.h"
#include "eCore/db.h"

using namespace Wt;



class MainApplication : public WApplication
{
public:
    MainApplication(const WEnvironment& env);
    ~MainApplication();
    std::shared_ptr<Wt::WBootstrapTheme> p_wtTheme;



    void initConfigration();

    mongocxx::client* mClient;

    mongocxx::database db;

    eCore::DB* mDB;


};

#endif // MAINPAGE_H
