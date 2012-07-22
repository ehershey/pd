#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("A hidden path in the jungle");
   set_long(
            "%^GREEN%^A small break in the jungle allows travel "
            "to the north. The main path is back south. Trees "
            "and plants are pretty much the only sight to see.%^RESET%^");
   set_items(([
            "trees" : "There are plenty of trees on each side of the path. "
                        " They are all different sizes and varieties, "
                        "but they all have an exotic look to them.",
            "path" : "The main path is south of here. ",
            "plants" : "All sorts of different plant species grow in the jungle"
                 ". Most of them are huge compared to more domesticated plants.",
            "canopy" : "The canopy is very thick, allowing little or no access"
                " to the vastness of the sky. ",
            "break" : "This is a small break in the jungle. It leads north "
                "and the main path is south of here. "
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "The buzzing of large insects from all over. ");
   set_exits( ([ 
        "north" :  ROOMS "n_4",
        "southeast" : ROOMS  "n_2"]));
    if(!present("ant")) new(MOB"ant1.c")->move(this_object());
    if(!present("ant 2")) new(MOB"ant4.c")->move(this_object());
    if(!present("ant 3")) new(MOB"ant3.c")->move(this_object());
}
