#include <std.h>
#include <legodith_forest.h>

inherit MONSTER; 

void create() {
    ::create();
        set_name("wild gnome");
        set_id( ({ "gnome", "wild gnome" }) );
        set_short("Wild gnome");
        set("aggressive", 8);
        set_level(1 + random(5));
        set_long("A wild gnome of the forest, he doesn't look very happy");
        set_gender("male");
        set_alignment(-40);
        set_race("gnome");
        set_body_type("human");
        
        new(ARM"hide_gloves.c")->move(this_object());
        force_me("wear gloves");   
        new(ARM"rusty_helmet.c")->move(this_object());
        force_me("wear helmet");
        new(WEP"old_sword.c")->move(this_object());
        force_me("wield sword");
}
