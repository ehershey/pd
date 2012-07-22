#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("A path");
    set_long("Arlon is southwest of here.  This path of stones has "
        "been slightly overrun by vines and mossy material.  Something "
        "big can be seen north, some kind of dull grey structure. ");
    
    set_items(([
          "path" : "The path is composed of many little stones.  They have been
covered by vegetation.",
          "vines" : "The vines are pretty fragile looking.",
          "mossy material" : "A thick mossy material covers the ground.",
          "structure" : "An odd looking thing.",
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 1,
        "no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "seekpal2.c",
        "south" : "/d/nopk/arlon/room/plains6"
                
       ]));
       
}


