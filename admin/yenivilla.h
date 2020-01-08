#ifndef YENIVILLA_H
#define YENIVILLA_H

#include "eCore/containerwiget.h"
#include "villa/villa.h"
#include "eCore/db.h"

class YeniVilla : public ContainerWidget , public VillaItem
{
public:
    explicit YeniVilla(eCore::DB* _db);


    Signal<NoClass> &ClickBack();

private:
    Signal<NoClass> _ClickBack;

    WContainerWidget* mFotoContainerWidget;
    WContainerWidget* ekFotoContainer;

    WLineEdit* villaNameLineEdit;
    WSpinBox* villaKisiSayisiSpinBox;
    WLineEdit* villaKonumLineEdit;
    WComboBox* havuzComboBox;
    WTextEdit* aciklamaTextEdit;

    QVector<QString> ekFotoList;
    eCore::DB* mDB;
};

#endif // YENIVILLA_H
