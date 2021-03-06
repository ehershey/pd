#include <std.h>
#include <lost.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("lost field");
        set_short("Lost Field");
        set_day_long("%^GREEN%^%^BOLD%^A sheer cliff to the north goes straight down here. The grass of the field is rather long, making it difficult to travel through. A small tree stands off in the distance, blowing in the wind. The sun beats down on the field, reflecting off of all the grass. A soft breeze rustles the grass, making the field look alive. Some large beast can be seen far off in the distance, perhaps it is just an illusion. A large tree stands here with some large vines hanging off of them.%^RESET%^"); 

        set_night_long("%^GREEN%^A sheer cliff to the north goes straight down here. The darkness makes it difficult to tell how far the field stretches. A soft breeze blows through here, making the grass of the field rustle. Strange shadows can be seen moving in the distance, it is impossible to tell what they are though. The field is very quiet at night, only the sounds of the wind blowing fills the air. A large tree stands here with some large vines hanging off of them.%^RESET%^"); 

        set_properties(([ "light"          : 1,
                       "plain"          : 1,
                       "night light"    : 0
        ]));
        set_items(([
        "grass"               : "Tall thick grass that fills the field.",
        "tree"                  :   "A large tree with many thick vines hanging from it.",
        "vines"     : "Large vines that hang down from the tree, one of them seems to go over the cliff.",
        "vine"      : "A large thick vine that goes straight down the cliff, it may be possible to climb down it.",
        ]));
        set_smell("default","The smell of pollen fills the air.");
        set_listen("default","Grass rustles in the breeze.");
	    set_exits(([
			"east"		: ROOMS "lost_field034.c",
			"south"		: ROOMS "lost_field032.c",

        ]));
}

void init()
{
    ::init();
    add_action("climb_funct", "climb"); // function, command
}

int climb_funct(string str)
{
    if(str == "down vine")
    {  
        write("You climb down the vine.");
        message("room", this_player()->query_cap_name()+" climbs down a vine.", environment(this_player()), this_player());
       this_player()->move("/d/freepk/merkkerri/lost_caves/rooms/beach01.c");
       this_player()->force_me("look"); 
        return 1;
    }
    return notify_fail("Climb what?");
}
