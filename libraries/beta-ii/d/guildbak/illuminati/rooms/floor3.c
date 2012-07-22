#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "indoors":1, "no scry":1]));
     set_name("Illuminati Tower");
     set_short("Illuminati Tower");
     set_long("%^ORANGE%^The third floor of the Tower of Light. Here is where the various magical rooms are are located, as well as the guild lockers. Two doors open to the northern balconies.%^RESET%^");
     set_exits(([
		"down"          : ILROOM"floor2.c",
		"southeast"     : ILROOM"mainportal.c",
		"southwest"     : ILROOM"lockers", 
		"west"          : ILROOM"scry.c",
		"east"          : ILROOM"prayer.c",
		"northwest"     : ILROOM"nwturret3.c",
		"northeast"     : ILROOM"neturret3.c",
		"up"            : ILROOM"floor4.c"
		]));
}

void init() {
   ::init();
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}
