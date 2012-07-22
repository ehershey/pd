#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("At the shores of Terra");
    set_long(
      "%^BOLD%^This is the mighty shore of Terra.  The "        "mighty %^BLUE%^ocean %^RESET%^%^BOLD%^can be "
       "seen to the south.  To the north is a great "
       "wall, while past that lies a great Palace.  "
       "Barely within mortal view, past the palace, a "
       "tarnished silver tower stands tall, reaching "
       "straight into the heavens.  To the northeast "
       "there appears to be a golden structure of some "
       "kind, it looks abandoned with vines and plants "
       "growing all over it.  Northwest there is a dark "
       "looking cavern.");
   
    set_items(([
        "wall" : "The wall shimmers with silver.  The "
              "guards stand within it ready to protect "
              "their beautiful city, probably from the "
              "vampires.",
        "palace" : "The Palace shimmers slightly, it " 
              "was made a goddess named Terra. ",
        "tower" : "A huge, seemingly never-ending tower "
              "reaches far into the heavens, far, far "
              "to the north.",
        "caverns" : "The caverns radiate with evil.",
        "structure" : "A golden structure that looks "
              "abandoned.",
    ]));

    set_exits( ([ "north" : ROOMS  "trm2",
        
    ]) );
    
}
