#include <std.h>
#include <venenum.h>
inherit VAULT;

void create() {
    ::create();
    set_short("End of a long corridor");
    set_long("The corridor ends here with a huge window, overlooking the Ganthus road. The window is possibly three metres across with wooden struts to support the various panes which coalesce into a single vast window. To the east there is a single door, while to the south lies a long corridor ending in a spiraling staircase.");
    set_smell("default", "This part of the house smells clean and pleasant.");
    set_listen("default", "The house is quiet and peaceful.");
    set_items(([
	({"window", "huge window"}) : "A fine view of Ganthus road is found through the glass here. The window itself is a work of engineering and art combined- magnificent and truely wonderful. Not to mention, expensive.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"devereux4.c",
	"east" : ROOMS"devereux_mainbed.c",
      ]));

    set_door("east door", ROOMS"devereux_blank.c", "east", "devereux_main_key");
    set_open("east door", 0);
}

