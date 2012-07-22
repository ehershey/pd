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
      "Running north to south is Yull Boulevard, and east to west is Market road. "
      "A large, intricately crafted fountain stands proudly in the center of the square. " );
    set_exits( ([ "north" : ROOMS "yullblvd_n01.c",
	"south" : ROOMS "wilndursquare.c",
	"east" : ROOMS "wilndursquare_et.c",
	"west" : ROOMS "wilndursquare_wt.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");

}
