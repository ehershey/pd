#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^There are a lot less buildings around here.  Large walls protect the city from light but a tiny bit seeps through a crack in the wall.  Paths lead north and south. ");
   
    set_night_long("%^BOLD%^%^BLACK%^There are a lot less buildings around here.  Large walls protect the city from light but a tiny bit seeps through a crack in the wall.  Paths lead north and south. ");
    
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
        "west" : ROOMS "dtowne6.c",
	"south" : ROOMS "jungleent.c",
	"north" : ROOMS "dtowne8n.c",
	     
	 ]));
    
}


