#include <std.h>
#include <cc.h>
inherit VAULT;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("In the cave");
    set_long("The passage declines slightly as it runs from the east to the west, the walls becoming more and more natural, as though carved with tools instead of the eons of erosion seen earlier. A heavy steel grate has been set into position here, keeping unwanted creatures from venturing in further- or escaping. A small keyhole is embedded into the wall just to the east of the grill.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is reasonably musty.");
    set_items(([
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"east" : ROOMS"cc30.c",
	"west" : ROOMS"ccp.c",
      ]));

    set_door("door", ROOMS"cc30.c", "west", "key2");
    set_open("door", 0);
    set_locked("door", 1);
}
