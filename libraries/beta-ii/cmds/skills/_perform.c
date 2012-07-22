#include <std.h>
#define DDIR "/cmds/dances/"
#define FAIL(s) return notify_fail(s)
#define DANCE_ID "dance_ob_id"
inherit DAEMON;

int abil() {
  object o = this_player();
  if (o->query_subclass() == "gypsy")
    return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <perform [dance name] (for [whom])>\n\n"
    "Gypsies can perform many dances with different effects.",
    this_player());
}

int can_cast(object tp, object tgt, object dance) {

  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("Your voice is hollow.\n");

  if (tp->query_rest_type())
    FAIL("You can't dance while sitting.\n");
  
  if (present(DANCE_ID,tp))
    FAIL("You are already performing a dance!\n");

  if (environment(tp)->query_property("no magic"))
    FAIL("You cannot dance here.\n");

  if (!objectp(dance))
    FAIL("You do not know that dance.\n");

  if (!(dance->dance(tp)))
    FAIL("You do not know that dance.\n");

  if (dance->query_target_required()) {
    if (!tgt)
      FAIL("Perform for whom?\n");

    if (!living(tgt))
      FAIL("The "+tgt->query_name()+" doesn't seem to appreciate your talent.\n");
  }

  // check() should use notify_fail() to set a message so don't set one here
  if (function_exists("check",dance) != 0 && !(dance->check()))
    return 0;
  
  if (dance->query_auto() || dance->query_type() == "attack") {
    if (environment(tp)->query_property("no attack"))
      FAIL("You cannot attack here.\n");
    if (tp == tgt)
      FAIL("You cannot attack yourself.\n");
    if (dance->query_target_required() && !(tp->kill_ob(tgt)))
      FAIL("You cannot attack "+tgt->query_cap_name()+" yet.\n"); 
  }

  return 1;
}

int cmd_perform(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, dance;
  object *ai;
  string what, target="";
  string path, party;
  int s;

  if (!abil())
    return 0;

  if (!str)
    FAIL("Perform what?\n");

  if ((s = strsrch(str, " for ", -1)) != -1) {
    what = str[0..s-1];
    target = str[s+5..<1];
  }
  else
    what = str;

  if (target) {
    if (target == "me")
      tgt = tp;
    else
      tgt = present(target,env);
  }

  path = DDIR+replace_string(what, " ", "_");

  if (file_size(path+".c") >= 1)
    dance = new(path);
  else {
    path = DDIR+replace_string(str, " ", "_");
    if (file_size(path+".c") >= 1)
      dance = new(path);
  }
   
  // do all this here so the check() function can access
  //  query_caster() and query_target() 
  if (objectp(dance)) {

    // choose default targets based on type of dance
    if (!objectp(tgt) && objectp(dance) && dance->query_target_required()) {
      if (dance->query_auto() || dance->query_type() == "attack" ||
          dance->query_type() == "detrimental") {
            tp->clean_up_attackers();
            tgt = tp->query_current_attacker();
      }
      if (dance->query_type() == "beneficial")
        tgt = tp;
    }
        
    // Set caster/target
    dance->set_id( dance->query_id()+({DANCE_ID}) );
    dance->set_caster(tp);
    if (tgt)
      dance->set_target(tgt);

  }

  if (!can_cast(tp, tgt, dance)) {
    if (dance) dance->remove();
    return 0;
  }

  // area attacks...
  if (dance->query_auto() && !(dance->query_target_required())) {
    ai = all_inventory(env);
    if (!(dance->query_party_hit()) && sizeof(party=tp->query_party()))
      ai = filter(ai,
        function (object thing, string party) {
          if (!living(thing)) return 0;
          if (thing->query_party() == party) return 0;
          return 1;
        }, party);
    else
      ai = filter(ai, (: living($1) :) );
    foreach (object who in ai-({tp}))
      if (!(tp->kill_ob(who)))
        message("dance", "You cannot attack "+who->query_cap_name()+" yet.", tp);
  }

  // Move the song to this player and start singing!
  dance->move(tp);
  dance->start();

  return 1;
}

