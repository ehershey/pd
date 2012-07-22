#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("In the cave");
    set_long("The passage widens slightly here, the cave breaking into three directions, one to the southwest and dipping down, one travelling level to the southwest and one rising slightly to the northeast. The stone here is mostly limestone.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is a little musty.");
    set_items(([
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"northeast" : ROOMS"cc23.c",
	"southeast" : ROOMS"cc28.c",
	"southwest" : ROOMS"cco.c",
      ]));
}
