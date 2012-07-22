// File:      /std/object.c
// Purpose:   Define functions and varibles to be used by all objects
// Mudlib:    Nightmare
// Credits:
// 92-10-**   Descartes of Borg created this, based on TMI's Object.c
// 93-06-16   Pallando reordered and commented it.
// 93-06-16   Pallando added create(), reset(), prop() and set_material()
// 93-06-21   Pallando added init()
// 93-06-23   Pallando added seteuid(getuid()) to create()
// 
// 2011-09-29 Nulvect cleaned this file up, removing a bunch of crap
// that doesn't get used and adding some useful functions

#include <std.h>

// for move() and remove() funcs
inherit MOVE;
// tastes, smells, sounds, etc
inherit SENSES;


// --- saved vars --- ///

mapping props;
private string creator; // filename of ob that created this ob
private string true_name;
string prevent_get;


// --- unsaved vars --- ///

static private mapping ob_data;
static private string cap_name;
static private int enchanted=0;   // Has this object already been enchanted
static private string orig_short; // Bypasses (worn) and (wielded)
static private string Plural;
static private int Autoload_Level;


// --- prototypes --- //

void init_ob();
void set(string what, mixed arg);
static void add(string what, mixed arg);
varargs mixed query(string what, mixed element);
void set_properties(mapping prop);
void set_property(string prop, mixed value);
void set_prevent_get(string str);
string query_prevent_get();
mixed query_property(string prop);
mapping query_all_properties();
void remove_all_properties();
int remove_property (string prop);
int remove_property_value(string prop, mixed val);
string *regexp_query_property (string pattern);
void set_id(string str);
string *query_id();
void set_name(string str);
string query_name();
string query_true_name();
string query_creator();
void set_plural(string s);
string query_plural();
string query_orig_short();
void set_short(string str);
string query_short();
void set_short_more(string *more);
string query_short_more();
void set_value(int x);
int query_value();
int set_curr_value(string cur, int val);
mapping query_curr_value();
void set_autoload(int l);
void set_auto_load(int l);
int query_autoload();
int query_auto_load();
void set_destroy();
int query_destroy();
int query_light();
int move(mixed dest);
int remove();
int get();


// --- applies --- ///

void create() {
  senses::create();
  seteuid( getuid() ); // ensures all objects have an euid.

  // Once all objects call ::create(), many of the checks that
  // ob_data and props exist can be removed, saving on cpu.
  ob_data = ([ "id": ({}) ]);
  props = ([]);
}

void reset() {
}

void init() {
}

int id(string str) {
  if (!ob_data) init_ob();
  if (!stringp(str)) return 0;
  if (lower_case(str) == true_name) return 1;
  if (member_array(str, ob_data["id"]) != -1) return 1;
  return 0;
}


// --- data that does NOT get saved --- //

void init_ob() { ob_data = ([ "id": ({}) ]); }

void set(string what, mixed arg) {
  if (!stringp(what)) return;
  if (!ob_data) init_ob();
  if (ob_data[what]) ob_data[what] = arg;
  else ob_data += ([ what: arg ]);
  if (what == "short" && orig_short == "") orig_short = arg;
}

static void add(string what, mixed arg) {
  if (!ob_data) ob_data = ([]);
  if (functionp(arg) && geteuid(this_object()) != geteuid(arg[0])) return;
  if (stringp(arg) || intp(arg)) arg = ({ arg });
  if (!ob_data[what]) {
    ob_data += ([what:arg]);
    return;
  }
  if (!pointerp(ob_data[what]) && !mapp(ob_data[what])) return;
  ob_data[what] += arg;
}

varargs mixed query(string what, mixed element) {
  mixed res = 0;
  if (!ob_data) init_ob();
  if (!stringp(what)) return 0;
  if (!ob_data[what]) return 0;
  if (!element) res = ob_data[what];
  else if (stringp(element)) res = ob_data[what][element];
  else if ((intp(element)) && pointerp(ob_data[what]) &&
          (element < sizeof(ob_data[what])))
            res = ob_data[what][element];
  if (pointerp(res) && previous_object() != this_object()) res += ({});
  return res;
}

// --- end set()/query() code --- //


// --- data that DOES get saved --- //

void set_properties(mapping prop) {
  int i;
  string *str;
  mixed *val;
  if (!props) props = ([]);
  if (!prop || !mapp(prop)) return;
  /*
    i = sizeof(str = keys(prop));
    i = sizeof(val = values(prop));
    while(i--)
    props += ([ str[i] : val[i] ]);
  */
  props += prop;
}
void set_property(string prop, mixed value) {
  if (!props) props = ([]);
  if (props[prop]) {
    props[prop] += value;
  }
  else {
    props += ([ prop : value]);
  }
}
void set_prevent_get(string str) { prevent_get = str; }
string query_prevent_get() { return prevent_get; }

mixed query_property(string prop) {
  if (!props) {
    props = ([]);
    return 0;
  }
  return props[prop];
}

mapping query_all_properties() { return copy(props); }

void remove_all_properties() {
  props = ([]);
}

int remove_property (string prop) {
  if (props && props[prop]) {
    props[prop] = 0;
    return 1;
  }
  return 0;
}

int remove_property_value(string prop, mixed val) {
  if (props && props[prop]) {
    props[prop] -= val;
    return 1;
  }
  return 0;
}

string *regexp_query_property (string pattern) {
  string *vars = keys(props);
  string *prop = regexp(vars, pattern);

  if (!prop) 
    prop = ({});

  return prop;
}

// --- end properties --- //


void set_id(string str) { set("id", str); }
string *query_id() { return query("id"); }

void set_name(string str) {
  if (!stringp(str)) return;
  cap_name = capitalize(str);
  true_name = str;
  if (!creator) {
    if (previous_object()) creator = file_name(previous_object());
    else creator = "Unknown";
  }
}
string query_name() { return true_name; }
string query_true_name() { return true_name; }

string query_creator() { return creator; }

string query_cap_name() { 
  if (!true_name) return 0;
  if (!cap_name) return 0;
  if (this_object()->query_invis()) return "A shadow";
  /*
  if (this_object()->query_ghost()) {
    return "%^WHITE%^The ghost of " + cap_name;
  }
  */
  return cap_name;
}

void change_cap(string str) { cap_name = str; }


void set_plural(string s) { Plural = s; }
string query_plural() { return Plural; }

string query_orig_short() { return orig_short; }

void set_short(string str) { set("short", str); }
string query_short() {
  if (functionp(ob_data["short"]))
    return (string)evaluate(ob_data["short"]);
  else return ob_data["short"];
}

void set_long(string str) {
  set("long", str);
  set_item("default", str);
}
string query_long(string str) {
  if (functionp(ob_data["long"]))
    return (string)evaluate(ob_data["long"], str);
  else return ob_data["long"];
}

void set_short_more(string *more) { set("short_more", more); }
string query_short_more() {
  string ret="";

  if (!ob_data["short_more"] || !sizeof(ob_data["short_more"]))
    return "";

  foreach (string f in ob_data["short_more"]) {
    string tmp = call_other(this_object(), f);
    if (strlen(tmp)) ret += tmp;
  }
  return ret;
}

void set_long_more(string *more) { set("long_more", more); }
string query_long_more() {
  string ret = "";

  if (!ob_data["long_more"] || !sizeof(ob_data["long_more"]))
    return "";

  foreach (string f in ob_data["long_more"]) {
    string tmp = call_other(this_object(), f);
    if (strlen(tmp)) ret += tmp+"\n";
  }
  return ret;
}

void set_value(int x) { set("value", x); }
int query_value() { return (int)this_object()->query("value"); }

int set_curr_value(string cur, int val) {
  if (!ob_data) init_ob();
  if (!stringp(cur) || !val || val < 0) return 0;
  // if (ob_data["cur_value"]) return 0;
  ob_data["cur_value"] = ([ cur : val ]);
  return 1;
}
mapping query_curr_value() { return ob_data["cur_value"]; }

void set_autoload(int l) { Autoload_Level = l; }
void set_auto_load(int l) { set_autoload(l); }
int query_autoload() { return Autoload_Level; }
int query_auto_load() { return query_autoload(); }

// destroy this item when sold to a vendor
void set_destroy() {
  if(!ob_data) ob_data = ([]);
  ob_data["destroy"] = 1;
}
int query_destroy() { return ob_data["destroy"]; }

int query_light() {
  if (!props) return 0;
  if (props["light"]) return props["light"];
  return 0;
}


// --- misc stuff --- ///

int move(mixed dest) {
  this_object()->unequip();
  return ::move(dest);
}

int remove() {
  return move::remove();
}

int get() {
  string who;

  who = (string)this_object()->query_property("keep");

  if (who && who != (string)this_player()->query_name()) {
    write("A magical force prevents you from taking it!\n");
    say("A magical force prevents "+(string)this_player()->query_cap_name()+
        " from taking the "+query_name()+".\n", this_player());
    return 0;
  }
  return 1;
}

void set_enchanted(int x) { enchanted = x; }
int query_enchanted() { return enchanted; }

void set_materials(string *m) { set("materials", copy(m)); }
string *query_materials() { return copy(query("materials")); }

void set_mass(int x) { set_weight(x); }

int is_object() { return 1; }

