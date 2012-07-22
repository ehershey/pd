#include <std.h>                                    
#include <simaril.h>

inherit MONSTER;                                    
int wielded = 0;
void create() {                                    
  ::create();
    set_name("captain chestin");                               
    set_short("Captain Chestin");                     
	set_id( ({ "captain", "captain chestin", "chestin", "capt" }) );    
    set_long("Captain Chestin is an old man. "
    		 "He has a long gray beard that stretches down to his stomach. "
    		 "He was once an admiral of the Syntherian fleet, but has since "
    		 "fallen out of favor with the nobility. "
    		 "He now commands this old run down warship."
			);        
    set_level(65);                                  
    set_body_type("human");                         
    set_race("human");
	set_gender("male");                             
    set_alignment(-250);                            
    set("aggressive", 35);                         
    set_money("gold", 100 + random(50));                          
    set_emotes(3, ({"Chestin looks over some papers.",
    				"Chestin pulls out an old map and looks at it.",
    				"Chestin mumbles something to himself.",
    				"Chestin plays with his long beard as he thinks.",
    				"Chestin lights a candle that burnt out.",
    				"Chestin hums an old sea tune.",
	}), 0);
	set_class("wanderer");
	set_subclass("swashbuckler");
	set_spell_chance(25);
	set_spells(({"bladedance", "lunge"}));
	new(ARM"black_boots.c")->move(this_object());
	force_me("wear boots");
	new(ARM"fancy_greaves.c")->move(this_object());
	force_me("wear greaves");
	new(ARM"cuirass.c")->move(this_object());
	force_me("wear cuirass");
	new(WEP"jade_cutlass.c")->move(this_object());
}

void heart_beat()
{
    ::heart_beat();
    if(!environment(this_object()))
    	return;
	if(sizeof(this_object()->query_attackers()) && wielded == 0)
    {
		force_me("say Yar! You scurvy dog!");
		force_me("wield sword");	
		wielded = 1;
	}
     
}
