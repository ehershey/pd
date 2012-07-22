#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1]) );
   set_long(
            "There is an intersection here between Platinum Street  "
            "and Bronze Street. There are houses along both roads.  "
            "The roads have very beautiful designs carved into them."
            "Dwarven villagers are all over the village, doing whatever "
            "it is that they do. Giant mountains surround the small "
	    "village. Large gates can be seen to the distant west. ");
   set_items(([
            "mountains" : "The mountains stretch in all directions. They "
                        "surround the small village. ",
            "platinum street" : "Platinum Street is the main street in the "
		 "village. It runs east and west and is usually very busy.",
            "houses" : "Small stone buildings that have been carved from the "
                "mountains lie ahead. They're all in different "
		"shapes and sizes, but they are all pretty small.",
            "bronze street" : "Bronze Street is a residential street. There "
                "are many houses on the east side of the street and the"
		 " mountains act as the city wall on the western side.",
            "roads" : "A very interesting design. The road is stone, carved "
                "from the mountain, and into various designs. The designs "
		"are very artistic and beautiful.",
            "dwarves" : "Dwarves are seen through the gate running all "
                "around the village, taking part in their daily activities."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "The solf rumble of the village drones the air.");
   set_exits( ([ 
        "west" :  ROOMS "sh_2",
	"north" : ROOMS "n_bronze1",
	"south" : ROOMS "s_bronze1",
        "east" :  ROOMS "sh_4"]));
}
void reset() {
    ::reset();
    if(!present("ant hill", this_object()))
        new(ITEMS"hill.c")->move(this_object());
}
