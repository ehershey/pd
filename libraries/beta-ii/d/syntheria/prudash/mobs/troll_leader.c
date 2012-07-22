
#include <std.h>                                    
#include <prudash.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("troll leader");                               
    set_id( ({ "troll leader", "leader", "troll" }) );    
    set_short("Troll leader");                     
    set_long("An old large troll who leads his clan. His domain is small, but his ambitions are large.");        
    set_level(20);                                  
    set_body_type("human");                         
    set_race("Troll");
	set_gender("male");                             
    set_alignment(-250);                            
    set("aggressive", 10);                         
    set_money("copper", 100 + random(50));                          
    set_class("fighter");
    set_skill("attack", 100);
    set_stats("strength", 30);
    set_stats("dexterity", 30);
    fix_vital_bonus();
    set_max_hp(900);
    set_hp(900);
    
    new(ARM"chain_gloves.c")->move(this_object());
    force_me("wear gloves");
    new(ARM"chainmail_armour.c")->move(this_object());
    force_me("wear armour");

    new(WEP"scimitar.c")->move(this_object());
    force_me("wield blade");       
            
}
