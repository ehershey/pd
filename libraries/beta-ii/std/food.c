//      /std/food.c
//      from the Nightmare mudlib
//      inheritable food item
//      created by Descartes of Borg October 1992
//    completely rewritten by Nulvect 2008-May-03
//    added multiple servings Nulvect 2010-Dec-14

#include <std.h>

inherit OBJECT;

int strength, disable, poisoned, uses;
string my_mess, your_mess, my_serving_mess, your_serving_mess;
mixed Extra;

string query_short_more();
string query_short_servings();
void set_my_mess(string mess);
void set_your_mess(string mess);
void set_my_serving_mess(string mess);
void set_your_serving_mess(string mess);
void set_strength(int x);
void set_dis(int x);
void set_disable(int x);
void set_uses(int x);
int query_uses();
void set_servings(int x);
int query_servings();
void set_extra(mixed);
void set_poisoned(int);
int query_poisoned();
int query_strength();
int query_disable();
string query_my_mess();
string query_your_mess();
string query_my_serving_mess();
string query_your_serving_mess();
mixed query_extra();
string expandos(string str);

string expandos(string str) {
  mapping rep = ([
   "N" : (: (this_player() ? this_player()->query_cap_name() : "") :),
   "P" : (: (this_player() ? this_player()->query_possessive() : "") :),
   "S" : (: (this_player() ? this_player()->query_subjective() : "") :),
   "AN" : (: (this_object() ? indefinite_article(strip_color(this_object()->query_short())) : "") :),
   "O" : (: (this_object() ? strip_color(this_object()->query_short()) : "") :),
  ]);

  foreach (string key, mixed f in rep)
    str = replace_string(str, "$"+key, evaluate(f));

  return str;
}

void create() {
  ::create();
  set_strength(1);
  set_poisoned(0);
  set_disable(1);
  set_uses(2);
  set_my_mess("You eat $AN.");
  set_your_mess("$N eats $AN.");
  set_my_serving_mess("You eat part of $AN.");
  set_your_serving_mess("$N eats part of $AN.");
}

int id(string str) { if (str == "food") return 1; return ::id(str); }

string query_short_more() {
  return query_short_servings();
}

string query_short_servings() {
  return " ("+uses+" serving" + (uses == 1 ? "" : "s") + ")";
}

void set_dis(int x) { disable = x; }  
void set_disable(int x) { set_dis(x); }
int query_disable() { return disable; }

void set_uses(int x) { uses = (x < 1 ? 0 : x); }
int query_uses() { return uses; }

void set_servings(int x) { set_uses(x); }
int query_servings() { return query_uses(); }

void set_strength(int x) {
  strength = x;
}

void set_my_mess(string str) {
  my_mess = str;
}

void set_your_mess(string str) {
  if (strsrch(str, "$") == -1) str = "$N "+str;
  your_mess = str;
}

string query_my_mess(string str) { return expandos(my_mess); }
string query_your_mess(string str) { return expandos(your_mess); }

void set_my_serving_mess(string str) {
  my_serving_mess = str;
}

void set_your_serving_mess(string str) {
  if (strsrch(str, "$") == -1) str = "$N "+str;
  your_serving_mess = str;
}

string query_my_serving_mess(string str) { return expandos(my_serving_mess); }
string query_your_serving_mess(string str) { return expandos(your_serving_mess); }

int query_strength() {
  return strength;
}

void set_poisoned(int p) { poisoned = (p < 0 ? 0 : p); }
int query_poisoned() { return poisoned; }
void set_extra(mixed ex) { if (functionp(ex)) Extra = ex; }
mixed query_extra() { return Extra; }

int is_food() { return 1; }
