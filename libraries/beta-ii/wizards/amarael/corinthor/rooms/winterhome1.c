//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Home");
     set_long("The main eating and dining area of an elven home. There are several chairs and lounges arranged around the middle of the room, with a small table in between them. In the northwest corner of the room is a small bench area with various cooking utensils, presumably for preparing food. There are two doors leading north and northeast.");
     set_exits(([
                "north"              : ELFROOM"winterhome2.c",
                "northeast"          : ELFROOM"winterhome3.c",
                "south"              : ELFROOM"winter2.c"
                ]));
     set_items(([
		"bench"		: "It's a bench, about three feet high with a flat top.",
		"utensils"	: "People use them to prepare food.",
		({ "chairs", "lounges" }) : "The chairs and lounges are arranged around a small table.",
		"table"		: "The table is small, and has several cups on it.",
		"cups"		: "The cups give off the smell of sweet herbs."
                ]));
}
