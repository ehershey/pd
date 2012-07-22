//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Home");
     set_long("This is the entry room of a nice elven home. An intricately woven straw mat covers much of the polished wooden floor. In the middle of the room is a leafless tree upon which hang a few hats and coats. A doorway in the northern wall leads into what looks like the living area. There is another door, closed, in the corner.");
     set_exits(([
                "west"          : ELFROOM"earth2.c",
                "north"         : ELFROOM"earthhome2.c",
                "northeast"     : ELFROOM"earthhome3.c"
                ]));
     set_items(([
		"mat" :		"The mat has a fine weave and is made of straw. Quite comfortable to walk on.",
		"tree" :	"The tree has not a single leaf on any of it's branches.",
	({ "hats", "coats" }) : 	"Many hats and coats hang upon the leafless tree in the middle of the room."
                ]));
}
