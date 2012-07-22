#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^YELLOW%^As you enter this room you notice how bright it is compared to the one before it.  There are torches everywhere and they seem to be blowing faintly.\n");
    set_items( ([ "torch": "%^BOLD%^%^BLACK%^The torches are flickering faintly." ]) );
    set_exits( ([ "east": ROOMS+"hamen_tomb_273" ]) );
    new(MON+"androsphinx")->move(this_object());
}
