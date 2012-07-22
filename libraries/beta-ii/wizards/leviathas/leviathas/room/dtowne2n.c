#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^This road leads to a larger residential area.  There are many houses but few look like they could be entered, "
            "many appearing as though they could fall apart at any moment.  The street itself is falling apart, tiles in places are warped upward "
            "or caved in.");
   
    set_night_long("%^BOLD%^%^BLACK%^This road leads to a larger residential area.  There are many houses but few look like they could be entered, "
            "many appearing as though they could fall apart at any moment.  The street itself is falling apart, tiles in places are warped upward "
            "or caved in.");
    
    set_items(([
        "houses" : "Many of the houses look like they're going to collpase.",
        "street" : "It's falling apart in it's old age.",
                  
        
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "dtowne2n2.c",
        "south" : ROOMS "dtowne2.c",
        
                
    ]));

}


