#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "forest":1, "no scry":1]));
     set_name("Illuminati Tower");
     set_short("Illuminati Tower");
     set_long("%^GREEN%^The clearing reaches its northern edge. The trees are so thick that it is impossible to get through them, and so they make an effective barrier. The air shimmers slightly as though there were some great heat, yet the place is quite cool. The feeling of great magic is ever present.%^RESET%^");
     set_exits(([
		"south"		: ILROOM"cfield.c",
		"southeast"	: ILROOM"efield.c",
		"southwest"	: ILROOM"wfield.c"
                ]));
}

void init() {
   ::init();
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}

void reset() {
   ::reset();
     if(!present("unicorn"))
       new(ILMOB"unicornbf.c")->move(this_object());
}
