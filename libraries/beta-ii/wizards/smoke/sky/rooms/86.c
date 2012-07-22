#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("Surrounded by mountains");
   set_long(
            "The tall mountains completely surround the small path. "
            "Palm trees and small shrubs grow along the trail. Grass "
            "grows wherever it can find some room. To the east are "
            "two huge, iron gates leading into a town of sorts. ");
   set_items(([
            "mountains" : "The mountains stretch in all directions. A mountain"
                        " wall denies any possibility of straying from "
                        "the path.",
            "shrubs" : "Small shrubs grow at random upon the ground.",
            "gates" : "Large, iron gates stand east of here and lead "
                "into some sort of town. They are connected to the "
                "mountains, so there's absolutely no way of getting "
                "around them.",
            "trees" : "A few palm trees grow here, providing a little bit of "
                "shade from the elements.",
            "path" : "A dirt path runs through the mountains. ",
            "town" : "A town of sorts is visable through the gates "
                "east of here. Buildings and small people can be "
                "seen through the gates. ",
            "grass" : "Grass covers the ground just off of the path."
   ]));
   set_smell("default", "The air is crisp and the air is humid.");
   set_listen("default", "Occasionally a twig can be heard snapping from afar.");
   set_exits( ([ 
        "west" :  ROOMS "85",
        "east" :  ROOMS "sh_1.c"]));
}
