#include <swamp.h>
#include <std.h>
inherit MONSTER;

int clawsgo();
void create() {
::create();
set_name("ghast");
set_short("a horrible little ghast");
set_long("Ghasts are nasty bipedal creatures that stand two meters high but do
to their 'haunched' posture, they tend to be closer to one meter in height. 
They have slick olive green skin, buldging eyes, and course black hair.  The
most distinguishing feature of the ghast is its claws which measure nearly a
foot in length.");
set_invis();
set_moving(1);
set_speed(20);
set("aggressive", 80);
set_id(({"ghast", "shadow"}));
set_skill("attack", 255);
set_class("fighter");
set_swarm("");
set_subclass("warrior");
set_alignment(-800);
set_skill("blade", 300);
set_stats("intelligence", 75);
set_stats("wisdom", 60);
set_race("ghast");
set_body_type("human");
if(random(3) < 2) set_gender("male"); else set_gender("female");
set_emotes(12, ({"The ghast screams at you with a chilling sound!", "The ghast licks its claws and dives back into battle!"}),1);
set_spell_chance(40);
set_spells(({"slash", "sharpen claws"}));
set_level(40);
set_die((:  clawsgo  :));
set_hp(1100);
set_exp(195000);
new(MOB "claw")->move(this_object());
command("wield claw");
new(MOB "claw")->move(this_object());
command("wield claw");
}

int clawsgo() {
object ob;
   tell_room(environment(this_object()),"%^GREEN%^The ghast crumples into a pile of dust!%^RESET%^", ({ }));
  if (present("claw", this_object())) {
      ob = present("claw", this_object());
      catch ( ob->remove() );
   }
  if (present("claw", this_object())) {
      ob = present("claw", this_object());
      catch ( ob->remove() );
   }
this_object()->remove();

  return 0;
}
