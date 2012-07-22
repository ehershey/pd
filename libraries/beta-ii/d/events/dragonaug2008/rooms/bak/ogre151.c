#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^The cavern is enormous and dark. The sound of %^RESET%^%^BLUE%^water %^BOLD%^%^BLACK%^gently dripping from the ceiling echoes loudly throughout the empty cave. The only source of %^WHITE%^light %^BLACK%^in these depths are %^WHITE%^white crystals%^BLACK%^ lining the walls, somehow giving off %^WHITE%^light %^BLACK%^and allowing one to see enough to find a single pathway through the middle of the cave. Stalagmites and stalactites litter either side of the path, making it even more prevalent.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "north" : DRAG_ROOMS "ogre147", "west" : DRAG_ROOMS "ogre150", "northwest" : DRAG_ROOMS "ogre146", "northeast" : DRAG_ROOMS "ogre148" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre4", this_object()))
	new(DRAG_MOBS "ogre4")->move(this_object());
    if (!present("ogre7", this_object()))
	new(DRAG_MOBS "ogre7")->move(this_object());
    if (!present("ogre8", this_object()))
	new(DRAG_MOBS "ogre8")->move(this_object());
}
