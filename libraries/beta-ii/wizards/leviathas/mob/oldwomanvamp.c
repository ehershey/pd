#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("vampire");
   set_id( ({ "vampire" }) );
   set_short("A beautiful old lady");
   set("aggressive", 20);
  set_level(50);
   set_long("This old lady must be a vampire, but she is extremely beautiful and adorned with many jewels.  How could such a beautiful old lady be so evil?");
    set_body_type("human");
   set_class("mage");
   set_subclass("sorceror");
   set_spell_chance(50);
   set_spells( ({ "liquify", "missile" }) );
   set_skill("magic attack", 200);
   set_skill("sorcery", 200);
   set("race", "vampire");
   set_gender("female");
new(WEP "glimscept.c")->move(this_object());
    command("wield staff");

new(ARM "jeweledress.c")->move(this_object());
    command("wear dress");
}
int query_sp() { return 16000; }

