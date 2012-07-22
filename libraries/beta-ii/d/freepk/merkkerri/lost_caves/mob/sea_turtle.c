#include <std.h>                                    
#include <lost_caves.h>

inherit MONSTER;                                    

void create() {                                    
    ::create();
        set_name("sea turtle");                               
        set_id( ({ "sea turtle", "turtle" }) );    
        set_short("Sea turtle");                     
        set_long("A titan sized sea turtle. This large beast meanders around the beach bathing in the sun.");        
        set_level(65 + random(5));                                  
        set_body_type("quadrupe");                         
        set_race("turtle");
    	set_gender("male");                             
        set_alignment(0);                                                      
        set("aggressive", 5);
        set_stats("dexterity",5);
        set_stats("constitution",200);                               
        set_stats("strength",100);
        set_stats("wisdom",100);
        set_stats("intelligence",10); 
        set_skill("defense", 500); 
        set_exp(150000);   
        set_max_hp(50000);
        set_hp(50000);
        set_max_sp(1000);
        set_sp(1000);
        if(random(10)>8)
            new(OBJ"shell.c")->move(this_object());
          
}                  
