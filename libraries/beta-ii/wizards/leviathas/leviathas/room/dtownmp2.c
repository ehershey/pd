#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A glass path");
    set_day_long("%^CYAN%^%^BOLD%^The light is getting brighter and the "
"mansion shimmers in it, however the tower which extends from it remain"
"s a ghastly jet black.  Not far north from here is a huge, glass door. ");
    
    set_night_long("%^CYAN%^%^BOLD%^The light is getting brighter and t"
"he mansion shimmers in it, however the tower which extends from it rem"
"ains a ghastly jet black.  Not far north from here is a huge, glass door. ");

    set_items(([
          "path" : "The path has been lit by a blue light produced under"
	"neath the glass.",
          "light" : "The blue light is becoming quite strong.",
          "mansion" : "Now illuminated by the blue light, the mansion "
	"shimmers as if it were blue silver.",
          "tower" : "The darkness of the tower is uninterrupted by the "
	"blue light.",
          
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "dtownmp3.c",
        "south" : ROOMS "dtownmp1.c",
        
       ]));
    add_invis_exit("");   
}
