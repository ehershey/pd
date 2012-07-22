#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("vampire");
   set_id( ({ "vampire" }) );
   set_short("A rather wealthy looking Gentleman");
   set("aggressive", 20);
  set_level(60);
   set_long("Along with all the other vampires in here, this man looks very rich.  He is well dressed and he sure knows how to dance!.");
    set_body_type("human");
   set("race", "vampire");
   set_skill("melee", 600);
   set_skill("attack", 600);
   set_gender("male");
new(ARM "blacksuit.c")->move(this_object());
    command("wear suit");

new(ARM "goldencape.c")->move(this_object());
    command("wear cape");

new(ARM "tie.c")->move(this_object());
    command("wear tie");

new(ARM "timepiece.c")->move(this_object());
    command("wear time");

}

