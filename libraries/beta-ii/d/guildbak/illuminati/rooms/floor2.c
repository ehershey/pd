#include <std.h>
#include <illuminati.h>

inherit ROOM;
void create() {
   ::create();
     set_properties((["light":3, "indoors":1,"no scry":1]));
     set_name("Illuminati Tower");
     set_short("Illuminati Tower");
     set_long("%^ORANGE%^The second floor of the tower of light. On this floor there several shops and the guild treasury. Stairs lead up and down, and there are also open balconies to the northeast and northwest.%^RESET%^");
     set_exits(([
		"down"          : ILROOM"newhall.c",
		"south"         : ILROOM"treasury.c",
		"southwest"     : ILROOM"stoneshop.c",
		"southeast"     : ILROOM"itemshop.c",
		"west"          : ILROOM"weapshop.c",
		"east"          : ILROOM"armshop.c",
		"northwest"     : ILROOM"nwturret2.c",
		"northeast"     : ILROOM"neturret2.c",
		"up"            : ILROOM"floor3.c"
		]));
}

void init() {
   ::init();
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}
