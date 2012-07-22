#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path through the trees");
    set_long("An opening to a small cave sits into a hillock slightly to the southeast of here, clearly visible between the trees which clump on the sides of the path. The path leads right to it.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is fresh and crisp.");

    set_items(([
	({"bushes"}) : "There are an abnormal amount of bushes here.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"ccd2.c",
	"southeast" : ROOMS"cc22.c",
      ]));
}
