#include <std.h>
#include <cc2.h>
inherit VAULT;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("In the cave");
    set_long("This section of the cave tightens to a narrow bottleneck, sealed off with a wide door to the west. The door appears to be reinforced with bars of metal running across it and is placed upon solid hinges. A complicated-looking lock is shackled across a central bar, keeping the door closed. The cave leads out to northeast.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is reasonably musty.");
    set_items(([
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"west" : ROOMS"cc30.c",
	"northeast" : ROOMS"cc24.c",
      ]));

    set_door("door", ROOMS"cc30.c", "west", "key1");
    set_open("door", 0);
    set_locked("door", 1);
}
