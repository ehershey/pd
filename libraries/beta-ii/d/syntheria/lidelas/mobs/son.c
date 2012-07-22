
#include <std.h>                                    
#include <lidelas.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("son");                               
    set_id( ({ "son", "peasant", "child", "kid"  }) );    
    set_short("Son");                     
    set_long("A young child sits here playing in his room.");        
    set_level(4);                                  
    set_body_type("human");                         
    set_race("Human");
	set_gender("male");                             
    set_alignment(34);                            
    set("aggressive", 4);                         
    set_money("copper", 5 + random(10));                          
    
    new(ARM"pants.c")->move(this_object());
    force_me("wear pants");
    new(ARM"tattered_shirt.c")->move(this_object());
    force_me("wear shirt");
    new(WEP"short_stick.c")->move(this_object());
    force_me("wield stick");       
            
}
