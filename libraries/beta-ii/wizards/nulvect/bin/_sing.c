#include <std.h>
#define SDIR "/cmds/song/"
#define FAIL(s) return notify_fail(s)
#define SONG_ID "song_ob_id"
inherit DAEMON;

int abil() {
  object o = this_player();
  if (o->query_subclass() == "bard" ||
      o->query_subclass() == "jester" ||
      o->query_subclass() == "gypsy")
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <sing [song name]>\n\n"
    "Many wanderers are able to sing wonderous songs to harm or heal.",
    this_player());
}

int can_cast(object tp, object tgt, object song) {

  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("Your voice is hollow.\n");

  if (present(SONG_ID,tp))
    FAIL("You are already singing a song!\n");

  if (environment(tp)->query_property("no magic"))
    FAIL("You cannot sing here.\n");

  if (!objectp(song))
    FAIL("You do not know that song.\n");

  if (!(song->song(tp)))
    FAIL("You do not know that song.\n");

  if (song->query_target_required()) {
    if (!tgt)
      FAIL("Sing to whom?\n");

    if (!living(tgt))
      FAIL("Do the objects sing back to you?\n");
  }
  
  if (song->query_auto() || song->query_type() == "attack") {
    if (environment(tp)->query_property("no attack"))
      FAIL("You cannot attack here.\n");
    if (tp == tgt)
      FAIL("You cannot attack yourself.\n");
    if (song->query_target_required() && !(tp->kill_ob(tgt)))
      FAIL("You cannot attack "+tgt->query_cap_name()+" yet.\n"); 
  }

  /*
  if (song->query_type() == "detrimental" && tp == tgt)
    FAIL("You would not like to sing this song to yourself.\n");
  */

  // check() should use notify_fail() to set a message so don't set one here
  if (function_exists("check",song) != 0 && !(song->check()))
    return 0;

  return 1;
}

int cmd_sing(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, song;
  object *ai;
  string what, target="";
  string path, party;
  int s;

  if (!abil())
    return 0;


  if (!str)
    FAIL("Sing what?\n");

  if ((s = strsrch(str, " to ", -1)) != -1) {
    what = str[0..s-1];
    target = str[s+4..<1];
  }
  else
    what = str;

  if (target) {
    if (target == "me")
      tgt = tp;
    else
      tgt = present(target,env);
  }

  path = SDIR+replace_string(what, " ", "_");

  if (file_size(path+".c") >= 1)
    song = new(path);
  else {
    path = SDIR+replace_string(str, " ", "_");
    if (file_size(path+".c") >= 1)
      song = new(path);
  }
    
  // do all this here so the check() function can access
  //  query_caster() and query_target()
  if (objectp(song)) {

    // choose default targets based on type of song
    if (!objectp(tgt) && song->query_target_required()) {
      if (song->query_auto() || song->query_type() == "attack" ||
          song->query_type() == "detrimental") {
            tp->clean_up_attackers();
            tgt = tp->query_current_attacker();
      }
      if (song->query_type() == "beneficial")
        tgt = tp;
    }
        
    // Set caster/target
    song->set_id( song->query_id()+({SONG_ID}) );
    song->set_caster(tp);
    if (tgt)
      song->set_target(tgt);

  }

  if (!can_cast(tp, tgt, song)) {
    song->remove();
    return 0;
  }

  // Move the song to this player and start singing!
  song->move(tp);
  song->start();

  // area attacks...
  if (song->query_auto() && !(song->query_target_required())) {
    ai = all_inventory(env);
    if (!(song->query_party_hit()) && sizeof(party=tp->query_party()))
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
        message("song", "You cannot attack "+who->query_cap_name()+" yet.", tp);
  }

  return 1;
}

