#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Smoke rises to the north causing all sight to become trialing. A %^RESET%^%^ORANGE%^f%^BOLD%^%^WHITE%^a%^RESET%^%^ORANGE%^lcon %^BOLD%^%^BLACK%^takes flight and soars above the smoke. Small bugs crawl around on the ground in search of a safe place. Loud growling comes from the northwest causing the marsh to become silent.%^RESET%^");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "water": "%^RESET%^%^BLUE%^The water is thick with mud and thick with bodies.  You see and feel dead things around you.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "northeast" : MARSHROOM+"BM_37", "west" : MARSHROOM+"BM_39" ]) );
}
void reset() {
    ::reset();
    if (!present("skeleton", this_object()))
	new(MARSHMON+"skeleton")->move(this_object());
    if (!present("gnoll", this_object()))
	new(MARSHMON+"inferi_gnoll")->move(this_object());
}
