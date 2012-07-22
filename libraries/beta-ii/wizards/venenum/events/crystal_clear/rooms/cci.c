#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("In the cave");
    set_long("This section of the cave finishes here, heading southeast. The walls here are limestone, as are all the cave surfaces around this area. Attached to the west wall is a small statuette.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is reasonably musty.");
    set_items(([
	({"statue", "statuette"}) : "This brass small statue depicts a halfling striding merrily along, miming whistling some kind of tune. This is a well known mark of safety or safe passage.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"west" : ROOMS"cck.c",
	"southeast" : ROOMS"cc30.c",
      ]));
    add_invis_exit("west");
}
