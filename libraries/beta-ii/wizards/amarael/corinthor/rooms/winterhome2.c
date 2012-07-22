//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Home");
     set_long("This is a strange room to find in an elven town. The walls have been painted green, rather than being left as natural wood. Rather than the few paintings showing scenes of nature, they depict buildings from a city. The bed, however, still has a plain wooden frame.");
     set_exits(([
                "south"              : ELFROOM"winterhome1.c"
                ]));
     set_items(([
		"paintings"	: "The paintings show famous buildings from Tirun. The Drowning Fish Tavern, the old temple, the Gate of Kings, and a few others.",
		"bed"		: "It's a bed.",
		"walls"		: "They're painted green."
                ]));
}

void reset() {
   ::reset();
     if(!present("youth"))
       new(ELFMOB"winhyouth.c")->move(this_object());
}
