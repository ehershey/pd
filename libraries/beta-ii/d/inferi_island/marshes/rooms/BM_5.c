#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^In all directions the marsh stretches as far as the naked eye can see. To the east, %^BOLD%^%^BLACK%^black smoke %^RESET%^%^ORANGE%^can be seen rising above a few small f%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^s. More dragons can be seen flying south towards the ocean. They seem to be running away.%^RESET%^");
    set_items( ([ "smoke": "%^BOLD%^%^BLACK%^There are fires light all around." ]) );
    set_exits( ([ "southeast" : MARSHROOM+"BM_7", "southwest" : MARSHROOM+"BM_3", "north" : MARSHROOM+"BM_45", "northwest" : MARSHROOM+"BM_53" ]) );
    add_pre_exit_function("southwest", "sp_sap");
    add_pre_exit_function("southeast", "sp_sap");
}
