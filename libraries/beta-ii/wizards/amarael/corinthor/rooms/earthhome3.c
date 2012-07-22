//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Home");
     set_long("Obviously the bedroom of an elven couple, many paintings adorn the walls not of people, but rather of places, and ones of great natural beuty at that. The bed is a simply mattress kept a small way off the ground by perfectly round, straight branches.");
     set_exits(([
                "southwest"          : ELFROOM"earthhome1.c"
                ]));
     set_items(([
		"bed" :	"A bed, for lying down in, when you sleep.",
		"mattress" : "It is a mattress, it is on the bed. It is for sleeping on.",
		"paintings" : "Lovely pieces of art they are, of most beautiful places."
                ]));
}

void reset() {
   ::reset();
     if(!present("lady"))
       new(ELFMOB"erthlady.c")->move(this_object());
}
