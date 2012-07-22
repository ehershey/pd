
#include <std.h>
#include <durst.h>

inherit ROOM;

void create()
{
    ::create();
    set_properties(([
        "light" : 3,
        "night" : 1,
        "dessert" : 1]));
    set_short("MuaBark Desert oasis");
    set_long("There is a pool of crystal clear water here,"
        " around which some palm trees and flowers grow."
        " The plants are the only splash of color for as"
        " far as the eye can see.");
    set_items(([
        ({ "trees", "tree", "palm trees", "palm tree" })
            : "Just regular palm trees.",
        ({ "flower", "flowers", "plant", "plants" })
            : "Colorful desert flowers."
        ]));
    set_exits(([
        "north" : ROOMS "muabark053.c"
        ]));
}

void reset()
{
    ::reset();
    if( !present("nesoo_pool", this_object()) )
        new(OBJ"nes_pool.c")->move(this_object());
}
