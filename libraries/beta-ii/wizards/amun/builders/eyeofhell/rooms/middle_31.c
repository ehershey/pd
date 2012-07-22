#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^A fresh trail of blood crosses the path here. Strangely, the blood-trail veers around the corner, behind some jagged rocks. Strange noises, like something being eaten, can be heard coming from behind these rocks. A small tower of skulls and a %^BLACK%^long black spear%^RED%^, which pierces the bone holding them upright, forces the trail to veer around it. Bats fly down in search of their master.%^RESET%^");
    set_items( ([ "skulls": "%^RESET%^%^RED%^These are the rotton skulls of the dead souls.%^RESET%^" ]) );
    set_exits( ([ "south": HELLROOM+"middle_32", "west": HELLROOM+"middle_30", "southwest": HELLROOM+"middle_43" ]) );
}
void reset() {
    ::reset();
    if (!present("banshee", this_object()))
	new(HELLMON+"banshee")->move(this_object());
    if (!present("wolf", this_object()))
	new(HELLMON+"werewolf")->move(this_object());
}
