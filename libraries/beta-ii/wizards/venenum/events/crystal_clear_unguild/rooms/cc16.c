#include <std.h>
#include <cc2.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path by a cliff");
    set_long("The trees pack in tightly to the west, blocking all passage. The ocean can be seen over the edge of the eastern cliff here, although there is no visible way to gain access and the cliff is too steep to be climbed. The path divides here, heading to the southeast, to the southwest and to the north.");
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
	"north" : ROOMS"cc13.c",
	"southeast" : ROOMS"cc19.c",
	"southwest" : ROOMS"cc18.c",
      ]));
}
