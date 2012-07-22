#include <std.h>
#include <thrarandil.h>

inherit ROOM;

int cmd_start(string str);

void create()
{
    ::create();
        set_name("thrarandil square");
        set_short("Thrarandil Square");
        set_long("This is the main square of the ancient port town Thrarandil. After the great chaos, this was the first town founded on this continent. The square is the intersection of Emmurd street, which runs from north to south, and Uhreln avenue, which runs from west to east. A large cathedral lies to the northwest, it looks like it may be the oldest building in the town. A large fountain is at the very center of the square, and at the top of the fountain is the large statue of some human. The streets are made of some very old brick, the brick looks very worn. A strong breeze blows from the west, bringing in the sea air.");  
        set_properties( ([ 
        "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1, 
        ]) );
        set_items(([
            "fountain"      :   "A large water fountain that throws water high into the air, it has a large statue at its very top.",
            "statue"        :   "A large statue of a human monk, he is pointing to the east.",
            "brick"         :   "Light red brick, it is very old and worn.",
        ]));
        set_listen("default", "Many people can be heard talking in all directions.");
        set_smell("default", "The strong smell of sea salt fills the air.");
        set_exits(([
			"north"		: ROOMS "thrarandil045.c",
			"south"		: ROOMS "thrarandil001.c",
			"east"		: ROOMS "thrarandil052.c",
			"west"		: ROOMS "thrarandil033.c",
        ]));
        
}


void reset() {
    ::reset();
        if(!present("fountain"))
            new(OBJ "fountain.c")->move(this_object());
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

   
this_player()->set_primary_start("/d/syntheria/thrarandil/room/thrarandil000.c");
    write("You are now set to start in Thrarandil.");
    return 1;
}
