#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("%^BLUE%^Peaceful glyphs cover the ground here.  The Avatar must have wanted his followers to be safe.%^RESET%^  In all directions, nothing can be seen but rock and the sky.  The only way to go now is north or southwest and the walls are far too steep to scale.");
    
    set_items(([
          "path" : "The path is composed of many little stones.  They have been covered by vegetation.",
          "hills" : "The hills are made up of a grey rock slightly darker than that of the structure.",
          "rock" : "The hills are made of a dark grey rock.",
          
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 1,
        "no teleport" : 1,
        "no attack" : 1,
        "no steal" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal6.c",
        "southwest" : ROOMS "seekpal4.c",
        
       ]));
}
