#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Clearing");
    set_long("This small clearing appears to be a naturally occuring hole in the forest, created when a larger tree collapsed during a heavy storm. Whoever created the path here obviously cleared the tree, then changed the layout of the path to suit- it branches off in two directions, to the southeast and to the southwest, as well as running off to the north.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is fresh and crisp.");

    set_items(([
	({"clearing", "tree"}) : "The clearing appears to have occured naturally, although the tree which created it is long since gone, leaving only a stump.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"cc7.c",
	"southeast" : ROOMS"cc12.c",
	"southwest" : ROOMS"cc11.c",
      ]));
}
