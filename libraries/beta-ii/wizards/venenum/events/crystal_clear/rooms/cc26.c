#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("In the cave");
    set_long("The passage here twists slightly, the ground underneath broken and uneven. The cave narrows slightly, small cracks starting to show along the ceiling, walls and floor of this section of the passage. It would appear that this part of the cave has destabalized somewhat.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is a little musty.");
    set_items(([
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"northwest" : ROOMS"cc23.c",
	"south" : ROOMS"ccw.c",
      ]));
}
