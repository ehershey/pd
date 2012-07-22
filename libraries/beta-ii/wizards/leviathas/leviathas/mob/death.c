#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("death");
   set_id( ({ "death" }) );
   set_short("%^BOLD%^%^BLACK%^D%^RESET%^%^BOLD%^e%^RESET%^a%^BOLD%^t%^BLACK%^h%^RESET%^");
   set("aggressive", 20);
  set_level(800);
   set_long("Death searches the deathless tower endlessly for a soul to claim. 
It would not be wise to upset him, however perhaps there is an alternative way
of obtaining his equipment which you so obviously want.");
    set_body_type("human");
   set_class("fighter");
   set_spell_chance(95);
   set_spells( ({ "behead", "slash" }) );
   set_skill("blade", 1000000);
   set("race", "spirit");
   set_gender("neuter");
new(WEP "deathblade.c")->move(this_object());
    command("wield blade");

new(WEP "deathblade.c")->move(this_object());
    command("wield blade");

new(ARM "blackplatemail.c")->move(this_object());
    command("wear platemail");

new(ARM "bplategloves.c")->move(this_object());
    command("wear gloves");

new(ARM "bplateboots.c")->move(this_object());
    command("wear boots");

new(ARM "bshoulderplating.c")->move(this_object());
    command("wear plating");
}
int query_sp() { return 16000; }

