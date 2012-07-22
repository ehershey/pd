#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("In a jungle");
   set_long(
            "%^GREEN%^The deeper in the jungle the thicker the trees "
            "become. Plants also grow abundantly and the path is very "
            "hard to see at points. Small rocks litter the path in "
            "various places. A large birds nest can be seen high in "
            "a tree. The canopy is very thick, allowing little light "
            "shine upon the path, no matter what time of day.%^RESET%^");
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
            "rocks" : "Some small rocks, some big rocks. They are all over "
                 "the old dirt path. ",
            "nest" : "The birds nest sits high above in a tree. It's hard to "
                 "fathom what type of bird would need a nest so big.",
            "canopy" : "The canopy is very thick, allowing little or no access"
                " to the vastness of the sky. "
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "The buzzing of large insects from all over. ");
   set_exits( ([ 
        "northwest" :  ROOMS "64",
        "northeast" :  ROOMS "65",
        "southwest" :  ROOMS "72",
        "southeast" : ROOMS  "73"]));
    if(!present("hunter")) new(MOB"dh2.c")->move(this_object());
    if(!present("hunter 2")) new(MOB"dh2.c")->move(this_object());
    if(!present("beetle")) new(MOB"beetle2.c")->move(this_object());
}
