#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
	"light" : 2,
      ]));
    set_short("%^YELLOW%^Wilndur Square");
    set_long("Welcome to Wilndur Square, the center of this bustling community. The two "
      "main roads of Helgrath intersect this square, heading off in the four cardinal directions. "
      "To the southeast lies Helgrath National bank. " );
    set_exits( ([ "north" : ROOMS "wilndursquare_em.c",
	"west" : ROOMS "wilndursquare_mb.c",
	 ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");

}