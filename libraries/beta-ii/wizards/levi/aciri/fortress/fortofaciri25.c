//Made using Room generator by Nightshade

#include <std.h>
#include <aciri.h>
inherit ROOM;

void create() {
    ::create();
    set_short("The Impregnable Fortress of Aciri");
    set_properties( (["light" : 3, "night light" : 2]) );
    set_property("town", 1);
    set_listen("default", "A dull humming is audible.");
    set_long("The entrance to a small building can be seen directly east of here.  The roof, more visible from "
         "this position, appears to be expertly shingled with precisely cut pieces of bark.  No chimney can be "
         "seen from here but smoke is visible.  Further down north, the street seems to be a dead end. Far beyond "
         "it's walls, mountains can be seen, surrounding a shining blue and red pillar.  The pillar appears to be "
         "a leafless tree, shifting supernaturally.  Part of a valley is visible behind the northern wall.  A massive "
         "set of stairs ascends into the mountains.");
    set_exits( (["enter" : ROOMS+"fortofaciri68.c"
             ,"south" : ROOMS+"fortofaciri3.c"
             ,"north" : ROOMS+"fortofaciri26.c"
              ]) );
    set_items( ([ "pillar" : "Blue and red shifting lights cover the pillar."
                 ,"building" : "Quite a small, nice building in this fortress. It's shingles have been geniusly constructed to reject rain."
                 ]) );
}

void reset() {
  ::reset();
    if(!present("soldier")) 
      new(MOB "soldier.c")->move(this_object());
}
