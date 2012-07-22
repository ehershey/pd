
#include <std.h>
#include <lidelas.h>

inherit ROOM;

void create() 
{
        ::create();
                set_no_clean(1);
                set_name("storage room");
                set_short("storage room");
                set_long("This room hold the stuff for the lidelas shop");
                

                
                
}
void reset()
{
 ::reset();
    if (!present("wooden sword")) 
    new(WEP "wooden_sword.c")->move(this_object());
    if (!present("simple cloth jerkin")) 
    new(ARM "cloth_jerkin.c")->move(this_object());
    if (!present("wooden club")) 
    new(WEP "wooden_club.c")->move(this_object());
    if (!present("wooden pike")) 
    new(WEP "wooden_pike.c")->move(this_object());
}

