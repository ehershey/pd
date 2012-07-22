#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light":3, "forest":1, "no scry":1]));
     set_name("Illuminati Tower");
     set_short("Illuminati Tower");
     set_long("%^GREEN%^This is the central area of a large clearing in a strange forest. The air itself tingles with the feeling of raw magic. The colours here are sharper, the green of the forest so deep it doesn't look real. Several strange horses can be seen grazing around near the edges.%^RESET%^");
     set_exits(([
		"north"		: ILROOM"nfield.c",
		"south"		: ILROOM"sfield.c",
		"east"		: ILROOM"efield.c",
                "west"          : ILROOM"wfield.c"
                ]));
}

void init() {
   ::init();
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}

void reset() {
   ::reset();
     if(!present("portal"))
       new(ILOBJ"portal.c")->move(this_object());
}
