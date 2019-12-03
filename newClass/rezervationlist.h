#ifndef REZERVATIONLIST_H
#define REZERVATIONLIST_H


class RezervationList : public eCore::ContainerWidget , public eCore::ListItem<RezervationItem>
{
public:
    RezervationList();
};

#endif // REZERVATIONLIST_H
