#include <std.h>
#include <daemons.h>

inherit OBJECT;

void create() {

    set_name("fire");
    set("id", ({ "fire", "a fire", "the fire" }) );
    set("short", "a %^ORANGE%^c%^YELLOW%^r%^ORANGE%^a%^YELLOW%^c%^ORANGE%^k%^YELLOW%^l%^ORANGE%^i%^YELLOW%^n%^ORANGE%^g %^RED%^fire%^RESET%^");
    set("long", "A warm crackling fire\n");
    set_prevent_get(" The fire burns you! );
    }
