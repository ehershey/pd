//      /std/living/skills.c
//      from the Nightmare mudlib
//      code for the Nightmare skill system
//      created by Descartes of Borg 1september 1992
//      recoded 14 february 1993

#include <daemons.h>

string player_class, subclass;
mapping skills;
static mapping skill_bonus;

varargs void init_skills(string cl);
void set_skill_points(string, int);
int add_skill_points(string skill, int amount);
void reduce_skill_points(string skill, int amount);
int clean_skill_points(string skill);
void set_skill(string str, int x);
int skill_exists(string str);
int query_max_skill(string str);
int query_skill(string str);
int query_skill_points(string str);
int query_max_skill_points(string str);
void set_class(string str);
void set_subclass(string str);
mapping query_skills();
string query_class();
string query_subclass();

mapping query_skills()
{
  return copy(skills);
}
int query_max_skill_points(string skill)
{
  int max;
  max = ((skills[skill]["max"])*((int)this_object()->query_level()))/20;
  return max;
}
int clean_skill_points(string skill)
{
  int i;

  skills[skill]["points"] = 0 ;
}
varargs void init_skills(string cl) {
  skills = (mapping)SKILLS_D->init_skills(this_object());
}

void set_skill_points(string skill, int points) {
  if (skill_exists(skill))
    skills[skill]["points"] = points;
}
int add_skill_points(string skill, int amount) {
  int x, max, borg, lvl, trained, bef;

  if(!skills[skill]) return 0;


  if(amount<1) return 0;

  bef = x = skills[skill]["points"];
  lvl = skills[skill]["level"];
  x += amount;
  trained = amount;
  //    max = ((skills[skill]["max"])*((int)this_object()->query_level()))/20;
  max = skills[skill]["max"]*(this_object()->query_level())/2;
  while( x > (
    borg = (int)SKILLS_D->training_formula(player_class, subclass, lvl, skill)) ) {
    x -= borg;
    if (trained!=x) trained += borg;
    if(max > lvl) lvl ++;
    else break;
  }
  skills[skill]["points"] = x;
  if(lvl != skills[skill]["level"]) {
    if (this_object()->getenv("SKILL_SHOW")=="1")
      message("info", "%^YELLOW%^You feel more skilled in the art of "+skill+".\n", this_object());

    log_file("skills", (string)this_object()->query_name()+" advanced "+
     skill+" from "+skills[skill]["level"]+" to "+lvl+" ("+
     ctime(time())+")\n"
    );
  }
  skills[skill]["level"] = lvl;
  return trained;
}

void reduce_skill_points(string skill, int amount) {
  int x, lev;

  if(skills[skill]) x = skills[skill]["points"];
  else return;
  if(amount < 1) return;
  x -= amount;
  lev = skills[skill]["level"];
  while(x<0) {
    x +=(int)SKILLS_D->training_formula(player_class,subclass,skills[skill]["level"]-1, skill);
    skills[skill]["level"] --;
  }
  skills[skill]["points"] = x;
  if(skills[skill]["level"] != lev)
    log_file("skills", (string)this_object()->query_name()+" reduced "+
     skill+" from "+skills[skill]["level"]+" to "+lev+" ("+
     ctime(time())+")\n"
    );
}

int query_max_skill(string skill) {
  if(!skills[skill]) return 0;
  else return skills[skill]["max"];
}

int skill_exists(string str) {
  string *vars;

  vars = keys(skills);
  if(str == "picking") return 0;

  if(member_array(str, vars) == -1) return 0;
  else return 1;
}
int query_skill_points(string skill)
{
  if (skills[skill])
    return skills[skill]["points"];
  return 0;
}
int query_skill(string skill) {
  int x;

  if(skill_bonus) x= skill_bonus[skill];
  else x = 0;
  if(skills[skill]) x+= skills[skill]["level"];
  else x+= 0;
  return x;
}

int query_base_skill(string skill) {
  if(!skills || !skills[skill]) return 0;
  else return skills[skill]["level"];
}

void set_skill(string str, int x) {
  if(!skills[str]) skills[str] = ([ "level":0 ]);
  skills[str]["level"] = x;
  return;
  log_file("illegal", (string)this_object()->query_name()+
   " was advanced in "+str+" artificially by "+
   (this_player() ? this_player()->query_name() : previous_object()->query_name())+"\n");
  log_file("illegal", "file: "+file_name(previous_object())+" ("+
   getuid(previous_object())+") "+ctime(time())+"\n");
}

void fix_skills()
{
  mapping old_skills = copy(skills);
  int player_level = this_object()->query_level();

  this_object()->init_skills();

  foreach (string sk, mapping data in skills) {
    if (skill_exists(sk) && old_skills[sk]) {
      int max = skills[sk]["max"] * player_level / 2;
      int level = old_skills[sk]["level"];
      skills[sk]["level"] = level > max ? max : level;
      skills[sk]["points"] = old_skills[sk]["points"];
    }
  }
}

void set_class(string str) { 
  player_class = str; 
  fix_skills();  
  if (this_object()->is_monster()) this_object()->set_level(this_object()->query_level());
}
void set_subclass(string str) { 
  subclass = str; 
  fix_skills();
  if (this_object()->is_monster()) this_object()->set_level(this_object()->query_level());
}

string query_subclass() { 
  if (!subclass) return "none"; 
  return subclass;
}
string query_class() { return player_class; }

static void reduce_skills() {
  string *ind;
  int x;
  int i;

  ind = keys(skills);
  for(i=0; i<sizeof(ind); i++) {
    if(!skills[ind[i]]) continue;
    if(query_skill(ind[i]) < 5) continue;
    if(random(101) > 50) {
      log_file("skills", this_object()->query_name()+" lost "+
       ind[i]+" through reduce_skills() "+ctime(time())+"\n");
      skills[ind[i]]["level"] -= random(5)+1;
      skills[ind[i]]["points"] = 0;
    }
  }
}

int add_skill(string type, int level, int max)
{
  if(skill_exists(type)) return 0;
  skills[type] = (["level" : level, "points": 0, "max": max]);
  return 1;
}

int delete_skill(string type)
{
  if(!skill_exists(type)) return 0;
  map_delete(skills, type);
  return 1;
}

string *query_all_skills() { return keys(skills); }

void add_skill_bonus(string skill, int amount, int len) {
  if(!skill_bonus) skill_bonus = ([]);
  if(!skill_bonus[skill]) skill_bonus[skill] = amount;
  else skill_bonus[skill] += amount;
  if(!skill_bonus[skill]) map_delete(skill_bonus, skill);
  if (len) call_out("add_skill_bonus", len, skill, (amount * -1));
}

int query_skill_bonus(string skill) {
  if(!skill_bonus) return 0;
  if(!skill_bonus[skill]) return 0;
  return skill_bonus[skill];
}
void set_skills(mapping t) { 
  if (t) 
    if (mapp(t)) skills = t; 
}
