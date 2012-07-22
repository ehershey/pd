
#include <std.h>                                    
#include <prudash.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("troll spy");                               
    set_id( ({ "troll spy", "spy", "troll" }) );    
    set_short("Troll spy");                     
    set_long("A very sneaky troll, who goes to Lidelas to gather intelligence for the troll army.");        
    set_level(14+random(5));                                  
    set_body_type("human");                         
    set_race("Troll");
	set_gender("male");                             
    set_alignment(-350);                            
    set("aggressive", 1);                         
    set_money("copper", 50 + random(20));                          
    
    new(ARM"black_robe.c")->move(this_object());
    force_me("wear robe");
    new(ARM"black_gloves.c")->move(this_object());
    force_me("wear gloves");
    new(ARM"black_mask.c")->move(this_object());
    force_me("wear mask");
    new(ARM"black_boots.c")->move(this_object());
    force_me("wear boots");

    new(WEP"rusty_dagger.c")->move(this_object());
    force_me("wield dagger");       
            
}

int query_invis() {return 1;}
