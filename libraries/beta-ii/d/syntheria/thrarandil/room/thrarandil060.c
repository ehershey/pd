#include <std.h>
#include <thrarandil.h>

inherit ROOM;

int cmd_touch(string);

void create()
{
    ::create();
        set_name("irminric circle street");
        set_short("Irminric Circle Street");
        set_long("Irminric Circle Street encircles the southern half of Thrarandil. The street is made of worn cobblestone, it looks to be very old. Some small buildings line the street, they are the homes of the many workers of the city. Each building has a small window looking out into the street. The homes are made of wood and brick, a sharp contrast to the large stone buildings of the inner city. To the north lies a large tower, it reaches high into the sky. There doesn't look to be any entrance to the tower, just a large golden cross at street level where the door should be.");  
        set_properties( ([ 
        "town"        : 1, 
        "light"       : 2,
        "night light" : -2,        
        ]) );
        set_items(([
            "buildings"     :   "Small homes for all the workers. Each home has little window that looks out onto the steet.",
            "tower"         :   "A large white tower, it is very smooth. At the very top is a large golden sphere, which appears to be floating on its own.",
            "cross"         :   "A large golden cross on the south side of the tower. It seems to glow softly, it looks like it could be warm to the touch.",
        ]));
        set_listen("default", "Only the sounds of people walking on the road can be heard.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"west"		: ROOMS "thrarandil058.c",
			"northeast" : ROOMS "thrarandil061.c",
        ]));
        
}

void init()
{
    ::init();
    add_action("cmd_touch", "touch");
    
}

int cmd_touch(string str)
{
    if(!str)
    {
    write("Touch what?\n");
    return 1;
    }
    if(str != "cross")
    {
    write("Now why would you want to touch " + str + "!\n");
    return 1;
    }
    
    message("touch", "A bright light flashes from the cross!", this_player());
	message("other_twist", "A bright light flashes from the tower to the north, and "+this_player()->query_cap_name()+" disappears in it!", environment(this_player()), this_player());
	
	this_player()->move(ROOMS "thrarandilMhall.c");
	this_player()->force_me("look");
    return 1;
}
