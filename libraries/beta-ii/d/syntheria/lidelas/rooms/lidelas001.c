#include <std.h>
#include <lidelas.h>

inherit ROOM;

int cmd_start(string str);

void create()
{
    ::create();
        set_name("lidelas square");
        set_short("Lidelas Square");
        set_long("This is the town center of Lidelas, a small town that belongs to the Syntheria Empire. This square is the where the two main streets of Lidelas intersect. Rafore street runs north and south, while Feng avenue goes east and west through the town. A large statue sits in the center of the square. The statue is of a horse on its hind legs, with a heavily armored soldier on it. The statue takes up a large portion of the square, and is very tall. Large metal benches dot the square, each on looks like a work of art. The ground is made of square bricks, they look as if they have just been laid. Large buildings surround the square, each building reaches into the sky. The buildings have large statues of gargoyles perched on them, looking down onto the square. An orb sits a top a pedestal just in front of the statue.");  
        set_properties( ([ "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1 ]) );
        set_items(([
        "statue"   : "This large statue is made of solid bronze. It looks like it was made by a true master of the craft, it must have taken some time to complete.",
        "bench"    : "A bench made of solid bronze, it has many small gargoyles molded into it. The bench looks like it has been secured to the ground."
            ]));
            set_listen("default", "The sounds of people socializing around the square fill the air.");
            set_smell("default", "The odor of horse manure fills the air.");
            set_exits(([
			"north"		: ROOMS "lidelas039.c",
			"south"		: ROOMS "lidelas002.c",
			"east"		: ROOMS "lidelas010.c",
			"west"		: ROOMS "lidelas028.c",
        ]));
}


void reset() {
    ::reset();
        if(!present("orb"))
            new(OBJ "newb_orb.c")->move(this_object());
}


void init()
{
    ::init();
    add_action("cmd_start", "start");

}

int cmd_start(string str)
{
    if (!str || str=="") 
    {
        notify_fail("Start where?\n");
        return 0;
    }

    if (str!="here")
    {
        notify_fail("You cannot start there.\n");
        return 0;
    }

   
this_player()->set_primary_start("/d/syntheria/lidelas/rooms/lidelas001.c");
    write("You are now set to start in Lidelas.");
    return 1;
}
