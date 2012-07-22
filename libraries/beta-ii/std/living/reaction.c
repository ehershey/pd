
// for Reaction class def, init_reaction() func, and all REACTION_ macros:
#include <reaction_cl.h>
#include <function.h>

static class Reaction *ReactionQueue = ({});
static string *ReactionNames = ({});

int valid_reaction(class Reaction reac);
void insert_reaction(class Reaction reac, int index);
void add_reaction(class Reaction reac);
void remove_reaction_number(int index);
void remove_reaction_name(string name);
void remove_reaction(class Reaction reac);
void remove_invalid_reactions();
class Reaction *query_reactions();
string *query_reaction_names();
int query_reaction_name(string name);
int query_reaction(class Reaction reac);
varargs int do_reactions(object target, object subject, string verb, int type);

void create() {
  ReactionQueue = ({});
  ReactionNames = ({});
}

void heart_beat() {
  remove_invalid_reactions();
}

int valid_reaction(class Reaction reac) {
  if (!reac || reac->time < time() ||
      !reac->name || !strlen(reac->name) ||
      !functionp(reac->func) )
        return 0;
  return 1;
}

void insert_reaction(class Reaction reac, int index) {
  if (!valid_reaction(reac)) return;
  if (member_array(reac->name, ReactionNames) != -1) return;
  if (index >= sizeof(ReactionQueue)) {
    ReactionQueue += ({ reac });
    ReactionNames += ({ reac->name });
  }
  else {
    ReactionQueue =
      ReactionQueue[0..index-1] + ({ reac }) + ReactionQueue[index+1..<1];
    ReactionNames =
      ReactionNames[0..index-1] + ({ reac->name }) + ReactionNames[index+1..<1];
  }
}

void add_reaction(class Reaction reac) {
  insert_reaction(reac, sizeof(ReactionQueue));
}

void remove_reaction_number(int index) {
  if (index >= sizeof(ReactionQueue)) return;
  ReactionQueue = ReactionQueue[0..index-1] + ReactionQueue[index+1..<1];
  ReactionNames = ReactionNames[0..index-1] + ReactionNames[index+1..<1];
}

void remove_reaction_name(string name) {
  int index;
  if (!name || !strlen(name)) return;
  index = member_array(name, ReactionNames);
  if (index == -1) return;
  remove_reaction_number(index);
}

void remove_reaction(class Reaction reac) {
  int index;
  index = member_array(reac, ReactionQueue);
  if (index == -1) return;
  remove_reaction_number(index);
}

void remove_invalid_reactions() {
  foreach (class Reaction reac in ReactionQueue)
    if (!valid_reaction(reac))
      remove_reaction(reac);
}

class Reaction *query_reactions() {
  remove_invalid_reactions();
  return ReactionQueue;
}

string *query_reaction_names() {
  remove_invalid_reactions();
  return ReactionNames;
}

int query_reaction_name(string name) {
  remove_invalid_reactions();
  return member_array(name, ReactionNames) != -1;
}

int query_reaction(class Reaction reac) {
  remove_invalid_reactions();
  return member_array(reac, ReactionQueue) != -1;
}

varargs int do_reactions(object target, object subject, string verb, int type) {

  int finalret = 0;

  if (nullp(target)) target = this_object();
  if (nullp(subject)) subject = this_player();
  if (nullp(verb)) verb = query_verb();
  if (nullp(type)) type = REACTION_TYPE_ATTACK;

  foreach(class Reaction reac in ReactionQueue) {
    int ret = 0;

    if (!valid_reaction(reac)) {
      remove_reaction(reac);
      continue;
    }

    reac->current["target"] = target;
    reac->current["subject"] = subject;
    reac->current["verb"] = verb;
    reac->current["type"] = type;
    reac->current["fail"] = 0;

    // can match ANY ONE of the types
    if (reac->type && (type & reac->type) == 0) continue;
    // but ignore it if it also matches one of the ignored types
    if (type & reac->ignore != 0) continue;
    // if it matches a type but also matches a fail type, fail
    if (reac->fail && (type & reac->fail) != 0) ret |= REACTION_FAILED;

    if (sizeof(reac->verbs) && member_array(verb, reac->verbs) == -1) continue;
    if (member_array(verb, reac->ignore_verbs) != -1) continue;
    if (sizeof(reac->fail_verbs) && member_array(verb, reac->fail_verbs) != -1) ret |= REACTION_FAILED;

    if (!(ret & REACTION_FAILED))
      ret = evaluate(reac->func, reac);

    if (ret & REACTION_FAILED) {
      reac->current["fail"] = 1;
      if (reac->continue_on_fail)
        ret |= REACTION_CONTINUE;
      if (functionp(reac->failfunc) && !(functionp(reac->failfunc) & FP_OWNER_DESTED))
        evaluate(reac->failfunc, reac);
    }
    else if (ret & REACTION_SUCCEEDED) {
      if (functionp(reac->postfunc) && !(functionp(reac->postfunc) & FP_OWNER_DESTED))
        evaluate(reac->postfunc, reac);
      if (reac->uses != -1)
        reac->uses = reac->uses - 1;
    }

    if (ret & REACTION_PREVENT)
      finalret = 1;

    if (reac->uses == 0)
      remove_reaction(reac);

    if (!(ret & REACTION_CONTINUE)) break;

  }

  return finalret;
}

