#include "villaaddpage.h"

#include "base/villaitem.h"

VillaAddPage::VillaAddPage(mongocxx::database *_db)
    :DBClass (_db)
{


    Coll = this->collection("villa");
    setContainerType(ContainerType::CONTAINERFLUID);
    auto rContainer = addWidget(cpp14::make_unique<ContainerWidget>());
    rContainer->setContainerType(ContainerType::ROW);

    {

        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setRandomBackGroundColor(25,35);
        container->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        container->setMargin(15,Side::Top|Side::Bottom);

        auto mVillaAdiLineEdit = container->addWidget(cpp14::make_unique<WText>("Villa Bilgileri"));
        mVillaAdiLineEdit->setAttributeValue(Style::style,Style::font::size::s18px+Style::font::weight::bold+Style::color::color(Style::color::White::Snow));

    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                 +Bootstrap::Grid::Medium::col_md_6
                                 +Bootstrap::Grid::Small::col_sm_6
                                 +Bootstrap::Grid::ExtraSmall::col_xs_12);

        container->setMargin(5,Side::Top|Side::Bottom);


        mVillaAdiLineEdit = container->addWidget(cpp14::make_unique<WLineEdit>());
        mVillaAdiLineEdit->setPlaceholderText("Villa Adını Giriniz");
    }


    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                 +Bootstrap::Grid::Medium::col_md_6
                                 +Bootstrap::Grid::Small::col_sm_6
                                 +Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->setMargin(5,Side::Top|Side::Bottom);

        mVillaKonumuLineEdit = container->addWidget(cpp14::make_unique<WLineEdit>());
        mVillaKonumuLineEdit->setPlaceholderText("Villa Konumunu Giriniz");
    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                 +Bootstrap::Grid::Medium::col_md_6
                                 +Bootstrap::Grid::Small::col_sm_6
                                 +Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->setMargin(5,Side::Top|Side::Bottom);

        mKisiAdetComboBox = container->addWidget(cpp14::make_unique<WComboBox>());

        for( int  i = 1 ; i <= 15 ; i++ )
        {
            mKisiAdetComboBox->addItem(WString("{1} Kişi").arg(i));
        }
    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                 +Bootstrap::Grid::Medium::col_md_6
                                 +Bootstrap::Grid::Small::col_sm_6
                                 +Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->setMargin(5,Side::Top|Side::Bottom);

        mHavuzComboBox = container->addWidget(cpp14::make_unique<WComboBox>());


        mHavuzComboBox->addItem(WString("Havuzlu"));
        mHavuzComboBox->addItem(WString("Ortak Havuzlu"));
        mHavuzComboBox->addItem(WString("Havuzsuz"));

    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                 +Bootstrap::Grid::Medium::col_md_6
                                 +Bootstrap::Grid::Small::col_sm_6
                                 +Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->setMargin(5,Side::Top|Side::Bottom);

        mIlComboBox = container->addWidget(cpp14::make_unique<WComboBox>());


        mIlComboBox->addItem(WString("Antalya"));
    }
    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::Large::col_lg_6
                                 +Bootstrap::Grid::Medium::col_md_6
                                 +Bootstrap::Grid::Small::col_sm_6
                                 +Bootstrap::Grid::ExtraSmall::col_xs_12);
        container->setMargin(5,Side::Top|Side::Bottom);

        mIlceComboBox = container->addWidget(cpp14::make_unique<WComboBox>());


        mIlceComboBox->addItem(WString("Serik"));
    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass( Bootstrap::Grid::col_full_12 );
        container->setMargin( 5 , Side::Top|Side::Bottom );

        mVillaYayinda = container->addWidget(cpp14::make_unique<WCheckBox>("Yayında"));
    }


    {
        mFotoContainer = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        mFotoContainer->addStyleClass(Bootstrap::Grid::col_full_12);
        mFotoContainer->setContentAlignment(AlignmentFlag::Center);
    }

    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);

        container->setMargin(5,Side::Top|Side::Bottom);

        //        auto aciklamaLineEdit = container->addWidget(cpp14::make_unique<WLineEdit>());
        //        aciklamaLineEdit->setPlaceholderText("Açıklama Ekleyiniz");
        //        aciklamaLineEdit->addStyleClass(Bootstrap::Grid::col_full_12);

        auto fileUploaderContainer = container->addWidget(cpp14::make_unique<WContainerWidget>());
        fileUploaderContainer->setAttributeValue(Style::style,Style::background::color::rgba(this->getRandom(150,170),this->getRandom(170,190),this->getRandom(200,220)));
        fileUploaderContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
        fileUploaderContainer->setMargin(10,Side::Top|Side::Bottom);

        mFileUploader = fileUploaderContainer->addWidget(cpp14::make_unique<WFileUpload>());
        auto progresBar = fileUploaderContainer->addWidget(cpp14::make_unique<WProgressBar>());
        mFileUploader->setFileTextSize(6000); // Set the maximum file size to 2048 kB.
        mFileUploader->setMargin(10, Wt::Side::Right);
        mFileUploader->setFilters("image/*");
        mFileUploader->setMultiple(false);
        mFileUploader->setProgressBar(progresBar);

        mFileUploader->fileTooLarge().connect([=] {
            std::cout << mFileUploader->fileTextSize() << std::endl;
            this->showMessage("Hata",WString("Dosya Boyutu Fazla Büyük. Max: 6MB Olmalı. Dosyanız {1}MB").arg(mFileUploader->fileTextSize()).toUTF8());
        });

        Wt::WPushButton *uploadButton = fileUploaderContainer->addWidget(Wt::cpp14::make_unique<Wt::WPushButton>("Resmi Yükle"));
        uploadButton->setMargin(10, Wt::Side::Left | Wt::Side::Right);

        uploadButton->clicked().connect([=](){

            mFileUploader->upload();
            mFileUploader->enable();
            mFileUploader->setHidden(false);



        });


        mFileUploader->uploaded().connect([=] {


            QDir dir;

            if( dir.exists("docroot") )
            {
                if( dir.cd("docroot") ){
                    dir.mkdir("tempfile");
                }
            }else{
                if( dir.mkdir("docroot") ){
                    if( dir.cd("docroot") )
                    {
                        dir.mkdir("tempfile");
                    }
                }
            }

            auto list = mFileUploader->uploadedFiles();

            for( auto item : list )
            {
                QFileInfo fileinfo(item.clientFileName().c_str());
                QString _fileName = QString("%1.%2").arg(QUuid::createUuid().toString()).arg(fileinfo.suffix().toStdString().c_str());
                auto rootnewFileName = QString("docroot/tempfile/")+_fileName;
                QString newFileName = QString("tempfile/")+ _fileName;

                if( QFile::copy(item.spoolFileName().c_str(),rootnewFileName) )
                {
                    QImage img;
                    bool _mSuccess = false;
                    if( img.load(rootnewFileName) )
                    {
                        img = img.scaled(960,520,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
                        if( img.save(rootnewFileName,"JPG",75) )
                        {
                            _mSuccess = true;
                        }else{
                            this->showMessage("Hata","Dosya Kayıt Edilemedi");
                        }
                    }else{
                        this->showMessage("Hata","Dosya Açılamadı");
                    }

                    if( _mSuccess )
                    {
                        fileList.push_back(rootnewFileName.toStdString());

                        auto fContainer = mFotoContainer->addWidget(cpp14::make_unique<WContainerWidget>());
                        fContainer->decorationStyle().setBorder(WBorder(BorderStyle::Solid,1,WColor(150,150,150,125)),AllSides);
                        fContainer->setMargin(5,AllSides);
                        fContainer->setWidth(160);
                        fContainer->setHeight(90);
                        fContainer->setMinimumSize(160,90);
                        fContainer->setMaximumSize(160,90);
                        //                            fContainer->setId("fCOntainer");
                        fContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
                        fContainer->setAttributeValue(Style::style,Style::background::url(newFileName.toStdString())
                                                      +Style::background::size::cover
                                                      +Style::background::repeat::norepeat
                                                      +Style::background::position::center_center);
                        fContainer->setAttributeValue(Style::dataoid,rootnewFileName.toStdString());
                        fContainer->setPadding(0,AllSides);

                        auto cContainer = fContainer->addWidget(cpp14::make_unique<ContainerWidget>());
                        cContainer->setWidth(WLength("100%"));

                        cContainer->setMargin(0,AllSides);
                        cContainer->setHeight(20);
                        cContainer->setMaximumSize(WLength::Auto,20);
                        cContainer->setRandomBackGroundColor(50,75,0.75);
                        cContainer->setContentAlignment(AlignmentFlag::Justify|AlignmentFlag::Bottom);
                        auto text = cContainer->addWidget(cpp14::make_unique<WText>("Sil"));
                        text->setAttributeValue(Style::style,Style::font::size::s14px+Style::color::color(Style::color::White::Snow)+Style::font::weight::bold);
                        cContainer->decorationStyle().setCursor(Cursor::PointingHand);
                        cContainer->clicked().connect([=](){
                            for (int i = 0 ; i < fileList.size() ; i++ ) {
                                if( fileList.at(i) == fContainer->attributeValue(Style::dataoid).toUTF8() )
                                {
                                    fileList.removeAt(i);
                                    break;
                                }
                            }
                            mFotoContainer->removeWidget(fContainer);
                        });
                    }else{
                        this->showMessage("Uyarı","Resim Yüklenemedi");
                    }
                }else{
                    this->showMessage("Uyarı","Resim Yüklenemedi");
                }
            }
        });
    }


    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->setContentAlignment(AlignmentFlag::Justify);
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setMargin(10,AllSides);

        mVillaAciklama = container->addWidget(cpp14::make_unique<WTextEdit>());
        mVillaAciklama->setHeight(350);

    }


    {
        auto container = rContainer->addWidget(cpp14::make_unique<ContainerWidget>());
        container->setContentAlignment(AlignmentFlag::Center);
        container->addStyleClass(Bootstrap::Grid::col_full_12);

        auto saveBtn = container->addWidget(cpp14::make_unique<WPushButton>("Kaydet"));
        saveBtn->addStyleClass(Bootstrap::Button::Primary);

        saveBtn->clicked().connect(this,&VillaAddPage::SaveVilla);

    }

}

void VillaAddPage::LoadVilla(const std::string &villaOid)
{

    auto villaItem = VillaItem::Load_Villa(Coll,bsoncxx::oid{villaOid});

    mVillaAdiLineEdit->setText(villaItem.villaName());


}

void VillaAddPage::SaveVilla()
{
    auto villaItem = VillaItem::Create_EmptyVilla(Coll);

    villaItem.setVillaKisiAdet(mKisiAdetComboBox->currentIndex()+1);
    villaItem.setVillaName(mVillaAdiLineEdit->text().toUTF8());
    villaItem.setVillaIlce(mIlceComboBox->currentText().toUTF8());
    villaItem.setVillaIl(mIlComboBox->currentText().toUTF8());
    villaItem.setVillaKonum(mVillaKonumuLineEdit->text().toUTF8());
    villaItem.setVillaHavuz(mHavuzComboBox->currentText().toUTF8());
    villaItem.setVillaAciklama(mVillaAciklama->text().toUTF8());
    villaItem.setVillaYayinda(mVillaYayinda->isChecked());

    for( auto item : fileList )
    {
        auto val = this->uploadfile(item.c_str());
        villaItem.appendImgOid(val);
    }


}
