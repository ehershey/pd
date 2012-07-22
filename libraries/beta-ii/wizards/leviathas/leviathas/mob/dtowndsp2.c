#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^A tiny and slender spire stands here.  The bridge linking it to the rest of the town could crumble at any "
           "moment.  When the %^YELLOW%^lightning%^BLACK%^ strikes, it lights up the side of the spire and snatches it's form from the shadows.  "
           "It is composed of countless %^RESET%^%^BLUE%^ve%^GREEN%^ig%^BLUE%^n%^GREEN%^s%^BLACK%^%^BOLD%^, all of which rapidly pump blood.  A "
           "dark opening which must be the door is also here amidst the beating walls.");
   
    set_night_long("%^BOLD%^%^BLACK%^A tiny and slender spire stands here.  The bridge linking it to the rest of the town could crumble at any "
           "moment.  When the %^YELLOW%^lightning%^BLACK%^ strikes, it lights up the side of the spire and snatches it's form from the shadows.  "
           "It is composed of countless %^RESET%^%^BLUE%^ve%^GREEN%^ig%^BLUE%^n%^GREEN%^s%^BLACK%^%^BOLD%^, all of which rapidly pump blood.  A "
           "dark opening which must be the door is also here amidst the beating walls.");
    
    set_items(([
        "spire" : "The entire spire is composed of veigns."
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "southwest" : ROOMS "dtowndsp1.c",
	"opening" : ROOMS "dspire1.c",		     
	 ]));
	
    add_invis_exit("opening");
}

