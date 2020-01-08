#include "yenivilla.h"

YeniVilla::YeniVilla(eCore::DB *_db)
    :ContainerWidget ("Yeni Villa Ekle"),
      mDB(_db)
{

    Content ()->setContentAlignment (AlignmentFlag::Center);

    {
        auto container = Content ()->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::col_full_12);
        container->setContentAlignment (AlignmentFlag::Center);
        container->setMargin (25,Side::Top|Side::Bottom);

        mFotoContainerWidget = container->addWidget (cpp14::make_unique<WContainerWidget>());
        mFotoContainerWidget->setWidth (250);
        mFotoContainerWidget->setHeight (150);
        mFotoContainerWidget->addStyleClass (Bootstrap::ImageShape::img_thumbnail);
        mFotoContainerWidget->setMinimumSize (250,150);
        container->addWidget (cpp14::make_unique<WBreak>());
        container->addWidget (cpp14::make_unique<WText>("Villa Başlık Resmi"));

    }


    {
        auto container = Content ()->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::col_full_12);
        container->setContentAlignment (AlignmentFlag::Center);
        auto uploaderContainer = container->addWidget (cpp14::make_unique<FileUploaderWidget>("Resim Yükle"));
        uploaderContainer->setType (FileUploaderWidget::Image);
        uploaderContainer->Uploaded ().connect ([=](){
            mFotoContainerWidget->setAttributeValue (Style::style,Style::background::url (uploaderContainer->doocRootLocation ().toStdString ())+
                                                     Style::background::size::contain+
                                                     Style::background::position::center_center+
                                                     Style::background::repeat::norepeat);
            mFotoContainerWidget->setWidth (250);
            mFotoContainerWidget->setHeight (150);
            mFotoContainerWidget->setMinimumSize (250,150);

        });
    }


    auto contentContainer = Content()->addWidget (cpp14::make_unique<WContainerWidget>());
    contentContainer->addStyleClass (Bootstrap::Grid::container_fluid);
    contentContainer->setContentAlignment (AlignmentFlag::Center);

    auto rContainer = contentContainer->addWidget (cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass (Bootstrap::Grid::row);
    rContainer->setMaximumSize (1024,WLength::Auto);
    rContainer->addStyleClass (Bootstrap::ContextualBackGround::bg_info);


    {
        auto container = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::col_full_12);
        container->setContentAlignment (AlignmentFlag::Center);
        villaNameLineEdit = container->addWidget (cpp14::make_unique<WLineEdit>());
        villaNameLineEdit->setPlaceholderText ("Villa Adını Giriniz");
    }

    {
        auto container = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::Large::col_lg_3+
                                  Bootstrap::Grid::Medium::col_md_3+
                                  Bootstrap::Grid::Small::col_sm_3+
                                  Bootstrap::Grid::ExtraSmall::col_xs_3);
        auto vLayout = container->setLayout (cpp14::make_unique<WVBoxLayout>());
        auto villaKisiSayisiLabel = vLayout->addWidget (cpp14::make_unique<WLabel>("Kişi Sayısı"),0,AlignmentFlag::Middle|AlignmentFlag::Center);
    }

    {
        auto container = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::Large::col_lg_9+
                                  Bootstrap::Grid::Medium::col_md_9+
                                  Bootstrap::Grid::Small::col_sm_9+
                                  Bootstrap::Grid::ExtraSmall::col_xs_9);
        villaKisiSayisiSpinBox = container->addWidget (cpp14::make_unique<WSpinBox>());
    }


    {
        auto container = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::col_full_12);
        villaKonumLineEdit = container->addWidget (cpp14::make_unique<WLineEdit>());
        villaKonumLineEdit->setPlaceholderText ("Villa Konumunu Giriniz");
    }


    //HAVUZ CONTAINER
    {
        auto container = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::Large::col_lg_3+
                                  Bootstrap::Grid::Medium::col_md_3+
                                  Bootstrap::Grid::Small::col_sm_3+
                                  Bootstrap::Grid::ExtraSmall::col_xs_3);
        auto vLayout = container->setLayout (cpp14::make_unique<WVBoxLayout>());
        vLayout->addWidget (cpp14::make_unique<WLabel>("Havuz"),0,AlignmentFlag::Middle|AlignmentFlag::Center);
    }

    {
        auto container = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::Large::col_lg_9+
                                  Bootstrap::Grid::Medium::col_md_9+
                                  Bootstrap::Grid::Small::col_sm_9+
                                  Bootstrap::Grid::ExtraSmall::col_xs_9);
        havuzComboBox = container->addWidget (cpp14::make_unique<WComboBox>());
        havuzComboBox->addItem ("Havuzlu");
        havuzComboBox->addItem ("Ortak Havuzlu");
        havuzComboBox->addItem ("Yok");
    }

    {
        auto container = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::col_full_12);
        aciklamaTextEdit = container->addWidget (cpp14::make_unique<WTextEdit>());
        aciklamaTextEdit->setHeight (350);
    }


    //FOTOĞRAFLAR
    {
        auto container = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::col_full_12);
        container->addStyleClass (Bootstrap::ImageShape::img_thumbnail);

        auto _rContainer = container->addWidget (cpp14::make_unique<WContainerWidget>());
        _rContainer->addStyleClass (Bootstrap::Grid::container_fluid);

        ekFotoContainer = _rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
        ekFotoContainer->addStyleClass (Bootstrap::Grid::row);


    }


    {
        auto container = Footer ()->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::col_full_12);
        container->setContentAlignment (AlignmentFlag::Center);
        auto uploaderContainer = container->addWidget (cpp14::make_unique<FileUploaderWidget>("Resim Yükle"));
        uploaderContainer->setType (FileUploaderWidget::Image);
        uploaderContainer->Uploaded ().connect ([=](){

            auto FotoContainer = ekFotoContainer->addWidget (cpp14::make_unique<WContainerWidget>());
            FotoContainer->addStyleClass (Bootstrap::Grid::Large::col_lg_2+
                                          Bootstrap::Grid::Medium::col_md_2+
                                          Bootstrap::Grid::Small::col_sm_3+
                                          Bootstrap::Grid::ExtraSmall::col_xs_4);
            FotoContainer->addStyleClass (Bootstrap::ImageShape::img_thumbnail);

            FotoContainer->setAttributeValue (Style::style,Style::background::url (uploaderContainer->doocRootLocation ().toStdString ())+
                                                     Style::background::size::cover+
                                                     Style::background::position::center_center+
                                                     Style::background::repeat::norepeat);
            FotoContainer->setHeight (100);
            FotoContainer->setMinimumSize (WLength::Auto,100);
            FotoContainer->setPositionScheme (PositionScheme::Relative);
            FotoContainer->setAttributeValue (Style::userdata1,std::to_string (ekFotoList.size ()));
            auto delText = FotoContainer->addWidget (cpp14::make_unique<WText>("<b>X</b>",TextFormat::UnsafeXHTML));
            delText->addStyleClass (Bootstrap::Label::Danger);
            delText->setPositionScheme (PositionScheme::Absolute);
            delText->setOffsets (0,Side::Top|Side::Right);
            delText->decorationStyle ().setCursor (Cursor::PointingHand);

            ekFotoList.push_back (uploaderContainer->fileLocation ());

            delText->clicked ().connect ([=](){

                auto yDialog = askConfirm ("Silmek istediğinize Emin misiniz?");

                yDialog->clicked ().connect ([=](){


                    auto index = std::stoi (FotoContainer->attributeValue (Style::userdata1).toUTF8 ());

                    if( ekFotoList.size () > index )
                    {
                        ekFotoList.removeAt (index);
                        ekFotoContainer->removeWidget(FotoContainer);
                    }else{
                        this->showPopUpMessage ("Silinemedi","hata");
                    }
                });

            });

        });
    }

    {
        auto container = Footer ()->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::col_full_12);
        container->setContentAlignment (AlignmentFlag::Center);
        auto svBtn = container->addWidget (cpp14::make_unique<WPushButton>("Kaydet"));
        svBtn->addStyleClass (Bootstrap::Button::Primary);

        svBtn->clicked ().connect ([=](){
            this->setAdi (villaNameLineEdit->text ().toUTF8 ());
            this->setYeri (villaKonumLineEdit->text ().toUTF8 ());
            this->setKisiSayisi (villaKisiSayisiSpinBox->value ());
            this->setHavuz (havuzComboBox->currentText ().toUTF8 ());
            this->setTanim (aciklamaTextEdit->text ().toUTF8 ());
            this->setYayinda (false);
            for( auto fotoItem : ekFotoList )
            {
                auto val = this->mDB->uploadfile (fotoItem);
                this->addFotoList (val.get_oid ().value);
            }
            mDB->insertItem (*this);
            _ClickBack.emit (NoClass());
        });



    }


}

Signal<NoClass> &YeniVilla::ClickBack()
{

    return _ClickBack;

}
