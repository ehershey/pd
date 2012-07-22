// this is a room that will show you a couple of different things you can do
// Suluial

#include <std.h>
#include "new_wiz.h"
inherit ROOM;

void create() {
::create();
   set_short("A middle class house");
   set_long("A nice home, probably owned by a merchant or craftsman. "
            "There are some stairs leading down to the cellar, and another "
            "flight of stairs leading upstairs.  Under the stairs is a small"
" cabinet with a vase with some beautiful tulips that are in "
            "season this time of year on it.  A family portrait hangs over a "
            "low burning fireplace.  Over the fire hangs an iron pot with "
            "pleasant aromas coming from it.");
   set_items(([
         "stairs" : "They lead both down to the cellar, and upstairs.",
         "vase" : "A crystal vase made by a local craftsman.",
         "tulips" : "These are beautiful %^YELLOW%^%^BOLD%^yellow tulips"
                  "%^RESET%^ that were picked from the garden.",
         "portrait" : "It is a portrayel of the family done in acrylics.",
         "family" : "Family of four, a father, mother, and two daughters.",
         "fireplace" : "Made of granite, it has a mantle and a low burning "
                    "%^RED%^fire %^BOLD%^%^ORANGE%^glows%^RESET%^ in it."
                    " An iron pot hangs from a hook.",
         "pot" : "Dinner slowly simmers withing, it seems to be beef stew",]));
   set_properties(([
	"light" : 1,
        "night light" : 1,
        "indoors" : 1,
        ]));
   set_exits(([
	"cellar" : ROOMS "house_cellar.c",
	"upstairs" : ROOMS "house_up.c",
    ]));
}

void reset() {
    set_search("clothes", (: this_object(), "cabinet_searching" :));
    set_search("cabinet", "There are some nice looking clothes in here.");
    if(!present("cabinet"))
        new(OBJ "cabinet.c")->move(this_object());

}

void cabinet_searching() {
    message("my_action", "Rummaging through the clothing, you find a pair"
      " of boots that might fit you", this_player());
    message("other_action", this_player()->query_cap_name()+" finds "
      "a wonderful pair of boots among the clothing.",
       this_object(), ({ this_player() }));
   new(ARM "wond_boots.c")->move(this_object());
    remove_search("clothes");
}
