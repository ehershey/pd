#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountains" : 1, "town" : 1]) );
   set_short("Steel Hammer Circle Park");
   set_long(
            "There is a fence wrapping all the way around the park.  "
            "An ancient oak tree stands in the very center of "
            "Steel Hammer Circle Park. Next to the tree, an immaculate "
            "stone statue of a Dwarf stands tall. There are houses "
            "and buildings visable all through the village. Many dwarves "
	    "roam through the park and the village. Enormous mountains "
	    "in the distance surround the village. Platinum Street "
	    "intersects with Silver Street here.");
   set_items(([
            "mountains" : "The mountains stretch in all directions. They "
                        "surround the small village. ",
            "platinum street" : "Platinum Street is the main street in the "
		 "village. It runs east and west and is usually very busy.",
            "silver street" : "Silver Street runs north and south through "
		 "Steel Hammer Circle Park. It is a very busy street in "
		 "the village. Many homes and businesses are on Silver Street.",
            "houses" : "Small stone buildings that have been carved from the "
                "mountains lie ahead. They're all in different "
		"shapes and sizes, but they are all pretty small.",
            "road" : "A very interesting design. The road is stone, carved "
                "from the mountain, and into various designs. The designs "
		"are very artistic and beautiful.",
            "fence" : "The fence surrounds the park here in the center "
                "of the village. It's iron and was probably mined in "
		"these very mountains.",
            "dwarves" : "Dwarves are seen through the gate running all "
                "around the village, taking part in their daily activities.",
	    "buildings" : "Many small buildings can be seen through the "
		 "village."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "The solf rumble of the village drones the air.");
   set_exits( ([ 
        "west" :  ROOMS "sh_5",
	"north" : ROOMS "sh_13",
	"south" : ROOMS "sh_14",
        "east" :  ROOMS "sh_7"]));
}
void reset() {
::reset();
    if(!present("crazy lady")) new(MOB"crazylady.c")->move(this_object());
    if(!present("villager")) new(MOB"villager2.c")->move(this_object());
    if(!present("child")) new(MOB"dwarfboy1.c")->move(this_object());
    if(!present("child 2")) new(MOB"dwarfgirl1.c")->move(this_object());
    if(!present("statue")) new(ITEMS"statue.c")->move(this_object());
    if(!present("tree")) new(ITEMS"oak.c")->move(this_object());
}
