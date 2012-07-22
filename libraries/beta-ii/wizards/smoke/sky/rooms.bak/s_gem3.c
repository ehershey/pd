#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountains" : 1, "town" : 1]) );
   set_short("Platinum Street and Gem Street - Steel Hammer Village");
   set_long(
            "The street turns sharply here where Gem Street and "
            "Copper Street intersect. A corner has been carved into "
            "the mountain to accomidate the roads. Several buildings "
            "can be seen north on Gem Street and a tall tower is "
            "west along Copper Street. Large mountains can be "
            "seen totally surrounding the village.");
   set_items(([
            "mountains" : "The mountains stretch in all directions. They "
                        "surround the small village. ",
            "road" : "A very interesting design. The road is stone, carved "
                "from the mountain, and into various designs. The designs "
                "are very artistic and beautiful.",
            "corner" : "A corner has been cut into the mountain, allowing "
                 "the roads to intersect as they do.",
            "tower" : "A tall, narrow tower stretches high into the sky "
                 "just west of here.",
            "buildings" : "Several buildings can be seen along Gem Street.",
            "buildings" : "Shops and buildings line both Platinum and "
                 "Gem Streets."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "The solf rumble of the village drones the air.");
   set_exits( ([ 
        "west" :  ROOMS "e_copper4.c",
        "north" : ROOMS "s_gem2"]));
}
void reset() {
::reset();
    if(!present("sign")) new(ITEMS"sign4.c")->move(this_object());
    if(!present("thief")) new(MOB"thief.c")->move(this_object());
    if(!present("villager")) new(MOB"villager1.c")->move(this_object());
}
