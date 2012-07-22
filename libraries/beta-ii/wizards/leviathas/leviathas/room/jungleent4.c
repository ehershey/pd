#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^The trees become less dense and the sky even darker.  A small rock formation is to the west. "
           "It looks man-made, as if carved out of some big rock.  It is possible to climb there. ");
   
    set_night_long("%^BOLD%^%^BLACK%^The trees become less dense and the sky even darker.  A small rock formation is to the west. "
           "It looks man-made, as if carved out of some big rock.  It is possible to climb there. ");
    
    set_items(([
        "formation" : "The rock looks man-made.",
        "trees" : "Many different, green trees.",
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "east" : ROOMS "jungleent3.c",
        "west" : ROOMS "formation.c",
		     
	 ]));
	

}


