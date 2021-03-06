//  Remort System
//  Generated by Whit

// edits by Nulvect 2011-09-21

#include <daemons.h>

//  Dataset:
//  remort_data = ([
//    "rogue" : ([
//      "race" : "ferrel",
//      "level" : 5,
//      "alignment" : -1500,
//      "stats" : ([
//        "wisdom" : 1,
//      ]),
//      "skills" : ([
//        "attack" : 1,
//      ]),
//    ]),
//  ]);

mapping remort_data;


varargs static private void init_remort_data(string *);
varargs void remort_save_current(string);
varargs void do_remort(string, string, string);
mapping query_remort_data();
void clear_remort_data();
void clear_remort_sub_data(string);


void create() {
  init_remort_data();
}


varargs static private void init_remort_data(string *subs) {
  if (!remort_data) remort_data = ([]);
  if (subs) {
    foreach (string s in subs) {
      if (!remort_data[s]) {
        remort_data[s] = ([]);
      }
    }
  }
}

varargs void remort_save_current(string race) {
  string cur = this_object()->query_subclass();

  init_remort_data( ({ cur }) );

  if (!race)
    race = this_object()->query_race();

  remort_data[cur]["race"] = race;
  remort_data[cur]["skills"] = this_object()->query_skills();
  remort_data[cur]["stats"] = this_object()->query_base_stats();
  remort_data[cur]["level"] = this_object()->query_level();
  remort_data[cur]["exp"] = this_object()->query_exp();
  remort_data[cur]["alignment"] = this_object()->query_alignment();
}

// do_remort(subclass) to change into a sub and assume races are set
// do_remort(subclass, race) to specify new race if no race exists
// do_remort(subclass, newrace, oldrace) to specify races for old and new subs
varargs void do_remort(string sub, string newrace, string oldrace) {
  string cls, cur;

  if (!sub) return;
  cur = this_object()->query_subclass();
  if (cur == sub) return;

  init_remort_data( ({ cur, sub }) );

  if (!newrace) {
    if (remort_data[sub]["race"])
      newrace = remort_data[sub]["race"];
    else
      newrace = this_object()->query_race();
  }

  if (!oldrace) {
    if (remort_data[cur]["race"])
      oldrace = remort_data[cur]["race"];
    else
      oldrace = this_object()->query_race();
  }

  cls = SKILLS_D->query_class(sub);

  remort_save_current(oldrace);

  if (!RACE_D->is_player_race(newrace))
    newrace = "human";

  this_object()->set_race(newrace);
  this_object()->set_class(cls);
  this_object()->set_subclass(sub);
  this_object()->set_exp(remort_data[sub]["exp"]);
  this_object()->new_body();

  if (!remort_data[sub]["skills"]) {
    this_object()->init_skills(cls);
    this_object()->fix_skills();
  }
  else
    this_object()->set_skills(remort_data[sub]["skills"]);

  if (!remort_data[sub]["stats"]) { 
    this_object()->init_stats();
    ADVANCE_D->roll_stats(this_object());
  }
  else {
    this_object()->set_base_stats(remort_data[sub]["stats"]);
  }

  if (remort_data[sub]["level"]) {
    this_object()->set_level(remort_data[sub]["level"]);
    this_object()->set_alignment(remort_data[sub]["alignment"]);
  }
  else {
    this_object()->set_level(1);
    this_object()->set_alignment(ADVANCE_D->query_initial_alignment(sub));
  }

  this_object()->fix_vital_bonus();

  remort_save_current(newrace);
}

mapping query_remort_data() { return copy(remort_data); }
void clear_remort_data() { remort_data=([]); }
void clear_remort_sub_data(string sub) { if (sizeof(remort_data)) map_delete(remort_data, sub); }

