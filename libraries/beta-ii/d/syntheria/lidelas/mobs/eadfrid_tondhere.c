//Eanfrid Tondhere 

#include <std.h>                                    
#include <lidelas.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("eanfrid");                               
    set_id( ({ "townsman", "peasant", "man", "eanfrid_tondhere ", "eanfrid"  }) );    
    set_short("Eanfrid");                     
    set_long("This townsman is dressed in some very nice clothes. He seems to be looking in all directions, he must be looking for someone. He walks down the street with confidence, he must be a person of importance.");        
    set_level(3);                                  
    set_body_type("human");                         
    set_race("Human");
	set_gender("male");                             
    set_alignment(5);                            
    set("aggressive", 4);                         
    set_money("copper", 25 + random(10));                          
    set_moving(1);
    set_speed(20);
    set_heart_beat(3);
    
    new(ARM"cloth_cap.c")->move(this_object());
    force_me("wear cap");
    new(ARM"hide_pants.c")->move(this_object());
    force_me("wear pants");
    new(WEP"hand_axe.c")->move(this_object());
    force_me("wield axe");       
            
}
