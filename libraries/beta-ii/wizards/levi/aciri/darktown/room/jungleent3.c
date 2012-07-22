#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^Large trees decorate the jungle, some blocking off exits.  A path leads west, toward a rock formation. "
            "A few leaves have fallen on the ground and tile the ground.");
   
    set_night_long("%^BOLD%^%^BLACK%^Large trees decorate the jungle, some blocking off exits.  A path leads west, toward a rock formation. "
            "A few leaves have fallen on the ground and tile the ground.");
    
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
        "west" : ROOMS "jungleent4.c",
		     
	 ]));
	

}


