#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path by a cliff");
    set_long("Trees grow to the west here, the path breaking into two here, running north to south but branching off to the west. The ocean can be seen over the edge of the eastern cliff here, although there is no visible way to gain access and the cliff is too steep to be climbed.");
    set_listen("default", "There is little sound here apart from the noise of the ocean.");
    set_smell("default", "The air is fresh and crisp, if salty.");
    set_items(([
	({"ocean", "sea", "water"}) : "The water looks awefully nice.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"ccd.c",
	"south" : ROOMS"cc16.c",
	"west" : ROOMS"cc12.c",
      ]));
}
