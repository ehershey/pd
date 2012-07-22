#include <std.h>                                    
#include <lost_caves.h>

inherit MONSTER;                                    

void create() {                                    
    ::create();
        set_name("lurker imp");                               
        set_id( ({ "lurker imp", "lurker", "imp" }) );    
        set_short("Lurker imp");                     
        set_long("A small black skinned imp. Its eyes seem to reflect some unseen light, making the imp easy to spot in the darkness.");        
        set_level(45 + random(5));                                  
        set_body_type("human");                         
        set_race("Lurker imp");
    	set_gender("male");                             
        set_alignment(0);                            
        set_class("fighter");                           
        set_subclass("warrior");   
        set("aggressive", 35);                         
                
        new(ARM"bone_bracelet.c")->move(this_object());
        force_me("wear bracelet");   
        new(ARM"leather_bracers.c")->move(this_object());
        force_me("wear bracers");  
        new(ARM"studded_leather_vest.c")->move(this_object());
        force_me("wear vest");  
        new(ARM"round_shield.c")->move(this_object());
        force_me("wear shield");  
        
        if(random(10) == 5)
        {
            new(ARM"gem_necklace.c")->move(this_object());
            force_me("wear necklace");
        }
          
        if(random(2) ==0)
        {
            new(WEP"bone_spear.c")->move(this_object());
            force_me("wield spear");               
        }
        else
        {
            new(WEP"rock_axe.c")->move(this_object());
            force_me("wield axe");      
        }
}                  




