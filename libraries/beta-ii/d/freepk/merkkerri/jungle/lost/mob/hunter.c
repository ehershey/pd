
#include <std.h>                                    
#include <lost.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("dino hunter");                               
    set_id( ({ "hunter", "dinosaur hunter" }) );    
    set_short("Dinosaur hunter");                     
    set_long("A young strong hunter that waits in the trees for the right shot.");        
    set_level(50+random(20));  
    set_body_type("human");                         
    set_race("Human");
    set_class("fighter");
    set_subclass("ranger");
	set_gender("male");                             
    set_alignment(-150);                            
    set("aggressive", 40);                         
    set_money("gold", 10 + random(20));                          
    
    new(OBJ"quiver.c")->move(this_object());
    force_me("wear quiver");
    new(OBJ"sarmour.c")->move(this_object());
    force_me("wear armour");

    new(OBJ"long_bow.c")->move(this_object());
    force_me("wield bow");       
            
}
