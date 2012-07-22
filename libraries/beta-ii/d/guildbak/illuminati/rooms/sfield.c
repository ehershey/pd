#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "forest":1, "no scry":1]));
     set_name("Illuminati Tower");
     set_short("Illuminati Tower");
     set_long("%^GREEN%^The trees cluster together just to the south, their trunks and branches so close and so thick that they prevent any passage out of the clearing. The air shimmers with an unfelt heat. The grass is an impossibly deep shade of green, and waves gently without a breeze.%^RESET%^");
     set_exits(([
		"north"		: ILROOM"cfield.c",
		"northeast"	: ILROOM"efield.c",
		"northwest"	: ILROOM"wfield.c"
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
       new(ILMOB"unicornb.c")->move(this_object());
}
