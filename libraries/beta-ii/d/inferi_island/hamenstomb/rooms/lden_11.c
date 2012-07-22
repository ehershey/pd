#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^RESET%^%^ORANGE%^Inside this room there is a %^BOLD%^%^BLACK%^darkened corner %^RESET%^%^ORANGE%^where a growl can be heard. Sand is all around the ground making it harder to walk than the grounds inside the pyramid. The ceiling is dome shaped, this must be the dirt dome noticeable from the patios.  Something scurries across the ground.\n");
    set_items( ([ "shadows": "%^BOLD%^%^BLACK%^You can see bright yellow eyes glaring at you watching you from the shadows.%^RESET%^" ]) ); 
    set_exits( ([ "north" : ROOMS+"lden_10" ]) );
}
void reset() {
    ::reset();
    if (!present("lion", this_object()))
	new(MON+"giant_lion")->move(this_object());
    if (!present("sphinx", this_object()))
	new(MON+"androsphinx")->move(this_object());
}
