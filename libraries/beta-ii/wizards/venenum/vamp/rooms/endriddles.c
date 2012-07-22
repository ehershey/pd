#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Deep within the Mausoleum");
    set_long("The hallway here branches off into two directions, east and west. The south passage is long and straight with no end in sight, with small sparkling fields appearing to wink in and out occasionally, seemingly at random. Each passage ends in two spiral stairways downwards, disappearing deep into the earth.");
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
	"south" : ROOMS"riddles6.c",
	"east" : ROOMS"stairway1.c",
	"west" : ROOMS"stairway2.c",
      ]));
}
