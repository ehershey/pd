#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("In a pond");
   set_long(
            "%^BOLD%^%^CYAN%^The water is warm in the pond. The jungle "
            "can be seen all around the pond. Trees stretch high into "
            "the sky and wild plants grow wherever they please. Mosquitos "
            "buzz above the pond, as they use this for their breeding "
            "grounds.%^RESET%^");
   set_items(([
            "trees" : "The trees grow wildly next to the pond. ",
            "plants" : "All sorts of different plant species grow in the jungle"
                 ". Most of them are huge compared to more domesticated plants "
                 "common to the land of Tirun.",
            "pond" : "The pond is refreshing in the warmth and humidity "
                 "of the jungle. ",
            "mosquitos" : "Giant mosquitos buzz over the pond. They probably "
                "use this pond to mate and hatch their eggs. "
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "The buzzing of large insects from all over. ");
   set_exits( ([ 
        "northwest" :  ROOMS "p_20",
        "northeast" :  ROOMS "p_21",
        "west" : ROOMS  "p_24",
        "east" :  ROOMS "p_26"]));
    if(!present("mosquito")) new(MOB"mosq4.c")->move(this_object());
    if(!present("mosquito 2")) new(MOB"mosq2.c")->move(this_object());
}
