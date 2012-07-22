#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("In a jungle");
   set_long(
            "%^GREEN%^Huge trees are everywhere except to the west a pond "
            "visable. Beautiful, exotic plants grow everywhere and are partic"
            "ularly thick just off the path. The path looks like it's seldomly"
            " used except for possible hunting adventures. The path has a few "
            "rocks scattered about on it. A thick canopy makes it very hard "
            "to see what's going on in the sky.%^RESET%^");
   set_items(([
            "trees" : "There are plenty of trees on each side of the path. "
                        " They are all different sizes and varieties, "
                        "but they all have an exotic look to them.",
            "path" : "An old, worn dirt path leads through the jungle. "
                 "It gets hard to see sometimes because the plants are "
                 "so dense with all the plantlife.",
            "plants" : "All sorts of different plant species grow in the jungle"
                 ". Most of them are huge compared to more domesticated plants.",
            "rocks" : "Some small rocks, some big rocks. They are all over "
                 "the old dirt path. ",
            "canopy" : "The canopy is very thick, allowing little or no access"
                " to the vastness of the sky. ",
            "pond" : "A small, dirty looking pond can be seen through a break "
                "in the jungle. It lies west of this path but the entire thing"
                " isn't visable from here. "
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "The buzzing of large insects from all over. ");
   set_exits( ([ 
        "southwest" :  ROOMS "42",
        "north" :  ROOMS "74",
        "east" :  ROOMS "40"]));
    if(!present("beetle")) new(MOB"beetle3.c")->move(this_object());
    if(!present("beetle 2")) new(MOB"beetle1.c")->move(this_object());
    if(!present("rat")) new(MOB"rat2.c")->move(this_object());
}
