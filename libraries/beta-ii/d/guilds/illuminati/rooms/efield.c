#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "forest":1, "no scry":1]));
     set_name("Illuminati Tower");
     set_short("Illuminati Tower");
     set_long("%^GREEN%^Over here on the eastern side of the clearing the place is just the same. Trees grow together so tightly, their brances criscossing so much, that they completely block off any travel exacept inside hte clearing itself. The deeply coloured green leaves make no noise as they sway in a nonexistent breeze.%^RESET%^");
     set_exits(([
		"west"		: ILROOM"cfield.c",
		"northwest"	: ILROOM"nfield.c",
		"southwest"	: ILROOM"sfield.c"
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
       new(ILMOB"unicornwf.c")->move(this_object());
}
