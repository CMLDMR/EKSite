#ifndef BOOTSTRAP_H
#define BOOTSTRAP_H


#include <string.h>
#include <iostream>



#define TEST    QFile::exists("TEST")


namespace Bootstrap {

namespace jumbotron {
    static const std::string jumbotron {"jumbotron "};
}

namespace ImageShape {
static const std::string img_rounded{"img-rounded "};
static const std::string img_circle{"img-circle "};
static const std::string img_thumbnail{"img-thumbnail "};
}

namespace ContextualBackGround {
static const std::string bg_primary{"bg-primary "};
static const std::string bg_success{"bg-success "};
static const std::string bg_info{"bg-info "};
static const std::string bg_warning{"bg-warning "};
static const std::string bg_danger{"bg-danger "};
}

namespace Grid {
    static const std::string container {"container "};
    static const std::string container_fluid {"container-fluid "};
    static const std::string row {"row "};
    static const std::string col_full_12{"col-xs-12 col-sm-12 col-md-12 col-lg-12 "};
    namespace ExtraSmall {
        static const std::string col_xs_1 {"col-xs-1 "};//
        static const std::string col_xs_2 {"col-xs-2 "};//
        static const std::string col_xs_3 {"col-xs-3 "};//
        static const std::string col_xs_4 {"col-xs-4 "};//
        static const std::string col_xs_5 {"col-xs-5 "};//
        static const std::string col_xs_6 {"col-xs-6 "};//
        static const std::string col_xs_7 {"col-xs-7 "};//
        static const std::string col_xs_8 {"col-xs-8 "};//
        static const std::string col_xs_9 {"col-xs-9 "};//
        static const std::string col_xs_10 {"col-xs-10 "};//
        static const std::string col_xs_11 {"col-xs-11 "};//
        static const std::string col_xs_12 {"col-xs-12 "};//
    }

    namespace Small {
        static const std::string col_sm_1 {"col-sm-1 "};//
        static const std::string col_sm_2 {"col-sm-2 "};//
        static const std::string col_sm_3 {"col-sm-3 "};//
        static const std::string col_sm_4 {"col-sm-4 "};//
        static const std::string col_sm_5 {"col-sm-5 "};//
        static const std::string col_sm_6 {"col-sm-6 "};//
        static const std::string col_sm_7 {"col-sm-7 "};//
        static const std::string col_sm_8 {"col-sm-8 "};//
        static const std::string col_sm_9 {"col-sm-9 "};//
        static const std::string col_sm_10 {"col-sm-10 "};//
        static const std::string col_sm_11 {"col-sm-11 "};//
        static const std::string col_sm_12 {"col-sm-12 "};//
    }

    namespace Medium {
        static const std::string col_md_1 {"col-md-1 "};//
        static const std::string col_md_2 {"col-md-2 "};//
        static const std::string col_md_3 {"col-md-3 "};//
        static const std::string col_md_4 {"col-md-4 "};//
        static const std::string col_md_5 {"col-md-5 "};//
        static const std::string col_md_6 {"col-md-6 "};//
        static const std::string col_md_7 {"col-md-7 "};//
        static const std::string col_md_8 {"col-md-8 "};//
        static const std::string col_md_9 {"col-md-9 "};//
        static const std::string col_md_10 {"col-md-10 "};//
        static const std::string col_md_11 {"col-md-11 "};//
        static const std::string col_md_12 {"col-md-12 "};//
    }

    namespace Large {
        static const std::string col_lg_1 {"col-lg-1 "};//
        static const std::string col_lg_2 {"col-lg-2 "};//
        static const std::string col_lg_3 {"col-lg-3 "};//
        static const std::string col_lg_4 {"col-lg-4 "};//
        static const std::string col_lg_5 {"col-lg-5 "};//
        static const std::string col_lg_6 {"col-lg-6 "};//
        static const std::string col_lg_7 {"col-lg-7 "};//
        static const std::string col_lg_8 {"col-lg-8 "};//
        static const std::string col_lg_9 {"col-lg-9 "};//
        static const std::string col_lg_10 {"col-lg-10 "};//
        static const std::string col_lg_11 {"col-lg-11 "};//
        static const std::string col_lg_12 {"col-lg-12 "};//
    }

    namespace Visible {
        static const std::string visible_xs {"visible-xs "}; //shown only on an EXTRA SYUSLL screen
        static const std::string visible_sm {"visible-sm "}; //shown only on a SYUSLL screen
        static const std::string visible_md {"visible-md "}; //shown only on a MEDIUM screen
        static const std::string visible_lg {"visible-lg "}; //shown only on a LARGE screen
    }

    namespace Hidden {
        static const std::string hidden_xs {"hidden-xs "}; // hidden on an EXTRA SYUSLL screen
        static const std::string hidden_sm {"hidden-sm "}; // hidden on a SYUSLL screen
        static const std::string hidden_md {"hidden-md "}; // hidden on a MEDIUM screen
        static const std::string hidden_lg {"hidden-lg "}; // hidden on a LARGE screen
    }

    namespace Offset {
        namespace ExtraSmall {
            static const std::string col_xs_1 {"col-xs-offset-1 "};//
            static const std::string col_xs_2 {"col-xs-offset-2 "};//
            static const std::string col_xs_3 {"col-xs-offset-3 "};//
            static const std::string col_xs_4 {"col-xs-offset-4 "};//
            static const std::string col_xs_5 {"col-xs-offset-5 "};//
            static const std::string col_xs_6 {"col-xs-offset-6 "};//
            static const std::string col_xs_7 {"col-xs-offset-7 "};//
            static const std::string col_xs_8 {"col-xs-offset-8 "};//
            static const std::string col_xs_9 {"col-xs-offset-9 "};//
            static const std::string col_xs_10 {"col-xs-offset-10 "};//
            static const std::string col_xs_11 {"col-xs-offset-11 "};//
            static const std::string col_xs_12 {"col-xs-offset-12 "};//
        }

        namespace Small {
            static const std::string col_sm_1 {"col-sm-offset-1 "};//
            static const std::string col_sm_2 {"col-sm-offset-2 "};//
            static const std::string col_sm_3 {"col-sm-offset-3 "};//
            static const std::string col_sm_4 {"col-sm-offset-4 "};//
            static const std::string col_sm_5 {"col-sm-offset-5 "};//
            static const std::string col_sm_6 {"col-sm-offset-6 "};//
            static const std::string col_sm_7 {"col-sm-offset-7 "};//
            static const std::string col_sm_8 {"col-sm-offset-8 "};//
            static const std::string col_sm_9 {"col-sm-offset-9 "};//
            static const std::string col_sm_10 {"col-sm-offset-10 "};//
            static const std::string col_sm_11 {"col-sm-offset-11 "};//
            static const std::string col_sm_12 {"col-sm-offset-12 "};//
        }

        namespace Medium {
            static const std::string col_md_1 {"col-md-offset-1 "};//
            static const std::string col_md_2 {"col-md-offset-2 "};//
            static const std::string col_md_3 {"col-md-offset-3 "};//
            static const std::string col_md_4 {"col-md-offset-4 "};//
            static const std::string col_md_5 {"col-md-offset-5 "};//
            static const std::string col_md_6 {"col-md-offset-6 "};//
            static const std::string col_md_7 {"col-md-offset-7 "};//
            static const std::string col_md_8 {"col-md-offset-8 "};//
            static const std::string col_md_9 {"col-md-offset-9 "};//
            static const std::string col_md_10 {"col-md-offset-10 "};//
            static const std::string col_md_11 {"col-md-offset-11 "};//
            static const std::string col_md_12 {"col-md-offset-12 "};//
        }

        namespace Large {
            static const std::string col_lg_1 {"col-lg-offset-1 "};//
            static const std::string col_lg_2 {"col-lg-offset-2 "};//
            static const std::string col_lg_3 {"col-lg-offset-3 "};//
            static const std::string col_lg_4 {"col-lg-offset-4 "};//
            static const std::string col_lg_5 {"col-lg-offset-5 "};//
            static const std::string col_lg_6 {"col-lg-offset-6 "};//
            static const std::string col_lg_7 {"col-lg-offset-7 "};//
            static const std::string col_lg_8 {"col-lg-offset-8 "};//
            static const std::string col_lg_9 {"col-lg-offset-9 "};//
            static const std::string col_lg_10 {"col-lg-offset-10 "};//
            static const std::string col_lg_11 {"col-lg-offset-11 "};//
            static const std::string col_lg_12 {"col-lg-offset-12 "};//
        }
    }

    namespace Push {
        namespace ExtraSmall {
        static const std::string col_xs_1 {"col-xs-push-1 "};//
        static const std::string col_xs_2 {"col-xs-push-2 "};//
        static const std::string col_xs_3 {"col-xs-push-3 "};//
        static const std::string col_xs_4 {"col-xs-push-4 "};//
        static const std::string col_xs_5 {"col-xs-push-5 "};//
        static const std::string col_xs_6 {"col-xs-push-6 "};//
        static const std::string col_xs_7 {"col-xs-push-7 "};//
        static const std::string col_xs_8 {"col-xs-push-8 "};//
        static const std::string col_xs_9 {"col-xs-push-9 "};//
        static const std::string col_xs_10 {"col-xs-push-10 "};//
        static const std::string col_xs_11 {"col-xs-push-11 "};//
        static const std::string col_xs_12 {"col-xs-push-12 "};//
        }

        namespace Small {
        static const std::string col_sm_1 {"col-sm-push-1 "};//
        static const std::string col_sm_2 {"col-sm-push-2 "};//
        static const std::string col_sm_3 {"col-sm-push-3 "};//
        static const std::string col_sm_4 {"col-sm-push-4 "};//
        static const std::string col_sm_5 {"col-sm-push-5 "};//
        static const std::string col_sm_6 {"col-sm-push-6 "};//
        static const std::string col_sm_7 {"col-sm-push-7 "};//
        static const std::string col_sm_8 {"col-sm-push-8 "};//
        static const std::string col_sm_9 {"col-sm-push-9 "};//
        static const std::string col_sm_10 {"col-sm-push-10 "};//
        static const std::string col_sm_11 {"col-sm-push-11 "};//
        static const std::string col_sm_12 {"col-sm-push-12 "};//
        }

        namespace Medium {
        static const std::string col_md_1 {"col-md-push-1 "};//
        static const std::string col_md_2 {"col-md-push-2 "};//
        static const std::string col_md_3 {"col-md-push-3 "};//
        static const std::string col_md_4 {"col-md-push-4 "};//
        static const std::string col_md_5 {"col-md-push-5 "};//
        static const std::string col_md_6 {"col-md-push-6 "};//
        static const std::string col_md_7 {"col-md-push-7 "};//
        static const std::string col_md_8 {"col-md-push-8 "};//
        static const std::string col_md_9 {"col-md-push-9 "};//
        static const std::string col_md_10 {"col-md-push-10 "};//
        static const std::string col_md_11 {"col-md-push-11 "};//
        static const std::string col_md_12 {"col-md-push-12 "};//
        }

        namespace Large {
        static const std::string col_lg_1 {"col-lg-push-1 "};//
        static const std::string col_lg_2 {"col-lg-push-2 "};//
        static const std::string col_lg_3 {"col-lg-push-3 "};//
        static const std::string col_lg_4 {"col-lg-push-4 "};//
        static const std::string col_lg_5 {"col-lg-push-5 "};//
        static const std::string col_lg_6 {"col-lg-push-6 "};//
        static const std::string col_lg_7 {"col-lg-push-7 "};//
        static const std::string col_lg_8 {"col-lg-push-8 "};//
        static const std::string col_lg_9 {"col-lg-push-9 "};//
        static const std::string col_lg_10 {"col-lg-push-10 "};//
        static const std::string col_lg_11 {"col-lg-push-11 "};//
        static const std::string col_lg_12 {"col-lg-push-12 "};//
        }
    }


    namespace Pull {
        namespace ExtraSmall {
        static const std::string col_xs_1 {"col-xs-pull-1 "};//
        static const std::string col_xs_2 {"col-xs-pull-2 "};//
        static const std::string col_xs_3 {"col-xs-pull-3 "};//
        static const std::string col_xs_4 {"col-xs-pull-4 "};//
        static const std::string col_xs_5 {"col-xs-pull-5 "};//
        static const std::string col_xs_6 {"col-xs-pull-6 "};//
        static const std::string col_xs_7 {"col-xs-pull-7 "};//
        static const std::string col_xs_8 {"col-xs-pull-8 "};//
        static const std::string col_xs_9 {"col-xs-pull-9 "};//
        static const std::string col_xs_10 {"col-xs-pull-10 "};//
        static const std::string col_xs_11 {"col-xs-pull-11 "};//
        static const std::string col_xs_12 {"col-xs-pull-12 "};//
        }

        namespace Small {
        static const std::string col_sm_1 {"col-sm-pull-1 "};//
        static const std::string col_sm_2 {"col-sm-pull-2 "};//
        static const std::string col_sm_3 {"col-sm-pull-3 "};//
        static const std::string col_sm_4 {"col-sm-pull-4 "};//
        static const std::string col_sm_5 {"col-sm-pull-5 "};//
        static const std::string col_sm_6 {"col-sm-pull-6 "};//
        static const std::string col_sm_7 {"col-sm-pull-7 "};//
        static const std::string col_sm_8 {"col-sm-pull-8 "};//
        static const std::string col_sm_9 {"col-sm-pull-9 "};//
        static const std::string col_sm_10 {"col-sm-pull-10 "};//
        static const std::string col_sm_11 {"col-sm-pull-11 "};//
        static const std::string col_sm_12 {"col-sm-pull-12 "};//
        }

        namespace Medium {
        static const std::string col_md_1 {"col-md-pull-1 "};//
        static const std::string col_md_2 {"col-md-pull-2 "};//
        static const std::string col_md_3 {"col-md-pull-3 "};//
        static const std::string col_md_4 {"col-md-pull-4 "};//
        static const std::string col_md_5 {"col-md-pull-5 "};//
        static const std::string col_md_6 {"col-md-pull-6 "};//
        static const std::string col_md_7 {"col-md-pull-7 "};//
        static const std::string col_md_8 {"col-md-pull-8 "};//
        static const std::string col_md_9 {"col-md-pull-9 "};//
        static const std::string col_md_10 {"col-md-pull-10 "};//
        static const std::string col_md_11 {"col-md-pull-11 "};//
        static const std::string col_md_12 {"col-md-pull-12 "};//
        }

        namespace Large {
        static const std::string col_lg_1 {"col-lg-pull-1 "};//
        static const std::string col_lg_2 {"col-lg-pull-2 "};//
        static const std::string col_lg_3 {"col-lg-pull-3 "};//
        static const std::string col_lg_4 {"col-lg-pull-4 "};//
        static const std::string col_lg_5 {"col-lg-pull-5 "};//
        static const std::string col_lg_6 {"col-lg-pull-6 "};//
        static const std::string col_lg_7 {"col-lg-pull-7 "};//
        static const std::string col_lg_8 {"col-lg-pull-8 "};//
        static const std::string col_lg_9 {"col-lg-pull-9 "};//
        static const std::string col_lg_10 {"col-lg-pull-10 "};//
        static const std::string col_lg_11 {"col-lg-pull-11 "};//
        static const std::string col_lg_12 {"col-lg-pull-12 "};//
        }
    }
}


    namespace Typography {

        static const std::string lead{"lead "};//                            Make Paragraph stand out
        static const std::string small{"small "};//                          Indicates smaller text (set to 85% of the size of the parent)
        static const std::string text_left{"text-left "};//                  Indicates left-aligned text
        static const std::string text_center{"text-center "};//              Indicates center-aligned text
        static const std::string text_right{"text-right "};//                Indicates right-aligned text
        static const std::string text_justify{"text-justify "};//            Indicates justified text
        static const std::string text_nowrap{"text-nowrap "};//              Indicates no wrap text
        static const std::string text_lowercase{"text-lowercase "};//        Indicates lowercased text
        static const std::string text_uppercase{"text-uppercase "};//        Indicates uppercased text
        static const std::string text_capitalize{"text-capitalize "};//  	Indicates capitalized text
        static const std::string list_unstyled{"list-unstyled "};//          Removes the default list-style and left margin on list items (works on both <ul> and <ol>). This class only applies to immediate children list items (to remove the default list-style from any nested lists, apply this class to any nested lists as well)
        static const std::string initialism{"initialism "};//                Displays the text inside an <abbr> element in a slightly smaller font size
        static const std::string list_inline{"list-inline "};//              Places all list items on a single line
        static const std::string dl_horizontal{"dl-horizontal "};//          Lines up the terms (<dt>) and descriptions (<dd>) in <dl> elements side-by-side. Starts off like default <dl>s, but when the browser window expands, it will line up side-by-side
        static const std::string pre_scrollable{"pre-scrollable "};//        Makes a <pre> element scrollable

    }

    namespace TextDecoration {

        static const std::string none{"decnone "};//                            Make Paragraph stand out
        static const std::string underline{"decunderline "};//                          Indicates smaller text (set to 85% of the size of the parent)
        static const std::string overline{"decoverline "};//                  Indicates left-aligned text
        static const std::string line_through{"decline-through "};//              Indicates center-aligned text
        static const std::string initial{"decinitial "};//                Indicates right-aligned text
        static const std::string inherit{"decinherit "};//            Indicates justified text
    }


    namespace Badges {
        static std::string badget(std::string str){return std::string{"<span class=\"badge\">"+str+"</span>"};};
        static std::string badget(std::string str, std::string value){return str+std::string{" <span class=\"badge\">"+value+"</span>"};};
        static std::string badget(std::string str, std::string color , std::string value){return str+std::string{" <span class=\"badge " + color +"\">"+value+"</span>"};};
        namespace Color {
        static const std::string primary{"badge-primary"};
        static const std::string secondary{"badge-secondary"};
        static const std::string success{"badge-success"};
        static const std::string danger{"badge-danger"};
        static const std::string warning{"badge-warning"};
        static const std::string info{"badge-info"};
        static const std::string light{"badge-light"};
        static const std::string dark{"badge-dark"};
        }
    }

    namespace Label {
    static std::string Default{"label label-default "};
    static std::string Primary{"label label-primary "};
    static std::string Success{"label label-success "};
    static std::string info{"label label-info "};
    static std::string Warning{"label label-warning "};
    static std::string Danger{"label label-danger "};
    }

    namespace Button {
    static std::string Default{"btn-default "};
    static std::string Primary{"btn-primary "};
    static std::string Success{"btn-success "};
    static std::string info{"btn-info "};
    static std::string Warning{"btn-warning "};
    static std::string Danger{"btn-danger "};
    static std::string Link{"btn-link "};
    }




    namespace Test {

        static const std::string border1px {"border1px "};//
        static const std::string maxWidth150{"maxWidth150 "};
        static const std::string font16px{"font16px "};

        namespace Padding
        {
            static const std::string Padding10px{"Padding10px "};
        }

        namespace Margin
        {
            static const std::string margin10px{"margin10px "};
        }



        namespace Shadow
        {
            static const std::string boxshadow2p2p4pGray{"boxshadow2p2p4pGray "};
        }

        namespace Color {
            static const std::string red {"red "};//
            static const std::string orange {"orange "};//
            static const std::string blue {"blue "};//
            static const std::string pink {"pink "};//
            static const std::string green {"green "};//
            static const std::string white {"white "};//
            static const std::string lavender {"lavender "};//
        }

        namespace Display {
            static const std::string block {"displayBlock "};//
        }
    }
}

#endif // BOOTSTRAP_H
