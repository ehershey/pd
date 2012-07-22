#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("building",1);
    set_short("A Mental Insitution");
    set_long(
      "%^BOLD%^%^WHITE%^Inside this building, it looks to be one long hall with doors on "
      "%^BOLD%^%^WHITE%^either side of the hallway, and a door at the very end of the hallway. 
"
      "%^BOLD%^%^WHITE%^This room is the waiting room.  There is a desk with a clerk typing away
"
      "%^BOLD%^%^WHITE%^and straightback chairs outline the room.  There is nothing to read or
look "
      "%^BOLD%^%^WHITE%^at, the walls, ceilings, and floor are all the same color, white."
          );
    set_items(([
        "building" : "It is a mental insitution.",
        "walls" : "No pitures on them, they are a solid white.",
        "hallway" : "It's a long hallway with doors on either side of it.",
        "door" : "It is at the end of the hallway, and there seems to be a sign
on it.",
        "chairs" : "They uncomfortable ones, made of solid wood and no curves
designs.",
        "desk" : "Not a very big one, but it serves it's purpose.",
        "floor" : "White tiles line the floor, and spotless.",
        "ceiling" : "Looking up almost makes you think that you are hanging
upside down.",
        "clerk" : "Typing away at what looks like a death certificate.",
    ]));
    set_listen("default", "Complete silence fills the air");
    set_smell("default", "Smells of chlorine stings at your nose");
    set_exits( ([
"out" : UMI "umi38",
"hallway" : UMI "hosp9",
    ]) );
}
