#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path through shrubs");
    set_long("This section of the path appears to be surrounded by thick bushes and shrubs, obscuring visibility of the path somewhat, although it currently remains distinct and not too difficult to follow. Many of the bushes here are covered in prickles, making a journey off the path one fraught with hazard.");
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
	"northeast" : ROOMS"cc12.c",
	"south" : ROOMS"ccd2.c",
      ]));
}
