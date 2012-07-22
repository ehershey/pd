#include <std.h>                                    
#include <lidelas.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("lidelas patrol");                               
    set_id( ({ "lidelas patrol", "patrol", "guard", "lidelas guard" }) );    
    set_short("Lidelas patrol");                     
    set_long("A guard who patrols the town of Lidelas. The guards never go easy on trouble makers, they prefer to execute first, and ask questions later.");        
    set_level(6);                                  
    set_body_type("human");                         
    set_race("Human");
	set_gender("male");                             
    set_alignment(50);                            
    set("aggressive", 6);                         
    set_money("copper", 50 + random(30));                          
    set_patrol(8, ({ "east", "east", "east", "north", "north", "west", "west", "west", "south", "south" }) );
    
    new(ARM"red_cloak.c")->move(this_object());
    force_me("wear cloak");
    new(ARM"blue_sash.c")->move(this_object());
    force_me("wear sash");
    new(ARM"leather_body_armour.c")->move(this_object());
    force_me("wear armour");
    new(WEP"large_axe.c")->move(this_object());
    force_me("wield axe");
    
            
            
}

void heart_beat()
{
    ::heart_beat();
    if( random(20) == 5 ) {
        if(random(2) == 0) {
            force_me("say Watch your step!");
        }
        else {
            force_me("say I'll be keeping my eye on you.");
        }
    }
}
