#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^WHITE%^This is the second level of the palace. There are stairs towards the north that lead further up the palace. There are pictures along the wall that show the family of King Hamen. The columns along the walls reach all the way up to the ceiling.\n");
    set_exits( ([ "west" : ROOMS+"hamen_tomb_31", "east" : ROOMS+"hamen_tomb_32", "northwest" : ROOMS+"hamen_tomb_33", "northeast" : ROOMS+"hamen_tomb_34", "north" : ROOMS+"center_2.c" ]) );
}
void reset() {
    ::reset();
    if (!present("magi", this_object()))
	new(MON+"magi")->move(this_object());
    if (!present("sekhmet", this_object()))
	new(MON+"sekhmet")->move(this_object());
    if (!present("bast", this_object()))
	new(MON+"bast")->move(this_object());
}
