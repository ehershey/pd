#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^Recent %^BOLD%^%^BLUE%^rai%^CYAN%^nf%^BLUE%^all %^RESET%^%^ORANGE%^has caused the swamplands to swell, the water rising up to a few feet high. The reeds in this area have grown particularly thick, and together with the thick muddy water make travel difficult. A large rotting tree trunk lays just to the west, a swarm of flies filling the air over it. A badly decayed corpse rests inside the hollow log with its flesh half eaten by larvae and birds.%^RESET%^ ");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "northwest" : MARSHROOM "BM_51","east" : MARSHROOM+"BM_17", "south" : MARSHROOM+"BM_13" , "west" : MARSHROOM+"BM_49" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}