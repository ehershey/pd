#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("Atop a rock");
   set_long(
            "%^GREEN%^The top of the rock doesn't give off much more "
            "scenery of the jungle. Trees still dominate the landscape "
            "and various exotic plants live amongst them. The pond is "
            "here next to the rock. Some wild moss grows all around "
            "the slippery rock.%^RESET%^");
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
            "rock" : "A large rock has fallen from the mountain and landed "
                 "right here next to the pond. It looks like a good place to "
                 "dive into the pond. ",
            "pond" : "A good sized pond sits directly next to this rock. ",
            "moss" : "Some wild moss is growing on top of the giant rock.",
            "canopy" : "The canopy is very thick, allowing little or no access"
                " to the vastness of the sky. "
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "The buzzing of large insects from all over. ");
   set_exits( ([ 
        "dive" :  ROOMS "p_1",
        "down" :  ROOMS "72"]));
set_invis_exits(({"dive"}));
    if(!present("mosquito")) new(MOB"mosq2.c")->move(this_object());
    if(!present("mosquito 2")) new(MOB"mosq3.c")->move(this_object());
    if(!present("mosquito 3")) new(MOB"mosq4.c")->move(this_object());
    if(!present("mosquito 4")) new(MOB"mosq1.c")->move(this_object());
    if(!present("mosquito 5")) new(MOB"mosq4.c")->move(this_object());
    if(!present("mosquito 6")) new(MOB"mosq4.c")->move(this_object());
}
