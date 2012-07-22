#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("vampire");
   set_id( ({ "vampire" }) );
   set_short("An old man who looks like a King");
   set("aggressive", 20);
  set_level(70);
   set_long("Amazing.  Even among the vampires this old man looks like a king.  He is dressed in a robe that shines brightly against the amber light.");
    set_body_type("human");
   set("race", "vampire");
   set_skill("melee", 700);
   set_skill("attack", 700);
   set_gender("male");
new(ARM "kingrobe.c")->move(this_object());
    command("wear robe");

new(ARM "kcrown.c")->move(this_object());
    command("wear crown");


}

