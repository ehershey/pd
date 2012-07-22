#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^A road to the north leads to a couple of houses and in between them, a huge gate.");
   
    set_night_long("%^BOLD%^%^BLACK%^A road to the north leads to a couple of houses and in between them, a huge gate.");
    
    set_items(([
        "houses" : "The houses to the north look pretty big.",
        "gate" : "Hard to make anything of it from here.",
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "dtowne4.c",
        "east" : ROOMS "dtowne6.c",
	"north" : ROOMS "dtowne5n.c",
	     
	 ]));
    
}


