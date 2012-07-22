#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^In all directions, the marsh stretches as far as the naked eye can see. To the east, %^BOLD%^%^BLACK%^black smoke %^RESET%^%^ORANGE%^can be seen rising above a few small f%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s. More dragons can be seen flying south towards the ocean. They seem to be running away.%^RESET%^");
    set_items( ([ "smoke": "%^BOLD%^%^BLACK%^There are fires light all around." ]) );
    set_exits( ([ "southeast" : MARSHROOM+"BM_37", "west" : MARSHROOM+"BM_33" ]) );
}
void reset() {
    ::reset();
    if (!present("elf", this_object()))
	new(MARSHMON+"inferi_elf")->move(this_object());
    if (!present("illithid", this_object()))
	new(MARSHMON+"inferi_illithid")->move(this_object());
}
