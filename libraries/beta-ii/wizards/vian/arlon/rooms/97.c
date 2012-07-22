#include <std.h>
#include <arlon2.h>
#include <daemons.h>
inherit BEACH;
#include <ocean.h>

void create() {
::create();
set_properties( ([ "beach" : 2, "town" : 1, "night light" : 2]) );
set_smell("default", "The salty smell of ocean air is present here.");
set_listen("default", "The sound of crashing waves is overpowering.");
set_short("Arlon shopping district");
set_long("The beach is covered in a dazzling, sparkling sand.  This far out toward the water, the sand is wet, with distinct footprints of animals and travelers visible.  There are some dinghies washed up upon the shore here, and stakes to tie a dinghy up to.");
set_letter("a");
set_exits(([ "north" : ROOMS "84.c",
"west" : ROOMS "99.c",
"east" : ROOMS "100.c"]));
set_items(([
({"sand", "wet sand"}) : "The sand is wet closer to the ocean, less dazzling than the sand on the rest of the beach.",
({"water", "ocean"}) : "The ocean creates gigantic waves, crashing water onto the beach.",
({"dinghy", "stakes", "dinghies"}) : "Dinghies have been washed up on the beach here, and there are a few wooden stakes in the ground that a dinghy can be tied to.",
({"footprint", "footprints"}) : "Footprints vary from crabs to birds to adventurers.",
]));
}
void reset() {
    ::reset();
    if(!present("angrycrab")){
        new(MOB"angrycrab")->move(this_object());
}
    if(!present("seagull")){
        new(MOB"seagull")->move(this_object());
        new(MOB"seagull")->move(this_object());
}
}
