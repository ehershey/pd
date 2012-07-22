#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^WHITE%^The area is suddenly full of light and life.  Crystals are embedded into every crevice, and they hang down over a low bridge in the ceiling.  The walls sparkle so brilliantly that it is hard for onlookers to focus on anything else.  A %^CYAN%^small pool of water %^WHITE%^provides the illusion of a never ending room with its reflections.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "north" : DRAG_ROOMS "ogre91", "east" : DRAG_ROOMS "ogre104", "south" : DRAG_ROOMS "ogre114", "southwest" : DRAG_ROOMS "ogre113" ]) );
}
