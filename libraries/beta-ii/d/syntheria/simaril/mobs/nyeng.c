#include <std.h>                                    
#include <simaril.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("nyeng");                               
    set_short("Nyeng the dock hand");                     
	set_id( ({ "nyeng", "dock hand", "hand" }) );    
    set_long("Nyeng is a young resident of Simaril. "
				"He works at the docks to help his "
				"family pay their bills. He is a strong "
				"looking youth, and can lift the large "
				"crates without much trouble.");        
    set_level(40);                                  
    set_body_type("human");                         
    set_race("human");
	set_gender("male");                             
    set_alignment(150);                            
    set("aggressive", 7);                         
    set_money("gold", 10 + random(20));                          
    set_emotes(3, ({"Nyeng lifts a crate off of a boat.",
					"Nyeng takes a quick break.",
					"Nyeng rolls a barrel down the pier.",
					"Nyeng ties a rope from a boat to the pier.",
					"Nyeng moves a crate."
	}), 0);
	new(ARM"overalls.c")->move(this_object());
	force_me("wear overalls");
	new(ARM"work_shirt.c")->move(this_object());
	force_me("wear shirt");
        new(ARM"work_gloves.c")->move(this_object());
	force_me("wear gloves");
}
