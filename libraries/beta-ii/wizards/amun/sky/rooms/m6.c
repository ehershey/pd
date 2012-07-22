#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set("long","%^BOLD%^%^CYAN%^The %^WHITE%^clouds %^CYAN%^along the path start to thin, becoming faint and wispy. The light all around becoming ever more intense. The cobblestone path flows seamlessly into a shiny quartz. The path begins to curve to the northwest.%^RESET%^");
    set_items( ([ "walkway": "%^BOLD%^%^WHITE%^This s%^RESET%^t%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^e walkway is magically places for travelers to walk on.%^RESET%^" ]) );
    set_exits( ([ "northwest" : SKYROOM "m13", "southeast" : SKYROOM "m1" ]) );
}
void reset() {
    ::reset();
    if (!present("penguin", this_object()))
	new(SKYMOB "penguin_2")->move(this_object());
    if (!present("monk", this_object()))
	new(SKYMOB "praying_monk")->move(this_object());
}