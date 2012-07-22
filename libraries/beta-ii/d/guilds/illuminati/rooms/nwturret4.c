#include <std.h>
#include <illuminati.h>

inherit ROOM;
void create() {
   ::create();
     set_properties((["sky":1, "no scry":1, "light":2]));
     set_name("Illuminati Tower");
     set_short("Illuminati Tower"); 
     set_day_long("%^ORANGE%^This is a northwestern turret of the Illuminati tower. The floor is made of stone blocks rather than the marble of inside, and they show signs of wear. From this vantage point you can see the the ocean all around.%^RESET%^");
     set_night_long("%^CYAN%^A northwestern turret of the Illuminati tower. Torches are lit along the tower wall to provide light. In the darkness you can see the night sky in all of it's beauty.%^RESET%^"); 
     set_items(([
		"ocean"         : "%^BOLD%^BLUE%^The ocean surrounds the Tower of Light on all sides.%^RESET%^",
		"floor"         : "The stone blocks have been worn smooth by the constant wind and rain.",
		"torches"       : "The torches provide light during the night.",
		"wall"          : "The walls of the tower seem to be void of wear, and still show their intricate carvings perfectly."
		]));
     set_listen("default", "Waves crash onto the beach far below.");
     set_exits(([
		"southeast" : ILROOM"floor4.c"
		]));
}

void init() {
   ::init();
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}
