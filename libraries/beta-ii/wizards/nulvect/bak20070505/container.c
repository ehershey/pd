//      /std/container.c
//      from the Nightmare mudlib
//      code inherited by all items which can hold things
//      created by Sulam@TMI for the TMI mudlib distribution
//      13 january 1992
// Bug with invisible objects fixed by Pallando 93-07-14

// took out code for closing, fixed up the describe functions,
// changed receive_objects to take optional argument
// Nulvect 2007-02-15

#include <std.h>

inherit OBJECT;

#define COLOR_ITEM "%^BOLD%^%^MAGENTA%^"
#define COLOR_LIV "%^BOLD%^%^RED%^"

private static int internal_encumbrance;
private static int max_internal_encumbrance;

void set_max_internal_encumbrance(int max);
int query_max_internal_encumbrance();

void set_internal_encumbrance(int x);
int query_internal_encumbrance();
int add_encumbrance(int enc);

varargs int receive_objects(object ob);

string describe_living_contents(object *exclude);
string describe_item_contents(object *exclude);
string *consolidate_contents(object *exclude);

// Implement an object that can contain things.
// The 'remove()' function is implemented by the move.c object
// and will take care of any objects inside this object.

void set_max_internal_encumbrance(int max) {
  max_internal_encumbrance = max;
}

int query_max_internal_encumbrance() {
  return max_internal_encumbrance;
}

void set_internal_encumbrance(int x) {
  internal_encumbrance = x;
}

int add_encumbrance(int enc) {
/* Code added by Whit to prevent autoload bug.
 * In setup is set when a player is called
 * setup();
 */
  if (this_object()->in_setup()) {
    internal_encumbrance += enc;
    return 1;
  }
  if ( !max_internal_encumbrance ) return 1;
  if ( enc + internal_encumbrance > max_internal_encumbrance ) return 0;
  internal_encumbrance += enc;
  return 1;
}

int query_internal_encumbrance() {
  return internal_encumbrance;
}

// This function is called from move()
// don't check encumbrance levels here, move() does that
varargs int receive_objects(object ob) {
  return 1;
}

string describe_living_contents(object *exclude) {
  object *ai;
  string *shorts;
  string ret;
  
  if (!arrayp(exclude)) exclude = ({});

  ai = all_inventory(this_object());

  exclude += filter(ai, (: !living($1) :) );

  ai -= exclude;

  shorts = consolidate_contents(exclude);

  if (!sizeof(shorts)) return "";
  
  shorts[0] = COLOR_LIV + capitalize(shorts[0]);

  ret = implode(shorts, "\n"+COLOR_LIV);

  return ret;
}

string describe_item_contents(object *exclude) {
  object *ai;
  string *shorts;
  string ret;
  int s;
  
  if (!arrayp(exclude)) exclude = ({});
  
  ai = all_inventory(this_object());

  exclude += filter(ai, (: (living($1) || !strlen($1->query_short())) :) );

  ai -= exclude;
  
  shorts = consolidate_contents(exclude);

  s = sizeof(shorts);
  
  if (!s) return "";
  
  shorts[0] = COLOR_ITEM + capitalize(shorts[0]);

  switch (s) {
    case 1:
      ret = shorts[0] + COLOR_ITEM+ " ";
      if (sizeof(ai) == 1)
        ret += "is";
      else
        ret += "are";
      ret += " here.";
    break;

    default:
      ret = implode(shorts[0..<2], ", "+COLOR_ITEM);
      ret += COLOR_ITEM+" and "+shorts[<1]+COLOR_ITEM+" are here.";
  }

  return ret;
}

string *consolidate_contents(object *exclude) {
  string *shorts = ({});
  int *counts = ({});
  object *obs;

  if (!arrayp(exclude)) exclude = ({});

  obs = all_inventory(this_object()) - exclude;

  foreach (object ob in obs) {
    string sh = ob->query_short();
    string dis = ob->query_disquised_short();
    int i;

    if (!sh || sh == "" || ob->query_invis())
      continue;

    if (dis && dis != "") sh = dis;

    if ((i = member_array(sh, shorts)) == -1) {
      shorts += ({ sh });
      counts += ({ 1 });
    }
    else
      counts[i] += 1;
  }

  for (int i=0; i < sizeof(shorts); i++)
    shorts[i] = consolidate(counts[i], shorts[i]);
  
  return shorts;
}

