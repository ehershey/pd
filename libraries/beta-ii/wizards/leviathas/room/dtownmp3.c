#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A glass path");
    set_day_long("%^BOLD%^The light is complete.  The mansion shimmers "
"an almost blinding beauty, while south a small, quiet town slumbers. "
"A huge, glass doorway to the north is open and a %^RED%^red%^RESET%^"
"%^BOLD%^ carpet has been rolled down the steps leading up to it.  ");
    
    set_night_long("%^BOLD%^The light is complete.  The mansion shimmer"
"s an almost blinding beauty, while south a small, quiet town slumbers. "
"A huge, glass doorway to the north is open and a %^RED%^red%^RESET%^%"
"^BOLD%^ carpet has been rolled down the steps leading up to it.  ");

    set_items(([
          "path" : "The path has been lit by a blue light produced under"
	"neath the glass.",
          "light" : "It is complete.",
          "mansion" : "The blinding shimmer of the mansion stuns your eyes. " 
	"You can barely make out the sound of music within the doorway.",
          "tower" : "The tower stands lonely, seeming to humm of warning to "
	"itself.  It is rather small, but shadows leap all across it and you "
	"can definately make out humanoid shapes.",
          
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "dtownmp2.c",
                
       ]));
    add_invis_exit("");   
}

void init() {
 ::init();
   add_action("mansion", "enter");
}

int mansion(string str) {
   if (!str || str != "mansion") return notify_fail("Enter what?\n");
   write("You slowly advance through the massive, glass doors.  They close
behind you.");
   this_player()->move_player( ROOMS  "vhall1.c");
   return 1;
}

