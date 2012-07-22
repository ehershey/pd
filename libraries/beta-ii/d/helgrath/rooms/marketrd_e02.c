#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Market Road");
    set_long("Cracked and broken cobbles lie scattered about in disarray, "
      "the dark soil underneath revealing the rich mineral deposits hidden "
      "beneath the city streets. A slight breeze blowing in from the east "
      "rustles fallen leaves, causing them to dance merrily about the road." );
    set_exits( ([ "west" : ROOMS "marketrd_e01.c",
      "east" : ROOMS "marketrd_e03.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The wind yawns lazily through the streets.");

}
