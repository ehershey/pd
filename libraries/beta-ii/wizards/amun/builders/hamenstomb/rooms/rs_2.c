#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^WHITE%^There is something magical about this area of the pyramid. The walls are golden and glowing brightly, but the ground is made of dirt and is very fertile. The noise that was heard earlier is now a distinctive roar from a lion.  The writings on the walls are now completely vanished.\n");
    set_exits( ([ "northwest" : ROOMS+"rs_5", "northeast" : ROOMS+"rs_7", "north" : ROOMS+"rs_6" ]) );
}
void reset() {
    ::reset();
    if (!present("tree", this_object()))
	new(MON+"tree_of_life")->move(this_object());
    if (!present("sphinx", this_object()))
	new(MON+"androsphinx")->move(this_object());
}
