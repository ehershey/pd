#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Banshee");
    set("id", ({ "banshee", "monster" }) );
    set_level( 110 );
    set("short", "%^BOLD%^%^WHITE%^Banshee" );
    set("long", "%^RESET%^This Banshee is fierce with her ghostly pale green skin and her long finger nails.  Her wail is overwhelming.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "female" );
    set_body_type("human");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set("aggressive", 55);
    set_emotes(20, ({"%^BOLD%^%^CYAN%^You are thrown back by the wailing of the banshee!%^RESET%^"}), 1);
}
void heart_beat() {
    ::heart_beat();
    if(this_object()->query_current_attacker()) {
	if(random(100) < 30) {
	    this_object()->query_current_attacker()->set_paralyzed(3, "You are too frightened to move!");
	    force_me("emote screams loudly!");
	}
    }
}
