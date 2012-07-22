#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("In a jungle");
   set_long(
            "%^GREEN%^Trees reach up into the sky. A small pond can "
            "be seen through the trees on the southern side of the "
            "small, dirt path. Plants grow abundantly on both sides "
            "of the path. The air is so thick it is hard to breathe.%^RESET%^");
   set_items(([
            "trees" : "There are plenty of trees on each side of the path. "
                        " They are all different sizes and varieties, "
                        "but they all have an exotic look to them.",
            "path" : "An old, worn dirt path leads through the jungle. "
                 "It gets hard to see sometimes because the plants are "
                 "so dense with all the plantlife.",
            "plants" : "All sorts of different plant species grow in the jungle"
                 ". Most of them are huge compared to more domesticated plants "
                 "common to the land of Tirun.",
            "pond" : "A small pond can be seen on the southern side of the "
                "path. Thick plants grow around the pond. The animals of the "
                "jungle probably get most of their water at this pond."
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "Loud birds can be heard talking to eachother "
                 "from the treetops.");
   set_exits( ([ 
        "northeast" :  ROOMS "73",
        "northwest" :  ROOMS "72",
        "south" :  ROOMS "41"]));
    if(!present("mosquito")) new(MOB"mosq2.c")->move(this_object());
    if(!present("mosquito 2")) new(MOB"mosq4.c")->move(this_object());
    if(!present("rat")) new(MOB"rat3.c")->move(this_object());
    if(!present("rat 2")) new(MOB"rat1.c")->move(this_object());
    if(!present("rat 3")) new(MOB"rat2.c")->move(this_object());
}
