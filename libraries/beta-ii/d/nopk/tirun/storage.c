#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() 
{
    ::create();
        set_no_clean(1);
        set_name("storage room");
        set_short("storage room");
        set_long("This room holds the stuff for the Tirun shop");
        set_exits((["north" : ROOMS"supply"]) );

        new(OBJ"vial")->move(this_object());
        new("/d/nopk/standard/obj/misc/forage/pot")->move(this_object());
        new(OBJ"tirun_seal")->move(this_object());
        new(OBJ"tirun_seal")->move(this_object());
        new(OBJ"tirun_seal")->move(this_object());
        new(OBJ"seal_blank")->move(this_object());
        new(OBJ"seal_blank")->move(this_object());
        new("/wizards/daboura/healing_ring.c")->move(this_object());
        new(OBJ"backpack")->move(this_object());
        new(OBJ"backpack")->move(this_object());

                
}
void reset()
{
 ::reset();
    if (!present("tirun seal")) 
        new(OBJ "tirun_seal.c")->move(this_object());
    if (!present("tirun seal 2")) 
        new(OBJ "tirun_seal.c")->move(this_object());
    if (!present("tirun seal 3")) 
        new(OBJ "tirun_seal.c")->move(this_object());
    if (!present("vial")) 
        new(OBJ "vial.c")->move(this_object());
    if (!present("pot")) 
        new("/d/nopk/standard/obj/misc/forage/pot")->move(this_object());
    if (!present("backpack")) 
        new(OBJ "backpack.c")->move(this_object());
    if (!present("backpack 2")) 
        new(OBJ "backpack.c")->move(this_object());    

    if(random(100) < 35) {
        if (!present("wax")) 
        new(OBJ "seal_blank")->move(this_object());  
        if(random(100) < 35) {
            if (!present("wax 2")) 
            new(OBJ "seal_blank")->move(this_object());
        }  
    }
    if(random(100) < 5) {
        if (!present("healing ring")) 
            new(OBJ "/wizards/daboura/healing_ring.c")->move(this_object());   
    }
}

