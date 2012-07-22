#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_193", "northeast" : MARSHROOM+"marsh_204", "west" : MARSHROOM+"marsh_191", "northwest" : MARSHROOM+"marsh_206", "southwest" : MARSHROOM+"marsh_188", "southeast" : MARSHROOM+"marsh_186", "south" :
	MARSHROOM+"marsh_187" ]) );
    new(MARSHMON+"inferi_centaur")->move(this_object());
    new(MARSHMON+"inferi_gremlin")->move(this_object());
}