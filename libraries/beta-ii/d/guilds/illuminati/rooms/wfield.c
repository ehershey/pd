#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "forest":1, "no scry":1]));
     set_name("Illuminati Tower");
     set_short("Illuminati Tower");
     set_long("%^GREEN%^Travel further to the west is blocked off by the trees surrounding the clearing. Their branches are long and thick, crossing each other often ccreating an effective barrier to movement. The air shimmers with faint rainbow colours, giving the place a magical glow. Everything moves and sways gently to a breeze that isn't there.%^RESET%^");
     set_exits(([
		"east"		: ILROOM"cfield.c",
		"northeast"	: ILROOM"nfield.c",
		"southeast"	: ILROOM"sfield.c"
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
       new(ILMOB"unicornw.c")->move(this_object());
}
