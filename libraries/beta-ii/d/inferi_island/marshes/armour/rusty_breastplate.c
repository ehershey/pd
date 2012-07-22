#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create(); 
    set_name("Rusty Breastplate");
    set("id", ({ "breastplate", "armour" }) );
    set("short", "%^ORANGE%^Rusty Breastplate%^RESET%^");
    set("long", "%^ORANGE%^After wearing for a long time, this breastplate is rusted beyond its years and it may not offer much protection.%^RESET%^" );
    set_type("vest");
    set_ac(1);
    set_limbs( ({ "torso" }) );
    set_weight(20);
    set_curr_value("gold", 20);
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
