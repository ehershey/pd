#include <std.h>                                    
#include <simaril.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("achray");                               
    set_short("Achray the dock hand");                     
	set_id( ({ "achray", "dock hand", "hand" }) );    
    set_long("Achray is a tall middle aged man who works "
    		 "at the docks to support his heavy drinking. "
    		 "He has worked there for many years, and in "
    		 "general does a good job."
	);        
    set_level(45);                                  
    set_body_type("human");                         
    set_race("human");
	set_gender("male");                             
    set_alignment(150);                            
    set("aggressive", 7);                         
    set_money("gold", 10 + random(20));                          
    set_emotes(3, ({"Achray opens one of the boxes and throws something inside of it.",
    				"Achray grabs a small bottle from his shirt and takes a drink from it.",
    				"Achray gets a crate from one of the boxes and loads it on a boat.",
    				"Achray unties a rope and throws it on to a nearby ship.",
    				"Achray sits down on he pier and looks up at the sky.",
	}), 0);
	new(ARM"overalls.c")->move(this_object());
	force_me("wear overalls");
	new(ARM"work_shirt.c")->move(this_object());
	force_me("wear shirt");
	new(ARM"work_gloves.c")->move(this_object());
	force_me("wear gloves");
	new(OBJ"flask.c")->move(this_object());
}
