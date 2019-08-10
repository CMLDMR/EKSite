#include "rezervationdialog.h"
#include <QDate>
RezervationDialog::RezervationDialog(mongocxx::database *_db)
    :DBClass (_db)
{
    setClosable(true);

    this->setWindowTitle("Rezerve Yap");
    titleBar()->addStyleClass(Bootstrap::ContextualBackGround::bg_primary);



    contents()->setContentAlignment(AlignmentFlag::Center);
    auto rContainer = contents()->addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::row);
    rContainer->setWidth(WLength("100%"));


    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setAttributeValue(Style::style,Style::background::color::rgba(150,160,170));
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setMargin(5,Side::Top|Side::Bottom);
        mBeginJulianDateText = container->addWidget(cpp14::make_unique<WText>(WString("Başlangıç Tarihi: {1}").arg(QDate::currentDate().toString().toStdString())));
    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setAttributeValue(Style::style,Style::background::color::rgba(150,160,170));
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setMargin(5,Side::Top|Side::Bottom);
        mEndJulianDateText = container->addWidget(cpp14::make_unique<WText>(WString("Bitiş Tarihi: {1}").arg(QDate::currentDate().toString().toStdString())));
    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setAttributeValue(Style::style,Style::background::color::rgba(150,160,170));
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setMargin(5,Side::Top|Side::Bottom);
        mTotalJulianDateText = container->addWidget(cpp14::make_unique<WText>(WString("Toplam Gün: {1}").arg(QDate::currentDate().toString().toStdString())));
    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setAttributeValue(Style::style,Style::background::color::rgba(150,160,170));
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setMargin(5,Side::Top|Side::Bottom);
        mKisiSayisiText = container->addWidget(cpp14::make_unique<WText>(WString("Toplam {1} Kişi").arg(QDate::currentDate().toString().toStdString())));
    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setAttributeValue(Style::style,Style::background::color::rgba(150,160,170));
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setMargin(5,Side::Top|Side::Bottom);
        mTelefonNumarasiLineEdit = container->addWidget(cpp14::make_unique<WLineEdit>());
        mTelefonNumarasiLineEdit->setPlaceholderText("Telefon Numarası Giriniz (Zorunlu)");
    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setAttributeValue(Style::style,Style::background::color::rgba(150,160,170));
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setMargin(5,Side::Top|Side::Bottom);
        mAdSoyadLineEdit = container->addWidget(cpp14::make_unique<WLineEdit>());
        mAdSoyadLineEdit->setPlaceholderText("Ad Soyad Giriniz (Zorunlu)");
    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setAttributeValue(Style::style,Style::background::color::rgba(150,160,170));
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setMargin(5,Side::Top|Side::Bottom);
        mEmailLineEdit = container->addWidget(cpp14::make_unique<WLineEdit>());
        mEmailLineEdit->setPlaceholderText("e-Mail Giriniz (İsteğe Bağlı)");
    }


    {
        auto container = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
        container->setAttributeValue(Style::style,Style::background::color::rgba(150,160,170));
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setMargin(5,Side::Top|Side::Bottom);
        container->addWidget(cpp14::make_unique<WText>(WString("<h6>Dikkat Villaya En Erken Giriş Saati Öğleden Sonra 14:00 - En Geç Çıkış Saati Sabah 10:00'dur</h6>")));
    }


    {
        auto svBtn = this->footer()->addWidget(cpp14::make_unique<WPushButton>("Kaydet"));
        svBtn->addStyleClass(Bootstrap::Button::Primary);
        svBtn->clicked().connect(this,&RezervationDialog::Save);
    }

    {
        auto svBtn = this->footer()->addWidget(cpp14::make_unique<WPushButton>("Kapat"));
        svBtn->addStyleClass(Bootstrap::Button::Default);
        svBtn->clicked().connect([=](){
            wApp->instance()->root()->removeChild(this);
        });
    }


}

std::int64_t RezervationDialog::beginJulianDate() const
{
    return mBeginJulianDate;
}

void RezervationDialog::setBeginJulianDate(const std::int64_t &beginJulianDate)
{
    mBeginJulianDate = beginJulianDate;
    mBeginJulianDateText->setText(WString("Başlangıç Tarihi: {1}").arg(QDate::fromJulianDay(mBeginJulianDate).toString("dddd dd/MM/yyyy").toStdString()));

    mTotalJulianDateText->setText(WString("Toplam: {1} Gün").arg(mEndJulianDate - mBeginJulianDate));

}

std::int64_t RezervationDialog::endJulianDate() const
{
    return mEndJulianDate;
}

void RezervationDialog::setEndJulianDate(const std::int64_t &endJulianDate)
{
    mEndJulianDate = endJulianDate;
    mEndJulianDateText->setText(WString("Bitiş Tarihi: {1}").arg(QDate::fromJulianDay(mEndJulianDate).toString("dddd dd/MM/yyyy").toStdString()));
    mTotalJulianDateText->setText(WString("Toplam: {1} Gün").arg(mEndJulianDate - mBeginJulianDate));

}

int RezervationDialog::kisiSayisi() const
{
    return mKisiSayisi;
}

void RezervationDialog::setKisiSayisi(int kisiSayisi)
{
    mKisiSayisi = kisiSayisi;
    mKisiSayisiText->setText(WString("Toplam: {1} Kişi").arg(mKisiSayisi));

}

void RezervationDialog::Save()
{
    wApp->instance()->root()->removeChild(this);
}
