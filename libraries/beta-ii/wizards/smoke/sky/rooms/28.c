#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "forest" : 1]) );
   set_short("In a jungle");
   set_long(
            "%^GREEN%^Trees totally surround the path, which is barely "
            "visable because of all the plant life. Something scurries "
            "into a small break in the jungle north off the path. Some "
            "rocks lay on the path in various places. The air is very "
            "heavy in the jungle. The canopy barely lets any natural "
            "light enter because it's so thick.%^RESET%^");
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
            "break" : "There is a small break in the jungle to the north. No "
                "path leads there, but it looks like something is moving around"
                " in the distance. ",
             "something" : "Something scurries north very quickly, trying to "
                "avoid being seen."
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "The buzzing of large insects from all over. ");
   set_exits( ([ 
        "northeast" :  ROOMS "29",
        "north" :  ROOMS "n_1",
        "west" : ROOMS  "27"]));
set_invis_exits(({"north"}));
    if(!present("ant")) new(MOB"ant1.c")->move(this_object());
    if(!present("ant 2")) new(MOB"ant3.c")->move(this_object());
    if(!present("ant 3")) new(MOB"ant4.c")->move(this_object());
}
