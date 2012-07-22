#include <lodos.h>
#include <std.h>
inherit VAULT;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 2, "night light" : 1,
     "forest" : 1 ]));
   set_short("The far edge of the forest, still within Lodos");
   set_day_long("The town of Lodos merges with the very edges of the "
     "forest here. The vines, trees and a small house to the west merge "
"together beautifully. A small guard tower stands on the east side of the path here. A small and well tended "
"garden is right before the house to the west. A path leads off south through the forest from here.");
   set_night_long("The town of Lodos merges with the very edges of the "
     "forest here. Vines, trees and a small house spill various strange "
     "shadows across the road. A lantern shines from the garden right "
     "before the house to the west.");
   set_items(([
     "forest" : "It lies south of here, but actually merges before the "
                "borders with the town.",
     "vines" : "They wrap nicely about the house.",
     "trees" : "The beginings of a forest, one in the center of the path.",
     "house" : "The house lies amidst trees, vines and underbrush to the west.",
     "garden": "It is beautiful, a direct result of love and hard work."
   ]));
   set_exits(([ "north" : ROOMS"stown4",
                "west"  : ROOMS"garden",
                "east"  : "/d/coach/rooms/lodos_coach",
                "south"  : "/d/lodos_path/rooms/lodos_path_0.c",
                "enter" : ROOMS"ltower1" ]));
   set_door("door", ROOMS"ltower1", "enter", "");
}

void reset() {
 ::reset();
   if (!present("raccoon"))
     make(MOB"raccoon");
}
