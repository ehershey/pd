
// vitals.c
// data about health that does not involve limbs
//
// includes hp, sp, mp, intoxication, quenched, stuffed,
// physical and spiritual biorhythms, healing rate,
// periodic healing, and vitals bonuses

#include <std.h>
#include <rest.h>

#define TIME_TO_HEAL 6


int ok_to_heal;
int vital_bonus;
private int heal_rate;
mapping player_data = ([]);
mapping healing = ([]);
mapping magic = ([]);

mapping Vitals = ([
  "hp" : 10,
  "max hp": 10,
  "sp" : 10,
  "max sp": 10,
  "mp" : 10,
  "max mp": 10,
  "vital bonus": 0,
  "intox": 0,
  "quenched": 0,
  "stuffed": 0,
  "physical": 0,
  "spiritual": 0,
  "heal rate": 5,
  "converted" : 0,
]);

static mapping VitalsTemp = ([
  "hp heal bonus": 0,
  "sp heal bonus": 0,
  "mp heal bonus": 0,
  "all heal bonus": 0,
]);


void init_vitals();
void show_status_line();
void do_status();
void do_healing();
void heal(int x);
int set_heal_rate(int x);
int query_heal_rate();
void set_heal_rate_bonus(string s, int b);
void add_heal_rate_bonus(string s, int b);
int query_heal_rate_bonus(string s);
void adjust_biorhythms();
int query_spiritual();
int query_physical();
int query_max_intox();
int query_intox();
int set_intox(int x);
void add_intox(int x);
int query_max_quenched();
int query_quenched();
int set_quenched(int x);
void add_quenched(int x);
int query_max_stuffed();
int query_stuffed();
int set_stuffed(int x);
void add_stuffed(int x);
void set_max_hp(int hp);
int query_max_hp();
void set_hp(int hp);
void add_hp(int hp);
int query_hp();
void set_max_sp(int sp);
int query_max_sp();
void set_sp(int sp);
void add_sp(int sp);
int query_sp();
void set_max_mp(int mp);
int query_max_mp();
void set_mp(int mp);
void add_mp(int mp);
int query_mp();
int fix_vital_bonus(int i);
int query_vital_bonus(string str);
void set_vital_bonus();

void init_vitals() {
  if (!sizeof(Vitals)) Vitals = ([]);
  if (!sizeof(VitalsTemp)) VitalsTemp = ([]);
  if (!query_heal_rate()) set_heal_rate(0);
  adjust_biorhythms();

  if (!Vitals["converted"]) {
    if (sizeof(player_data)) {
      if (sizeof(player_data["general"])) {
        Vitals["hp"] = player_data["general"]["hp"];
        Vitals["max hp"] = player_data["general"]["max hp"];
        Vitals["sp"] = player_data["general"]["sp"];
        Vitals["max sp"] = player_data["general"]["max sp"];
        this_object()->set_alignment(player_data["general"]["alignment"]);
        this_object()->set_quest_points(player_data["general"]["quest points"]);
        this_object()->set_exp(player_data["general"]["experience"]);
      }
      if (sizeof(player_data["kills"]))
        this_object()->set_kills(player_data["kills"]);
      player_data = ([ ]);
    }
    if (sizeof(magic)) {
      Vitals["mp"] = magic["points"];
      Vitals["max mp"] = magic["max points"];
      magic = ([ ]);
    }
    Vitals["converted"] = 1;
  }

}

void create() {
}

void heart_beat() {
  object to = this_object();

  if (!to) return;

  do_status();

  if (to->query_age() > ok_to_heal) {
    do_healing();
    ok_to_heal = to->query_age() + TIME_TO_HEAL;
  }

}

void show_status_line() {
  message("status",
    "hp: "+query_hp()+"    "
    "sp: "+query_sp()+"    "
    "mp: "+query_mp()+"    ",
    this_object() );
}

void do_status() {
  
  object to = this_object();
  object env = environment(to);
  int i;

  i = query_intox();
  add_intox(-(1+random(2)));
  if (!query_intox() && i) {
    if (query_quenched() < query_max_quenched()/4) {
      to->add_hp(-(5+random(6)));
      message("info", "Suddenly you get a bad headache.", to);
    }
    else if (random(100) < 3) {
      mixed *drunk = ({
        ({
          "You stumble.",
          "You hiccup.",
          "You look drunk.",
          "You burp.",
        }),
        ({
          " stumbles.",
          " hiccups.",
          " looks drunk.",
          " burps.",
        }),
      });
      int r = random(sizeof(drunk[0]));
      message("info", drunk[0][r], to);
      message("info", to->query_cap_name()+drunk[1][r], env, to);
    }
  }

  add_stuffed(-1);
  add_quenched(-2);

}

void do_healing() {

  object to = this_object();
  int phys = to->query_physical();
  int spir = to->query_spiritual();
  int stuffed = query_stuffed();
  int quenched = query_quenched();
  int intox = query_intox();
  int rate = query_heal_rate();
  int all = (int)query_heal_rate_bonus("all");
  int h, s, m;
  int vamp = 0;

  switch(to->query_race()) {
    // vamps use up blood, range -3 to 0
    case "vampire":
    vamp = 1;
    h = -7+phys;
    h /= 4;
    s = 8+phys;
    m = 5+phys;
    break;

    case "lich":
    h = 5+spir;
    s = 5+spir;
    m = 9+spir;
    break;

    case "dragon":
    h = 7+phys;
    s = 7+phys;
    m = 8+spir;
    break;

    default:
    h = 6+phys;
    s = 6+phys;
    m = 7+spir;
  }

  if (!vamp) {
    h += rate+all+random(2);
    h += (int)query_heal_rate_bonus("hp");
  }

  s += rate*2+all+random(3);
  s += (int)query_heal_rate_bonus("sp");

  m += rate/2 + all+random(4);
  m += (int)query_heal_rate_bonus("mp");

  switch (to->query_rest_type()) {
    case SLEEP:
      if (!vamp && h > 0) h *= 2;
      if (s > 0) s = s*7/3;
      m += rate/2;
      if (m > 0) m *= 3;
    break;
    case REST:
      if (!vamp && h > 0) h = h*4/3;
      if (s > 0) s = s*5/3;
      m += rate/4;
      if (m > 0) m *= 2;
    break;
  }

  if (this_object()->query_current_attacker()) {
    if (h > 0) h /= 3;
    if (s > 0) s /= 2;
    if (m > 0) m = m*3/4;
  }

  add_hp(h);
  add_sp(s);
  add_mp(m);

  // this should probably go in body.c
  foreach (string l in to->query_limbs())
    to->heal_limb(l, rate+all);

  rate = intox/3 + stuffed + quenched/2;

  // this progressively reduces the healing rate to make sure
  // nobody winds up healing hundreds of hp at a time idly
  /*
  for (int i = 10; i < 100; i += 10)
    if (rate > i) rate = i + (rate-i)/((i/10)+1);
  */

  switch (rate) {
    case 0: rate = 0; break;
    case 1..10: rate = 2; break;
    case 11..20: rate = 4; break;
    case 21..35: rate = 6; break;
    case 36..50: rate = 8; break;
    case 51..80: rate = 10; break;
    case 81..120: rate = 12; break;
    case 121..170: rate = 14; break;
    case 171..190: rate = 17; break;
    case 231..300: rate = 20; break;
    case 301..380: rate = 23; break;
    case 381..470: rate = 26; break;
    case 471..570: rate = 29; break;
    case 571..680: rate = 32; break;
    case 681..800: rate = 35; break;
    case 801..1000: rate = 38; break;
    default: rate = 40 + (rate-1000)/60;
  }

  set_heal_rate(rate);
  adjust_biorhythms();

}

void heal(int x) {
  add_hp(x);
  add_sp(x);
  add_mp(x);
  foreach (string l in this_object()->query_limbs())
    this_object()->heal_limb(l, x);
}


// heal rate and biorhythms

int set_heal_rate(int x) { return Vitals["heal rate"] = x; }
int query_heal_rate() { return Vitals["heal rate"]; }

void set_heal_rate_bonus(string s, int b) {
  if (s && (s == "hp" || s == "sp" || s == "mp" || s == "all"))
    VitalsTemp[s+" heal bonus"] = b;
}
void add_heal_rate_bonus(string s, int b) {
  set_heal_rate_bonus(s, query_heal_rate_bonus(s)+b);
}
int query_heal_rate_bonus(string s) { return VitalsTemp[s+" heal bonus"]; }

void adjust_biorhythms() {
  object to = this_object();
  float freq, temps;

  temps = to->query_age()/1000.0;

  freq = to->query_stats("wisdom");
  Vitals["spiritual"] = to_int(5 * sin(freq*temps) );
  freq = to->query_stats("strength");
  Vitals["physical"] = to_int(5 * sin(freq*temps) );
}
int query_spiritual() { return Vitals["spiritual"]; }
int query_physical() { return Vitals["physical"]; }


// intox, quenched, stuffed

int query_max_intox() {
  object to = this_object();
  return
    to->query_level()*6 +
    to->query_stats("constitution")*3 +
    to->query_stats("strength")*2 +
    to->query_stats("charisma")*2;
}
int query_intox() { return Vitals["intox"]; }
void set_intox(int x) {
  if (x > query_max_intox()) x = query_max_intox();
  if (x < 0) x = 0;
  Vitals["intox"] = x;
}
int add_intox(int x) { if (x+query_intox() > query_max_intox()) return 0; set_intox(query_intox()+x); return 1; }

int query_max_quenched() {
  object to = this_object();
  return
    to->query_level()*2 +
    to->query_stats("constitution")*4 +
    to->query_stats("strength")*3 +
    to->query_stats("dexterity")*3;
}
int query_quenched() { return Vitals["quenched"]; }
void set_quenched(int x) {
  if (x > query_max_quenched()) x = query_max_quenched();
  if (x < 0) x = 0;
  Vitals["quenched"] = x;
}
int add_quenched(int x) { if (x+query_quenched() > query_max_quenched()) return 0; set_quenched(query_quenched()+x); return 1; }

int query_max_stuffed() {
  object to = this_object();
  return
    to->query_level()*4 +
    to->query_stats("constitution")*5 +
    to->query_stats("strength")*4;
}
int query_stuffed() { return Vitals["stuffed"]; }
void set_stuffed(int x) {
  if (x > query_max_stuffed()) x = query_max_stuffed();
  if (x < 0) x = 0;
  Vitals["stuffed"] = x;
}
int add_stuffed(int x) { if (x+query_stuffed() > query_max_stuffed()) return 0; set_stuffed(query_stuffed()+x); return 1; }


// hp, sp, mp

void set_max_hp(int hp) { Vitals["max hp"] = hp; }
int query_max_hp() { return Vitals["max hp"]; }

void set_hp(int hp) {
  if (!query_max_hp()) set_max_hp(hp);
  if (hp > query_max_hp()) hp = query_max_hp();
  Vitals["hp"] = hp;
}
void add_hp(int hp) { set_hp(query_hp()+hp); }
int query_hp() { return Vitals["hp"]; }

void set_max_sp(int sp) { Vitals["max sp"] = sp; }
int query_max_sp() { return Vitals["max sp"]; }

void set_sp(int sp) {
  if (!query_max_sp()) set_max_sp(sp);
  if (sp > query_max_sp()) sp = query_max_sp();
  if (sp < -200) sp = -200;
  Vitals["sp"] = sp;
}
void add_sp(int sp) {
  int v, y;
  
  // this is just a hack for the moment
  if ((v=this_object()->query("vigor_spell")) > 0 && sp < -10) {
    y = v + sp;
    if (y > -10) sp = -10;
    else sp = y;
  }

  set_sp(query_sp()+sp);
}
int query_sp() { return Vitals["sp"]; }

void set_max_mp(int mp) { Vitals["max mp"] = mp; }
int query_max_mp() { return Vitals["max mp"]; }

void set_mp(int mp) {
  if (!query_max_mp()) set_max_mp(mp);
  if (mp > query_max_mp()) mp = query_max_mp();
  if (mp < -200) mp = -200;
  Vitals["mp"] = mp;
}
void add_mp(int mp) { set_mp(query_mp()+mp); }
int query_mp() { return Vitals["mp"]; }


// vitals bonuses

int fix_vital_bonus(int i) {
  if (!i) i = this_object()->query_level();
  Vitals["vital bonus"] = i;
  set_vital_bonus();
}

int query_vital_bonus(string str) {
  int v = Vitals["vital bonus"];

  if (this_object()->query_race() == "vampire") {
    switch (str) {
      case "hp": return v*25;
      case "sp": return v*10;
      case "mp": return v*6;
      case "weight": return 100+v*3;
    }
  }

  switch (str) {
    case "hp": return v*10;
    case "sp": return v*6;
    case "mp": return v*10;
    case "weight": return 100+v*2;
  }

  return 0;
}

void set_vital_bonus() {
    object to;
    int i,j;
    string cl;
    to = this_object();
    cl = to->query_class();
    /* hp */
    switch (cl) {
      case "fighter": i=12; break;
      case "wanderer": i=11; break;
      case "dragon": i=11; break;
      case "vampire": i=18; break;
      default: i=10; break;
    }
    set_max_hp(50+i*to->query_stats("constitution")+query_vital_bonus("hp"));
    /*
    player_data["general"]["max_hp"] = 50 + i*stats["constitution"]+
    query_vital_bonus("hp");
    */
    to->augment_body(to->query_stats("constitution"));
    /* sp */
    switch (cl) {
      case "rogue": i=9; break;
      case "wanderer": i=8; break;
      case "dragon": i=8; break;
      case "vampire": i=9; break;
      default: i=7; break;
    }
    set_max_sp(to->query_stats("dexterity")*i+query_vital_bonus("sp"));
    /* mp */
    switch (cl) {
      case "mage": i=12; break;
      case "dragon": i=11; break;
      case "vampire": i=6; break;
      default: i=10; break;
    }
    if (cl == "clergy") j=7;
    else j=5;
    i = (to->query_stats("wisdom")*j)+(to->query_stats("intelligence")*i);
    to->set_max_mp(50+i+query_vital_bonus("mp"));
    /* weight */
    to->set_max_internal_encumbrance(
      to->query_stats("strength")*22 + query_vital_bonus("weight")
    );
}

