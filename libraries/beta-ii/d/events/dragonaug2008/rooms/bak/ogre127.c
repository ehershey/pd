#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^What looks like rock formed coral sits along the sides of the cavern walls.  Hanging off of the ceiling are sharply daggered rock formed ice cycles daring someone to make a sound.  The area is %^RESET%^%^ORANGE%^dimly lit %^BOLD%^%^BLACK%^through a small hole in the side of the cave, but offers no help in the area of guidance.  The sides of the walls look like they�ve been eaten by a field of %^RESET%^%^GREEN%^moss%^BOLD%^%^BLACK%^, and also look as if they are closing inward.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northwest" : DRAG_ROOMS "ogre112", "northeast" : DRAG_ROOMS "ogre113" ]) );
}
void reset() {
    ::reset();
    if (!present("ogre2", this_object()))
	new(DRAG_MOBS "ogre2")->move(this_object());
    if (!present("ogre4", this_object()))
	new(DRAG_MOBS "ogre4")->move(this_object());
}
