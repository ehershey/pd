#include <std.h>                                    
#include <durst.h>
inherit MONSTER;                                    
void create() {                                    
  ::create();
    set_name("scorpion");                               
    set_id( ({ "scorpion", "monster" }) );    
    set_short("Large scorpion");                     
    set_long("A gigantic scorpion that searches the desert for food, it looks as though he has found some.");        
    set_level(25);                                  
    set_body_type("scorpion");                         
    	set_race("scorpion");
	set_gender("male");                             
    set_alignment(0);                            
    set("aggressive", 50);                         
    set_money("gold", 1);                          
	new(WEP"md-tail.c")->move(this_object());
	force_me("wield tail");  

}  
