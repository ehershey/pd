#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("In a jungle");
   set_long(
            "%^GREEN%^Trees are everywhere. Large exotic looking plants "
            "prevent access off of the old, worn path. The thick canopy "
            "barely allows sight of the sky. Loose rocks litter the path."
            " A small pond can barely be seen through the trees on the "
            "northern side of the path.%^RESET%^");
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
            "pond" : "A portion of a small pond can be seen north of "
                 "the path. The entire thing cannot be seen because of "
                 "all the trees.",
            "canopy" : "The canopy is very thick, allowing little or no access"
                " to the vastness of the sky. "
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "Loud birds can be heard talking to eachother "
                 "from the treetops.");
   set_exits( ([ 
        "west" :  ROOMS "46",
        "east" : ROOMS  "44"]));
    if(!present("rat")) new(MOB"rat3.c")->move(this_object());
    if(!present("hunter")) new(MOB"dh1.c")->move(this_object());
}
