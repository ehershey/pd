#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^This path looks old and even the weeds that have grown up around it are dead.  A beautiful gate stands north, with two houses northeast and northwest.  All is silent.");
   
    set_night_long("%^BOLD%^%^BLACK%^This path looks old and even the weeds that have grown up around it are dead.  A beautiful gate stands north, with two houses northeast and northwest.  All is silent.");
    
    set_items(([
        "houses" : "The houses to the northeast and northwestwest look pretty big... and scary.",
        "gate" : "The gate is crafted of beautiful gold but has rusted over the years.  What little can be seen behind it is a beautiful garden, full of life.",
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "dtownm2.c",
	"south" : ROOMS "dtowne5.c",
	     
	 ]));
    
}


