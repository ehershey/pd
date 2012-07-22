#include <std.h>
#include <lost_caves.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("sandy beach");
        set_short("Sandy Beach");
        set_long("The beach stretches far off to the east, hugging the sheer cliff to the south. Waves slide up onto the beach slowly, and recede just as slowly. The sand is bright white, making it very easy to see how far the beach goes. To the north is the endless sea that stretches off into the horizon. To the south is a tall sheer cliff, with a lot of green growth on them. There seems to be a large vine hanging down from above here. To the west the cliff protrudes out into the deep water, making travel impossible in that direction.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"beach"    :  "The beach is composed of an endless amount of white sand.",
    	"sea"    :  "The endless sea sparkles.",
    	"cliff"    : "A very tall sheer cliff, it looks like it is impossible to scale.",
    	"vine"    : "A large vine that hangs down from something a top the cliff, it may be climbable.",
	    ]));
	    set_listen("default", "The sounds of waves fill the air.");
	    set_smell("default", "The smell of sea salt is everywhere.");
	    set_exits(([
			"northeast"	: ROOMS "beach03.c",
			"north"		: ROOMS "beach02.c",

        ]));
}

void init()
{
    ::init();
    add_action("climb_funct", "climb"); // function, command
}

int climb_funct(string str)
{
    if(str == "up vine")
    {  
        write("You climb up the vine.");
        message("room", this_player()->query_cap_name()+" climbs up a vine.", environment(this_player()), this_player());
       this_player()->move("/d/freepk/merkkerri/jungle/lost/room/lost_field033.c");
       this_player()->force_me("look"); 
       return 1;
    }
    return 0;
}