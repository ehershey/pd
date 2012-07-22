#include <std.h>;
#include <shadow.h>;

inherit MONSTER;

void create() {
    ::create();
    set_name("Chimney Sweeper");
    set("id",({"sweeper","worker","chimney sweeper","monster"}));
    set_level(30);
    set("short","A Chimney Sweeper");
    set("long","The Chimney Sweeper smiles at you and and works away.");
    set("race","elf");
    set_gender("male");
    set_body_type("human");
    set_alignment(100);
    if(random(100) < 95) {
    new(WEP "broom.c")->move(this_object());
    this_object()->force_me("wield broom");
    }
    else {
    new("/wizards/daboura/wep/ancient_trident.c")->move(this_object());
    command("wield spear");
    }
    set("aggressive",10);
    set_spell_chance(20);
    set_spells(({"pummel"}));
}
