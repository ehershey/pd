#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("A long corridor");
    set_long("This long corridor stretches out to the south with a large curved stairway to the north. To the east and west more rooms lay the doors to rooms in the house, their contents shielded by thick wooden oak doors. The floor here consists of white marble tiles, set in a spiraling mosaic which finishes at the centre of the room.");
    set_smell("default", "This corridor smells clean and pleasant.");
    set_listen("default", "The house is quiet and peaceful.");
    set_items(([
	({"tiles", "mosaic", "marble"}) : "This marble looks extremely expensive and was probably not sourced locally; it must be imported. The mosaic in the centre of the room spirals in and in and is formed from bright yellow tiles.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"stairway" : ROOMS"devereux4.c",
	"south" : ROOMS"devereux2.c",
	"east" : ROOMS"devereux_study.c",
	"west" : ROOMS"devereux_guest.c",
      ]));
}

