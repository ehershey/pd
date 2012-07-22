#include <std.h>
inherit MONSTER;

void create() {
    ::create();
    set_name("dark elf");
    set_short("a dark elf");
    set_long("This tall, handsome creature closely resembles the woodland elves. The only difference "
      "being it's deep blue skin and intelligent black eyes. ");
    set_id(({"elf", "dark", "darkelf"}));
    set_level(30);
    set_race("dark elf");
    set_body_type("human");
    set_gender("male");
    set_class("wanderer");
    set_subclass("swashbuckler");
    set_spell_chance(45);
    set_spells( ({"bladedance"}) );
    new("/d/helgrath/items/armor/platemail")->move(this_object());
    new("/d/helgrath/items/weapons/shortsword")->move(this_object());
    command("wield sword");
    command("wear all");
     if(random(200) > 180) {
        new("/wizards/daboura/arm/dull_brass_leggings.c")->move(this_object());
       command("wear leggings");
    }
}
