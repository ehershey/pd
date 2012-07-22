//      /adm/daemon/skills_d.c
//      from the Nightmare mudlib
//      contains code that would be very memory wasteful if in the user object
//      created by Descartes of Borg 14 february 1993
//      modified by Seeker,  March 2001
//      almost completely rewritten from scratch by Nulvect 2009-06-11

#define ALLOW_SAVE 0

#include <security.h>
#include <save.h>

// this file contains a list of all skills,
// all classes, skill maxes and costs:
#include <skills_d.h>

string *allskills;
mapping subtoclass;
mapping skilltocat;

void create() {
  allskills = ({});
  subtoclass = ([]);
  skilltocat = ([]);

  // set up some reversed mappings for later lookups

  foreach (string c, string *subs in classes) {
    foreach (string sub in subs) {
      subtoclass[sub] = c;
    }
  }
  foreach (string cat, string *sks in skillcategories) {
    allskills |= sks;
    foreach (string sk in sks) {
      skilltocat[sk] = cat;
    }
  }

  // initialize skills for mobs

  foreach (string sk in allskills - keys(skillmobs))
    skillmobs[sk] = skillmobs["default"];

#ifdef ALLOW_SAVE
  seteuid( UID_SECURE_DAEMONSAVE );
  if (file_exists(SAVE_SKILLS+".o"))
    restore_object( SAVE_SKILLS );
  seteuid( getuid() );
#endif
}

#ifdef ALLOW_SAVE
void save_skills() {
  seteuid( UID_SECURE_DAEMONSAVE );
  save_object( SAVE_SKILLS );
  seteuid( getuid());
}
#endif

string *query_all_skills() { return copy(allskills); }
mapping query_all_skills_categories() { return copy(skillcategories); }
string *query_category_skills(string cat) {
  return nullp(skillcategories[cat]) ? ({}) : skillcategories[cat];
}
string query_skill_category(string sk) { return skilltocat[sk]; }

mapping query_all_classes() { return copy(classes); }
string *query_subclasses(string c) {
  return classes[c] || ({});
}
string query_class(string sub) {
  return subtoclass[sub] || "";
}

mapping init_skills(mixed thing) {
  mapping skills = ([]);
  object tp;
  string cl;
  string subcl;
  int level;
  int mob;


  if (stringp(thing)) {
    tp = previous_object();
    cl = thing;
  }
  else if (objectp(thing)) {
    tp = thing;
    cl = tp->query_class();
  }
  subcl = tp->query_subclass() || "none";
  level = tp->query_level();
  mob = tp->is_monster();

  if (!cl) {
    if (mob) {
      // this code will be used a lot, should be as fast as possible
      foreach (string sk in allskills) {
        skills[sk] = ([ "level" : evaluate(skillmobs[sk], level) ]);
      }
    }
    else {
      skills["melee"] =  ([ "level":0, "points":0, "max":1 ]);
      skills["attack"] = ([ "level":0, "points":0, "max":1 ]);
    }
  }
  
  else {
    mapping maxes = skillmaxes[cl];
    if (!nullp(skillmaxes[subcl]))
      // do not use |= here, we want any subclass specifics to overwrite class specifics
      maxes += skillmaxes[subcl];

    if (mob) {
      foreach (string sk, int max in maxes)
        skills[sk] = ([ "level" : level*max/2 ]);
    }
    else {
      foreach (string sk, int max in maxes) {
        int start;
        if (skillstarts[subcl] && !nullp(skillstarts[subcl][sk]))
          start = skillstarts[subcl][sk];
        else if (skillstarts[cl] && !nullp(skillstarts[cl][sk]))
          start = skillstarts[cl][sk];
        else
          start = max/2;
        skills[sk] = ([ "level" : start, "points" : 0, "max" : max ]);
      }
    }
  }

  skills = specialmaxes(tp, skills);

  return skills;
}

int training_formula(string cl, string subcl, int lvl, string skill) {
  int expo;
  int mult;
  object tp = previous_object();
  string race = tp->query_race();

  mixed f;

  if (!nullp(skillcosts[subcl]) &&
      functionp(f = skillcosts[subcl][skill]))
        return evaluate(f, lvl);

  else if (!nullp(skillcosts[cl]) &&
      functionp(f = skillcosts[cl][skill]))
        return evaluate(f, lvl);

  f = specialcosts(tp, skill);
  if (functionp(f))
    return evaluate(f, lvl);

  // default
  return evaluate(cubed, lvl);
}
  
// this function does not appear to be used anywhere
int query_melee_ac(string cl) {
  object tp = previous_object();
  string subcl = tp->query_subclass();

  switch(cl) {
    case "wanderer": return 19;
    case "fighter": return 20;
    case "rogue": return 18;
    case "dragon":
      if (subcl == "red") return 21;
      return 18;
      break;
    case "clergy": 
      if (subcl == "cleric") return 8;
      if (subcl == "druid") return 8;
      if (subcl == "kataan") return 10;
      if (subcl == "monk") return 26;
      break;
    case "mage": return 6;
    case "vampire": return 20;
    default: return 1;
  }
  return 0; // should never get here
}

// the following 3 functions were setting/querying m_skills,
// which seemed to be trying (and failing) to track which subs
// got which skills
// not used anywhere on the mud that I can find, so I disabled these
void add_skill(string *classes, string *subclasses, string name) { return; }
string *query_skills() { return ({}); }
mapping query_skill(string skill) { return ([]); }
// end of unused functions

