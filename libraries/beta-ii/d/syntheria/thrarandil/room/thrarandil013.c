#include <std.h>
#include <thrarandil.h>

inherit ROOM;

int cmd_squeeze(string);

void create()
{
    ::create();
        set_name("dirt road");
        set_short("Dirt Road");
        set_long("A thin dirt road that runs off of the main road. This road looks like it is very old, there is no grass anywhere on it, and the ground is packed down hard. A small lantern is fixed to one of the buildings. The buildings on this street look to be old and decrepit, this is where most of the dock hands live.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "buildings"     :   "Small homes for all the workers. Each home has little window that looks out onto the steet.",
            "lantern"       :   "A small lantern fixed to the side of a house. There look to be some scratches at the base of the lantern.",
            "scratches"     :   "Some thin scratches at the base of the lantern, it looks like the lantern has been moved.",
        ]));
        set_listen("default", "It is rather quiet in this part of town.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
                        "north"          : ROOMS "thrarandil014.c",
                        "south"          : ROOMS "thrarandil012.c",
        ]));
        add_invis_exit("twist hinge");
        
}

void init()
{
    ::init();
    add_action("cmd_twist", "twist");
    
}

int cmd_twist(string str)
{
    if(!str)
    {
    write("Twist what?\n");
    return 1;
    }
    if(str != "lantern")
    {
    write("Now why would you want to twist " + str + "!\n");
    return 1;
    }
    
    message("twist", "The ground disappears beneath your feat, and you fall!", this_player());
	message("other_twist", this_player()->query_cap_name()+" falls through a hole in the ground that quickly vanishes!", environment(this_player()), this_player());
	
	this_player()->move(ROOMS "thrarandilRhall.c");
	this_player()->force_me("look");
    return 1;
}


