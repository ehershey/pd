#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^It appears as if many cave-ins have happened in this part of the cave.  Piles of rocks litter the ground, as if placed there for a reason.  At least two feet of rock covers all exits, as if they were completely covered, but the rocks moved.  Shadows dance behind the piles of rocks, swaying in a romantically deceptive motion.  There is a circle of rocks surrounding charred wood in the center of the room as if a fire pit had been here some time ago.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "north" : DRAG_ROOMS "ogre145", "east" : DRAG_ROOMS "ogre150", "northeast" : DRAG_ROOMS "ogre146" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre4", this_object()))
	new(DRAG_MOBS "ogre4")->move(this_object());
    if (!present("ogre7", this_object()))
	new(DRAG_MOBS "ogre7")->move(this_object());
}