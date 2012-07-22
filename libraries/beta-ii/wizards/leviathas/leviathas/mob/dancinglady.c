#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("vampire");
   set_id( ({ "vampire" }) );
   set_short("Dancing Lady");
   set("aggressive", 20);
  set_level(60);
   set_long("This female vampire can't seem to stop dancing - she twirls, she spins, she flips, she flies.  She looks incredibly rich.");
    set_body_type("human");
   set_skill("melee", 600);
   set_skill("attack", 500);
   set("race", "vampire");
   set_gender("female");
new(ARM "bandgdress.c")->move(this_object());
    command("wear dress");

new(ARM "beadednecklace.c")->move(this_object());
    command("wear necklace");

new(ARM "starbracelet.c")->move(this_object());
    command("wear bracelet");
}

