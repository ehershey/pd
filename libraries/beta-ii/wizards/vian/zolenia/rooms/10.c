#include <std.h>
#include <zolenia.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "cavern" : 1, "night light" : 1]) );
set_smell("default", "The smell of rotting flesh permeates from the caverns to the south, although it fades away with every footstep.");
set_listen("default", "To the southeast, the sounds of animals can be heard fighting, and to the north, the clamor of a city.");
set_short("a path of onyx");
set_long("The onyx path toward a possible city is surrounded by sharp and jagged rocks. Moving toward the seemingly crowded area, the air seems to get humid and stagnant. The darkness makes traveling through the path quite difficult. Although shadows don't seem to exist in the darkness, there seems to be some sort of presence. A dim source of light is coming from somewhere nearby.");
set_items(([
({"onyx", "path"}) : "In the middle of treacherous rocks, a path of onyx stays maintained and unbothered.",
({"dirt", "footprints"}) : "Dirt and dust cover the path, and footprints can be seen, some appear to have been dragged.",
"ground" : "The ground is covered in treacherous rocks, although there is an onyx path.",
({"rock", "stones", "rocks"}) : "The rocks are jagged and large for the most part, and without the path, travel would be difficult..",
({"air", "dust"}) : "Particles of dust can be seen floating throughout the air.",
"gate" : "A gigantic gate can be seen in the distance.",
"bat" : "A bat flutters throughout the rooms, hissing and baring its fangs.",
"light" : "A dim source of light can be seen from the distance.",
"shadows" : "The darkness makes for no shadows, although a presence can be felt.",
"bones" : "A pile of bones rests on the side of the pathway.",
"darkness" : "The absolute darkness makes traveling through the path quite uneasy.",
]));
set_exits(([ "south" : ROOMS "9.c",
"west" : ROOMS "11.c"]));
}