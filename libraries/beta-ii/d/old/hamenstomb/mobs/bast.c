#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Bast");
    set("id", ({ "bast", "monster" }) );
    set_level( 56 );
    set("short", "%^RESET%^%^ORANGE%^Bast" );
    set("long", "%^ORANGE%^The Goddess of the Home protects those around her.%^RESET%^" );
    set("race", "bastet" ); 
    set_gender( "female" );
    set_body_type("bastet");
    set_fingers(5); 
    set_max_sp(2000);      
    set_skill("melee", 40);
    set_class("mage");
    set("aggressive", 40);
    set_spell_chance(10); 
    set_spells( ({ "sandstorm", "acidcone" }) );
}
