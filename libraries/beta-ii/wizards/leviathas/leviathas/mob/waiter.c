#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("waiter");
   set_id( ({ "waiter" }) );
   set_short("A Waiter");
   set("aggressive", 20);
  set_level(50);
   set_long("A young elven man would appear to be under the mind control of the collective vampires.  He walks around taking people's orders.");
    set_body_type("elf");
   set_class("fighter");
   set_subclass("warrior");
   set_spell_chance(50);
   set_skill("melee", 300);
   set_skill("attack", 300);
   set("race", "elf");
   set_gender("male");
}

