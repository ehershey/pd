#include <std.h>
#include <illuminati.h>

inherit ROOM;

void create() {
    ::create();
    set_properties((["light":2, "indoors":1, "no scry":1]));
    set_name("Illuminati Tower");
    set_short("Illuminati Tower");
    set_long("%^ORANGE%^In the middle of the room stands a massive golden archway, inside it "
      "is what looks to be a vertical silver shimmering lake. The arch acts as a gate"
      " between halls of the Illuminati.%^RESET%^");
    set_exits(([
	"northwest"         : ILROOM"floor3.c"
      ]));
}

void reset() {
    ::reset();
    if(!present("portal"))
	new(ILOBJ"portal.c")->move(this_object());
}

void init() {
    ::init();
    if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
	ILOBJ"ejection"->eject(this_player());
}
