#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^The town is quite large.  The tiles on the ground have been "
	"pushed out of place, probably by the massive tower swaying underneath.  Ghastly lookin"
	"g, abandoned houses decorate the streets and it looks like some of them could be enter"
	"ed here. ");
   
    set_night_long("%^BOLD%^%^BLACK%^The town is quite large.  The tiles on the ground have been "
	"pushed out of place, probably by the massive tower swaying underneath.  Ghastly lookin"
	"g, abandoned houses decorate the streets and it looks like some of them could be enter"
	"ed here. ");
    
    set_items(([
        "houses" : "The houses seem to stare you down.  A couple of them are missing doors that lead into black nothingness.",
        "tiles" : "The tiles have been pushed out of place or smashed from the swaying of the tower underneath.",
	"doors" : "You could probably enter.",                  
                
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "dtowne2.c",
        "east" : ROOMS "dtowne4.c",
	"house" : ROOMS "dhouse1rm1.c",
    ]));
}
