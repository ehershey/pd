#include <std.h>                                    
#include <durst.h>
inherit MONSTER;                                    

int xran = random(30);
int yran = random(100);

void create() {                                    
  ::create();
    set_name("nomad");                               
    set_id( ({ "nomad","monster","wandering nomad" }) );    
    set_short("Wandering nomad");                     
    set_long("A very weathered wanderer of this desert. How he could manage to survive in this place is unthinkable.");        
    set_level(28);                                  
    set_body_type("human");                         
    set_gender("male");                             
    set_alignment(-100);                            
    set_race("Human");                               
    set_class("fighter");                           
    set_subclass("warrior");                      
    set_spell_chance(25);                          
    set("aggressive", 40);                         
    set_spells( ({ "jab" }) );          
    set_money("gold", 50 + random(50));                          
	set_moving(1);
	set_speed(3);


    if (yran < 5)
        {
            new(ARM"md-thick_body_armour.c")->move(this_object());
            force_me("wear armour");
        }
        else
        {
            new(ARM"md-body_armour.c")->move(this_object());
            force_me("wear armour");
        }
        if(xran < 10)
        {
            new(WEP"md-axe.c")->move(this_object());
            force_me("wield axe");
        }
        else if(xran > 9 && xran < 20)
        {
            new(WEP"md-flail.c")->move(this_object());
            force_me("wield flail");
        }
        else if(xran > 19)
        {
            new(WEP"md-spear.c")->move(this_object());
            force_me("wield spear");
        }
}                  
