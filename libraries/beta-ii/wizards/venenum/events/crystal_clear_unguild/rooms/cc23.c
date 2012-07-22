#include <std.h>
#include <cc2.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("In the cave's mouth");
    set_long("This cave is narrow but stable, carved by water in the limestone rock deposits which litter this area. Fine footprints can occasionally be seen in the dust on the ground, although caves of this nature are rarely more then fifty feet deep. The cave here branches off into four directions, including a passage to light to the north.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is clean but musty.");
    set_items(([
	({"cave"}) : "This is a cave. You are inside.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"cc22.c",
	"south" : ROOMS"ccb.c",
	"southeast" : ROOMS"cc26.c",
	"southwest" : ROOMS"cc24.c",
      ]));
}
