//    originally by Descartes
//    completely rewritten by Nulvect 2008-05-03

#include <std.h>

inherit OBJECT;

int strength, disable, poisoned;
string my_mess, your_mess, my_serving_mess, your_serving_mess;
string emptyname, emptyfile, type;
int uses;
mixed Extra;

string query_short_more();
string query_short_servings();
void set_my_mess(string mess);
void set_your_mess(string mess);
void set_my_serving_mess(string mess);
void set_your_serving_mess(string mess);
void set_type(string);
void set_empty(string);
void set_empty_name(string);
void set_empty_file(string);
void set_strength(int x);
void set_uses(int x);
void set_servings(int x);
void set_dis(int x);
void set_disable(int x);
void set_extra(mixed);
void set_poisoned(int);
int query_poisoned();
int query_strength();
int query_uses();
int query_servings();
int query_disable();
string query_my_mess();
string query_your_mess();
string query_my_serving_mess();
string query_your_serving_mess();
string query_type();
string query_empty();
string query_empty_name();
string query_empty_file();
mixed query_extra();
string expandos(string str);
object clone_empty();

string expandos(string str) {
  mapping rep = ([
    "N" : (: (this_player() ? this_player()->query_cap_name() : "") :),
    "P" : (: (this_player() ? this_player()->query_possessive() : "") :),
    "S" : (: (this_player() ? this_player()->query_subjective() : "") :),
    "AN" : (: (this_object() ? indefinite_article(strip_color(this_object()->query_short())) : "") :),
    "O" : (: (this_object() ? remove_article(strip_color(this_object()->query_short())) : "") :),
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
  set_uses(1);
  set_my_mess("You drink $AN.");
  set_your_mess("$N drinks $AN.");
  set_my_serving_mess("You drink some of $AN.");
  set_your_serving_mess("$N drinks some of $AN.");
  set_type("soft drink");
  set_empty_name("bottle");
}

void set_id(string *ids) { if (sizeof(ids)) ids |= ({ "drink" }); ::set_id(ids); }

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

void set_type(string str) { type = str; }
string query_type() { return type; }

void set_empty(string str) { if (strsrch(str, "/") != -1) set_empty_file(str); else set_empty_name(str); }
string query_empty() { return query_empty_file() || query_empty_name(); }

void set_empty_name(string str) { emptyname = str; }
string query_empty_name() { return emptyname; }

void set_empty_file(string str) { emptyfile = str; }
string query_empty_file() { return emptyfile; }

void set_poisoned(int p) { poisoned = (p < 0 ? 0 : p); }
int query_poisoned() { return poisoned; }
void set_extra(mixed ex) { if (functionp(ex)) Extra = ex; }
mixed query_extra() { return Extra; }

object clone_empty() {
  object empty;
  string *ids = ({});
   
  if (emptyfile) empty = new(emptyfile);

  if (!empty && emptyname) {
    empty = new("/std/object");
    empty->set_short("an empty "+emptyname);
    empty->set_long(capitalize(indefinite_article(emptyname))+" which was used to hold something.");
    empty->set_value(1);
    empty->set_weight(1);
    foreach (string word in explode(emptyname, " ")) ids |= ({ word });
    empty->set_id( ids + ({ emptyname, "empty "+emptyname, "empty container" }));
  }

  return empty;
}

int is_drink() { return 1; }

