//Made using Room generator by Nightshade

#include <std.h>
#include <aciri.h>
inherit ROOM;

void create() {
    ::create();
    set_short("%^BOLD%^%^RED%^The Impregnable Fortress of Aciri");
    set_properties( (["light" : 2, "night light" : 1]) );
    set_property("town", 1);
    set_listen("default", "Humming can barely be heard from far away.");
    set_long("A few streets can be seen north of here.  To the south, a couple of pillars form a gate.  The streets are tiled.  What looks to be a large building sits to the northeast.  On the horizon, massive mountains and a shaft of red and blue.");
    set_exits( (["north" : ROOMS+"fortofaciri3.c"
             ,"south" : ROOMS+"fortofaciri1.c"
              ]) );
    set_items( ([ "pillars" : "Two large pillars act as an entrance."
                 ,"shaft" : "A large shaft in the middle of the mountains, rather blurry from here, seems to be red and green but the colours shift back and forth."
                 ,"streets" : "They are tiled.  There are a few of them further in."
                 ,"tiles" : "The tiles are made of various pieces of normal rock."
                 ,"building" : "The building, northeast of here, is pretty plain looking."
                 ,"mountains" : "The mountains are just massive.  They surround the north and link up with the fortress walls, concealing the area in between."
                 ]) );
}

