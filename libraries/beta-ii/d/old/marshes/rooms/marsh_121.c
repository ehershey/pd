#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^Looking in all directions you notice the marshes stretch as far as your eyes can see.  It look that you have to find you way through this maze.\n");
    set_items( ([ "faces": "These faces, are the faces of those who came, fought and died.", "bodies": "These bodies are those of many races." ]) );
    set_exits( ([ "northwest" : MARSHROOM+"marsh_125", "northeast" : MARSHROOM+"marsh_127", "southeast" : MARSHROOM+"marsh_107", "south" : MARSHROOM+"marsh_106", "southwest" : MARSHROOM+"marsh_105", "east" : MARSHROOM+"marsh_120", "west" : 
	MARSHROOM+"marsh_122" ]) );
    new(MARSHMON+"inferi_weimic")->move(this_object());
    new(MARSHMON+"inferi_imp")->move(this_object());
}
