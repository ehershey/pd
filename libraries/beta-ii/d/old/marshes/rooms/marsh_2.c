#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^BLACK%^Walking into the room, the sense of dread returns to you.  You hear the silence of the dead.\n");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_1", "west": MARSHROOM+"marsh_3" ]) );
    add_pre_exit_function("east", "go_east");
    new(MARSHMON+"inferi_gremlin.c")->move(this_object());
    new(MARSHMON+"inferi_raknid.c")->move(this_object());
}
int go_east() {
    if(!this_player()->is_player()) return 0;
    return 1;
}
