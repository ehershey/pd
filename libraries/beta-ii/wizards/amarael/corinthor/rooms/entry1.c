//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>
#include <nwvforest1.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor");
     set_long("This is a huge hollow inside one of the forest trees. It has obviously been carved out somehow, as stairs have been placed around the perfectly circular walls, providing path up to the top. There is a large hole between the stairs around the edge. A hole in the wall leads out to the south.");
     set_exits(([
		"up"    : ELFROOM"entry2.c",
		"south" : EROOMS"somewhere.c"
                ]));
     set_items(([
		"hole" : "The hole between the stairs continues on and on, showing a roof far above.",
		({ "stairs", "steps" }) : "They are wooden planks set into the side of the hollow."
		]));
}
