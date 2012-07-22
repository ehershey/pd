
#include <std.h>                                    
#include <prudash.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("troll soldier");                               
    set_id( ({ "troll soldier", "soldier", "troll" }) );    
    set_short("Troll soldier");                     
    set_long("One of the soldiers in the Prudash army. The army is just a small group of strong trolls who want to kill the people of Lidelas.");        
    set_level(13+random(5));                                  
    set_body_type("human");                         
    set_race("Troll");
	set_gender("male");                             
    set_alignment(-250);                            
    set("aggressive", 8);                         
    set_money("copper", 30 + random(20));                          
    
    new(ARM"studded_body_armour.c")->move(this_object());
    force_me("wear armour");
    new(ARM"green_war_mask.c")->move(this_object());
    force_me("wear mask");
    new(ARM"rusty_iron_boots.c")->move(this_object());
    force_me("wear boots");

    new(WEP"worn_mace.c")->move(this_object());
    force_me("wield mace");       
            
}
