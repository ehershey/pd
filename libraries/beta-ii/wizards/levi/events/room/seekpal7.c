#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("The walls seem to be deteriorating a lot.  Large crater-like marks are all over the place. "
        "Some of them even appear to be burned, the ash still fresh.");
    
    set_items(([
          "path" : "The path is composed of many little stones.  They have been covered by vegetation.",
          "hills" : "The hills are made up of a grey rock slightly darker than that of the structure.",
          "rock" : "The hills are made of a dark grey rock.",
          "craters" : "They look like something big hit the wall.",
          "ash" : "Something powerful must have went storming this way.",
          
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 1,
        "no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal8.c",
        "southeast" : ROOMS "seekpal6.c",
        
       ]));
       
}

