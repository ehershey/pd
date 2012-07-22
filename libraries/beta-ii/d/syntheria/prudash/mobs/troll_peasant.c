
#include <std.h>                                    
#include <prudash.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("troll peasant");                               
    set_id( ({ "troll peasant", "peasant", "troll" }) );    
    set_short("Troll peasant");                     
    set_long("A small troll that lives in the village of Prudash.");        
    set_level(10+random(5));                                  
    set_body_type("human");                         
    set_race("Troll");
	set_gender("male");                             
    set_alignment(-50);                            
    set("aggressive", 3);                         
    set_money("copper", 20 + random(10));                          
    
    new(ARM"cap.c")->move(this_object());
    force_me("wear cap");
    new(ARM"old_tunic.c")->move(this_object());
    force_me("wear tunic");
                 
}
