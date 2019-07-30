#include "loginwidget.h"

LoginWidget::LoginWidget(mongocxx::database *_db)
    :DBClass (_db)
{
//    addWidget(cpp14::make_unique<WText>("Login Widget"));


    auto mContainer = addWidget(cpp14::make_unique<WContainerWidget>());
    mContainer->addStyleClass(Bootstrap::Grid::container_fluid);

    auto rContainer = mContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    rContainer->addStyleClass(Bootstrap::Grid::row);


    auto contentContainer = rContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    contentContainer->addStyleClass(Bootstrap::Grid::col_full_12);
    contentContainer->setMargin(100,Side::Top|Side::Bottom);
    contentContainer->setContentAlignment(AlignmentFlag::Center);

    auto wContainer = contentContainer->addWidget(cpp14::make_unique<WContainerWidget>());
    wContainer->addStyleClass(Bootstrap::Grid::container_fluid);
    wContainer->setHeight(250);
    wContainer->setMaximumSize(600,WLength::Auto);
    wContainer->addStyleClass(Bootstrap::ImageShape::img_thumbnail);
    wContainer->setWidth(600);
    wContainer->setAttributeValue(Style::style,Style::background::color::rgb(this->getRandom(127),this->getRandom(127),this->getRandom(127)));



    auto layout = wContainer->setLayout(cpp14::make_unique<WVBoxLayout>());
    layout->addStretch(1);




    {
        auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        mUserNameLineEdit = container->addWidget(cpp14::make_unique<WLineEdit>());
        mUserNameLineEdit->setPlaceholderText("Kullanıcı Adını Giriniz");
    }

    {
        auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        mPasswordLineEdit = container->addWidget(cpp14::make_unique<WLineEdit>());
        mPasswordLineEdit->setPlaceholderText("Şifrenizi Giriniz");
        mPasswordLineEdit->setEchoMode(EchoMode::Password);
    }

    {
        auto container = layout->addWidget(cpp14::make_unique<WContainerWidget>());
        container->addStyleClass(Bootstrap::Grid::col_full_12);
        container->setContentAlignment(AlignmentFlag::Center);
        auto backBtn = container->addWidget(cpp14::make_unique<WPushButton>("Giriş"));
        backBtn->addStyleClass(Bootstrap::Button::Primary);
        backBtn->clicked().connect([=](){


            auto filter = document{};

            try {
                filter.append(kvp("username",mUserNameLineEdit->text().toUTF8()));
            } catch (bsoncxx::exception &e) {

            }

            try {
                filter.append(kvp("password",mPasswordLineEdit->text().toUTF8()));
            } catch (bsoncxx::exception &e) {

            }


           _LoginSucces.emit(NoClass());
        });
    }

    layout->addStretch(1);


}

Signal<NoClass> &LoginWidget::ClickMainMenu()
{
    return _ClickMainMenu;
}

Signal<NoClass> &LoginWidget::LoginSucces()
{
    return _LoginSucces;
}
