#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path through the Woodlands");
    set_long("This path leads through dense woodlands, the trees here tightly packed around the path, creating a shaded environment. The path here is narrow and thin, the ground littered by twigs and leaves.");
    set_listen("default", "The sound of animals foraging in the undergrowth is heard here.");
    set_smell("default", "The air is fresh and crisp.");

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"northeast" : ROOMS"cc4.c",
	"south" : ROOMS"cc7.c",
      ]));
}
