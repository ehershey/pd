
#include <std.h>                                    
#include <lidelas.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("wife");                               
    set_id( ({ "townswoman", "peasant", "woman", "wife", "house wife"  }) );    
    set_short("House wife");                     
    set_long("A young woman prepares a meal, she seems to be very focused.");        
    set_level(4);                                  
    set_body_type("human");                         
    set_race("Human");
	set_gender("female");                             
    set_alignment(50);                            
    set("aggressive", 4);                         
    set_money("copper", 5 + random(10));                          
    
    new(ARM"white_dress.c")->move(this_object());
    force_me("wear dress");
    new(ARM"black_shoes.c")->move(this_object());
    force_me("wear shoes");
    new(WEP"cooking_knife.c")->move(this_object());
    force_me("wield knife");       
            
}
