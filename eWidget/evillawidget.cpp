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
