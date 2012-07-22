#include <std.h>                                    
#include <arund.h>

inherit MONSTER;                                    

int battlecry = 0;

void create() {                                    
  ::create();
    set_name("bilino badminer");                               
    set_short("Bilino Badminer");                     
    set_id( ({ "bilino", "bilino badminer", "badminer", "worker" }) );    
    set_long("Bilino is a younger dwarf, his beard lacks any grey "
                 "and his face is free of wrinkles. "
                 "He has just started working for the Arund Mining Company, "
                 "but for a dwarf to be put to work above ground is a terrible insult. "
                 "Bilino looks bitter, even for a dwarf. "
        );        
    set_level(20);                                  
    set_body_type("human");                         
    set_race("dwarf");
    set_gender("male");                             
    set_alignment(10);                            
    set("aggressive", 10);                         
    set_money("silver", 5 + random(20));                          
    set_emotes(3, ({"Bilino grabs the crank and turns it madly.",
                    "Bilino takes a bucket of dirt and throws it on to the ground.",
                    "Bilino mutters something about low pay under his breath.",
                    "Bilino takes a quick break.",
        }), 0);
       
        new(ARM"wpants.c")->move(this_object());
        force_me("wear pants");
        new(ARM"shat.c")->move(this_object());
        force_me("wear hat");
        new(ARM"lgloves.c")->move(this_object());
        force_me("wear gloves");
        new(OBJ"note.c")->move(this_object());
}

void heart_beat()
{
    ::heart_beat();
    if(!this_object()) return;
    if(!environment(this_object()))
        return;
    if(sizeof(this_object()->query_attackers()) && battlecry == 0)
    {
        force_me("say I don't get paid enough for this!");
        battlecry = 1;
    } 
}
