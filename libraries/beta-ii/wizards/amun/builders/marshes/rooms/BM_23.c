#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^A corpse rises out of the marsh and looks around, then runs behind a shrub in search of a weapon. %^YELLOW%^L%^WHITE%^i%^YELLOW%^g%^RESET%^%^MAGENTA%^h%^BOLD%^%^YELLOW%^t%^WHITE%^e%^YELLOW%^n%^RESET%^%^MAGENTA%^i%^BOLD%^%^YELLOW%^n%^WHITE%^g %^RESET%^%^ORANGE%^touches down on a shrub causing it to engulf in flames. Another loud growl is heard across the marsh, it seems to be coming from the northwest. The corpse looks in the direction of the noise and whimpers.%^RESET%^");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "water": "%^RESET%^%^BLUE%^The water is thick with mud and thick with bodies.  You see and feel dead things around you.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "south" : MARSHROOM+"BM_25", "north" : MARSHROOM+"BM_21", "northwest" : MARSHROOM+"BM_11" ]) );
}
void reset() {
    ::reset();
    if (!present("gremlin", this_object()))
	new(MARSHMON+"inferi_gremlin")->move(this_object());
    if (!present("raknid", this_object()))
	new(MARSHMON+"inferi_raknid")->move(this_object());
}
