#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("In a jungle");
   set_long(
            "%^GREEN%^Huge trees are everywhere. Large plants grow everywhere, "
            "but seem to be very dense just off the path. Small rocks cover "
            "parts of the path. A small pile of bones lies partially on the "
            "path and partially in the plants. The canopy is thick, allowing "
            "in very little light, no matter what time of day it is.%^RESET%^");
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
            "bones" : "A small pile of bones can barely be seen here. It's "
                "partially hidden by some plants. Whatever it was isn't "
	        "suffering from the humidity anymore. "
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "The buzzing of large insects from all over. ");
   set_exits( ([ 
        "west" :  ROOMS "54",
        "east" :  ROOMS "56"]));
    if(!present("hunter")) new(MOB"dh1.c")->move(this_object());
    if(!present("ant")) new(MOB"ant3.c")->move(this_object());
    if(!present("rat")) new(MOB"rat3.c")->move(this_object());
    if(!present("rat 2")) new(MOB"rat2.c")->move(this_object());
}
