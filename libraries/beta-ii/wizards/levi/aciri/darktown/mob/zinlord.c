#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("Balra'Zin");
    set_short("Balra'Zin the Vampire Lord");
    set_long("Balra'Zin is very old.  He looks almost dead.");
    set_id(({"balra", "zin"}));
    set_level(80);
    set_race("vampire");
    set_body_type("human");
    set_gender("male");
    set_skill(({"blade", 500, "attack", 500,);
    set_stats("strength", 500, "dexterity", 500,);
new("/wizards/leviathas/wep/darksword.c")->move(this_object());
    command("wield sword");
    
}

   
