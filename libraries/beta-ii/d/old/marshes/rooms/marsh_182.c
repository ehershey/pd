#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "northwest" : MARSHROOM+"marsh_196", "northeast" : MARSHROOM+"marsh_198", "north" : MARSHROOM+"marsh_197", "west" : MARSHROOM+"marsh_183", "south" : MARSHROOM+"marsh_178", "east" : MARSHROOM+"marsh_181", "southeast" : 
	MARSHROOM+"marsh_180", "southwest" : MARSHROOM+"marsh_178" ]) );
    new(MARSHMON+"inferi_illithid")->move(this_object());
}
