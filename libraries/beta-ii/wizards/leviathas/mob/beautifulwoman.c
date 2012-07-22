#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("vampire");
   set_id( ({ "vampire" }) );
   set_short("Beautiful lady");
   set("aggressive", 20);
  set_level(50);
   set_long("This vampire is a beautiful lady, smiling and looking around as she drinks from her goblet.");
    set_body_type("human");
   set_class("rogue");
   set_subclass("assassin");
   set_spell_chance(50);
   set_spells( ({ "stab", "circle" }) );
   set_skill("knife", 300);
   set_skill("murder", 300);
   set("race", "vampire");
   set_gender("female");
new(WEP "spyknife.c")->move(this_object());
    command("wield knife");

new(ARM "jeweledress.c")->move(this_object());
    command("wear dress");
}

