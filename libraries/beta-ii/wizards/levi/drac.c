#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
::create();
set_name("Drac");
set("id", ({ "drac", "monster" }) );
set_level( 110 );
set("short", "Drac" );
set("long", "Staying in the shadows, Drac bares his fangs at you.  He has pale white skin, and bright red eyes.  You get he feeling that he is glaring at your neck.  Drac has a thurst for blood.  " );
set("race", "human" ); 
set_gender( "male" );
set_body_type("human");
set_ac("right hand", 7);  
set_fingers(5); 
set_class("fighter");
set("aggressive", 55);
new(HELLARM+"lava_ring")->move(this_object());
force_me("wear ring");
 }
void heart_beat() {
    ::heart_beat();
    if(this_object()->query_current_attacker()) {
        if(random(100) < 30) {
            this_object()->query_current_attacker()->query_hitpoints() <= 200)
                {  this_player()->add_hp(-500);
                    return 1;}  
                    (3, "Your blood is drained by Drac, leaving your body dead!");
            force_me("emote screams loudly and falls limp!");
        }
    }
}
