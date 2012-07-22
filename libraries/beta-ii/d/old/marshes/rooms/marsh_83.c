#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_82", "northeast" : MARSHROOM+"marsh_85", "north" : MARSHROOM+"marsh_84" ]) );
    new(MARSHMON+"inferi_ogre.c")->move(this_object());
    new(MARSHMON+"inferi_dwarf.c")->move(this_object());
}
