//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Home");
     set_long("A nicely furnished bedroom, there is a giant double width bed siting against the south wall. There is a small table on either side of the bed, and a huge chest of drawers along the western wall. The eastern wall has a wooden pole stretching along it upon which many suits and dresses are hanging.");
     set_exits(([
                "north"		: ELFROOM"sunhome1.c"
                ]));
     set_items(([
		"bed" : "It's huge, and comfortable, and soft, and mmmm... Mustn't sleep in it though.",
		({"table", "tables"}) : "The tables each hold an oil lamp and a few random tidbits. A nice book, some incense, nothing of any interest.",
		"pole" : "Many suits and dresses hang from it.",
		({"suits", "dresses"}) : "Finely made clothing for whoever lives here."
		]));
}
