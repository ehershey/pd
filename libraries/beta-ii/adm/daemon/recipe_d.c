
#include <std.h>
#include <security.h>
#include <dirs.h>
#include <recipe_cl.h>

#define SAVE_FILE DIR_SECURE_DAEMONS_SAVE+"/recipe_d.o"

inherit DAEMON;

class Recipe *all_recipes;

void saveme() {
  seteuid(UID_SECURE_DAEMONSAVE);
  save_object(SAVE_FILE);
  seteuid(getuid());
}

void restoreme() {
  seteuid(UID_SECURE_DAEMONSAVE);
  restore_object(SAVE_FILE);
  seteuid(getuid());
}

void create() {
  restoreme();
  if (!all_recipes)
    all_recipes = ({});
}

class Recipe *query_all_recipes() { return copy(all_recipes); }

class Recipe query_recipe(string name) {
  class Recipe *r = filter(all_recipes, (: $1->name == $2 :), name);
  if (sizeof(r))
    return r[0];
  return 0;
}

varargs void add_recipe(mixed recipe, string type, string yield, mapping reqs) {
  class Recipe r;
  if (classp(recipe)) {
    r = recipe;
  }
  else if (stringp(recipe)) {
    if (query_recipe(recipe) || nullp(type) || nullp(yield) || nullp(reqs))
      return;
    r = new(class Recipe);
    r->name = recipe;
    r->type = type;
    r->yield_file = yield;
    r->user_requirements = copy(reqs);
  }

  if (r) {
    all_recipes += ({ r });
    saveme();
  }
}

void add_step(string name, int time, string method,
string *req, string *prohib, string *temps, string fail) {
  class Recipe r = query_recipe(name);
  class RecipeStep s;
  if (!r) return;
  s = new(class RecipeStep);
  s->time = time;
  s->combine_method = method;
  s->required_materials = copy(req);
  s->prohibited_materials = copy(prohib);
  s->allowed_temperatures = copy(temps);
  s->failure_yield = fail;
  if (!sizeof(r->steps)) r->steps = ({});
  r->steps += ({ s });
  saveme();
}

void remove_recipe(mixed recipe) {
  class Recipe r;
  if (classp(recipe)) {
    r = recipe;
  }
  else if (stringp(recipe)) {
    r = query_recipe(recipe);
  }

  if (r) {
    all_recipes -= ({ r });
    saveme();
  }
}

void remove_step(string name, int step) {
  class Recipe r = query_recipe(name);
  if (!r) return;
  step--;
  if (step < 0 || step >= sizeof(r->steps)) return;
  r->steps = r->steps[0..step-1] + r->steps[step+1..];
  saveme();
}

int check_user_requirements(mixed recipe, object tp) {
  class Recipe r;
  int pass;

  if (stringp(recipe)) {
    r = query_recipe(recipe);
  }
  if (classp(recipe)) {
    r = recipe;
  }
  if (!r) return 0;

  foreach (string key, mixed value in r->user_requirements) {
    switch (key) {
      case "level": 
        if (tp->query_level() < value) return 0;
      break;
      case "race": 
        if (member_array(tp->query_race(), value) == -1) return 0;
      break;
      case "class": 
        if (member_array(tp->query_class(), value) == -1) return 0;
      break;
      case "subclass": 
        if (member_array(tp->query_subclass(), value) == -1) return 0;
      break;
      case "skills":
        foreach (string sk, int amt in value) {
          if (tp->query_skill(sk) < amt)
            return 0;
        }
      break;
      case "stats":
        foreach (string st, int amt in value) {
          if (tp->query_stats(st) < amt)
            return 0;
        }
      break;
    }
  }

  return 1;
}

int check_step_requirements(mixed recipe, int step,
object *items, string *methods, string *temps) {
  class Recipe r;
  class RecipeStep s;
  string *materials;

  if (stringp(recipe)) {
    r = query_recipe(recipe);
  }
  if (classp(recipe)) {
    r = recipe;
  }
  if (!r) return 0;
  if (step >= sizeof(r->steps) || step < 0) return 0;

  s = r->steps[step];

  materials = ({});
  foreach (object a in items)
    materials |= (a->query_materials() || ({}) );

  // gods this looks ugly
  if (
     (sizeof(s->required_materials & materials) !=
      sizeof(s->required_materials)) ||
     (sizeof(s->prohibited_materials & materials)) ||
     (
       member_array(s->combine_method, methods) == -1 &&
       s->combine_method != "any"
     ) ||
     (

       !sizeof(s->allowed_temperatures & temps) &&
       (sizeof(s->allowed_temperatures) && s->allowed_temperatures[0] != "any")
     )
  ) {
    return 0;
  }

  return 1;
}

static varargs string display_variable(mixed v, string type) {
  string ret;

  if (nullp(v)) return "";
  if (nullp(type)) type = typeof(v);

  switch (type) {
    case "float":
    case "int": ret = ""+v; break;
    case "string": ret = v; break;
    case "array":
      if (!v || !sizeof(v))
        return "";
      ret = implode(v, ",");
      //ret = "(" + implode(v, ",") + ")";
    break;
    case "mapping":
      if (!v || !sizeof(v))
        return "";
      ret = "";
      foreach (string key, mixed value in v) {
        ret += key + "(" + display_variable(value) + ") ";
      }
      ret = ret[0..<2]; // remove space at end of last entry
    break;
  }

  return ret;
}

string *query_recipe_names() {
  return map(query_all_recipes(), (: $1->name :) );
}

string query_recipe_string(mixed recipe) {
  class Recipe r;
  string ret, tmp;

  if (classp(recipe)) r = recipe;
  else if (stringp(recipe)) r = query_recipe(recipe);

  if (!r) return "";

  ret = sprintf("%%^BOLD%%^%%^RED%%^Name:%%^RESET%%^ %s\ntype: %s\nyield: %s\n",
    r->name, r->type, r->yield_file);
  ret += "user requirements: ";
  tmp = display_variable(r->user_requirements, "mapping");
  if (!strlen(tmp)) tmp = "none";
  ret += tmp+"\n";

  for (int i = 0; i < sizeof(r->steps); i++) {
    ret += sprintf("step %2d.  time: %2d  method: %s\n",
      i+1, r->steps[i]->time, r->steps[i]->combine_method
    );
    tmp = display_variable(r->steps[i]->required_materials, "array");
    if (!strlen(tmp)) tmp = "none";
    ret += sprintf("  materials required: %s\n", tmp);
    tmp = display_variable(r->steps[i]->prohibited_materials, "array");
    if (!strlen(tmp)) tmp = "none";
    ret += sprintf("  materials prohibited: %s\n", tmp);
    tmp = display_variable(r->steps[i]->allowed_temperatures, "array");
    if (!strlen(tmp)) tmp = "none";

    ret += sprintf("  temperatures allowed: %s\n", tmp);
    tmp = r->steps[i]->failure_yield;
    if (!tmp || !strlen(tmp)) tmp = "none";
    ret += sprintf("  failure yields: %s\n", tmp);
  }

  return ret;
}


