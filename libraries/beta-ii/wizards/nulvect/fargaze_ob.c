#include <std.h>
#include <daemons.h>

#define COL "%^MAGENTA%^"
#define RES "%^RESET%^"

inherit OBJECT;
inherit "/std/living/follow";

object owner;
object tgt;
int rounds;

void receive_message(mixed cl, mixed msg);
int follow_him(string str);

void setup(object tp, object watch, int time) {
  object env;
  if (!tp || !time) return;
  owner=tp;
  tgt=watch;
  rounds=time;
  env = environment(tgt);
  set_heart_beat(1);
  tgt->add_follower(this_object());
  receive_message("room",
    "\n"+
    env->query_long()+"\n"+
    env->query_long_exits()+"\n"+
    env->describe_living_contents(({this_object()}))+"\n"+
    env->describe_item_contents(({}))
  );
}

void create() {
  ::create();
  set_name("fargaze_ob");
  set_id(({"fargaze_ob"}));
  set_weight(0);
  enable_commands();
  set_living_name("fargaze_ob");
  set_prevent_get("What?");
}

void heart_beat() {
  if (!this_object()) return;
  if (!owner || !tgt || rounds <= 0) {
    if (owner)
      message("magic", COL+"Your vision fades away."+RES, owner);
    remove();
    return;
  }
  rounds--;
}

void receive_message(mixed cl, mixed msg) {
  string tmp, dir;
  if (owner) {
    msg = TERMINAL_D->no_colours(msg);
    switch (cl) {
      case "mout":
        tmp = tgt->query_mout();
        tmp = replace_string(tmp, "$D", "%s");
        sscanf(msg, tmp, dir);
        if (dir == "enter") msg = "through the entrance.";
        else msg = dir+".";
        msg = tgt->query_cap_name()+" goes "+msg;
      break;
      case "min":
        if (sscanf(msg, "%s %*s", tmp) == 2 &&
            tmp == tgt->query_cap_name())
              return;
      case "talk":
        sscanf(msg, "%s:%*s", tmp);
        msg = tmp+" something.%^RESET%^";
      break;
      case "tell":
        return;
      break;
    }
    message("info",
      COL+"Through misty eyes you see: "+RES+(string)msg,
      owner);
  }
}

// this gets called by the follow code, return 0 for fail 1 for success
int follow(string exit) {
  object env=environment();
  string junk;
  
  if (!environment()) return 0;

  if (sscanf(exit, "%s.c", junk) == 1) exit = junk;

  // couldn't move there for some reason...
  if (move(exit)) {
    if (owner)
      message("info", COL+"Your vision fades away."+RES, owner);
    remove();
    return 0;
  }

  return 1;
}

int is_invincible() { return 1; }

int query_invis() { return 1; }

string query_long() { return "You do not notice that here."; }
