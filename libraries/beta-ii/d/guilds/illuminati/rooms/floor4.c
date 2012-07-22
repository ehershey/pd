#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "indoors":1, "no scry":1]));
     set_name("Illuminati Tower");
     set_short("Illuminati Tower");
     set_long("%^ORANGE%^The 4th floor of the Tower of Light. In addition to the northwest and northeast balconies, this floor also holds the guild's board, as well as the Book of Grudges. Stairs continue up to the training halls.%^RESET%^");
     set_exits(([
		"down"          : ILROOM"floor3.c",
		"up"            : ILROOM"floor5.c",
		"northeast"     : ILROOM"neturret4.c",
		"northwest"     : ILROOM"nwturret4.c",
		"southwest"     : ILROOM"grudges.c",
		"southeast"     : ILROOM"board.c"
		]));
}

void init() {
   ::init();
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}
