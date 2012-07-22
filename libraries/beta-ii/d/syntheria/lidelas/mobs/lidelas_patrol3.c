#include <std.h>                                    
#include <lidelas.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("lidelas patrol");                               
    set_id( ({ "lidelas patrol", "patrol", "guard", "lidelas guard" }) );    
    set_short("Lidelas patrol");                     
    set_long("A guard who patrols the town of Lidelas. The guards never go easy
on trouble makers, they prefer to execute first, and ask questions later.");   

    set_level(6);                                  
    set_body_type("human");                         
    set_race("Human");
        set_gender("male");                             
    set_alignment(50);                            
    set("aggressive", 6);                         
    set_money("copper", 50 + random(30));                          
    set_patrol(10, ({ "south", "south", "south", "south", "south", "south",
"south", "south",
                        "no
th", "north", "north", "north", "north", "north", "north", "north", }) );
    
    new(ARM"red_cloak.c")->move(this_object());
    force_me("wear cloak");
    new(ARM"blue_sash.c")->move(this_object());
    force_me("wear sash");
    new(ARM"leather_body_armour.c")->move(this_object());
    force_me("wear armour");
    new(WEP"large_scourge.c")->move(this_object());
    force_me("wield whip");
    
            
            
}

void heart_beat()
{
    ::heart_beat();
    if( random(10) == 1 ) {
        if(random(2) == 0) {
            force_me("say Watch your step!");
        }
        else {
            force_me("say I'll be keeping my eye on you.");
        }
    }
}
