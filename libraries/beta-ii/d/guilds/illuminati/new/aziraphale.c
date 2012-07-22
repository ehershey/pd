//Aziraphale

#include <std.h>
#include <guild.h>
inherit ROOM;
void create() 
{
::create();
set_properties(([ "light" : 2, "indoors" : 1]));
set_short("Azira's Room");
set_long("You are standing on a cloud high in the sky. The majestic panorama "
"surrounds you, stretching all the way to the horizon. A white arch leads back "
"to the Tower.");
set_smell("default", "Fresh air fills your senses.");
set_listen("default", "A light wind brushes against your face.");
set_exits(([ 
"out" :  ROOMS"illuminati/new/floor5.c",
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
       tp->move_player(ROOMS"illuminati/new/chambermon.c");
       write("\n\n%^BOLD%^%^WHITE%^You drift thourgh the clouds...%^RESET%^");
       return 1;
       }
    return 0;
}
