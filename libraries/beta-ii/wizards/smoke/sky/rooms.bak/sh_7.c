#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountains" : 1, "town" : 1]) );
   set_short("Steel Hammer Circle Park");
   set_long(
            "There is a fence alongside the path in a circular formation  "
            "here. Just ahead to the west is a giant statue and many "
            "dwarves hustle about. Several houses can be seen in "
            "every direction and some buildings are ahead further east. "
            "The beautifully carved road, Platinum Street, travels "
	    "through the village. Tall mountains surround the village. ");
   set_items(([
            "mountains" : "The mountains stretch in all directions. They "
                        "surround the small village. ",
            "platinum street" : "Platinum Street is the main street in the "
		 "village. It runs east and west and is usually very busy.",
            "houses" : "Small stone buildings that have been carved from the "
                "mountains lie ahead. They're all in different "
		"shapes and sizes, but they are all pretty small.",
            "road" : "A very interesting design. The road is stone, carved "
                "from the mountain, and into various designs. The designs "
		"are very artistic and beautiful.",
            "fence" : "The fence surrounds the park here in the center "
                "of the village. It's iron and was probably mined in "
		"these very mountains.",
	    "statue" : "A statue can be see off to the west.",
            "dwarves" : "Dwarves are seen through the gate running all "
                "around the village, taking part in their daily activities.",
	    "buildings" : "Many small buildings can be seen through the "
		 "village."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "The solf rumble of the village drones the air.");
   set_exits( ([ 
        "west" :  ROOMS "sh_6",
	"northwest" : ROOMS "sh_13",
	"southwest" : ROOMS "sh_14",
        "east" :  ROOMS "sh_8"]));
}
void reset() {
::reset();
    if(!present("villager")) new(MOB"villager2.c")->move(this_object());
}
