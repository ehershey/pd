#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("In a pond");
   set_long(
            "%^BOLD%^%^CYAN%^The warm water is almost relaxing. The "
            "jungle is so hot and humid that this pond feels great. The "
            "water seems to be getting deeper as it distances itself "
            "from land. Tall trees stretch high in the distance, and "
            "beyond that mountains can be seen reaching even higher. "
            "The plants can be seen ashore growing wildly as they "
            "please. Mosquitos fly around the pond watching over their "
            "eggs.%^RESET%^");
   set_items(([
            "trees" : "The trees grow wildly around the pond. ",
            "plants" : "All sorts of different plant species grow in the jungle"
                 ". Most of them are huge compared to more domesticated plants "
                 "common to the land of Tirun.",
            "pond" : "The pond is refreshing in the warmth and humidity "
                 "of the jungle. ",
            "mountains" : "Mountain peaks are visable poking out over the "
                 "trees. They totally surround the jungle.",
            "mosquitos" : "Giant mosquitos buzz over the pond. They probably "
                "use this pond to mate and hatch their eggs. "
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "The buzzing of large insects from all over. ");
   set_exits( ([ 
        "northwest" :  ROOMS "p_7",
        "northeast" :  ROOMS "p_1",
        "southwest" :  ROOMS "p_15",
        "down" :  ROOMS "dp_4",
        "southeast" : ROOMS  "p_16"]));
set_invis_exits(({"down"}));
    if(!present("mosquito")) new(MOB"mosq3.c")->move(this_object());
    if(!present("mosquito 2")) new(MOB"mosq3.c")->move(this_object());
    if(!present("mosquito 3")) new(MOB"mosq4.c")->move(this_object());
}
