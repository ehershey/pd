#include <std.h>                                    
#include <simaril.h>

inherit MONSTER;                                    

int wielded = 0;

void create() {                                    
  ::create();
    set_name("thyas");                               
    set_short("First Mate Thyas");                     
	set_id( ({ "mate", "first mate", "thyas", "first mate thyas" }) );    
    set_long("First Mate Thyas is a middle aged man. "
    		 "He has been on this ship since he was a small boy. "
    		 "Thyas has a short black beard and long black hair "
    		 "put into a ponytail. He is even more feared than the captain."
			);        
    set_level(70);                                  
    set_body_type("human");                         
    set_race("human");
	set_gender("male");                             
    set_alignment(150);                            
    set("aggressive", 35);                         
    set_money("gold", 50 + random(25));                          
    set_emotes(3, ({"Thyas looks out over the sea.",
    				"Thyas grabs the wheel and steadies it.",
    				"Thyas yells down an order to a deck hand.",
    				"Thyas looks out to the pier.",
	}), 0);
	set_class("fighter");
	set_subclass("warrior");
	set_spell_chance(15);
	set_spells(({"hack", "headbutt"}));
	new(ARM"black_boots.c")->move(this_object());
	force_me("wear boots");
	new(ARM"hauberk.c")->move(this_player());
	force_me("wear shirt");
	new(WEP"boarding_axe.c")->move(this_player());
}

void heart_beat()
{
    ::heart_beat();
    if(!environment(this_object()))
    	return;
	if(sizeof(this_object()->query_attackers()) && wielded == 0)
    {
		force_me("say I'll have yer head!");
		force_me("wield axe");	
		wielded = 1;
	}
     
}
