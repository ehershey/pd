#include <std.h>
#include <venenum.h>
inherit ROOM;

int pushed=0;

void create() {
    ::create();
    set_short("Deep within the Mausoleum");
    set_long("This passage is crafted from dull grey stone blocks. Otherwise unremarkable, this place appears barren of any other features apart from a small inscription on the floor.");
    set_items(([
	({"inscription"}) : "%^BOLD%^%^WHITE%^There are many ways to hate, but only one way to love; completely.%^RESET%^",
      ]));
    set_listen("default", "There are no audible noises here.");
    set_smell("default", "The slight scent of mildew is present here.");
    set_properties(([
	"light" : 1,
	"night light" : 0,
	"no teleport" : 1,
	"indoors" : 1,
	"outdoors" : 0,
      ]));
    set_exits(([
	"south" : ROOMS"puzzlef.c",
	"west" : ROOMS"puzzleb.c",
      ]));
}
