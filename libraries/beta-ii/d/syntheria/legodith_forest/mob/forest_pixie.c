#include <std.h>                                    
#include <legodith_forest.h>

inherit MONSTER;                                    

void create() {                                    
    ::create();
        set_name("pixie");                               
        set_id( ({ "pixie" }) );    
        set_short("Pixie");                     
        set_long("A small forest pixie floats around here, it seems to be playing around.");        
        set_level(1 + random(5));                                  
        set_body_type("faerie");                         
        set_race("pixie");
    	set_gender("female");                             
        set_alignment(30);                            
        set("aggressive", 2);  
        
        new(ARM"wing_guard.c")->move(this_object());
        force_me("wear armour");                       
}                  


