#include <std.h>
inherit BEACH;

void create() {
 ::create();
   set_short("The Dou Key beach");
   set_long("The Dou Key is one of the Merkkirrian keys, a group of "
	"small islands off the coast of Merkkirri. Dou is a mostly "
	"sand-covered island, with little movement to be seen anywhere "
	"at all. The small beachy island goes east and south from "
	"here.");
   set_items(([
	"island" : "A small sand-covered island, nothing much to it.",
	"keys" : "Unlike the other keys, Dou has no plant or animal "
		 "life, but hosts only sandy shores.",
	"shores" : "Perfect for relaxing on."
   ]));
   set_exits(([
        "south" : "/d/freepk/keys/dou/beachs.c",
        "east"  : "/d/freepk/keys/dou/beache.c"
   ]));
   set_max_catch(20);
   set_max_fishing(2);
   set_chance(75);
   set_fish(([
     "rainbow fish":10,
     "trout":15,
     "gold fish":5,
     "pirch":5,
     "stingray": 10,
     "lamprey":15
   ]));
   set_letter("g");
}
