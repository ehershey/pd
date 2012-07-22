//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor");
     set_long("The stairs finally reach their top here, with the hollow ending just several feet above. There is a hole in the side of the tree acting as an archway to the outside. A wooden bridge starts right at the foot of the arch, and leads north, swaying n hte breeze. The stairs spiral around the edge of the hollow, leaving a hole in the middle.");
     set_exits(([
		"north" : ELFROOM"bridge2-2.c",
		"down"  : ELFROOM"entry4.c",
                ]));
     set_items(([
		"hole" : "It's a long, long way down.",
		"stairs" : "They are wooden planks set into the side of the tree.",
		({ "arch", "hole" }) : "It leads to the outside world.",
		"bridge" : "The bridge is made of wood, and sways slightly in the breeze."
		]));
}
