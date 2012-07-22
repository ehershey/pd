#include <std.h>
#include <simaril.h>

inherit ROOM;
void create()
{
    ::create();
        set_name("small island");
        set_short("Small island");
        set_long("Lush green plants cover the entire island with the exception of a sandy shore that circles the island. "
                  "Out in the water are the piers of Simaril, and beyond that the town of the same name. "
                  "Several large trees stand tall above the plants to the west, deeper into the island. "       
                );  
        set_properties( ([
        "light"       : 2,
        "night light" : 0,
        "forest"      : 1,
        ]) );
        set_items(([
        "piers"     :   "Several large wooden piers jut out into the sea from the land to the north.",
        "sea"       :   "A vast sea which looks endless.",
        ({"city","simaril"})      :   "The port town of Simaril, if it can be found in the world, it is probably sold here. Traders come from all around the world to try and sell rare and expensive items.",
        "island"    :   "A small island covered with lush greens.",
        "water"     :   "Small waves break on the sandy shore. It may be possible to swim to land and reach the town from here.",
        "plants"    :   "A wide variety of green plant life that grows wild.",
        "shore"     :   "A thin sandy beach that circles most of the island.",
        "trees"     :   "Large, thin, and tall. Maybe they have some fruit growing on them.",
        ]));
            set_listen("default", "The waves wash up on the shore creating a calming scene. Occasionally  a strange noise from the island breaks the peace.");
            set_smell("default", "Sea salt fills the air, masking out all other smells.");
                set_exits(([
                        "northwest"         : ROOMS"island02.c",
                                  
        ])); 
}
 
void reset() {
   ::reset();

   
}
      

void init() {
        ::init();
                add_action("go_dive", "swim");
}


int go_dive(string str)
{
        if(!str)
                return notify_fail("Swim to what?\n");
        if(str != "to land")
                return notify_fail("You can not swim to that!\n");
        
        message("target", "You run out into the water, pushing passed all the waves. After a quick swim you reach dry land.", this_player()); 
        message("room", ""+this_player()->query_cap_name()+" runs out into the water!", environment(this_player()), this_player());
        this_player()->move(ROOMS"simaril010.c");
        return 1;
}





