#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_221", "south" : MARSHROOM+"marsh_211", "west" : MARSHROOM+"marsh_223", "southeast" : 
	MARSHROOM+"marsh_212", "southwest" : MARSHROOM+"marsh_210" ]) );
    new(MARSHMON+"undead_corpse")->move(this_object());
    new(MARSHMON+"skeleton")->move(this_object());
}
