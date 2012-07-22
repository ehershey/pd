#include <std.h>
#include <simaril.h>

inherit ROOM;
int padlock = 0;
void create()
{
    ::create();
        set_name("simaril pier");
        set_short("Simaril Pier");
        set_long("The large wooden pier stands firmly in the sea floor. All around waves smash into the wooden supports, causing the whole structure to sway back and forth. "
                    "To the north the pier extends further out into the sea, into what looks like far deeper waters. "
                    "An array of boats are docked here, many would seem to be simple fishing vessels. Some are bustling with activity while others look deserted. "
                );  
        set_properties( ([
        "light"       : 2,
        "night light" : 0,
        "town"        : 1,
        ]) );
        set_items(([
        "piers"     :   "Several large wooden piers jut out into the sea from the land to the north.",
        "pier"      :   "A large wooden structure, it meets with land to the south. Many large wooden pillars stretch into the air, stabilizing the pier, and are used by ships to secure them to the structure.",
        "sea"       :   "The endless sea meets the horizon far to the north and west, its waves slam into the pier. A small island sits just off to the west",
        "boats"     :   "A large variety of boats, some as small as dinghies, and some as large as warships.",
        ({"city","simaril"})      :   "The port town of Simaril, if it can be found in the world, it is probably sold here. Traders come from all around the world to try and sell rare and expensive items.",
        "island"    :   "A small island covered with lush greens. It may be possible to swim to it through the water.",
        "water"     :   "It is far below the pier, but it may be possible to dive into the water, and than swim to the island.",
        ]));
            set_listen("default", "Dock hands can be heard cursing all around.");
            set_smell("default", "Sea salt fills the air, masking out all other smells.");

                set_exits(([
                        "north"         : ROOMS"simaril002.c",
                        "east"          : ROOMS"simaril004.c",           
        ])); 
}
 
void reset() {
   ::reset();

   
}
      

void init() {
        ::init();
                add_action("go_dive", "dive");
}


int go_dive(string str)
{
        if(!str)
                return notify_fail("Dive into what?\n");
        if(str != "into the water")
                return notify_fail("You can not dive into that!\n");
        
        message("target", "You leap off the pier and slam into the cold water below. After fighting the current you find yourself on a small island near the piers.", this_player()); 
        message("room", ""+this_player()->query_cap_name()+" leaps off the pier and down into the water!", environment(this_player()), this_player());
        this_player()->move(ROOMS"island01.c");
        return 1;
}





