
#include <std.h>

static string DisguisedShort = "";
static string DisguisedLong = "";
static string DisguisedName = "";
static string *DisguisedID = ({});
static mixed *StoleFrom = ({ ({}), ({}) });
static int Stealth = 0;
static int StealthBonus = 0;
static mapping Actions = ([
  "look" : 2,
  "give" : 6,
  "get" : 6,
  "drop" : 5,
  "put" : 4,
  "move" : 7,
  "sneak" : 15,
]);
static string *NonDisguisedActions = ({
  "quit", "who", "finger", "shout", "yell", "tell", "emoteto",
  "reply", "list", "post", "mail", "people", "peopleg", "party",
});

int query_base_stealth();
int query_stealth();
void set_stealth(int s);
void add_stealth(int s);
int query_stealth_bonus();
void set_stealth_bonus(int b);
void add_stealth_bonus(int b);
int use_stealth(mixed a);

void create() {
  Stealth = 0;
  StealthBonus = 0;
  DisguisedShort = "";
  DisguisedLong = "";
  DisguisedName = "";
  DisguisedID = ({});
  StoleFrom = ({ ({}), ({}) });
}

string query_disguised_short() { return DisguisedShort; }
string query_disguised_long() { return DisguisedLong; }
string query_disguised_name() { return DisguisedName; }
string *query_disguised_id() { return copy(DisguisedID) || ({}); }

void set_disguised_short(string str) { DisguisedShort = str; }
void set_disguised_long(string str) { DisguisedLong = str; }
void set_disguised_name(string str) { DisguisedName = str; }
void set_disguised_id(string *ids) { DisguisedID = copy(ids); }

void remove_disguised_short() { DisguisedShort = ""; }
void remove_disguised_long() { DisguisedLong = ""; }
void remove_disguised_name() { DisguisedName = ""; }
void remove_disguised_id() { DisguisedID = ({}); }

int can_disguise(string verb) { if (verb) return member_array(verb, NonDisguisedActions) == -1; }
// these are for backwards compatibility
string query_disquised_short() { return query_disguised_short(); }
void set_disquised_short(string str) { set_disguised_short(str); }
void remove_disquised_short() { remove_disguised_short(); }

int query_stolen(object tgt) {
  int a = member_array(tgt, StoleFrom[0]);
  if (a == -1) return 0;
  return StoleFrom[1][a];
}
void add_stolen(object tgt, int x) {
  int a = member_array(tgt, StoleFrom[0]);
  if (a == -1) {
    StoleFrom[0] += ({ tgt });
    StoleFrom[1] += ({ x });
  }
  else
    StoleFrom[1][a] += x;
}
void remove_stolen(object tgt) {
  int a = member_array(tgt, StoleFrom[0]);
  if (a == -1) return;
  StoleFrom[0] = StoleFrom[0][0..a-1] + StoleFrom[0][a+1..<1];
  StoleFrom[1] = StoleFrom[1][0..a-1] + StoleFrom[1][a+1..<1];
}

int query_base_stealth() {
  if (Stealth < 0) Stealth = 0;
  return Stealth;
}
int query_stealth() { return query_base_stealth() + query_stealth_bonus(); }

void set_stealth(int s) { Stealth = s; }
void add_stealth(int s) { Stealth += s; }

// bonus cannot excede the base
int query_stealth_bonus() {
  int tmp = StealthBonus - Stealth;

  if (tmp > 0) return Stealth;
  else return StealthBonus;
}

void set_stealth_bonus(int b) { StealthBonus = b; }
void add_stealth_bonus(int b) { StealthBonus += b; }

int use_stealth(mixed a) {
  int s;
  int ret = 0;

  if (intp(a))
    s = a;
  else if (stringp(a) && member_array(a, keys(Actions)) != -1)
    s = Actions[a];
  else
    return 0;

  if (query_stealth() >= s) {
    ret = 1;
  }

  add_stealth(-s);

  if (query_stealth() < 0)
    set_stealth(0);

  return ret;
}
  
