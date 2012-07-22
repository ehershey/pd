// Must die from Angel within _3_ rounds or player will die

#include <std.h>
inherit MONSTER;
void set_kill(object ob);

static object kill_me;
static int count=0;
void reaper_die();

void create() {
 ::create();
   set_name("death");
   set_id(({ "death", "reaper", "grim", "grim reaper" }));
   set_short("Death, the right hand of Carnage");
   set_long("Commonly referred to as the Grim Reaper, Death is "
            "the right hand of the High God, Carnage. The Grim "
            "Reaper's power is almost limitless.");
   set_level(50);
   set_gender("male");
   set_race("undead");
   set_max_hp(500);
   set_hp(10);
   set_body_type("human");
   set_heart_beat(1);
   set_die( (: reaper_die() :) );
}

void set_kill(object ob) { kill_me = ob; }

void heart_beat() {
 ::heart_beat();
   if (count == 3) {
      tell_room(environment(kill_me), "%^BOLD%^%^BLACK%^Death screams "
         "in fury!", ({ }));
      tell_object(kill_me, "%^BOLD%^%^BLACK%^Death places his hands upon "
         "the sides of your face. A cold nothingness overcomes you.");
      tell_room(environment(kill_me), "%^BOLD%^%^BLACK%^Death places "
         "his hands upon "+kill_me->query_cap_name()+"'s face.", ({ kill_me }));
      kill_me->force_me("scream in pain!");
      kill_me->die();
      this_object()->force_me("emote fades into nothingness.");
      this_object()->remove();
   }
   count++;
}

void reaper_die()
{
 say( "The reaper fades away into the shadows.");
 this_object()->remove();
}
