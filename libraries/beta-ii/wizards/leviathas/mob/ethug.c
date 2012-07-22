#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("Ethereal Thug");
   set_id( ({ "thug", "ethug" }) );
   set_short("%^GREEN%^%^BOLD%^An Ethereal Thug%^RED%^");
   set("aggressive", 200);
  set_level(60);
   set_long("The ethereal thugs wander around and prey on those who would enter
the vampiric city.");
    set_body_type("human");
   set_class("rogue");
   set_subclass("assassin");
   set_spell_chance(50);
   set_spells( ({ "stab", "circle" }) );
   set_skill("knife", 250);
   set_skill("murder", 250);
   set("race", "shadow");
   set_gender("male");
   set_moving(1); 
   set_speed(4);
new(WEP "riskydag.c")->move(this_object());
    command("wield dagger");

new(ARM "trench.c")->move(this_object());
    command("wear coat");
}


