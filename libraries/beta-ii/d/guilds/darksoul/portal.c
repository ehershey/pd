#include <std.h>

inherit OBJECT;

void create() {
    set_name("A shimmering portal");
    set("id", ({ "portal" }) );
    set_short("A shimmering portal");
    set("long", "A shimmering portal used by the captured souls to move members from place to place.");
    set_prevent_get("");
}

int get() { return 0; }
