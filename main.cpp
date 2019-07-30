#include "mainapplication.h"
#include <mongocxx/instance.hpp>

#include <QApplication>

///https://www.flaticon.com/packs/essential-collection
/// https://codepen.io/asfarmed/pen/cfslr

//erkksbc
//<erkksbc/>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    WString::setDefaultEncoding(Wt::CharEncoding::UTF8);

    mongocxx::instance ins{};

    return Wt::WRun(argc,argv,[](const Wt::WEnvironment &env){
        return Wt::cpp14::make_unique<MainApplication>(env);
    });

//    try {
//      int argc = 5;
//      auto argv1 = std::unique_ptr<char*[]>(new char*[argc]);

//      argv1[0] = (char *) "multiple";
//      argv1[1] = (char *) "--http-address=127.0.0.1";
//      argv1[2] = (char *) "--http-port=80";
//      argv1[3] = (char *) "--deploy-path=/";
//      argv1[4] = (char *) "--docroot=docroot";

//      WServer server1(argc, argv1.get(), WTHTTP_CONFIGURATION);

//      auto argv2 = std::unique_ptr<char*[]>(new char*[argc]);

//      argv2[0] = (char *) "multiple";
//      argv2[1] = (char *) "--http-address=127.0.0.1";
//      argv2[2] = (char *) "--http-port=80";
//      argv2[3] = (char *) "--deploy-path=/admin";
//      argv2[4] = (char *) "--docroot=docroot";

//      WServer server2(argc, argv2.get(), WTHTTP_CONFIGURATION);

//      server1.addEntryPoint(EntryPointType::Application, [](const Wt::WEnvironment &env){
//                  return Wt::cpp14::make_unique<MainApplication>(env);
//              });

//      server2.addEntryPoint(EntryPointType::Application, [](const Wt::WEnvironment &env){
//                  return Wt::cpp14::make_unique<MainApplication>(env);
//              });
////      server2.addEntryPoint(EntryPointType::Application, createApplication);

//      if (server1.start()) {
//        if (server2.start()) {
//                WServer::waitForShutdown();
//                server2.stop();
//        }
//                server1.stop();
//      }
//    } catch (WServer::Exception& e) {
//      std::cerr << e.what() << std::endl;
//    } catch (std::exception &e) {
//      std::cerr << "exception: " << e.what() << std::endl;
//    }




}
