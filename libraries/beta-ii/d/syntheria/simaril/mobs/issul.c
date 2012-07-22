#include <std.h>                                    
#include <simaril.h>

inherit MONSTER;                                    

int wielded = 0;

void create() {                                    
  ::create();
    set_name("issul");                               
    set_short("Issul the ship hand");                     
	set_id( ({ "issul", "ship hand", "hand" }) );    
    set_long("Issul has served with this vessel since he was a small boy "
    		 "It is the only world he knows, he is a staunch "
    		 "defender of the captain. "
    		 "He is still a young man, and likes to fight."
	);        
    set_level(50);                                  
    set_body_type("human");                         
    set_race("human");
	set_gender("male");                             
    set_alignment(-150);                            
    set("aggressive", 25);                         
    set_money("gold", 10 + random(20));                          
    set_emotes(3, ({"Issul ties a rope from the mast to the deck.",
    				"Issul swabs the deck.",
    				"Issul looks out at the sea.",
    				"Issul sizes you up.",
					"Issul polishes a cannon.",
	}), 0);
	set_class("wanderer");
	set_subclass("swashbuckler");
	set_spell_chance(15);
	set_spells(({"bladedance", "lunge"}));

	new(WEP"steel_cutlass.c")->move(this_object());

}

void heart_beat()
{
    ::heart_beat();
    if(!this_object()) return;
    if(!environment(this_object()))
    	return;
	if(sizeof(this_object()->query_attackers()) && wielded == 0)
    {
		force_me("say Avast ye! I'll cut your heart out!");
		force_me("wield sword");	
		wielded = 1;
	}
     
}
