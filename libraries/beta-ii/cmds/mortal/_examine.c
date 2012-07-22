
#include <std.h>
#include <dirs.h>

inherit DAEMON;

string *living_checks = ({
  DIR_MORTAL_CMDS+"/_consider",
  "sense", "measure", "evaluate", "case", "limbs",
  "mindprobe",
});
string *item_checks = ({
  "discern", "case", "lore",
});
string *living_sense_checks = ({
  "listen", "smell",
});
string *item_sense_checks = ({
  "listen", "smell", "read", "touch",
});

void help() {
  message("help",
    "Syntax: <examine [living]>\n"
    "        <examine [item]>\n"
    "\n"
    "Allows you to closely examine items or living things.\n"
    "This command will automatically use whatever special abilities you may "
    "have that will show you more information about the object or person.\n"
    "With items, you will notice any obvious sounds, smells, writing, or "
    "physical sensations present. With people you will only notice obvious "
    "sounds and smells.",
    this_player() );
}

int cmd_examine(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  string *checks;
  string *senses;
  string tgtname, tgtobjective;
  int flag = 0;

  if (tp->query_busy())
    return notify_fail("You are too busy to examine anything right now.");

  if (!str)
    return notify_fail("Examine what?");

  tgt = present(str, env);
  if (tgt) {
    if (tgt->is_living()) {
      checks = living_checks;
      senses = living_sense_checks;
      tgtname = tgt->query_cap_name();
      tgtobjective = tgt->query_objective();
    }
    else
      return notify_fail("You must be holding an item to examine it.");
  }
  else {
    tgt = present(str, tp);
    if (!tgt)
      return notify_fail("There is no \""+str+"\" here to examine.");
    checks = item_checks;
    senses = item_sense_checks;
    tgtname = definite_article(tgt->query_name());
    tgtobjective = "it";
  }

  message("info", "You examine "+tgtname+".", tp);

  foreach (string cmd in checks) {
    string path;
    object cmdob;
    string special;

    if (cmd[0..0] == "/") {
      path = cmd + ".c";
      sscanf(cmd, "%*s/_%s", cmd);
    }
    else {
      path = DIR_CLASS_CMDS + "/_" + cmd + ".c";
    }

    if (file_size(path) < 1 ||
      !(cmdob = load_object(path)))
        continue;

    if (!(cmdob->abil() || cmdob->spell()))
      continue;

    if (special = cmdob->query_examine(tp, tgt)) {
      message("info", special, tp);
    }
    else {
      tp->force_me(cmd + " " + str);
    }

    flag = 1;
  }
  foreach (string sense in senses) {
    if (strlen(tgt->query_sense(sense, "default"))) {
      tp->force_me(sense + " " + str);
      flag = 1;
    }
  }

  if (!flag)
    message("info", "You find nothing special about "+tgtobjective+".", tp);

  if (!tp->query_disable())
    tp->set_disable();

  return 1;
}
