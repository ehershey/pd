#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^WHITE%^This room is laced with pictures of royalty. Columns line the walls, and the sun windows offer a lot of light making the sculptures and the walls shine brightly. To the north, the stairs leading to the Kings bedroom can be seen. From the balcony, the lower floors of the palace can be seen to be bright and active.\n");
    set_exits( ([ "southwest": ROOMS+"hamen_tomb_37", "southeast": ROOMS+"hamen_tomb_38", "up" : ROOMS+"hamen_tomb_40" ]) );
}
void reset() {
    ::reset();
    if (!present("senamun", this_object()))
	new(MON+"queen_senamun")->move(this_object());
}
