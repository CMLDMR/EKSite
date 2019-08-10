#ifndef REZERVATIONDIALOG_H
#define REZERVATIONDIALOG_H

#include "base/dbclass.h"
#include "base/containerwidget.h"

class RezervationDialog : public WDialog , public DBClass
{
public:
    RezervationDialog(mongocxx::database* _db);


    std::int64_t beginJulianDate() const;
    void setBeginJulianDate(const std::int64_t &beginJulianDate);

    std::int64_t endJulianDate() const;
    void setEndJulianDate(const std::int64_t &endJulianDate);

    int kisiSayisi() const;
    void setKisiSayisi(int kisiSayisi);

private:
    std::int64_t mBeginJulianDate;
    std::int64_t mEndJulianDate;
    int mKisiSayisi;

    WText* mBeginJulianDateText;
    WText* mEndJulianDateText;
    WText* mTotalJulianDateText;
    WLineEdit* mTelefonNumarasiLineEdit;
    WLineEdit* mAdSoyadLineEdit;
    WLineEdit* mEmailLineEdit;
    WText* mKisiSayisiText;

    void Save();

};

#endif // REZERVATIONDIALOG_H
