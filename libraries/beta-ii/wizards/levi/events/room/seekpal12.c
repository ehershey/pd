#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A grey walkway");
    set_long("A small sheltered area with a roof but no walls marks the entrance to the temple, directly "
	"north of here, however the walkway has been smashed to bits and it is impossible to walk any "
	"farther. ");
    
    set_items(([
          "walkway" : "Utterly smashed, a great struggle must have occurred here.  It's impossible to %^RED%^walk%^RESET%^ any farther...  Perhaps you could %^BLUE%^jump%^RESET%^ to the %^BLUE%^entrance%^RESET%^.",
	  "structure" : "It looks totally out of place, almost unreal.  It is totally unphased.",
	  "pit" : "The walkway seems to be made to cross the pit but it is in horrible shape.",
	  "divine fire" : "The divine fire burns on and on.",
	  "lights" : "The lights are close to where the damage has stopped.",
	  
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "seekpal11.c",
        
       ]));
       
}

void init() {
 ::init();
   add_action("entrance", "jump");
}

int entrance(string str) {
   if (!str || str != "entrance") return notify_fail("What?\n");
   write("You lean back and take a mighty leap forward.");
   this_player()->move_player( ROOMS  "seekpal13.c");
   return 1;
}
