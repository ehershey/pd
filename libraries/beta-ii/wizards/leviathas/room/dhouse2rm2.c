#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("This is a plain room with a nice bed in the corner.  A tiny trapdoor on the ceiling would suggest that there is an attic.");
   
    set_night_long("This is a plain room with a nice bed in the corner.  A tiny trapdoor on the ceiling would suggest that there is an attic.");
    
    set_items(([
        "stairs" : "They are made of wood.",
        "bed" : "It is well kept.",
        "trapdoor" : "It leads to the attic.",
                  
        
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "downstairs" : ROOMS "dtowne2e1.c",
                
                
    ]));

}

void init() {
 ::init();
   add_action("trapdoor", "enter");
}

int trapdoor(string str) {
   if (!str || str != "trapdoor") return notify_fail("Enter what?\n");
   write("You push the door to the attic aside and climb up.");
   this_player()->move_player( ROOMS  "attic.c");
   return 1;
}
