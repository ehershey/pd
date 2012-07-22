#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("Deathless hall");
    set_day_long("%^ORANGE%^Awesome staircases of %^BOLD%^gold %^RESET%^%^ORANGE%^and %^RED%^ruby %^ORANGE%^branch up, straight north, northwest and northeast.  The actual staircases are made of %^BOLD%^gold%^RESET%^%^ORANGE%^, while the steps are %^RED%^ruby plates%^ORANGE%^.  The odd %^RESET%^%^BOLD%^silver %^RESET%^%^ORANGE%^swirl or engraving of some kind is indented in the %^BOLD%^gold %^RESET%^%^ORANGE%^but otherwise this area is pretty plain.                                                                          %^BOLD%^%^BLACK%^The rest of the area is pitch black, a dim %^RESET%^%^ORANGE%^orange %^BOLD%^%^BLACK%^light flickers from the top of the stairs.");
    
    set_night_long("%^ORANGE%^Awesome staircases of %^BOLD%^gold %^RESET%^%^ORANGE%^and %^RED%^ruby %^ORANGE%^branch up, straight north, northwest and northeast.  The actual staircases are made of %^BOLD%^gold%^RESET%^%^ORANGE%^, while the steps are %^RED%^ruby plates%^ORANGE%^.  The odd %^RESET%^%^BOLD%^silver %^RESET%^%^ORANGE%^swirl or engraving of some kind is indented in the %^BOLD%^gold %^RESET%^%^ORANGE%^but otherwise this area is pretty plain.                                                                             %^BOLD%^%^BLACK%^The rest of the area is pitch black, a dim %^RESET%^%^ORANGE%^orange %^BOLD%^%^BLACK%^light flickers from the top of the stairs.");
    


    set_items(([
	  "stairs" : "These stairs are beautiful but plain.",
	  "plates" : "The plates are ruby red and somewhat worn.",  	                
        	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"up" : ROOMS "cainthrone.c",
        "down" : ROOMS "cainball5.c",
       ]));
}

void reset() {
  ::reset();
    if(!present("advisor")) 
      new(MOB "cainsadvisor")->move(this_object());
}
