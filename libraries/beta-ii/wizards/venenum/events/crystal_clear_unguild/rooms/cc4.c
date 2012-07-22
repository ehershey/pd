#include <std.h>
#include <cc2.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path through the Woodlands");
    set_long("The path forks here, leading off to the northwest, the south and the southwest. The trees are firmly packed in together, making straying from the trail difficult. A trail of blood leads from the northwest to the south.");
    set_listen("default", "The soft noises of distant birds can be heard here.");
    set_smell("default", "The air is fresh and crisp.");

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"northwest" : ROOMS"cc2.c",
	"southwest" : ROOMS"cc5.c",
	"south" : ROOMS"cc6.c",
      ]));
}
