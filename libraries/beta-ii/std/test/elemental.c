
static mapping Elemental = ([]);
static mapping Opposites = ([]);

int is_element(string el);
mapping query_opposite_elements();
string query_opposite_element(string el);
void set_element(string el, int x);
void add_element(string el, int x);
int query_element(string el);
varargs int apply_element(string el, int amt, string limb);
varargs int query_elemental_armor(string el, string limb);
void do_elemental_damage(string limb, string el, int dmg);

void create() {
  Elemental = ([
    "fire" : 0,
    "water" : 0,
    "earth" : 0,
    "air" : 0,
  ]);

  Opposites = ([
    "fire" : "water",
    "water" : "fire",
    "earth" : "air",
    "air" : "earth",
  ]);
}

int is_element(string el) {
  return member_array(el ? el : "", keys(Elemental)) != -1;
}

mapping query_opposite_elements() { return copy(Opposites); }
string query_opposite_element(string el) {
  if (is_element(el))
    return Opposites[el];
  else
    return "";
}

void set_element(string el, int x) {
  if (is_element(el))
    Elemental[el] = x;
}
void add_element(string el, int x) {
  if (is_element(el))
    set_element(el, query_element(el) + x);
}

int query_element(string el) {
  if (is_element(el))
    return Elemental[el];
  else
    return 0;
}

varargs int apply_element(string el, int amt, string limb) {
  int x;
  int tmp;
  string opp;

  if (nullp(el) || nullp(amt)) return 0;
  
  x = query_element(el);
  
  // armour with elemental properties protects you, but not 100%
  x += query_elemental_armor(el, limb)*3/4;

  // fire elementals automatically take extra damage from water
  if (opp = query_opposite_element(el) &&
      tmp = query_element(opp) > 0)
        x -= tmp*3/4;

  amt = amt * (100-x) / 100;

  return amt;
}

// -----
// the following are just for living things
// -----

// adds up the elemental properties of worn items
varargs int query_elemental_armor(string el, string limb) {
  object to = this_object();
  object *armours;
  int total = 0;
 
  if (!el || !is_element(el) || !living(to)) return 0;
 
  if (limb && to->query_is_limb(limb))
    armours = to->query_armour_ob(limb);
  else
    armours = filter(all_inventory(to), (: $1->query_worn() :) );

  foreach (object a in armours)
    total += a->query_element(el);

  return total;
}

void do_elemental_damage(string limb, string el, int dmg) {
  object to = this_object();

  if (!living(to)) return;

  if (!to->query_is_limb(limb)) limb = to->return_limb();

  dmg = apply_element(el, dmg);
  
  if (dmg > 0)
    to->do_damage(limb, dmg);
}

