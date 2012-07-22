#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "cavern" : 1, "night light" : 2]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
set_listen("default", "The clamor of a busy city fills your ears.");
set_short("Zolenia city path");
set_long("%^BOLD%^%^BLACK%^The western pathway from the city square is one of the most nicely paved paths in the city.  There are lightposts on either side of the path, and statues of Lloth are scattered on and off the path.  There seems to be salt sprinkled all along the path.  In the near distance, a large black church can be seen.");
set_items(([
({"salt"}) : "The path is sprinkled with salt, some sort of superstitious doing.",
({"path"}) : "The path is one of the best paved paths of the city.",
({"statues"}) : "The statues of Lloth are varying from large to larger.",
({"lightposts"}) : "The lightposts appear to be lit by some sort of magic.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"house", "manor", "manors", "houses"}) : "The houses are giant buildings crafted of onyx, with different specialties to each of them.",
]));
}
void reset() {
    ::reset();
    if(!present("cityguard")){
        new(MOB"cityguard")->move(this_object());
        new(MOB"cityguard")->move(this_object());
}
    if(!present("drowpriest")){
        new(MOB"drowpriest")->move(this_object());
        new(MOB"drowpriest")->move(this_object());
}
set_exits(([ "east" : ROOMS "43.c",
"west" : ROOMS "churchroad2.c"]));
}
