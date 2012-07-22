//Aziraphale

#include <std.h>
#include <guild.h>
inherit ROOM;
void create() 
{
room::create();
set_properties(([ "light" : 2, "indoors" : 1]));
set_short("Azira's Room");
set_long("%^BOLD%^%^WHITE%^You have found your way to the 'link', the ethereal place "
"%^BOLD%^%^WHITE%^between Heaven and Earth. Here Prator works tirelessly to "
"%^BOLD%^%^WHITE%^restore the realms."); //
set_exits(([ 
"out" :  ROOMS"illuminati/new/aziraphale.c",
]));
}

void init() {
   ::init();
     add_action("chambers", "drift");
}
int chambers() {
    object tp;
    tp = this_player();
    if (tp->query_name() == "prator" || tp->query_name() == "aziraphale" || wizardp(tp)) {
       tp->move_player(ROOMS"illuminati/new/aziraphale.c");
       write("\n\n%^BOLD%^%^WHITE%^You drift thourgh the clouds...%^RESET%^");
       return 1;
       }
    return 0;
}
