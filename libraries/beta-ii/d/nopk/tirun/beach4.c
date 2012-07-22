#include <std.h>
#include <tirun.h>

inherit BEACH;

void create() {
    ::create();
    set_property("no castle", 1);
    set_property("light", 3);
    set_property("beach",1);
    set_max_catch(15);
    set_max_fishing(4);
    set_chance(10);
    set_property("night light", 2);
    set("short", "The Tirun shores");
   set_long("You are walking along the shores of the "
          "Tirun beach. Waves splash up against your "
          "feet. You notice some footprints in the sand.");
   set_items( ([
        "footprints" : "Small footprints lead west.",
        "waves" : "Waves splash up onto the wet sand."]) );
    set_exits( 
          (["west" : ROOMS"beach3",
        "east" : ROOMS"beach5",
        "south": "/d/waterworld/level1/rooms/room-1g1",
            ]) );
}

void reset() {
    ::reset();
    if(!present("sandcastle", this_object()))
        new(ROOMS"sandcastle/item/sandcastle.c")->move(this_object());
}
