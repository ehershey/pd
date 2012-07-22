#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Deep within the Mausoleum");
    set_long("This long stairway curls downwards to places unknown. A passage leads to the east, revealing a T intersection in that direction, with the path splitting off to the east and the south. To the east, down the short passage, an identical stair to this one may be seen.");
    set_smell("default", "The faint scent of earth is present here.");
    set_listen("default", "You can hear the distant sound of dripping water.");
    set_items(([
	({"stairways"}) : "These staircases spiral downwards and are identical in every respect except one spirals clockwise while another spirals anticlockwise.",
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
	"no teleport" : 1,
	"indoors" : 1,
	"outdoors" : 0,
      ]));
    set_exits(([
	"east" : ROOMS"endriddles.c",
	"stairs" : ROOMS"tportpassage1.c",
      ]));
}
