#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^Ghastly buildings surround the area.  The ground is warped from seizemic activity, the tiles that once decorate it cracked or no where to be found.  Faint light shines out of some houses and it looks like they were borded up to protect the outside town from them rather than the other way around.");
   
    set_night_long("%^BOLD%^%^BLACK%^Ghastly buildings surround the area.  The ground is warped from seizemic activity, the tiles that once decorate it cracked or no where to be found.  Faint light shines out of some houses and it looks like they were borded up to protect the outside town from them rather than the other way around.");
    
    set_items(([
        "houses" : "They look old and abandoned."
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "dtowne5.c",
	"east" : ROOMS "dtowne7.c",
	     
	 ]));
    
}


