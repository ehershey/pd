
#include <std.h>

static int Stealth = 0;
static int StealthBonus = 0;
static mapping Actions = ([]);

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
  Actions = ([
    "look" : 2,
    "give" : 5,
    "get" : 5,
    "drop" : 4,
    "put" : 3,
    "move" : 8,
  ]);
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
  int ret;
  int s;

  if (intp(a))
    s = a;
  else if (stringp(a) && member_array(a, keys(Actions)) != -1)
    s = Actions[a];
  else
    return 0;

  Stealth -= s;

  if (Stealth < 0) {
    ret = 0;
    Stealth = 0;
  }
  else ret = 1;

  return ret;
}
  
