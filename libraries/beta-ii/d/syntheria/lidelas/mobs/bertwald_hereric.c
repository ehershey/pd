// Bertwald Hereric
// A simple peasant who likes to talk

#include <std.h>                                    
#include <lidelas.h>

inherit MONSTER;                                    

void eanfrid_talk1(object blaber);
void eanfrid_talk2(object blaber);
void eanfrid_talk3(object blaber);
void eanfrid_talk4(object blaber);
void eanfrid_talk5(object blaber);
void eanfrid_talk6(object blaber);

void create() {                                    
  ::create();
    set_name("bertwald");                               
    set_id( ({ "townsman", "peasant", "man", "Bertwald_Hereric", "Bertwald"  }) );    
    set_short("Bertwald");                     
    set_long("This townsman is dressed in some very plain clothes. He seems to be looking in all directions, he must be looking for someone. His hands look to be very rough, his job must involve a lot of manual labor.");        
    set_level(3);                                  
    set_body_type("human");                         
    set_race("Human");
	set_gender("male");                             
    set_alignment(5);                            
    set("aggressive", 4);                         
    set_money("copper", 20 + random(10));                          
    set_moving(1);
    set_speed(20);
    set_heart_beat(3);
    
    new(ARM"cloth_boots.c")->move(this_object());
    force_me("wear boots");
    new(ARM"blue_cloak.c")->move(this_object());

    force_me("wear cape");
    new(WEP"short_sword.c")->move(this_object());
    force_me("wield sword");
    
            
            
}

void init()
{
    if(!this_player()->is_player())
    {
        string *ids;
        object blaber;
        ids = this_player()->query_id();
        
        if( sizeof(ids) < 1 )
            return 0;
        
        for( int i = 0; i < sizeof(ids); i++ )
        {
            if( ids[i] == "eanfrid_tondhere" )
            {
                blaber = this_player();
                
                call_out("eanfrid_talk1", 0, blaber); 
                return 0;;
            }
        
        }
    }
    
}

void eanfrid_talk1(object blaber)
{
    if (!present("eanfrid_tondhere", environment(this_object())))
        return;
    command("say Hello Eanfrid.");
    call_out("eanfrid_talk2", 4, blaber);
}

void eanfrid_talk2(object blaber)
{
    if (!present("eanfrid_tondhere", environment(this_object())))
        return;
    command("say How have you been?");
    call_out("eanfrid_talk3", 4, blaber);
}

void eanfrid_talk3(object blaber)
{
    if (!present("eanfrid_tondhere", environment(this_object())))
        return;
    blaber->force_me("say Good, and yourself?");
    call_out("eanfrid_talk4", 4, blaber);
}

void eanfrid_talk4(object blaber)
{
    if (!present("eanfrid_tondhere", environment(this_object())))
        return;
    command("say I have been well, but I must be off.");
    call_out("eanfrid_talk5", 4, blaber);
}

void eanfrid_talk5(object blaber)
{
    if (!present("eanfrid_tondhere", environment(this_object())))
        return;
    command("wave");
    call_out("eanfrid_talk6", 1, blaber);
}

void eanfrid_talk6(object blaber)
{
    if (!present("eanfrid_tondhere", environment(this_object())))
        return;
    blaber->force_me("wave");
}
