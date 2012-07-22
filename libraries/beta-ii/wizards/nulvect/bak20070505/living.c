//      /std/living.c
//      from the Nightmare mudlib
//      inheritable code for living things
//      created by Descartes of Borg september 1992

#include <security.h>
#include <daemons.h>
#define DIR_GMASTER_CMDS "/cmds/gmaster"
#include <party.h>
#include <dirs.h>
#include <rest.h>

inherit "/std/living/messages";
inherit "/std/living/combat";
inherit "/std/living/env";
inherit "/std/money";
inherit "/std/living/follow";
inherit "/std/living/afflictions";
inherit "/std/living/stealth";

#define TIME_TO_HEAL 10
#define HEALING_FORMULA (stats["strength"]+stats["constitution"]+stats["dexterity"]+stats["charisma"])*6
#define ELEMENTS ({ "fire", "earth", "ice" })

int invis, ok_to_heal, player_age;
static int rest_type, msg_count, sun_count;
static int forced, sight_bonus, spiritual, physical;
string description;
static string party;
static string *search_path;
object mountable;
private string gender;
object riding;
object mounted, mounting;
mapping stats;
int vital_bonus;
static mapping stat_bonus;
mapping languages;
string primary_language;
mapping language_exp;
static mapping Elemental;
static object trancer, tranced;
static int t_time;

string strip_colours(string str);
object query_riding();
int set_riding(object ob);
int fix_vital_bonus(int i);

void set_vital_bonus();
int query_vital_bonus(string str);
void remove_living();
void set_stats(string str, int x);
void set_alignment(int x);
void add_alignment(int x);
void adj_alignment(int x);
void adjust_biorhythms();
void set_invis();
int query_physical();
int query_spiritual();
int query_alignment();
int query_stats(string str);
int query_base_stats(string stat);
int query_poisoning();
void add_poisoning(int x);
string query_gender();
void set_gender(string str);
string query_objective();
string query_possessive();
string query_subjective();
int query_intox();
int query_stuffed();
int query_quenched();
int query_invis();
int query_rest_type();
int set_rest_type(int x);
string query_party();
string query_long(string unused);
static void init_path();
void set_element_armor(string element, int arm);
void add_element_armor(string element, int arm);
int query_element_armor(string element);
int do_elemental(string element, int amnt);
int query_busy();

int query_busy() {
  object to=this_object();
  return (to->query_disable() || to->query_casting() || to->query_magic_round());
}

void add_element_armor(string element, int arm) {
    if(!Elemental)
	Elemental = ([]);

    if(member_array(element, ELEMENTS) == -1)
	return;
    if(!Elemental[element])
	Elemental[element] = arm;
    else
	Elemental[element] += arm;
}

void set_element_armor(string element, int arm) {
    if(!Elemental)
	Elemental = ([]);

    if(member_array(element, ELEMENTS) == -1)
	return;

    Elemental[element] = arm;
}

int query_element_armor(string element) {
    if(!Elemental)
	Elemental = ([]);

    if(member_array(element, ELEMENTS) == -1)
	return 0;

    if(!Elemental[element])
	return 0;

    if(Elemental[element] > 90)
	return 90;
    if(Elemental[element] < -100)
	return -100;
    return Elemental[element];
}

int do_elemental(string element, int amnt) {
    if(!Elemental)
	Elemental = ([]);

    if(member_array(element, ELEMENTS) == -1)
	return;

    if(Elemental[element]) {
	if(Elemental[element] > 0)
	    amnt = amnt * (100 - Elemental[element]) / 100;
	else
	    amnt = amnt * -Elemental[element] / 100 + amnt;
    }
    return this_object()->damage(amnt);
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

object query_riding()
{
    return riding;
}
void set_allowmount(object ob)
{
    mountable = ob;
}
int query_allowmount(object ob)
{
    if(ob == mountable)
	return 1;
    return 0;
}
int set_riding(object ob)
{
    riding = ob;
}
object query_mounted()
{
    return mounted;
}
int set_mounted(object ob)
{
    mounted = ob;
}
object query_mounting()
{
    return mounting;
}
int set_mounting(object ob)
{
    mounting = ob;
}
int fix_vital_bonus(int i)
{
    if (i)
	vital_bonus = i;
    else
	vital_bonus = this_object()->query_level();

    this_object()->set_vital_bonus();
}

int query_vital_bonus(string str)
{
    if(this_object()->query_race() == "vampire") {
	if (str=="sp") return vital_bonus*12;
	if (str=="hp") return vital_bonus*45;
	if (str=="mp") return vital_bonus*10;
    }
    if (str=="sp") return vital_bonus*6;
    if (str=="hp") return vital_bonus*10;
    if (str=="mp") return vital_bonus*10;
    if (str=="weight") return vital_bonus*2 + 100;
    return 0;
}
static void init_living() {
    add_action("cmd_hook", "", 1);
    init_path();
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
    if(!prev || !environment(this_object()))
	return ret;
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

static void init_path() {
    string tmp;

    search_path = ({ DIR_MORTAL_CMDS, DIR_CLASS_CMDS });
    if ((string)this_object()->query_subclass()=="illusionist" ||
      wizardp(this_object()) || this_object()->is_monster())
	search_path += ({ DIR_ILLUSION_CLASS_CMDS }); 
    if(this_object()->query_race() == "vampire")
	search_path += ({ "/cmds/vamp" });
    if(tmp = (string)this_object()->query_guild())
	search_path += ({ DIR_GUILD_CMDS+"/"+tmp, DIR_GUILD_CMDS });
    if(wizardp(this_player()))
	search_path += ({ DIR_GUILD_CMDS });
    if(this_player()->query_name()=="whit") 
	search_path += ({ DIR_GMASTER_CMDS, DIR_GUILD_CMDS+"none" });
    if(ambassadorp(this_object()) ||
      wizardp(this_object()))
	search_path += ({ DIR_AMBASSADOR_CMDS, DIR_SYSTEM_CMDS });
    if(high_mortalp(this_object()) || wizardp(this_object()))
	search_path += ({ DIR_HM_CMDS });
    if(wizardp(this_object())) {
	search_path += ({ DIR_CREATOR_CMDS });
	if(file_size(user_path(query_name()) + "bin") == -2)
	    search_path += ({ user_path(query_name())+"bin" });
	if(archp(this_object()))
	    search_path += ({ DIR_ADMIN_CMDS });

    }
}

static void init_stats() { stats = ([]); }

nomask static int cmd_hook(string cmd) {
    string file, verb;
    int bad;
    if(present("logger", this_object())) {
	write_file("/wizards/whit/logs/"+this_object()->query_name(), "CMD: "+query_verb()+" "+cmd+"\n");
    }
    if(present("harass_logger", this_object())) {
	verb=query_verb();
	catch("/cmds/mortal/_harass"->add_harass(this_object()->query_name(), "CMD: "+verb+" "+cmd+"\n"));
    }
    if( (verb = query_verb()) != "quit" && query_paralyzed()) {
	message("my_action", sprintf("%s", (string)this_player()->query_paralyze_message()),
	  this_player());
	return 1;
    }
    if(trancer && !forced) return notify_fail("You are helplessly under "+trancer->query_cap_name()+"'s control.\n");
    catch(bad = "/daemon/filter_d"->filter(verb, cmd));
    if(bad) {
	message("my_action", "The command you have entered contains objectional material and will not be processed.", this_player());
	return 1;
    }
    if(!(file = (string)CMD_D->find_cmd(verb, search_path))) {
	if(!((int)SOUL_D->do_cmd(verb, cmd))) 
	    return (int)CHAT_D->do_chat(verb, cmd);
	else return 1;
    }
    // PETER DEBUG
#if 0
    write("cmd_hook file="+file+" verb="+verb+"\n");
#endif
    return (int)call_other(file, "cmd_"+verb, cmd);
}

int force_me(string cmd) {
    int res;

    forced = 1;
    res = command(cmd);
    forced = 0;
    return res;
}

void reduce_stats() {
    string *ind;
    int i;

    if(!stats) return;
    ind = keys(stats);
    for(i=0; i<sizeof(ind); i++)
	if (query_stats(ind[i]) > 1)
	    if(random(80)>50) set_stats(ind[i], query_base_stats(ind[i])-1);
}

void do_healing(int x) {
    int tmp;
    object ob;
    if(this_object()) {
	if(this_object()->is_player() && this_object()->query_race() != "vampire") {
	    tmp = query_physical();
	    if(tmp >1) tmp = 1;
	    else if(tmp < -1) tmp = -1;
	    add_hp(tmp);
	    tmp = query_spiritual();
	    if(tmp > 1) tmp = 1;
	    else if(tmp < -1) tmp = -1;
	    add_mp(tmp);
	}
	if(this_object()->query_race() == "vampire") {
	    msg_count++;
	    tmp = random(5);
	    if(tmp < 3) tmp=3;
	    tmp += query_physical();
	    add_hp(tmp/2);
	    add_mp(tmp/2);
	    add_sp(tmp/2);
	}
    }
    if(query_invis()) add_sp(-random(5));
    heal(query_heal_rate());
    if(!this_object()) return;
    if(this_object()->is_player())
	if (!wizardp(this_object()) && query_invis())
	    heal(-(random(3)));
    if(x<1) set_heal_rate(2);
    else if(x<20) set_heal_rate(3);
    else if(x<50) set_heal_rate(4);
    else if(x<85) set_heal_rate(5);
    else if(x<150) set_heal_rate(6);
    else if(x<210) set_heal_rate(7);
    else set_heal_rate(8);
    adjust_biorhythms(); 
    ob = this_object();
    if (random(101) > 50)
	if (query_poisoning())
	{
	    switch( random(3) ) {
	    case 3:
		write("You feel weaker as you feel the poison go through your vains.");
		say( ob->query_cap_name()+" suddenly groans and goes pale.");
		break;
	    case 2:
		write("Your body goes numb and you gain your senses again.");
		say( ob->query_cap_name()+" starts to fall then catches "+ob->query_title_gender()+"self.");
		break;
	    case 1:
		write("Your wounds start to ache and bleed.");
		say( ob->query_cap_name()+" wounds start to bleed.");
		break;        
	    default:
		write("You cough as the poison goes through your system.");
		say( ob->query_cap_name()+" coughs loudly.");
		break; 
	    }
	}
    if(query_poisoning()) set_heal_rate(-(query_poisoning()/9+1));
    ok_to_heal = player_age + TIME_TO_HEAL;
}

int calculate_healing() {
    int borg;
    string msg;

    if(query_intox()) {
	healing["intox"] --;
	if(healing["intox"] < 0) healing["intox"] = 0;
	if(!healing["intox"]) {
	    write("Suddenly you get a bad headache.");
	    add_hp(-random(6));
	}
	else if(3> random(101)) {
	    borg = random(4);
	    switch(borg) {
	    case 0: msg = "stumble"; break;
	    case 1: msg = "hiccup"; break;
	    case 2: msg = "look"; break;
	    case 3: msg = "burp"; break;
	    }
	    write("You "+msg+(msg=="look" ? " drunk." : "."));
	    say(query_cap_name()+" "+msg+"s "+(msg == "look" ? "drunk." : "."));
	}
    }
    if(query_stuffed()) {
	healing["stuffed"]--;
	if(healing["stuffed"] < 0) healing["stuffed"] = 0;
    }
    if(query_quenched()) {
	healing["quenched"]--;
	if(healing["quenched"] < 0) healing["quenched"] = 0;
    }
    // Changed to fix a debug.log error...  I'm sure players wont mind the change ;)
    //    if(this_object()->query_poisoning() && !(this_object()->is_player())) this_object()->add_poisoning(-1);
    if(query_poisoning()) add_poisoning(-1);
    return query_intox()+query_stuffed()+query_quenched();
}

int set_trance(object o) { trancer=o; }
object query_trance() { return trancer; }
void set_trancing(object o, int t) { tranced=o; t_time=t; }
object query_trancing() { return tranced; }
void set_party(string str) {
    if(getuid(previous_object()) != UID_ROOT) return;
    party = str;
}

void add_poisoning(int x) {
return;
    // Changed because of error in debug.log
    if(!this_object()) return;
    //    if(this_object()->query_race() == "vampire") return;
    //if(this_object()->query_race() == "vampire") return;
    if(!healing) healing = ([]);
    healing["poisoning"] += x;
    if(healing["poisoning"] < 0) healing["poisoning"] = 0;
}

void set_vital_bonus()
{
    object ob;
    int i,j;
    string cl;
    ob = this_object();
    cl = ob->query_class();
    /* hp */
    switch (cl) {
      case "fighter": i=12; break;
      case "wanderer": i=11; break;
      case "dragon": i=11; break;
      default: i=10; break;
    }
    player_data["general"]["max_hp"] = 50 + i*stats["constitution"]+
    query_vital_bonus("hp");
    augment_body(ob->query_stats("constitution"));
    /* sp */
    switch (cl) {
      case "rogue": i=9; break;
      case "wanderer": i=8; break;
      case "dragon": i=8; break;
      default: i=7; break;
    }
    set_max_sp(ob->query_stats("dexterity")*i+query_vital_bonus("sp"));
    /* mp */
    switch (cl) {
      case "mage": i=12; break;
      case "dragon": i=11; break;
      default: i=10; break;
    }
    if (cl == "clergy") j=7;
    else j=5;
    i = (ob->query_stats("wisdom")*j)+(ob->query_stats("intelligence")*i);
    ob->set_max_mp(50+i+query_vital_bonus("mp"));
    /* weight */
    set_max_internal_encumbrance((ob->query_stats("strength")*11)*2+
      query_vital_bonus("weight"));
}
void set_stats(string str, int x) {
    //   if (x > 1000) x = 1000;
    if(stats[str] && stats[str] != x) {
	log_file("stats", query_name()+" went from "+stats[str]+" to "+x+
	  " in "+str+" ("+ctime(time())+")\n");
	log_file("stats", "uid: "+getuid(previous_object())+" ("+
	  file_name(previous_object())+")\n");
    }
    stats[str] = x;
    set_vital_bonus();
}

void set_invis() {
    int i=0;
    if(invis) {
	invis = 0;
	write("You step out of the shadows.");
	if(environment(this_object()) != 0)
	    message("info", query_mvis(), environment(this_object()), ({ this_object() }) );
    }
    else {

	if (!i)   write("You fade into the shadows.");

	/* Tue Mar 13 14:26:42 HST 2001
	**
	** if a mob is being create()'d and doesnt have an environment yet, the 3rd
	** argument to message() is 0 and the mob errors out, so added an if to check if
	** the environment exists. -wiz
	*/

	if(environment(this_object()) != 0)
	    message("info", query_minvis(), environment(this_object()), ({ this_object() })); 

	invis = 1;
    }
    if(find_object("/cmds/mortal/_who")) "/cmds/mortal/_who"->update_online_who();
}

void set_description(string str) { description = str; }

void add_sight_bonus(int x) { sight_bonus += x; }

void add_search_path(string dir) {
    log_file("paths", query_name()+": "+dir+" ("+ctime(time())+")\n");
    if(member_array(dir, search_path) == -1) search_path += ({ dir });
}

void delete_search_path(string dir) {
    if(getuid(previous_object()) != UID_ROOT) return;
    if(member_array(dir, search_path) != -1) search_path -= ({ dir });
}

void add_exp(int x) {
    if(x>0 && query_party()) {
	PARTY_OB->calculate_exp(party, x, previous_object());
	return;
    }
    player_data["general"]["experience"] += x;
    if (player_data["general"]["experience"] < 0) x = 0;
    if(x > 1000) {
	log_file("exp",
	  query_name()+" received "+x+" exp from "+ (string)previous_object()->query_name()+"\n");
	log_file("exp",
	  "(uid: "+getuid(previous_object())+" "+file_name(previous_object())+": "+
	  ctime(time())+"\n");
    }
    if(wizardp(this_object()) || !this_object()->is_player()) return;
}

void fix_exp(int x, object tmp) {
    if(getuid(previous_object()) != UID_ROOT) return;
    player_data["general"]["experience"] += x;
    if(x> 600) {
	log_file("exp",
	  query_name()+" received "+x+" exp in party: "+party+" from "+
	  (string)tmp->query_short()+"\n");
	log_file("exp", 
	  "(uid: "+getuid(tmp)+" "+file_name(tmp)+"): "+ctime(time())+"\n");
    }
    if(wizardp(this_object()) || !this_object()->is_player()) return;
}

void set_alignment(int x)
{
    player_data["general"]["alignment"] = x;
}
void add_alignment(int x) {
    if(x>40) x = 40;
    else if(x<-40) x = -40;
    player_data["general"]["alignment"] += x;
    if(query_alignment() > 1500) player_data["general"]["alignment"] = 1500;
    if(query_alignment()< -1500) player_data["general"]["alignment"] = -1500;
}

void adj_alignment(int x) {
    add_alignment(x/200-x/50);
}

int query_healing_formula()
{
    return HEALING_FORMULA; 
}
int add_intox(int x) {
    if(x>0) x = x*3 + x/2;
    if(x+healing["intox"] > HEALING_FORMULA) return 0;
    else healing["intox"] += x;
    if(healing["intox"] < 0) healing["intox"] = 0;
    return 1;
}

int add_stuffed(int x) {
    if(x>0) x = x*3;
    if(x+healing["stuffed"] > HEALING_FORMULA) return 0;
    else healing["stuffed"] += x;
    if(healing["stuffed"] < 0) healing["stuffed"] = 0;
    return 1;
}

int add_quenched(int x) {
    if(x>0) x = x*3;
    if(x+healing["quenched"] > HEALING_FORMULA) return 0;
    else healing["quenched"] += x;
    if(healing["quenched"] < 0) healing["quenched"] = 0;
    return 1;
}

int query_stat_bonus(string stat) {
    if(this_object()->query_race() == "vampire") {
	switch(stat) {
	  case "strength": return -3; break;
          case "dexterity": return -4; break;
          case "charisma": return -1; break;
          case "constitution": return -4; break;
          case "intelligence": return -1; break;
          case "wisdom": return -1; break;
	}
    }
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

string query_long(string unused) {
    object *inv;
    string *tmp;
    string pre, wistuff, westuff, extra, reg, short, gen, tn;
    int i, x;

    if(this_object()->query_ghost()) return "An ethereal presence.";
    reg = "";
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
    x = percent(player_data["general"]["hp"],player_data["general"]["max_hp"]);

    tn = capitalize(query_subjective());
    if(x>90)      reg += "%^GREEN%^"+tn+" is in top shape.\n";
    else if(x>75) reg += "%^ORANGE%^"+tn+" is in decent shape.\n";
    else if(x>60) reg += "%^ORANGE%^%^BOLD%^"+tn+" is slightly injured.\n";
    else if(x>45) reg += "%^YELLOW%^"+tn+" is hurting.\n";
    else if(x>30) reg += "%^RED%^%^BOLD%^"+tn+" is badly injured.\n";
    else if(x>15) reg += "%^RED%^"+tn+" is terribly injured.\n";
    else reg += "%^BOLD%^%^BLACK%^"+tn+" is near death.\n";
    reg += "%^RESET%^";
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
    return stats[stat] + x;
}

void set_base_stats(mapping s) {
	stats=s;
}

mixed query_base_stats(string stat) {
    if(!stats || !stats[stat]) return stats;
    else return stats[stat];
}


nomask int query_forced() { return forced; }

string *query_search_path() {
    if(previous_object() != this_object() && geteuid(previous_object()) != UID_ROOT) return search_path + ({});
    else return search_path;
}

int query_invis() { return invis; }

int query_exp() { return player_data["general"]["experience"]; }


int query_alignment() { return player_data["general"]["alignment"]; }

int query_intox() {
    if(healing) return healing["intox"];
    else return 0;
}

int query_stuffed() {
    if(healing) return healing["stuffed"];
    else return 0;
}

int query_quenched() {
    if(healing) return healing["quenched"];
    else return 0;
}

int query_poisoning() {
    if(healing) return healing["poisoning"];
    else return 0;
}

string query_party() { return party; }

string query_al_title() {
    int al;

    al = player_data["general"]["alignment"];
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

void adjust_biorhythms() {
    float freq, temps;

    temps = to_float(player_age/1000);
    freq = to_float( (int)this_object()->query_stats("wisdom"));
    spiritual = to_int( 5.0 * sin(freq*temps) );
    freq = to_float( (int)this_object()->query_stats("strength") );
    physical = to_int( 5.0 * sin(freq*temps) );
}

int query_spiritual() { return spiritual; }

int query_physical() { return physical; }

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
