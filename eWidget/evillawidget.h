#ifndef EVILLAWIDGET_H
#define EVILLAWIDGET_H

#include "eCore/containerwiget.h"
#include "villa/villamanager.h"


namespace eWidget {

    class eVillaWidget : public VillaItem , public ContainerWidget
    {
    public:
        explicit eVillaWidget( const VillaItem& villaItem );

        virtual void errorOccured(const std::string &errorText) override;

        Signal<bsoncxx::oid> &ClickedVilla();

    private:

        Signal<bsoncxx::oid> _clickedVilla;

    };

}


#endif // EVILLAWIDGET_H
