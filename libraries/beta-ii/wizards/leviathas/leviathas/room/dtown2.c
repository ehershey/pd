#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A glass path");
    set_day_long("%^BOLD%^%^BLACK%^Silence joins forces with the darkness and the two become one fearsome sight.  Rotting houses that are all shut up are all over the place and the tiles on the ground are mostly busted or shifted upward.  ");
    
    set_night_long("%^BOLD%^%^BLACK%^Silence joins forces with the darkness and the two become one fearsome sight.  Rotting houses that are all shut up are all over the place and the tiles on the ground are mostly busted or shifted upward.  ");

    set_items(([
	  "path" : "The tiles on the path have been smashed by time.",
	  "houses" : "They rott and smell of decay.",
          "mansion" : "The blinding shimmer of the mansion stuns your eyes.  You can barely make out the sound of music within the doorway.",
          "tower" : "The tower stands lonely, seeming to humm of warning to itself.  It is rather small, but shadows leap all across it and you can definately make out humanoid shapes.",
          
 	
    ]));
    set_properties(([
	"outdoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"east" : ROOMS "dtown1.c",
	"west" : ROOMS "dtown3.c",
                
       ]));
    add_invis_exit("");   
}



