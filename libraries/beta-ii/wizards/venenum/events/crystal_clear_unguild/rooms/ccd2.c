#include <std.h>
#include <cc2.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path through shrubs");
    set_long("This section of the path appears to be surrounded by thick bushes and shrubs, obscuring visibility of the path somewhat, although it currently remains distinct and not too difficult to follow. Many of the bushes here are covered in prickles, making a journey off the path one fraught with hazard. A dead halfling lies here in a pool of blood.");
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
	"north" : ROOMS"cc15.c",
	"northwest" : ROOMS"cct.c",
	"south" : ROOMS"cc20.c",
      ]));
}

void reset()

{

    if (!present("body")) {
	new(ITEM"dead_halfling.c")->move(this_object());
    }
}