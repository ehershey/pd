#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^Small %^WHITE%^sparkles %^BLACK%^trickle along the cave walls, as if there were a million %^WHITE%^f%^YELLOW%^i%^WHITE%^refli%^YELLOW%^e%^WHITE%^s%^BLACK%^ lighting the way for onlookers.  However, they %^WHITE%^sparkle so brilliantly %^BLACK%^that it is hard for onlookers to focus on anything else.  The %^BLUE%^water %^BLACK%^sings a soft song against the ground, providing more rhythm for the dancing shadows.  Despite the musty feeling, a small breeze flows in through a small hole in the side of the cave walls.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "west" : DRAG_ROOMS "ogre31", "east" : DRAG_ROOMS "ogre33" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre4", this_object()))
	new(DRAG_MOBS "ogre4")->move(this_object());
    if (!present("ogre1", this_object()))
	new(DRAG_MOBS "ogre1")->move(this_object());
}
