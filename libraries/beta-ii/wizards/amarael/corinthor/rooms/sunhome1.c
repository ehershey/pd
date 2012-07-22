//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Home");
     set_long("This is the inside of a nice elven home. The doorway to the north leads into a large living area, with several chairs spread in a half circle facing the door. In between them is an elegant wooden table, with flowers growing out of a pot in the middle of it.");
     set_exits(([
                "north"         : ELFROOM"sun2.c",
                "south"         : ELFROOM"sunhome3.c",
                "west"          : ELFROOM"sunhome2.c"
                ]));
     set_items(([
		"flowers"	: "The flowers are a rare kind that grow only in a few places outside of the forest.",
		"pot"		: "The pot is actually a carved part of the table itself, and has no bottom! The flowers are actually growing through the floor.",
                "chairs"	: "They're just chairs.",
		"table"		: "The table is made from strong wood, and is of a single piece, rather than being nailed together. A nice piece, but no more interesting than that."
		]));
}

void reset() {
   ::reset();
     if(!present("lady"))
       new(ELFMOB"sunhlady.c")->move(this_object());
     if(!present("guest"))
       new(ELFMOB"sunhguest.c")->move(this_object());
     if(!present("guest 2"))
       new(ELFMOB"sunhguest.c")->move(this_object());
}
