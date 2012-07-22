#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("vampire");
   set_id( ({ "vampire" }) );
   set_short("A noble");
   set("aggressive", 20);
  set_level(50);
   set_long("This vampire is a noble man, extremely pale but handsome and clad in royal garb.");
    set_body_type("human");
   set_class("fighter");
   set_subclass("knight");
   set_spell_chance(50);
   set_spells( ({ "slash", "rush" }) );
   set_skill("blade", 200);
   set_skill("defense", 200);
   set("race", "vampire");
   set_gender("male");
new(WEP "broadsword.c")->move(this_object());
    command("wield sword");

new(ARM "noblegarb.c")->move(this_object());
    command("wear clothes");
}

