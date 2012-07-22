#include <std.h>
#include <venenum.h>
inherit VAULT;

void create() {
    ::create();
    set_short("A long corridor");
    set_long("The top floor of the house is covered, wall to wall, in the trophy heads of slain animals, their faces locked in a macabre visage of death. A long curved stairway exists to the south, stretching into a long corridor to the north and a pair of heavy oaken doors to the east and to the west.");
    set_smell("default", "This corridor smells clean and pleasant.");
    set_listen("default", "The house is quiet and peaceful.");
    set_items(([
	({"trophies", "trophy", "animals", "animal"}) : "These trophies seem extremely lifelike, although the spark of life in their eyes has been replaced by the dull spheres of marble.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"stairway" : ROOMS"devereux3.c",
	"south" : ROOMS"devereux5.c",
	"east" : ROOMS"devereux_blank.c",
	"west" : ROOMS"devereux_child.c",
      ]));

    set_door("east door", ROOMS"devereux_blank.c", "east", "%^BOLD%^%^WHITE%^totally_nothing_no_key_will_open%^RESET%^_this_door___!!%^RESET%^");
    set_door("west door", ROOMS"devereux_child.c", "west", "devereux_child_key");
    set_open("east door", 0);
    set_open("west door", 0);
}

