#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The palace of Seeker");
    set_long("A long hallway leads north.  A calming, dim blue light seems to slowly shine down and "
        "offer some solace.  The walls have been crafted to look like water rushing upward.  The "
        "floor is jett black and shiny. " );
    
    set_items(([
          "floor" : "The floor is black and shiny.",
          "walls" : "They have been crafted to look like waves going up.",
          "light" : "Lanterns offer a comforting blue light.",
          
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
        "no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal14.c",
        "back" : ROOMS "seekpal12.c"
        
        
       ]));
       
}



