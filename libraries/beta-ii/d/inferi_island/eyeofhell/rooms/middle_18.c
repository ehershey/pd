#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^BLACK%^Fire jets from the earth in destructive breaths of fury. Strange %^GREEN%^green steam %^BLACK%^rises from cracks in the stone, filling the air with deadly sulphur and brimstone. Caves dot the land, with their openings like hungry mouths and tongue-like tentacles reaching out for prey. A giant spider web threatens to trap passerbys as its sticky entrails latch onto anything that passes.%^RESET%^");
    set_exits( ([ "south": HELLROOM+"middle_17", "northwest": HELLROOM+"middle_19" ]) );
}
void reset() {
    ::reset();
    if (!present("wolf", this_object()))
	new(HELLMON+"werewolf")->move(this_object());
    if (!present("raknid", this_object()))
	new(HELLMON+"she_raknid")->move(this_object());
}
