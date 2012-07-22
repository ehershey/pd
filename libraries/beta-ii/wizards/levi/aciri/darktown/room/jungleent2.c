#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^The trees are thick together, forming walls in places.  Vines dangle all over the place. ");
   
    set_night_long("%^BOLD%^%^BLACK%^The trees are thick together, forming walls in places.  Vines dangle all over the place. ");
    
    set_items(([
        "vines" : "The vines are all over the place.",
        "trees" : "Many different, green trees.",
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "jungleent.c",
        "south" : ROOMS "jungleent3.c",
		     
	 ]));
	

}


