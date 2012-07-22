//Made using Room generator by Nightshade

#include <std.h>
#include <aciri.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Archmage's Domain");
    set_properties( (["light" : 3, "night light" : 2]) );
    set_property("town", 1);
    set_property("no teleport", 1);
    set_listen("default", "%^BOLD%^%^RED%^The crackling of a fire can be heard.%^RESET%^");
    set_long("The inside of this building is pretty plain.  The tiled ground has a carpet on it "
          "with shimmering fabrics and a few neon coloured stains.  A fireplace has been crafted "
          "out of red stone and placed in the north corner of the room, it's fire raging.  To the "
          "east, there is a table with many little trinkets on it.");
    set_exits( (["out" : ROOMS+"fortofaciri25.c",
             "northeast" : ROOMS+"fortofaciri67.c",
             "north" : ROOMS+"fortofaciri66.c",
             "east" : ROOMS+"fortofaciri69.c",
             
              ]) );
    set_items( ([ "fireplace" : "The fireplace is made of red rocks.",
                 "carpet" : "Stains of many different colours litter the carpet.",
                 ]) );
}

