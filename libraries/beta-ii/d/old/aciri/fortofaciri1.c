//Made using Room generator by Nightshade

#include <std.h>
#include <aciri.h>
inherit ROOM;

void create() {
    ::create();
    set_short("%^BOLD%^%^RED%^The Impregnable Fortress of Aciri");
    set_properties( (["light" : 2, "night light" : 1]) );
    set_property("town", 1);
    set_long("The fortress of Aciri begins here.  Two pillars to the east and west mark the gate entrance.  The path is tiled with stones and the area looks rather spartan.  ");
    set_exits( (["north" : ROOMS+"fortofaciri2.c",
             "south" : ROOMS+"marshfinal.c"
              ]) );
    set_items( ([ "pillars" : "Two large pillars act as an entrance.",
                 "fortress" : "The fortress is large and uninviting.",
                 "path" : "It is tiled.",
                 "tiles" : "The tiles are made of various pieces of normal rock.",
                 "stones" : "large pieces of rock."
                 ]) );
}

