#include "yenivilla.h"

YeniVilla::YeniVilla()
    :ContainerWidget ("Yeni Villa Ekle")
{

    Content ()->setContentAlignment (AlignmentFlag::Center);

    {
        auto container = Content ()->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::col_full_12);
        container->setContentAlignment (AlignmentFlag::Center);
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


    {
        auto container = Content ()->addWidget (cpp14::make_unique<WContainerWidget>());
        container->addStyleClass (Bootstrap::Grid::col_full_12);
        container->setContentAlignment (AlignmentFlag::Center);

        auto rContainer = container->addWidget (cpp14::make_unique<WContainerWidget>());
        rContainer->addStyleClass (Bootstrap::Grid::row);
        rContainer->setMaximumSize (1024,WLength::Auto);
        rContainer->addStyleClass ("boxShadow boxRadius");


        {
            auto itemContainer = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
            itemContainer->addStyleClass (Bootstrap::Grid::Large::col_lg_2+
                                          Bootstrap::Grid::Medium::col_md_2+
                                          Bootstrap::Grid::Small::col_sm_3+
                                          Bootstrap::Grid::ExtraSmall::col_xs_3);
            auto hLayout = itemContainer->setLayout (cpp14::make_unique<WHBoxLayout>());
            auto titleText = hLayout->addWidget (cpp14::make_unique<WText>("<h5>Villa Adı</h5>",TextFormat::UnsafeXHTML),1,AlignmentFlag::Justify);
            titleText->addStyleClass (Bootstrap::Label::info);
            titleText->setWidth (WLength("100%"));
        }

        {
            auto itemContainer = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
            itemContainer->addStyleClass (Bootstrap::Grid::Large::col_lg_10+
                                             Bootstrap::Grid::Medium::col_md_10+
                                             Bootstrap::Grid::Small::col_sm_9+
                                             Bootstrap::Grid::ExtraSmall::col_xs_9);
            auto villaAdiLineEdit = itemContainer->addWidget (cpp14::make_unique<WLineEdit>());
            villaAdiLineEdit->setPlaceholderText ("Yeni Villa Adını Giriniz");
            villaAdiLineEdit->setHeight (58);

        }


        {
            auto itemContainer = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
            itemContainer->addStyleClass (Bootstrap::Grid::Large::col_lg_2+
                                          Bootstrap::Grid::Medium::col_md_2+
                                          Bootstrap::Grid::Small::col_sm_3+
                                          Bootstrap::Grid::ExtraSmall::col_xs_3);
            auto hLayout = itemContainer->setLayout (cpp14::make_unique<WHBoxLayout>());
            auto titleText = hLayout->addWidget (cpp14::make_unique<WText>("<h5>Villa Yeri</h5>",TextFormat::UnsafeXHTML),1,AlignmentFlag::Justify);
            titleText->addStyleClass (Bootstrap::Label::info);
            titleText->setWidth (WLength("100%"));
        }

        {
            auto itemContainer = rContainer->addWidget (cpp14::make_unique<WContainerWidget>());
            itemContainer->addStyleClass (Bootstrap::Grid::Large::col_lg_10+
                                             Bootstrap::Grid::Medium::col_md_10+
                                             Bootstrap::Grid::Small::col_sm_9+
                                             Bootstrap::Grid::ExtraSmall::col_xs_9);
            auto villaYeriLineEdit = itemContainer->addWidget (cpp14::make_unique<WLineEdit>());
            villaYeriLineEdit->setPlaceholderText ("Villa Konumunu Giriniz");
            villaYeriLineEdit->setHeight (58);

        }
    }


}
