#ifndef VILLAADDPAGE_H
#define VILLAADDPAGE_H

#include "base/containerwidget.h"
#include "base/dbclass.h"

class VillaAddPage : public ContainerWidget , public DBClass
{
public:
    VillaAddPage(mongocxx::database* _db);

private:
    WFileUpload* mFileUploader;
    WContainerWidget* mFotoContainer;



    QVector<std::string> fileList;
};

#endif // VILLAADDPAGE_H
