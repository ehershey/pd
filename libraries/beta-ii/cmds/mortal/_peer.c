#include <std.h>
#include <rooms.h>

inherit DAEMON;

static private int lookup_file(string, object, string ref, string ref, object ref);

void help() {
  message("help",
    "Syntax: <peer [direction]>\n"
    "        <peer into [entrance]>\n\n"
    "Allows you to look into the next room.",
    this_player() );
}

int cmd_peer(string str) {
  object tp = this_player();
  object env = environment(tp);
  object dest, tgt;
  string file, exit;
  string mymsg, yourmsg, theirmsg;
  string *doors;
  int light, destlight, enter;
  
  light = effective_light(tp);

  if (tp->query_blind())
    mymsg = "You cannot see.";

  else if (light > 6)
    mymsg = "It is much too bright to see.";

  else if (light < -6)
    mymsg = "It is far too dark to see.";

  else if (!str) {
    mymsg = "You peer around the room.";
    theirmsg = tp->query_cap_name()+" peers around the room.";
  }

  else if (tgt = present(str, env)) {
    if (tgt == tp)
      mymsg = "That's not possible.";
    else {
      mymsg = "You peer at "+tgt->query_cap_name()+".";
      yourmsg = tp->query_cap_name()+" peers at you.";
      theirmsg = tp->query_cap_name()+" peers at "+tgt->query_cap_name()+".";
    }
  }

  /*
  else if (!(file = env->query_exit(
            exit = env->query_long_direction(env->exit_translate(str))
          )) || file == ROOM_VOID ||
          (!file_exists(file) && !file_exists(file+".c")) ||
          !(dest = load_object(file)))
            mymsg = "You cannot see far in that direction.";
  */

  // passing by reference, yum yum
  else if (!lookup_file(str, env, ref file, ref exit, ref dest))
    mymsg = "You cannot see far in that direction.";

  else if (sizeof(doors = env->query_doors_blocking_exit(exit)) &&
          sizeof(doors = filter(doors, (: $2->query_closed($1) :), env)))
            mymsg = "The "+env->query_door_name(doors[0])+" blocks your view.";

  else if ((destlight = dest->query_light()) > 3)
    mymsg = "It is too bright to see "+exit+".";

  else if (destlight < -3)
    mymsg = "It is too dark to see "+exit+".";

  else {
    mymsg = dest->query_long(0) + "\n" +
            dest->query_long_exits() + "\n" +
            dest->describe_living_contents( ({}) ) + "\n" +
            dest->describe_item_contents( ({}) );
    theirmsg = tp->query_cap_name()+" peers "+exit+".";
  }

  message("my_action", mymsg, tp);

  if (!tp->use_stealth("look")) {
    if (tgt && strlen(yourmsg))
      message("other_action", yourmsg, tgt);
    if (strlen(theirmsg))
      message("other_action", theirmsg, env, ({ tp, tgt }) );
  }

  return 1;
}

// arg list too long to fit on one line... argh
static private int lookup_file(
string str, object env, string ref file, string ref exit, object ref dest) {

  exit = env->query_long_direction(env->exit_translate(str));
  file = env->query_exit(exit);

  if (!file || file == ROOM_VOID)
    return 0;

  if (file[<2..<1] != ".c")
    file += ".c";

  dest = find_object(file);
  if (!dest && file_exists(file))
    dest = load_object(file);

  if (!dest)
    return 0;

  return 1;
}
