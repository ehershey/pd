#include <std.h>                                    
#include <lost_caves.h>

inherit MONSTER;                                    

void create() {                                    
    ::create();
        set_name("cave troll");                               
        set_id( ({ "cave troll", "troll" }) );    
        set_short("Cave troll");                     
        set_long("A large grey cave troll. Its muscles buldge all over its body, and from the looks of this troll, it likes to use them.");        
        set_level(45 + random(5));                                  
        set_body_type("human");                         
        set_race("Cave troll");
    	set_gender("male");                             
        set_alignment(0);                            
        set_class("fighter");                           
        set_subclass("warrior");   
        set_spell_chance(25);                          
        set("aggressive", 55);                         
        set_spells( ({ "maul" }) );         
        set_stats("strength",75);
        set_stats("wisdom",10);
        set_stats("intelligence",10);
        
        set_max_hp(5000);
        set_hp(5000);
        set_max_sp(1000);
        set_sp(1000);
        
        new(ARM"rock_helmet.c")->move(this_object());
        force_me("wear helmet");   
        new(WEP"bone_club.c")->move(this_object());
        force_me("wield club");               
}                  




