// File:      /std/object.c
// Purpose:   Define functions and varibles to be used by all objects
// Mudlib:    Nightmare
// Credits:
// 92-10-**   Descartes of Borg created this, based on TMI's Object.c
// 93-06-16   Pallando reordered and commented it.
// 93-06-16   Pallando added create(), reset(), prop() and set_material()
// 93-06-21   Pallando added init()
// 93-06-23   Pallando added seteuid(getuid()) to create()

// std contains the def of MOVE
#include <teststd.h>
// daemons contains the #define of ALCHEMIST_D
#include <daemons.h>

// move contains the functions "move", "remove", "clean_up", "set_no_clean"
//   "set_last_location", "query_last_location", "set_weight", "query_weight"
inherit MOVE;
// tastes, smells, sounds, etc
inherit SENSES;

//    Global variables defined in this file
//   =======================================
mapping props;                    // Object data that does get saved.
private static mapping ob_data;   // Object data that does not get saved.
private static string cap_name;   // kept in seperate variable for security
private string true_name;         // kept in seperate variable for security
private string creator;           // File name of the ob that created an object
static string d_master;           // File name of an object's domain master ob
string prevent_get;               // prevent get string
string material;                  // Substance object is made from.
static mapping protection;        // Damage protection
static private int enchanted=0;   // Has this object already been enchanted
static private string orig_short;  // Bypasses (worn) and (wielded)

//    Functions defined in this file
//   ================================
//
// a) Object property functions.
//   init_ob               - initalises the "ob_data" mapping
//   set                   - stores data in the "ob_data" mapping
//   add                   - alters data in the "ob_data" mapping
//   query                 - returns data from the "ob_data" mapping
//   set_property          - alters data in the "props" mapping
//   query_property        - returns data from the "props" mapping
//   remove_all_properties - initalises the "props" mapping
//   remove_property       - removes data from the "props" mapping
//   remove_property_value - alters data in the "props" mapping
//   regexp_query_property - returns data from the "props" mapping
// b) One line set and query functions.
//   set_id,set_short,set_long,set_value,query_id,query_name,query_true_name
//   query_long,query_value,query_destroy,query_creator
// c) More complicated set and query functions.
//   id                    - queries if a str is an id
//   set_name              - also sets cap_name
//   query_short           - also inits ob
//   query_cap_name        - deals with invisibility and ghosts
//   query_light           - also checks if props exists
//   set_destroy           - also resets ob_data
//   set_material          - calls domain master object
// d) Main functions.
//   create                - initialises object
//   reset                 - handles temperature
//   init                  - future expansion - currently a dummy function
//   move                  - makes sure armor is unequipped
//   get                   - handles "keep" property





// *** Object property functions ***
// I] That use the "ob_data" mapping
void init_ob() { ob_data = ([ "id": ({}) ]); }

void set(string what, mixed arg) {
    if( !stringp(what) ) return;
    if(!ob_data) init_ob();
    if(ob_data[what]) ob_data[what] = arg;
    else ob_data += ([ what: arg ]);
    if (what == "short" && orig_short == "") orig_short = arg;
}

static void add(string what, mixed arg) {
    if(!ob_data) ob_data = ([]);
    if(functionp(arg) && geteuid(this_object()) != geteuid(arg[0])) return;
    if(stringp(arg) || intp(arg)) arg = ({ arg });
    if(!ob_data[what]) {
	ob_data += ([what:arg]);
	return;
    }
    if(!pointerp(ob_data[what]) && !mapp(ob_data[what])) return;
    ob_data[what] += arg;
}

varargs mixed query(string what, mixed element) {
    mixed res;

    res = 0;
    if(!ob_data) init_ob();
    if(!stringp(what)) return 0;
    if(!ob_data[what]) return 0;
    if(!element) res = ob_data[what];
    else if( stringp(element) ) res = ob_data[what][element];
    else if( (intp(element)) && pointerp(ob_data[what]) &&
        (element < sizeof(ob_data[what])) ) res = ob_data[what][element];
    if( pointerp(res) && previous_object() != this_object() ) res += ({});
    return res;
}

// II] That use the "props" mapping
void set_properties(mapping prop)
{
  int i;
  string *str;
  mixed *val;
  if (!props) props = ([]);
  if (!prop) return;
  i = sizeof(str = keys(prop));
  i = sizeof(val = values(prop));
  while(i--)
   props += ([ str[i] : val[i] ]);
   
   
}
void set_property(string prop, mixed value) {
    if(!props) props = ([]);
    if(props[prop]) {
        props[prop] += value;
        return;
    }
    props += ([ prop : value]);
}
void set_prevent_get(string str)
{
 prevent_get = str;
}
string query_prevent_get()
{
 return prevent_get;
}
mixed query_property(string prop) {
    if(!props) 
    {
        props = ([]);
        return 0;
    }
    return props[prop];
}

void remove_all_properties() {
    props = ([]);
}

int remove_property (string prop)
{
    if(props && props[prop])
    {
        props[prop] = 0;
        return 1;
    }
    return 0;
}

int remove_property_value(string prop, mixed val) {
    if(props && props[prop]) {
        props[prop] -= val;
        return 1;
    }
    return 0;
}

string * regexp_query_property (string pattern)
{
   string *vars, *prop;

   vars = keys(props);
   prop = regexp (vars, pattern);
   if (!prop) 
        prop = ({});
   return prop;
}


int query_protection(string it)
{
    if(!protection[it]) return 0;
    if(intp(protection[it])) return protection[it];
    if(stringp(protection[it]))
      return call_other(this_object(),protection[it]);
    return 0;
}

void set_protection(string type, mixed value)
{
    protection[type] = value;
}



// *** One line set and query functions ***
void   set_id(string str)        { set("id", str); }
void   set_short(string str)     { set("short", str); }
void   set_long(string str)      { set("long", str); }
void   set_value(int x)          { set("value", x); }
void   set_mass(int x)           { set_weight(x); }
string *query_id()               { return query("id"); }
mapping query_curr_value()       { return ob_data["cur_value"]; }
string query_name()              { /*object o;
       if (o = present("paradox_-ring-_paradox", this_object())
        && o->query_worn() && o->new_name() != "" && o->is_active())
           return o->new_name(); */
                                   return true_name;
                                 }
string query_true_name()         { return true_name; }
string query_long(string str) {
    if(functionp(ob_data["long"]))
      return (string)(*ob_data["long"])(str);
    else return ob_data["long"];
}
int    query_value()             { return (int)this_object()->query("value"); }
int    query_destroy()           { return ob_data["destroy"]; }
string query_creator()           { return creator; }





// *** More complicated set and query functions ***
int set_curr_value(string cur, int val) {
 if (!ob_data) init_ob();
 if (!stringp(cur) || !val || val < 0) return 0;
 if (ob_data["cur_value"]) return 0;
 ob_data["cur_value"] = ([ cur : val ]);
 return 1;
}

int id(string str) {
//    int i;

//    string *parts;

    if(!ob_data) init_ob();
    if( !stringp(str) ) return 0;
    if( lower_case(str) == true_name) return 1;
    if(member_array(str, ob_data["id"]) != -1) return 1;
    return 0;
}

void set_name(string str) {
    if( !stringp(str) ) return;
    cap_name = capitalize(str);
    true_name = str;
    if(creator) return;
    if(previous_object()) creator = file_name(previous_object());
    else creator = "Unknown";
}

string query_short() {
    if(!ob_data) init_ob();
    if(functionp(ob_data["short"]))
      return (string)(*ob_data["short"])();
    else return ob_data["short"];
}

string query_cap_name() { 
// string msg;
// object ring;
    if(!true_name) return 0;
    if(!cap_name) return 0;
    if(this_object()->query_invis()) return "A shadow";
/*   if (ring = (present("paradox_-ring-_paradox", this_object()))
    && ring->query_worn() && ring->cap_name() != "" && ring->is_active())
       return ring->cap_name();*/
/*
    if(this_object()->query_ghost()) 
     {
      msg = "%^WHITE%^The ghost of " + cap_name;
      return msg;
     }
*/
    return cap_name;
}

void change_cap(string str) { cap_name = str; }

int query_light() {
    if(!props) return 0;
    if(props["light"]) return props["light"];
    return 0;
}

void set_destroy() {
    if(!ob_data) ob_data = ([]);
    ob_data["destroy"] = 1;
}

mixed prop( string str )
{
  mixed tmp;

  // first check if an override has been set in the object
  // (allows unique objects with properties different from the default)
  if( !undefinedp( tmp = query( str ) ) ) return tmp;
  // check all is set that should be
  if( !d_master || !str || !material ) return tmp;
  // convert, eg  "hardness"-> "hardness/metal/steel"
  // To not have the material added, start str with a /
  if( str[0..0] != "/" ) str += material;
  // If the object comes from a domain without a master, use alchemist
  if( d_master == ALCHEMIST_D ) return ALCHEMIST_D-> get( str );
  // call the object's domain master ob to get the property.
  return d_master-> query( str );
}

void set_material( string str )
{
  mixed parts, domain;
  int size;

  // make sure "material" exists and starts with a /
  if( !str ) material = "/default";
  else material = (  (str[0..0] == "/") ? str : ("/" + str)  );

  // The next few lines do the equivalent of 
  //   sscanf( material, "%s/%s", type, name );
  // except they search for the / from the other end first.
  parts = explode( material, "/" );
  size = sizeof( parts );
  set( "material_name", parts[size-1] );
  set( "material_type", ((size==1) ? "none" : implode(parts[0..size-2],"/")));

  // set_material can be called either on creation of an object or later
  // the first time it is called, previous_object() is passed to setup_object()
  // so things like finding the temperature of the creating object can be done
  // later times only properties relating to the material need to be altered.
  if( d_master )
  {
    d_master-> setup_object( this_object() );
    return;
  }
  // objects in /wizard/ not /d/ directories need to set the property
  // "domain" so we know where to look for the domain master ob.
  if( !( domain = query("domain") ) ) domain = this_object();
  // If the domain doesn't have a master ob, use ALCHEMIST_D
  if( !( d_master = domain_master( domain ) ) ) d_master = ALCHEMIST_D;
  d_master-> setup_object( this_object(), previous_object() );
}



void create() {
    senses::create();
    seteuid( getuid() ); // ensures all objects have an euid.

    // Once all objects call ::create(), many of the checks that
    // ob_data and props exist can be removed, saving on cpu.
    ob_data = ([ "id": ({}) ]);
    props = ([]);
}

void reset()
{
    // do temperature
}

void init() {
}

int move(mixed dest) {
    this_object()->unequip();
    return ::move(dest);
}

int get() {
    string who;

    who = (string)this_object()->query_property("keep");
    if(!who) return 1;
    if(who != (string)this_player()->query_name()) {
        write("A magical force prevents you from taking it!\n");
        say("A magical force prevents "+(string)this_player()->query_cap_name()+
            " from taking the "+query_name()+".\n", this_player());
	return 0;
    }
    return 1;
}

int query_enchanted() { return enchanted; }

void set_enchanted(int x) { enchanted = x; }

int is_object() { return 1; }

string query_orig_short() { return orig_short; }

/* EOF */
