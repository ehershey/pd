//      /std/living.c
//      from the Nightmare mudlib
//      inheritable code for living things
//      created by Descartes of Borg september 1992

#include <security.h>
#include <daemons.h>
#include <objects.h>
#define DIR_GMASTER_CMDS "/cmds/gmaster"
#include <party.h>
#include <dirs.h>
#include <rest.h>

inherit "/std/living/commandhook";
inherit "/std/living/messages";
inherit "/std/living/combat";
inherit "/std/living/vitals";
inherit "/std/living/env";
inherit "/std/money";
inherit "/std/living/follow";
inherit "/std/living/riding";
inherit "/std/living/hooks";
//inherit "/std/elemental";
inherit "/std/living/effects";
inherit "/std/living/stealth";

// this is checked in set_exp
#define MAX_INT 2147483647

mapping _LivingData = ([
  "experience" : 0,
  "alignment" : 0,
]);
int invis, player_age;
static int rest_type, msg_count, sun_count;
static int sight_bonus;
string description;
static string party;
private string gender;
mapping stats;
static mapping stat_bonus;
mapping languages;
string primary_language;
mapping language_exp;
static object trancer, tranced;
static int t_time;
static int Disable, MagicRound;
static mapping Allow;
static object *CurrentPets;

string strip_colours(string str);
void remove_living();
void set_stats(string str, int x);
void set_alignment(int x);
void add_alignment(int x);
void adj_alignment(int x);
varargs void set_invis(int, string, string);
int query_alignment();
int query_stats(string str);
int query_base_stats(string stat);
string query_gender();
void set_gender(string str);
string query_objective();
string query_possessive();
string query_subjective();
int query_invis();
int query_rest_type();
int set_rest_type(int x);
string query_party();
string query_long(string unused);
int query_busy();
int query_disable();
void set_disable(int x);
int query_magic_round();
void set_magic_round(int x);
private void make_corpse();
varargs void die(object killer);
void set_allow(string what, mixed who);
void add_allow(string what, mixed who);
void remove_allow(string what, mixed who);
object *query_allow(string what);
void add_pet(object);
void remove_pet(object);
varargs object *query_pets(mixed);

void create() {
  commandhook::create();
  vitals::create();
  combat::create();
  effects::create();
  stealth::create();
  riding::create();
  hooks::create();
//  elemental::create();
  Allow = ([]);
  CurrentPets = ({});
}

void heart_beat() {
  object to = this_object();

  player_age += 2;

  vitals::heart_beat();
  if (!to) return;
  effects::heart_beat();
  if (!to) return;

  if (Disable) Disable--;
  if (MagicRound) MagicRound--;

  // BE SURE to use -> to call die() here, so it calls it from
  // user.c or monster.c and not just the die() in living.c
  // note that this is before idle rounds actually happen
  // also note that monsters without a current attacker don't die
  if (to->query_hp() < 1 && !to->query_ghost() &&
      !(to->is_monster() && !to->clean_up_attackers()))
        to->die(to->query_current_attacker());

  if (!to) return;

  // this is in combat.c
  //to->continue_attack();
  combat::heart_beat();

}

void set_allow(string what, mixed who) { Allow[what] = ({who}); }
void add_allow(string what, mixed who) { if (!sizeof(Allow[what])) Allow[what] = ({}); Allow[what] += ({who}); }
void remove_allow(string what, mixed who) { Allow[what] -= ({who}); }
object *query_allow(string what) { return Allow[what] || ({}); }

void add_pet(object p) { CurrentPets |= ({ p }); }
void remove_pet(object p) { CurrentPets -= ({ p }); }
varargs object *query_pets(mixed p) {
  if (nullp(p)) return copy(CurrentPets);
  else if (arrayp(p)) return p & CurrentPets;
  else if (objectp(p)) {
    if (member_array(p, CurrentPets) != -1) return ({ p });
    else return 0;
  }
  return 0;
}

int query_disable() { return Disable; }
void set_disable(int x) { if (nullp(x)) x = 1; Disable = x; }
int query_magic_round() { return MagicRound; }
void set_magic_round(int x) { if (nullp(x)) x = 1; MagicRound = x; }

int query_busy() {
  object to=this_object();
  return (to->query_disable() || to->query_casting() || to->query_magic_round());
}

private void make_corpse() {
  object to = this_object();
  object corpse, money;
  object *inv;
  mixed err;

  err = catch {
    if (to->query_undead())
      corpse = new(OB_ASH);
    else
      corpse = new(OB_CORPSE);
  };

  if (!(intp(err) && err == 0)) {
    CHAT_D->do_raw_chat("system", "Error <system> "+err);
    return;
  }

  // this copies a ton of important stuff
  corpse->copy_body(to);

  money = new("/std/obj/coins");
  foreach (string curr in to->query_currencies()) {
    int m = to->query_money(curr);
    money->set_money(curr, m);
    to->add_money(curr, -m);
  }
  if (sizeof(money->query_currencies()))
    money->move(corpse);

  inv = all_inventory(to);
  inv->move(corpse);

  corpse->move(environment(to));
}

varargs void die(object killer) {
  object to = this_object();
  object *stuff;
  int exp;

  stuff = all_inventory(to);
  // this lets objects do something when their holder dies
  stuff->notify_die(killer);

  if (!to->query_property("no corpse") && !to->query_property("no_corpse")) {
    make_corpse();
    // if the items wouldn't move into the corpse for some reason...
    stuff = all_inventory(to);
    // try to put them in the room
    stuff->move(environment(to));
    stuff = all_inventory(to);
    // otherwise, they vanish
    foreach (object s in stuff)
      if (!s->remove())
        destruct(s);
  }

  if (killer && living(killer)) {
    killer->adj_alignment( (int)this_object()->query_alignment() );
    killer->add_kill((string)this_object()->query_name());
    this_object()->add_death((string)killer->query_name());
    exp = query_modified_exp(killer, this_object());

    message("info", "You feel more experienced for the kill. "
     "(%^BOLD%^"+add_commas(exp)+"%^RESET%^)", killer);
    killer->add_exp(exp);
    // this lets objects do something when their holder kills something
    all_inventory(killer)->notify_kill(to);
  }

  to->cease_all_attacks();
}


int query_rest_type() { return rest_type; }
int set_rest_type(int x) { rest_type = x; }
string query_short() { 
  string sh;

  if (this_object()->is_monster()) sh = ::query_short();
  else sh = "";

  switch (query_rest_type()) {
    case SLEEP: sh += " (sleeping)"; break;
    case REST: sh += " (resting)"; break;
    case SIT: sh += " (sitting)"; break; 
    case LAY: sh += " (laying)"; break;
    default:
  }
  return sh;
}

static void init_living() {
    if (!sizeof(_LivingData)) _LivingData = ([]);
    if (!sizeof(Allow)) Allow = ([]);

    init_hook(); // in commandhook.c
    init_path(); // in commandhook.c
    init_vitals(); // in vitals.c
    init_attack();
}

string strip_colours(string str) {
    return (string)TERMINAL_D->no_colours(str);
}

int move(mixed dest) {
    object prev;
    int ret;

    prev = environment(this_object());
    ret = ::move(dest);
    if(!prev || !this_object() || !environment(this_object()))
	return ret;
    if (prev->query_property("no zone") || environment(this_object())->query_property("no zone")) return ret;
    if(strlen(file_name(prev)) > 20)
	if(file_name(prev)[0..20] == "/d/nopk/standard/void")
	    return ret;
    if(strlen(file_name(environment(this_object()))) > 20)
	if(file_name(environment(this_object()))[0..20] == "/d/nopk/standard/void")
	    return ret;
    if(file_name(environment(this_object()))[0..6] == "/d/nopk") {
	if(file_name(prev)[0..6] != "/d/nopk")
	    message("info", "%^RESET%^%^BOLD%^You feel safe from attack from other players here.%^RESET%^", this_object());
    }
    else if(file_name(environment(this_object()))[0..8] == "/d/freepk") {
	if(file_name(prev)[0..8] != "/d/freepk")
	    message("info", "%^BOLD%^%^RED%^You feel the lack of law in this area!%^RESET%^", this_object());
    }
    else {
	if(file_name(prev)[0..8] == "/d/freepk" || file_name(prev)[0..6] == "/d/nopk")
	    message("info", "%^BOLD%^%^BLUE%^You feel like there is a lawful presence here.%^RESET%^", this_object());
    }
    return ret;
}


static void init_stats() { stats = ([]); }


void reduce_stats() {
    string *ind;
    int i;

    if(!stats) return;
    ind = keys(stats);
    for(i=0; i<sizeof(ind); i++)
	if (query_stats(ind[i]) > 1)
	    if(random(80)>50) set_stats(ind[i], query_base_stats(ind[i])-1);
}


int set_trance(object o) { trancer=o; }
object query_trance() { return trancer; }
void set_trancing(object o, int t) { tranced=o; t_time=t; }
object query_trancing() { return tranced; }
void set_party(string str) {
    if(getuid(previous_object()) != UID_ROOT) return;
    party = str;
}

void set_stats(string str, int x) {
    //   if (x > 1000) x = 1000;
    if (x < 1) x = 1;
    if(stats[str] && stats[str] != x) {
	log_file("stats", query_name()+" went from "+stats[str]+" to "+x+
	  " in "+str+" ("+ctime(time())+")\n");
	log_file("stats", "uid: "+getuid(previous_object())+" ("+
	  file_name(previous_object())+")\n");
    }
    stats[str] = x;
    set_vital_bonus();
}

varargs void set_invis(int i, string mymsg, string othermsg) {
  if (nullp(i)) i = !invis;
  if (nullp(mymsg)) {
    if (i) mymsg = "You fade into the shadows.";
    else mymsg = "You step out of the shadows.";
  }
  if (nullp(othermsg)) {
    if (i) othermsg = query_minvis();
    else othermsg = query_mvis();
  }
  if (i == invis) return;
  if (strlen(mymsg))
    message("info", mymsg, this_object());
  if (strlen(othermsg) && environment())
    message("info", othermsg, environment(), this_object());
  invis = i;
  if (find_object("/cmds/mortal/_who")) "/cmds/mortal/_who"->update_online_who();
}

void set_description(string str) { description = str; }

void add_sight_bonus(int x) { sight_bonus += x; }

int query_exp() { return _LivingData["experience"]; }
void set_exp(int x) {
  if (x < 0) x = 0;
  if (x > MAX_INT) x = MAX_INT;
  _LivingData["experience"] = to_int(x);
}
void add_exp(int x) {
    // calculate_exp will call fix_exp in this object, which will call add_exp, this first check
    // ensures we don't hit an infinite loop
    if (call_stack(2)[1] != "fix_exp" && x>0 && query_party()) {
	PARTY_OB->calculate_exp(party, x, previous_object());
	return;
    }
    // this makes sure nobody can wrap their exp around into negatives
    if (x > 0 && query_exp() == MAX_INT) return;
    if (x > 0 && query_exp() + x < 0) {
      x = MAX_INT - query_exp();
      message("info", "%^BOLD%^%^RED%^You have reached the maximum possible amount of experience points.\n"
        "You will not be able to gain any more until you spend the exp you have.%^RESET%^", this_object() );
    }
    set_exp(query_exp() + x);
    this_object()->add_exprate_exp(x);
    if(x > 1000) {
	log_file("exp",
	  query_name()+" received "+x+" exp from "+ (string)previous_object()->query_name()+"\n");
	log_file("exp",
	  "(uid: "+getuid(previous_object())+" "+file_name(previous_object())+": "+
	  ctime(time())+"\n");
    }
}

void fix_exp(int x, object tmp) {
    if(getuid(previous_object()) != UID_ROOT) return;
    add_exp(x);
    if(x> 600) {
	log_file("exp",
	  query_name()+" received "+x+" exp in party: "+party+" from "+
	  (string)tmp->query_short()+"\n");
	log_file("exp", 
	  "(uid: "+getuid(tmp)+" "+file_name(tmp)+"): "+ctime(time())+"\n");
    }
}
int query_alignment() { return _LivingData["alignment"]; }

void set_alignment(int x)
{
    if (x > 1500) x = 1500;
    if (x < -1500) x = -1500;
    _LivingData["alignment"] = to_int(x);
}
void add_alignment(int x) {
    if(x>40) x = 40;
    else if(x<-40) x = -40;
    set_alignment(query_alignment() + x);
}

void adj_alignment(int x) {
    add_alignment(x/200-x/50);
}

int query_stat_bonus(string stat) {
    if(!stat_bonus) return 0;
    if(!stat_bonus[stat]) return 0;
    return stat_bonus[stat];
}

void add_stat_bonus(string stat, int amount, int len) {
    if(!stat_bonus) stat_bonus = ([]);
    if(stat_bonus[stat]) stat_bonus[stat] += amount;
    else stat_bonus[stat] = amount;
    if(!stat_bonus[stat]) map_delete(stat_bonus, stat);
    fix_vital_bonus(this_object()->query_level());
    if (len) call_out("add_stat_bonus", len, stat, (amount * -1));
}

string query_long_health() {
  string heshe = capitalize(query_subjective());
  int x = to_int(this_object()->query_hp()*100 / this_object()->query_max_hp());
  string col, desc;

  switch (x) {
    default:
    case 0..15: col = "%^BOLD%^%^BLACK%^"; desc = "near death"; break;
    case 16..30: col = "%^RED%^"; desc = "terribly injured"; break;
    case 31..45: col = "%^BOLD%^%^RED%^"; desc = "badly injured"; break;
    case 46..60: col = "%^YELLOW%^"; desc = "hurting"; break;
    case 61..75: col = "%^ORANGE%^"; desc = "slightly injured"; break;
    case 76..90: col = "%^BOLD%^%^GREEN%^"; desc = "in decent shape"; break;
    case 91..100: col = "%^GREEN%^"; desc = "in top shape"; break;
  }

  return col+heshe+" is "+desc+".%^RESET%^";
}

string query_long(string unused) {
    object *inv;
    string *tmp;
    string pre, wistuff, westuff, extra, reg, short, gen, tn;
    int i, x;

    if(this_object()->query_ghost()) return "An ethereal presence.";
    reg = "";

    if (strlen(query_disguised_long())) return query_disguised_long();
    if (query_gender()=="male") gen = "%^BLUE%^%^BOLD%^male%^RESET%^";
    else if (query_gender()=="female") gen = "%^MAGENTA%^%^BOLD%^female%^RESET%^";
    else gen = "%^BOLD%^%^BLACK%^neuter%^RESET%^";
    if(this_object()->query("lion"))
        return pre = "%^CYAN%^You look over the "+gen+" %^CYAN%^lion%^RESET%^.\n";
    else if(this_object()->query("bear"))
        return pre = "%^CYAN%^You look over the "+gen+" %^CYAN%^bear%^RESET%^.\n";
    else if(this_object()->query("wolf"))
        return pre = "%^CYAN%^You look over the "+gen+" %^CYAN%^wolf%^RESET%^.\n";
    else if (query("race") == "dragon")
	pre = "%^CYAN%^You look over the "+gen+" %^CYAN%^"+capitalize(this_object()->query_subclass())+" Dragon%^RESET%^.\n";
    else
	pre = "%^CYAN%^You look over the "+gen+" %^CYAN%^"+query("race")+"%^RESET%^.\n";
    if(::query_long("junk")) pre += ::query_long("junk")+"\n";
    if(description) pre += query_cap_name()+" "+description+"\n";
    if(severed) tmp = keys(severed);
    if(tmp && sizeof(tmp)) {
	reg += query_cap_name()+" is missing a "+tmp[0];
	if(sizeof(tmp) > 1) {
	    if(sizeof(tmp) != 2) reg += ",";
	    for(i=1; i<sizeof(tmp); i++) {
		if(i== sizeof(tmp)-1) reg += " and a ";
		reg += " " +tmp[i];
		if(i != sizeof(tmp)-1) reg +=",";
	    }
	}
	reg += ".\n";
    }
    /*    else reg += query_cap_name() + " has no missing limbs.\n";*/
    x = percent(this_object()->query_hp(),this_object()->query_max_hp());

    tn = capitalize(query_subjective());
    reg += query_long_health()+"\n";
    wistuff = "";
    westuff = "";
    extra = "";
    inv = all_inventory(this_object());
    if(sizeof(inv)) {
	for(i=0; i<sizeof(inv); i++) {
	    if (inv[i]->extra_look()) extra += (string)inv[i]->extra_look();
	    if (inv[i]->query_wielded()) {
		if(inv[i]->query_invis()) continue;
		short = (string)inv[i]->query_short();
		if(short && short != "") wistuff += "%^RESET%^"+short + "\n";
	    } else if(inv[i]->query_worn()) {
		if(inv[i]->query_invis()) continue;
		short = (string)inv[i]->query_short();
		if(short && short != "") westuff += "%^RESET%^"+short + "\n";
	    }
	}
    }
    if(extra != "") pre = pre + extra;
    if(westuff == "") reg += "";
    else reg += capitalize(query_subjective())+" is wearing:\n"+westuff;
    if(wistuff == "") reg += "";
    else reg += capitalize(query_subjective())+" is wielding:\n"+wistuff;
    reg = pre + reg;
    return reg;
}

int query_stats(string stat) {
    int x;

    x = query_stat_bonus(stat);
    x += stats[stat];
    if (x < 1) x = 1;
    return x;
}

void set_base_stats(mapping s) {
	stats=s;
}

mixed query_base_stats(string stat) {
    if(!stats || !stats[stat]) return stats;
    else return stats[stat];
}




int query_invis() { return invis; }

string query_party() { return party; }

string query_al_title() {
    int al;

    al = query_alignment();
    if(al > 1499) return "godly";
    else if(al > 1000) return "saintly";
    else if(al >750) return "righteous";
    else if(al >500) return "good";
    else if(al > 280) return "benevolent";
    else if(al > 135) return "nice";
    else if(al > -135) return "neutral";
    else if(al > -300) return "mean";
    else if(al > -500) return "malevolent";
    else if(al > -800) return "bad";
    else if(al > -1100) return "evil";
    else if(al > -1500) return "demonic";
    else if(al > -1501) return "satanic";
    else return "satanic";
}

int query_sight_bonus() { return sight_bonus; }


int query_age() { return player_age; }
string *query_all_stats() { return keys(stats); }

string query_description() { return description; }

void remove_living() {
    int i;
    object *inv;
    inv = all_inventory(this_object());
    for(i=0; i<sizeof(inv); i++) {
	if(!inv[i]) continue;
	if(inv[i]->drop() && inv[i]) inv[i]->remove();

    }
    ::remove();
}

string query_primary_lang() { return primary_language; }

void set_primary_lang(string str) { primary_language = str; }


// language system added by Valodin in August 1993

int query_lang_prof(string lang) 
{ 
    if(!languages)
	return 0;
    if(!languages[lang]) 
	return 0;
    return languages[lang];
}

int set_lang_prof(string lang, int i)
{
    if(!languages)
	languages = ([]);
    if(i > 10)
	i = 10;
    languages[lang] = i;
    return languages[lang];
}

string *query_all_languages()
{
    if(!languages)
	return ({});
    return keys(languages);
}

int remove_language(string lang)
{
    if(!languages || !languages[lang])
	return 0;
    map_delete(languages, lang);
    return 1;
}


// each mapping element is an array of two ints
// The first is the number of language points amassed.  When this reaches
// (lang_prof + 1) ^ 4, the language prof advances and the language points
// are decreased.  The second number is the number of excess exp points
// have been spent.  When exp is spent, it is converted to lang_pts based
// on intelligence.  it takes (40 - int) exp pts to make one lang_pt
// -Valodin

void learn_language(string lang, int exp)
{
    int tot_exp, tmp, goal, lang_pts, intel_fac;

    if(!language_exp)
	language_exp = ([]);
    if(!language_exp[lang])
	language_exp[lang] = ({ 0, 0});
    tot_exp = exp + language_exp[lang][1];
    intel_fac = 40 - query_stats("intelligence");
    if(intel_fac < 1)
	intel_fac = 1;
    lang_pts = tot_exp / intel_fac;
    tot_exp = tot_exp % intel_fac;
    language_exp[lang][0] += lang_pts;
    language_exp[lang][1] = tot_exp;

    tmp = query_lang_prof(lang) + 1;
    if(tmp > 10)
	tmp = 10;

    while((goal = tmp * tmp * tmp * tmp) <= language_exp[lang][0])
    {
	set_lang_prof(lang, tmp);
	language_exp[lang][0] -= goal;
	tmp++;
	if(tmp > 10)
	    tmp = 10;
    }
}

int *query_lang_exp(string lang)
{
    if(!language_exp)
	return ({ 0, 0 });
    if(!language_exp[lang])
	return ({ 0, 0});
    return language_exp[lang];
}

void set_gender(string str) { 
    if(str != "male" && str != "female" && str != "neuter") return;
    gender = str;
}
string query_title_gender()
{ 
    return (((string)this_player()->query_gender() == "male") ? "his" : "her");
}
string query_gender() { return (gender ? gender : "neuter"); }

string query_subjective() { return nominative(gender); }

string query_possessive() { return possessive(gender); }

string query_objective() { return objective(gender); }
int is_living() { return 1; }
