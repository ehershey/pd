#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("advisor");
   set_id( ({ "cain's advisor" }) );
   set_short("The advisor of Cain");
   set("aggressive", 1);
  set_level(10);
   set_long("This man is Cain's advisor.  He is skinny and weak looking, not even a vampire.  He shreaks in fear as he sees you.");
    set_body_type("human");
   set_class("none");
   set_spell_chance(0);
   set("race", "human");
   set_gender("male");

new(ARM "sentientchainmail.c")->move(this_object());
    command("wear chainmail");
}


