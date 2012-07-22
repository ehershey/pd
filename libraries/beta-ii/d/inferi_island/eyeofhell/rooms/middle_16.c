#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^The land rises to a plateau, giving a better view of the surrounding area. Some poor souls are crucified upside down on inverted crosses made from black, rotting wood. Large rusting spikes hold feet and hands in place and more screams of suffering fill the air as small bat-like demons swoop down, clawing and biting and devouring the flesh of helpess men and women. A %^GREEN%^bright green light %^BLACK%^can be seen fl%^GREEN%^a%^BLACK%^sh%^GREEN%^i%^BLACK%^ng in the room from the whereabouts unknown.%^RESET%^");
    set_exits( ([ "southwest": HELLROOM+"middle_15", "north": HELLROOM+"middle_17" ]) );
}
void reset() {
    ::reset();
    if (!present("wolf", this_object()))
	new(HELLMON+"werewolf")->move(this_object());
    if (!present("raknid", this_object()))
	new(HELLMON+"she_raknid")->move(this_object());
}
