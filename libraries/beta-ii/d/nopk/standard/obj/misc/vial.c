#include <std.h>
inherit POISON;

void create() {
    set_name("vial");
    set("id", ({ "vial", "vial of poison", "poison" }) );
    set("short", "a Vial of poison");
    set("long", "A glass vial with a skull and crossbones on it.");
    set_poisoning(8);
    set("value", 150);
    set("weight", 1);
}
