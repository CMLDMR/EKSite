#include "evillawidget.h"


eWidget::eVillaWidget::eVillaWidget( const VillaItem &villaItem )
    :VillaItem (villaItem),
      ContainerWidget (this->adi ())
{

    setMargin (10,Side::Top);
    Content ()->clear();
    Content ()->addWidget (cpp14::make_unique<WText>("<b>"+this->havuz ()+"</b>",TextFormat::UnsafeXHTML));
    Content ()->addWidget (cpp14::make_unique<WBreak>());
    Content ()->addWidget (cpp14::make_unique<WText>(this->yayinda () ? "<b>Yayında</b>" : "Yayında Değil",TextFormat::UnsafeXHTML));
    setAttributeValue (Style::style,Style::background::color::color (Style::color::Purple::Plum));
    addStyleClass ("boxShadow boxRadius");
    decorationStyle ().setCursor (Cursor::PointingHand);
    this->clicked ().connect (this,[=](){
        _clickedVilla.emit (this->oid ().value ());
    });
}

void eWidget::eVillaWidget::errorOccured(const std::string &errorText)
{
    this->showPopUpMessage (errorText,"hata");
}

Signal<bsoncxx::oid> &eWidget::eVillaWidget::ClickedVilla()
{
    return _clickedVilla;
}

eWidget::eVillaThumpWidget::eVillaThumpWidget(const VillaItem &villaItem, eCore::DB *_db)
    :VillaItem (villaItem),
      ContainerWidget (this->adi ()),
      mDB(_db)
{

    auto thumpImg = mDB->downloadFileWeb (this->fotoOid ().c_str ());

    std::cout << "img: "+thumpImg << std::endl;

    Header ()->clear ();
    Header ()->setContentAlignment (AlignmentFlag::Center);
    auto imgContainer = Header ()->addWidget (cpp14::make_unique<ContainerWidget>());
    imgContainer->addStyleClass (Bootstrap::Grid::col_full_12);
    imgContainer->addStyleClass (Bootstrap::ImageShape::img_thumbnail);
    imgContainer->setBackGroundImg (thumpImg);
    imgContainer->setHeight (160);




    Content ()->clear();
    Content ()->addWidget (cpp14::make_unique<WText>("<b>"+this->havuz ()+"</b>",TextFormat::UnsafeXHTML));
    Content ()->addWidget (cpp14::make_unique<WBreak>());
    Content ()->addWidget (cpp14::make_unique<WText>(this->yayinda () ? "<b>Yayında</b>" : "Yayında Değil",TextFormat::UnsafeXHTML));
    setAttributeValue (Style::style,Style::background::color::color (Style::color::Purple::Plum));
    addStyleClass ("boxShadow boxRadius");
    decorationStyle ().setCursor (Cursor::PointingHand);
    this->clicked ().connect (this,[=](){
        _clickedVilla.emit (this->oid ().value ());
    });
}

void eWidget::eVillaThumpWidget::errorOccured(const std::string &errorText)
{
    this->showPopUpMessage (errorText,"hata");
}

Signal<bsoncxx::oid> &eWidget::eVillaThumpWidget::ClickedVilla()
{
    return _clickedVilla;
}
