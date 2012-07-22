#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_85", "south" : MARSHROOM+"marsh_83", "north" : MARSHROOM+"marsh_103" ]) );
    new(MARSHMON+"inferi_halfelf.c")->move(this_object());
    new(MARSHMON+"inferi_orc.c")->move(this_object());
    new(MARSHMON+"inferi_faerie.c")->move(this_object());
    new(MARSHMON+"inferi_halfling.c")->move(this_object());
    new(MARSHMON+"inferi_raknid.c")->move(this_object());
    new(MARSHMON+"inferi_ferrel.c")->move(this_object());
}
