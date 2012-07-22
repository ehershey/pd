#include <std.h>
#include <venenum.h>
inherit VAULT;

int closed=1;

void create() {
    ::create();
    set_short("Basement");
    set_long("The stairs in this basement lead in three directions, up to a pair of double doors, then to the east and west. The walls here are crafted from set stone, gray and dark in colour, the bricks set together with mortar. The floor looks to have been swept recently and is free of dust and dirt.");
    set_smell("default", "This place is musty although the air is surprisingly fresh.");
    set_listen("default", "There are not many noises here.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_items(([
	({"bricks"}) : "These bricks are simply set stone, interlocked with mortar.",
      ]));
    set_exits(([
	"out" : ROOMS"devereux_backyard.c",
	"east" : ROOMS"devereux_basement2.c",
	"west" : ROOMS"devereux_basement3.c",
      ]));
}
