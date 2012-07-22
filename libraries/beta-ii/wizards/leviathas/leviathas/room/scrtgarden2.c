#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^GREEN%^Garden of Darkness%^RESET%^");
    set_day_long("%^GREEN%^The garden is amazing.  %^CYAN%^A%^BOLD%^n underground spring sends warm water bubbling up in a tiny pond to the east%^RESET%^%^GREEN%^. The plant life around there is bright %^BOLD%^green%^RESET%^%^GREEN%^.  Not far north, a stone building can be seen.");
   
    set_night_long("%^GREEN%^The garden is amazing.  %^CYAN%^A%^BOLD%^n underground spring sends warm water bubbling up in a tiny pond to the east%^RESET%^%^GREEN%^. The plant life around there is bright %^BOLD%^green%^RESET%^%^GREEN%^.  Not far north, a stone building can be seen.");
    
    set_items(([
        "trees" : "The trees are simply wonderful.",
        "grass" : "Each blade of grass is simply perfect.  It's almost a shame to step on them.",
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "scrtgarden3.c",
	"south" : ROOMS "scrtgarden1.c",
	     
	 ]));
    
}


