#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("In a jungle");
   set_long(
            "%^GREEN%^Most of the trees give way on the southern side of "
            "the path and allow a big portion of the pond to be seen. A "
            "large rock has fallen down the mountain and sits just near "
            "the edge of the pond. Trees grow abundantly on the north side "
            "of the path. Lots of plants grow wildly all around the old, "
            "worn out path.%^RESET%^");
   set_items(([
            "trees" : "There are plenty of trees on each side of the path. "
                        " They are all different sizes and varieties, "
                        "but they all have an exotic look to them.",
            "path" : "An old, worn dirt path leads through the jungle. "
                 "It gets hard to see sometimes because the plants are "
                 "so dense with all the plantlife.",
            "plants" : "All sorts of different plant species grow in thejungle"
                 ". Most of them are huge compared to more domesticated plants.",
            "rocks" : "Some small rocks, some big rocks. They are all over "
                 "the old dirt path. ",
            "rock" : "A large rock has fallen from the mountain and landed "
                 "right here next to the pond. ",
            "pond" : "A good sized pond sits on the southern and western sides"
                 "of the path.",
            "canopy" : "The canopy is very thick, allowing little or no access"
                " to the vastness of the sky. "
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "The buzzing of large insects from all over. ");
   set_exits( ([ 
        "northwest" :  ROOMS "69",
        "northeast" :  ROOMS "70",
        "climb" :  ROOMS "rock",
        "southeast" :  ROOMS "74"]));
set_invis_exits(({"climb"}));
    if(!present("bison")) new(MOB"bison2.c")->move(this_object());
    if(!present("bison 2")) new(MOB"bison1.c")->move(this_object());
    if(!present("gorilla")) new(MOB"gorilla1.c")->move(this_object());
    if(!present("gorilla 2")) new(MOB"gorilla2.c")->move(this_object());
    if(!present("gorilla 3")) new(MOB"gorilla3.c")->move(this_object());
    if(!present("gorilla 4")) new(MOB"gorilla4.c")->move(this_object());
}
