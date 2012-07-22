#include <std.h>

#define STATIC_SALT "V."

inherit DAEMON;
inherit SENSES;

int MaxSentences, MinSentences, MaxInventory, StaticDescs;
string First, Last, Short;
string *DayLongs, *NightLongs;
mapping LivingInventory, Inventory, Properties;

void set_first_sentence(string s);
void set_last_sentence(string s);
void set_day_sentences(string *list);
void set_night_sentences(string *list);
void set_day_sentances(string *list);
void set_night_sentances(string *list);
void set_item_list(mapping stuff);
void set_properties(mapping stuff);
varargs void set_smell(mixed what, string str);
varargs void set_listen(mixed what, string str);
void set_reset_list(string *list);
void set_short(string str);
void set_how_long(int i);
void set_mob_cap(int i);
void set_static(int i);

void create() {
  daemon::create();
  senses::create();

  DayLongs = ({});
  NightLongs = ({});
  LivingInventory = ([]);
  Inventory = ([]);
  Properties = ([]);
  MaxSentences = 4;
  MaxInventory = 4;
  StaticDescs = 1;
}

void set_static(int i) { StaticDescs = (i ? 1 : 0); }
int query_static() { return StaticDescs; }

void set_max_sentences(int i) { MaxSentences = i; }
void set_min_sentences(int i) { MinSentences = i; }
void set_how_long(int i) { MaxSentences = i; MinSentences = i; }

void set_max_inventory(int i) { MaxInventory = i; }
void set_mob_cap(int i) { MaxInventory = i; }
int query_max_inventory(int i) { return MaxInventory; }

void set_first_sentence(string s) { First = s; }
void set_last_sentence(string s) { Last = s; }
string query_first_sentence() { return First; }
string query_last_sentence() { return Last; }

void set_day_sentences(string *list) { DayLongs = list; }
void set_night_sentences(string *list) { NightLongs = list; }
void set_day_sentances(string *list) { DayLongs = list; }
void set_night_sentances(string *list) { NightLongs = list; }
string *query_day_sentences() { return DayLongs; }
string *query_night_sentences() { return NightLongs; }

void set_short(string str) { Short = str; }
string query_short() { return Short; }

// using senses.c to handle all sense stuff (including set_items)
//   except for these backwards-compatibility hacks
varargs void set_smell(mixed what, string str) {
  if (nullp(what)) return;
  if (nullp(str)) senses::set_smell("default", what);
  else senses::set_smell(what, str);
}
varargs void set_listen(mixed what, string str) {
  if (nullp(what)) return;
  if (nullp(str)) senses::set_listen("default", what);
  else senses::set_listen(what, str);
}
void set_item_list(mapping m) {
  senses::set_items(m);
}
void set_item(string what, string str) {
  senses::set_item(what, str);
}

void set_living_inventory(mapping m) {
  LivingInventory = ([]);
  foreach (string key, int val in m) {
    if (key[<2..<1] == ".c") key = key[0..<3];
    LivingInventory[key] = val;
  }
}
mapping query_living_inventory() { return LivingInventory; }
void set_reset_list(string *list) {
  mapping m = ([]);
  foreach (string item in list) {
    if (m[item]) m[item] = m[item] + 1;
    else m[item] = 1;
  }
  set_living_inventory(m);
}

void set_inventory(mapping m) {
  Inventory = ([]);
  foreach (string key, int val in m) {
    if (key[<2..<1] == ".c") key = key[0..<3];
    Inventory[key] = val;
  }
}
mapping query_inventory() { return Inventory; }

void set_properties(mapping m) { Properties = m; }
mapping query_properties() { return Properties; }

varargs string query_random_long(int night, object room) {
  string ret;
  string *longs;
  int min;

  if (sizeof(NightLongs)) {
    if (query_night()) {
      if (!nullp(night) && night == 0)
	longs = DayLongs;
      else
	longs = NightLongs;
    }
    else {
      if (!nullp(night) && night == 1)
	longs = NightLongs;
      else
	longs = DayLongs;
    }
  }
  else
    longs = DayLongs;

  longs = copy(longs);

  if (!MinSentences) min = MaxSentences / 2;
  else min = MinSentences;

  ret = "";

  // make the description always the same for each room
  // this is dependant on the file name
  // crypt() returns a hashed string, using the same salt will always return
  //   the same string as before - so we #defined a salt to always use
  // strlen(crypt) == 13, always
  // crypt[0..1] is the salt used, so we skip that
  // the syntax crypt[2] returns the integer value (!) of the character
  //   in that position and we take a modulus to give us a range of
  //   possible desc lengths - that is, X % Y returns the range of (0 .. Y-1)
  // then we use crypt[3] through crypt[12] to determine which sentences
  //   to put into the descrption
  // the main downside to this method is that crypt has a rather small,
  //   set length of 13 (2 of which are unuseable, and 1 is used for number
  //   of sentences, leaving us with a max sentence number of 10)
  // also, crypt() works only on the first 8 characters of what you send,
  //   so we send only the last 8 characters of the file name - the first
  //   8 would probably all be the same in one place (like "/d/nopk/")
  if (StaticDescs && sizeof(longs) > 1) {
    string crypt;
    int len;
    // can pass in the room to make a desc for, needed for virtualmap bugfix
    if (nullp(room)) room = previous_object();
    crypt = crypt(file_name(room)[<8..<1], STATIC_SALT);
    len = crypt[2] % MaxSentences;

    if (len < min)
      len = min;
    // see comments above for why len must be <= 10
    if (len > 10)
      len = 10;

    for (int i = 0; i < len; i++) {
      int rand = crypt[i+3];
      int num = sizeof(longs);
      string tmp = longs[ rand % num ];
      ret += tmp + " ";
      longs -= ({ tmp });
    }
  }
  else {
    int len = random(MaxSentences);
    if (len < min)
      len = min;

    while (len-- && sizeof(longs)) {
      string tmp = longs[random(sizeof(longs))];
      ret += tmp + " ";
      longs -= ({ tmp });
    }
  }

  if (First) ret = First + " " + ret;
  if (Last) ret = ret + Last;

  return ret;
}

varargs string query_random_day_long(object room) { return query_random_long(0, room); }
varargs string query_random_night_long(object room) { return query_random_long(1, room); }

object *query_random_living_inventory(object *livings) {
  mapping allowed = copy(LivingInventory);
  object *ret = ({});
  int current;

  if (!sizeof(allowed)) return ({});

  // only care about things in our inventory list
  livings = filter(livings, (: !nullp($2[base_name($1)]) :), LivingInventory);

  current = sizeof(livings);

  for (int i = random(MaxInventory + 1 - current); i > 0; i--) {
    int r = random(sizeof(allowed));
    string inv = keys(allowed)[r];
    if (--(allowed[inv]) == 0)
      map_delete(allowed, inv);
    ret += ({ new(inv) });
    if (!sizeof(allowed))
      break;
  }

  return ret;
}

// objects are considered only AFTER living things,
// so if 4 mobs are loaded with max inventory = 4, no items will be loaded
object *query_random_object_inventory(object *ai) {
  mapping allowed = copy(Inventory);
  object *ret = ({});
  int current;

  if (!sizeof(allowed)) return ({});

  // only care about things in our inventory list
  ai = filter(ai,
   (: !nullp($2[base_name($1)]) || !nullp($3[base_name($1)]) :),
   Inventory, LivingInventory
  );

  current = sizeof(ai);

  for (int i = random(MaxInventory/2 + 1 - current); i > 0; i--) {
    int r = random(sizeof(allowed));
    string inv = keys(allowed)[r];
    if (--(allowed[inv]) == 0)
      map_delete(allowed, inv);
    ret += ({ new(inv) });
    if (!sizeof(allowed))
      break;
  }

  return ret;
}

object *query_random_inventory(object *ai) {
  object *livings;
  object *ret;

  livings = filter(ai, (: $1->is_living() :) );

  ret = query_random_living_inventory(livings);
  ret += query_random_object_inventory(ai);

  return ret || ({});
}

