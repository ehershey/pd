#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^RED%^An altar lies here, brilliantly carved out of ruby and silver.  A statue "
            "of the god, Carnage, stands proudly at it's center.  Very dim light fills the room.");
   
    set_night_long("%^RED%^An altar lies here, brilliantly carved out of ruby and silver.  A statue "
            "of the god, Carnage, stands proudly at it's center.  Very dim light fills the room.");
    
    set_items(([
        "altar" : "The altar has been carved out of ruby.",
        "statue" : "Strange as it may seem, the god has a grin on his face.",
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "out" : ROOMS "dtowndsp2.c",
		     
	 ]));
	

}

