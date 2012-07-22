// Peada Eadric
// A local bum who  likes to beg for money

#include <std.h>                                    
#include <lidelas.h>

inherit MONSTER;                                    

void create() {                                    
  ::create();
    set_name("peada");                               
    set_id( ({ "townsman", "peasant", "man", "Peada_Eadric", "peada", "bum"  }) );    
    set_short("Peada the bum");                     
    set_long("Peada is a local bum who likes to hang around alley ways and beg for change. It is rumored that he is really very rich, but is a little crazy.");        
    set_level(3);                                  
    set_body_type("human");                         
    set_race("Human");
	set_gender("male");                             
    set_alignment(5);                            
    set("aggressive", 4);                         
    set_money("copper", 5 + random(10));                          
    
    new(ARM"red_cap.c")->move(this_object());
    force_me("wear cap");
    new(ARM"plain_tunic.c")->move(this_object());
    force_me("wear tunic");
    new(WEP"dull_knife.c")->move(this_object());
    force_me("wield knife");
    
            
            
}

void heart_beat()
{
    ::heart_beat();
    if( random(20) == 1 )
       force_me("say Hey, could you spare some change?");
}
