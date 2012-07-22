#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("The rock seems to grow taller in the center of the hills.  To the east, it would appear "
        "that something large slammed into the wall and left a bit of a crater.  Perhaps the Avatar itself "
        "was recently here.");
    
    set_items(([
          "path" : "The path is composed of many little stones.  They have been covered by vegetation.",
          "hills" : "The hills are made up of a grey rock slightly darker than that of the structure.",
          "rock" : "The hills are made of a dark grey rock.",
          "crater" : "It looks like something big hit the wall.",
          
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 1,
        "no teleport" : 1,
    ]));
    set_exits(([
        "northwest" : ROOMS "seekpal7.c",
        "south" : ROOMS "seekpal5.c",
        
       ]));
       
}
