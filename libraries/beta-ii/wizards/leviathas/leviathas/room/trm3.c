#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("Getting closer to the wall");
    set_long(
      "%^BOLD%^The wall is getting closer and closer. "
      "Now the vast ocean has grown small and is on the "
      "southern horizon.  Four Griffon-statues stand on "
      "the four corners of the palace wall in a defensive "
      "stance.",);
 
    set_items(([
        "wall" : "It's beautiful, really, made of silver "
             "mud with amazing pictures carved into it.  "
             "One of them depicts the battle of the Terra "
             "Goddess and the Vampire Lord, Balra-Zin.",
        "ocean" : "A beautiful blue strip on to the south, "
             "however appearances are sometimes decieving...",
        "statues" : "The most amazing of all sculptures in "
             "the universe, these statues strike deep into "
             "the soul.",
        ]));
    
    set_exits( (["east" : ROOMS "trm4.c",
                 "north"  : ROOMS "trm5.c", 
                 "south" : ROOMS "trm2.c"]) );
    
}
