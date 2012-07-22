
#include <std.h>
#include <daemons.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^GREEN%^"
#define COL2 "%^RED%^"

#define MAX_PERC 175

inherit DAEMON;

void start_buff(object, object, int, int, int, int);
void end_buff(class Effect);

int spell() {
  object tp = this_player();
  if (tp->query_subclass() == "druid" &&
      tp->query_skill("nature") >= 120)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <bearsrage [whom]>\n\n"
    "Druids can call on the primal nature of the raging bear "
    "and bestow its powers on the target.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot call upon such forces in your state.");

  if (!tgt)
    FAIL("Call it upon whom?");

  if (!tgt->is_living())
    FAIL("That is not alive.");

  if (tgt->query_effect("bearsrage"))
    FAIL(
      (tgt == tp ? "You are" : capitalize(tgt->query_subjective())+" is")+
      " already filled with that power."
    );

  if (tp->query_mp() < 75)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_bearsrage(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int time, cost, attack, melee, strength;

  if (!spell()) return 0;

  if (str) {
    if (str == "me" || str == "myself")
      tgt = tp;
    else
      tgt = present(str, env);
  }

  if (!can_cast(tp, tgt)) return 0;

  attack = tp->query_base_skill("nature")/5;
  melee = tp->query_base_skill("nature")/5;
  strength = tp->query_base_stats("wisdom")/4;
  time = tp->query_base_stats("wisdom")*7 +
         random(tp->query_base_stats("intelligence")*4);

  cost = (attack+time)/2;

  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  tp->set_magic_round(1);
  tp->add_mp(-cost);
  tp->add_skill_points("nature", time/20 + 2);

  message("magic", COL+"You call upon the primal nature of the "+
                   COL2+"raging bear"+COL+"!"+RES, tp);
  message("magic", COL+tp->query_cap_name()+" calls upon the primal nature "
                   "of the "+COL2+"raging bear"+COL+"!"+RES, env, tp);

  message("magic", COL+"You feel the power of the "+COL2+"raging bear "+
                   COL+"enter your body!"+RES, tgt);
  message("magic", COL+tgt->query_cap_name()+" seems to look stronger."+RES,
                   env, tgt);

  start_buff(tp, tgt, time, attack, melee, strength);
  
  return 1;
}

void start_buff(object tp, object tgt, int time, int attack, int melee, int strength) {
  class Effect buff = new(class Effect);
  int tmp;

  tmp = tgt->query_skill("attack")*MAX_PERC/100;
  if (attack > tmp) attack = tmp;
  tmp = tgt->query_skill("melee")*MAX_PERC/100;
  if (melee > tmp) melee = tmp;
  tmp = tgt->query_stats("strength")*MAX_PERC/100;
  if (strength > tmp) strength = tmp;

  buff = new(class Effect);
  buff->name = "bearsrage";
  buff->castername = tp->query_name();
  buff->caster = tp;
  buff->target = tgt;
  buff->desc = "You are filled with the power of the raging bear.";
  buff->endmessages = ({
      COL+"You feel the nature of the raging bear leave you."+RES,
      COL+tgt->query_cap_name()+" seems less strong."+RES,
  });
  buff->misc = ({ attack, melee, strength });
  buff->endtime = time()+time;
  buff->endfunc = function(class Effect buff) {
    object tgt = buff->target;
    int *info = buff->misc;
    int attack = info[0];
    int melee = info[1];
    int strength = info[2];
  
    tgt->add_skill_bonus("attack", -attack);
    tgt->add_skill_bonus("melee", -melee);
    tgt->add_stat_bonus("strength", -strength);
  };

  tgt->add_skill_bonus("attack", attack);
  tgt->add_skill_bonus("melee", melee);
  tgt->add_stat_bonus("strength", strength);
  tgt->add_effect(buff);
}

void end_buff(class Effect buff) {
  object tgt = buff->target;
  int *info = buff->misc;
  int attack = info[0];
  int melee = info[1];
  int strength = info[2];

  tgt->add_skill_bonus("attack", -attack);
  tgt->add_skill_bonus("melee", -melee);
  tgt->add_stat_bonus("strength", -strength);
}
