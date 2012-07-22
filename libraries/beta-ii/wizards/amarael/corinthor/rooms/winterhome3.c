//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Home");
     set_long("The decorator of this room seems to have been in two minds at once. There are a few paintings hanging on the walls, yet while some are typical nature scenes, others are of cities. The bedside tables are made of unfinished wood, but the bed has a metal frame. Most peculiar for an elven home.");
     set_exits(([
                "southwest"          : ELFROOM"winterhome1.c"
                ]));
     set_items(([
		"bed"		: "A double size bed, meant for a couple.",
		"paintings"	: "Some show forest scenes, yet the others show streets of Tirun."
                ]));
}

void reset() {
   ::reset();
     if(!present("lord"))
       new(ELFMOB"winhlord.c")->move(this_object());
     if(!present("lady"))
       new(ELFMOB"winhlady.c")->move(this_object());
}
