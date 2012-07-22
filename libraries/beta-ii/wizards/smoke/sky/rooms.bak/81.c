#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "The path continues through the mountains. Palm trees "
            "and shrubs grow wherever there's room. Grass also "
            "grows on the flat land. There are large claw marks "
            "in the wall, probably from one of the large dragons "
            "of the island.");
   set_items(([
            "mountains" : "The mountains stretch in all directions. A mountain"
                        " wall denies any possibility of straying from "
                        "the path.",
            "shrubs" : "Small shrubs grow at random upon the ground.",
            "marks" : "Large claw marks adorn the mountain face. "
                "They're deep and long marks and come three to a set.",
            "trees" : "A few palm trees grow here, providing a little bit of "
                "shade from the elements.",
            "path" : "A dirt path runs through the mountains. ",
            "grass" : "Grass covers the ground just off of the path."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occassionally a twig can be heard snapping from
afar.");
   set_exits( ([ 
        "west" :  ROOMS "80",
        "southeast" :  ROOMS "82"]));
    if(!present("bison")) new(MOB"bison1.c")->move(this_object());
    if(!present("bison 2")) new(MOB"bison1.c")->move(this_object());
}
