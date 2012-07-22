#include <std.h>
#include <thrarandil.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("karisos street");
        set_short("Karisos Street");
        set_long("Karisos Street runs from north to south in the west side of the city. This is one of the most heavily travelled roads in the city of Thrarandil. Many people walk this road when they are on their way to pray at the cathedral to the North. Many of the goods unloaded from the harbor go by on this road, being delivered to homes of shop owners and wealthy buisness men.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "buildings"     :   "Small homes for all the workers. Each home has little window that looks out onto the steet.",
        ]));
        set_listen("default", "It is rather quiet in this part of town.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
                        "north"         : ROOMS "thrarandil017.c",
                        "south"         : ROOMS "thrarandil019.c",
        ]));
        
}

