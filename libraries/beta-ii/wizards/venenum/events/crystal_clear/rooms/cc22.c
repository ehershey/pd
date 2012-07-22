#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Entrance to a cave");
    set_long("An opening to a small cave sits into a hillock here, revealing an open mouth down into the earth tucked in amongst clumps of trees. A path leads right to the entrance, branching off to the northeast and the northwest as well as disappearing down the mouth of the cave.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is fresh and crisp.");

    set_items(([
	({"trees"}) : "These trees are packed in tightly around the path and the entrance to the cave.",
	({"cave"}) : "This cave disappears down into the ground.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"northeast" : ROOMS"ccr.c",
	"northwest" : ROOMS"cc20.c",
	"south" : ROOMS"cc23.c",
      ]));
}
