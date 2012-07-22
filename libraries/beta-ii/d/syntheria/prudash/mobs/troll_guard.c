
#include <std.h>                                    
#include <prudash.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("troll guard");                               
    set_id( ({ "troll guard", "guard", "troll" }) );    
    set_short("Troll guard");                     
    set_long("A large troll guard. He protects the village of Prudash from aggressors.");        
    set_level(11+random(5));                                  
    set_body_type("human");                         
    set_race("Troll");
	set_gender("male");                             
    set_alignment(-150);                            
    set("aggressive", 7);                         
    set_money("copper", 10 + random(20));                          
    
    new(ARM"studded_jerkin.c")->move(this_object());
    force_me("wear jerkin");
    new(ARM"studded_leggings.c")->move(this_object());
    force_me("wear leggings");

    new(WEP"curved_axe.c")->move(this_object());
    force_me("wield axe");       
            
}
