#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^BLACK%^Walking into the room, the sense of dread returns to you.  You hear the silence of the dead.\n");
    set_items( ([ "faces": "%^BOLD%^%^BLACK%^These faces, are the faces of those who came, fought and died." ]) );
    set_exits( ([ "south" : MARSHROOM+"marsh_1", "north": MARSHROOM+"marsh_19" ]) );
    add_pre_exit_function("south", "go_south");
    new(MARSHMON+"inferi_ogre.c")->move(this_object());
    new(MARSHMON+"inferi_gnome.c")->move(this_object());
}
int go_south() {
    if(!this_player()->is_player()) return 0;
    return 1;
}
