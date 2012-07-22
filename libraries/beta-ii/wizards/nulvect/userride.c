#include <locations.h>
//      /std/user.c -- modified by seeker and rest of the staff
//  Code optimized by Whit - 12/24/03
#define NO_MSQL

#include <locations.h>
#include <config.h>
#include <rooms.h>
#include <security.h>
#include <daemons.h>
#include <move.h>
#include <objects.h>
#include <money.h>
#include <flags.h>
#include <dirs.h>
#include <council.h>
#include <rest.h>

inherit "/std/living";
inherit "/std/user/tsh";
inherit "/std/user/autoload";
inherit "/std/user/save";
inherit "/std/user/communication";
inherit "/std/user/edit";
inherit "/std/user/trace";
inherit "/std/user/bitflags";
inherit "/std/user/refs";
inherit "/std/user/pueblo";
inherit "/std/user/remort";
inherit "/std/user/more";



#define ONLINE 1
#define QUIT 2
#define NETDEAD 3
#define death_messages ({ "Silence overcomes the land as %s dies.",\
                          "A scream is heard across the land as %s dies.",\
                          "The world darkens for a second as %s dies.",\
                          "You hear a terrible howl as %s is slain.",\
                          "A flash of lightning marks the death of %s.",\
                          "No stuck pig has squealed like %s in death."})
#define vamp_death "Blood red winds and lightning ravage the multiverse "\
			"as %s is stricken down in battle."


int platinum, gold, electrum, silver, copper, level, dragon_level, ghost,
crash_money, rolls, verbose_moves, autosave_off,birth, pk_flag, pinvis, 
killable, remorted, wizpeace, failed_read, snoop;
static int disable, time_of_login, autosave;
static mixed arena;
mapping news, gate_marks, mini_quests, proficiency, outlaw;
string  real_name, email, ip, last_on, password, cpath, race, original_site;
string *ConnectedIps, InitialIp;
private string position, primary_start;
string *quests, *mysites, *message, guild, married;
mixed *current_marriage, *divorced;
static int net_die_time, in_setup;
static string net_died_here, current_short;
static object died_here;
int no_idle, maps, recent_outlaw;

void set_maps(int i);
int query_peace_area();
void set_peace_area(int x);
int query_killable();
void set_killable(int x);
void sync_msql(string name, int i);
int query_dragon_level();
int set_dragon_level(int x);
void add_exp(int x);
int set_mini_quest(string str, int x, string desc);
int set_quest(string str);
int set_manual_quest(string str, int points);
string *query_mini_quests();
void convert_kills();
mapping get_mini_quest_map();
string *query_quests();
string *query_mysites();
void set_mysites(string *str);
void set_guild(string str);
void set_position(string pos);
void set_level(int x);
void fix_crash_victim();
nomask int query_level();
string query_kingdom();
string query_guild();
string query_original_guild();
void get_email(string e);
int query_ghost();
varargs nomask void die(mixed killer);
void save_player(string name);
void write_messages();
string query_email();
nomask string query_position();

string query_guild_position() {
    if(!query_guild()) return "None";
    return GUILD_D->query_actual_position(query_name(), query_original_guild());
}

string query_last_on() { return last_on; }
int query_can_arena() { return 1; }
void set_maps(int i) { maps = i; }

int set_disquised_short(string str) { current_short = str; }
int remove_disquised_short() { current_short = ""; }
string query_disquised_short() { return current_short; }

int query_remorted() { return remorted; }
void set_remorted(int x) { remorted = x; }

int query_read() { return failed_read; }

int query_proficiency(string str) {
    if (!str || str == "") return -1;
    return proficiency[str];
}

int set_proficiency(string str, int x) {
    if (!str || str == "" || !x) return -1;
    proficiency[str] = x;
}

int force_me(string str) {
    if (!this_player()) return ::force_me(str);
    if ((this_player()->is_player() && this_player()!=this_object()) &&
      archp(this_object()))
	return -5;
    return ::force_me(str);
}

void set_gate(mapping t) {
    gate_marks = t;
}
mapping query_gate() {
    if (!gate_marks) gate_marks = ([]);
    return gate_marks;
} 

void display_file(string str) {
    message("info", read_file(str), this_object());
}
int query_player_invis() {
    return pinvis;
}
void set_player_invis(int x) {
    pinvis = x;
}
void set_recent_outlaw(int i) { recent_outlaw = i; }
void remove_outlaw(string str) { outlaw[str] = 0; }
void add_outlaw(string str, int i) {
    if (!str) return;
    if(!outlaw) outlaw = ([]);
    if(!outlaw[str]) outlaw[str] = 0;
    if(outlaw[str]) outlaw[str] += i;
    else outlaw[str] = i;
    set_recent_outlaw(1);
}
void set_outlaw(string str, int i) {
    if (!str) return;
    if(!outlaw) outlaw = ([]);
    else outlaw[str] = i;
}
/**********************************(Note)**********************
*              Standard outlaw types:
*    (*)  pk
*    (*)  theft
*    (*)  drug
*    (*)  other1     (minor offense)
*    (*)  other2     (major offense)
* ----------------
*     Only add/set outlaw by a factor of 1 for each offense..
******************************(End Note)***********************/
int query_outlaw(string str) { if(!outlaw) return 0; if(!outlaw[str]) return 0; return outlaw[str];}
int query_recent_outlaw() { return recent_outlaw; }

int query_pk_flag() {
    return pk_flag;
}
void set_pk_flag(int i) {
    pk_flag = i;
}
void set_arena(mixed blah) { arena = blah; }
// Changed to prevent arena death
// mixed query_arena() { return arena; }
mixed query_arena() {
    if(environment(this_object()))
	if(strsrch(file_name(environment(this_object())), "/d/arena") != -1)
	    return 1;
	else return 0;
}
int query_peace_area() {
    return wizpeace;
}
void set_peace_area(int x) {
    wizpeace = x;
}
int query_dragon_level() {
    return dragon_level;
}
int set_dragon_level(int x) {
    dragon_level = x;
}

void get_email(string e) {
    string who, where;

    write("\n");
    if( sscanf(e, "%s@%s", who, where) != 2 ) {
	write("Sorry, email must be in the form of user@host");
	message("prompt", "Please reenter your email address: ", this_player());
	input_to("get_email");
	return;
    }
    email = e;
}

void describe_current_room(int verbose) {
    object env;
    string borg;
    mixed tmp;
    int light, blm = 0;

    env = environment(this_object());
    blm = env->query_block_light();
    if(wizardp(this_object())) borg = file_name(env)+"\n";
    else borg = "";
    if((light=effective_light(this_object())) > 6 || light < -5) {

	if(light > 6 && !blm) borg += "It is too bright to see.";
	if (light < -5 && !blm) borg += "It is completely dark.";

	message("room_description", borg, this_object());
	if(stringp(tmp=(string)env->query_smell("default")))
	    message("smell", tmp, this_object());
	else if(functionp(tmp))
	    message("smell",(string)((*tmp)("default")), this_object());
	if(stringp(tmp=(mixed)env->query_listen("default")))
	    message("listen", tmp, this_object());
	else if(functionp(tmp)) message("listen", (string)((*tmp)("default")), this_object());
	return;

    }
    else if(light > 5 && !blm) borg += "It is really bright.\n";
    else if(light > 4 && !blm) borg += "It is very bright.\n";
    else if(light > 2 && !blm) borg += "It is bright.\n";
    else if(light > 0 && !blm) borg += "";
    else if(light > -2 && !blm) borg += "It is dark.\n";
    else if(light > -4 && !blm) borg += "It is quite dark.\n";
    else if(light == -5 && !blm) borg += "It is very dark.\n";

    if(!env->query_property("no attack") && !env->query_property("no steal") &&
      query_peace_area()){
	set_peace_area(0);
	borg += "%^ORANGE%^You feel the peace leave you.%^RESET%^\n";
    }
    else if(env->query_property("no attack") && env->query_property("no steal")){
	set_peace_area(1);
	borg += "%^ORANGE%^You feel at peace here.%^RESET%^\n";
    }

    if (verbose){
	if(maps)
	    borg += (string)MAPPER_D->mapper(this_object());
	else
	    borg += wrap((string)env->query_long(0)+" ");
    }
    else
	borg += (string)env->query_short(0);

    message("no_wrap", borg, this_object());
    if(!verbose)
	message("room_exits", (string)env->query_short_exits(), this_object());
    if(verbose && stringp(tmp=(mixed)env->query_smell("default")))
	message("smell", tmp, this_object());
    else if(verbose && functionp(tmp))
	message("smell",(string)((*tmp)("default")), this_object());
    if(verbose && stringp(tmp=(mixed)env->query_listen("default")))
	message("listen", tmp, this_object());
    else if(verbose && functionp(tmp))
	message("listen", (string)((*tmp)("default")), this_object());
    if(verbose && (tmp=(string)env->query_long_exits()) && tmp != "")
	message("info", sprintf("\n%s\n", tmp), this_object());
    if((tmp=(string)env->describe_living_contents(({this_object()})))!="")
	message("living_item", tmp+"\n", this_object());
    if((tmp=(string)env->describe_item_contents(({})))!="")
	message("inanimate_item", tmp, this_object());
}

void basic_commands() {
    add_action("quit", "quit");
}

int query_verbose() { return verbose_moves; }

int set_brief() {
    verbose_moves = !verbose_moves;
    return 1;
}

varargs void move_player(mixed dest, string msg) {
    object prev, horse;
    object *inv;
    string here,going,temp1,temp2,temp3, temp4, temp5;
    string ridingmsg, ridermsg, outmsg, inmsg;
    int i, bzbd, adj, tmp, a;

    prev = environment( this_object() );
    if (!prev) return;

    here = file_name(prev);
    if (stringp(dest)) {
	if (sscanf(dest,"/%s",temp1)!=1) {
	    sscanf(here,"/%s",temp1);
	    going = "";
	    while(sscanf(temp1,"%s/%s",temp2,temp3)==2) {
		going = going + "/"+temp2;
		temp1 = temp3;
	    }
	    temp1 = dest;
	    if (file_size(going+"/"+temp1+".c") != -1) {
		dest = going +"/"+temp1;
	    }
	}
    }
    if (horse = query_riding()) {
      if (userp(query_riding())) {
        write("You are not in control to move around.");
        return;
      }
      else {
        ridingmsg = horse->query_cap_name() ? horse->query_cap_name() : a_or_an(horse->query_name())+" "+horse->query_name();
        ridingmsg = " on "+ridingmsg;
        horse->move(dest);
      }
    }
    if (this_object()->query_sp() < -10 && !query_riding()) {
	write("You are too tired to move!");
	return;
    }
    if (sizeof(query_riders()))
    {
	ridermsg = " with "+query_riders_list()+" on "+query_possessive()+" back";
	message("info","%^GREEN%^%^BOLD%^You ride "+msg+" on "+this_player()->query_cap_name()+"'s back.", query_riders());
	query_riders()->move(dest);
	foreach (object rtmp in query_riders()) rtmp->describe_current_room(rtmp->query_verbose());
    }
    if( (a = move(dest)) != MOVE_OK ) {
	if(wizardp(this_player())) temp5 = "a = "+(string)a; else temp5="";
	write("You remain where you are. "+temp5);
	return;
    }
    if(query_property("stealth")) set_property("stealth", -1);
    if(adj = query_property("stealth")) {
	if (query_property("stealth") > 0) {
	    add_skill_points("stealth", adj);
	    adj += query_stats("dexterity");
	    add_sp(-1);
	}
    }
    if(query_invis())
	this_object()->add_sp(-5 - random(6));
    if(!query_invis() && !hiddenp(this_object())) {
        outmsg = msg+ridingmsg+ridermsg;
	inv = all_inventory(prev);
	for(i=0, bzbd = sizeof(inv); i<bzbd; i++) {
	    if(!living(inv[i]) || inv[i] == this_object()) continue;
	    if(adj) tmp = (adj-(int)inv[i]->query_skill("perception") - (effective_light(inv[i])*4));
	    else tmp = 0;
	    if(tmp > random(70)) continue;
	    if(!msg || msg == "") message("mmout", query_mmout(),inv[i]);
	    else message("mout", query_mout(outmsg), inv[i]);
	}
        inmsg = ridingmsg+ridermsg;
        if (inmsg) inmsg = tp->query_cap_name()+" rides in"+inmsg+".";
        else inmsg = query_min();
	inv = all_inventory(environment(this_object()));
	for(i=0, bzbd = sizeof(inv); i<bzbd; i++) {
	    if(!living(inv[i])) continue;
	    if(inv[i] == this_object()) continue;
	    if(adj) tmp = (adj-(int)inv[i]->query_skill("perception") - (effective_light(inv[i])*4));
	    else tmp = 0;
	    if(tmp > random(101)) continue;
	    if(!msg || msg == "") message("mmin",query_mmin(),inv[i]);
	    else message("min", inmsg, inv[i]);
	}

    }
    if (query_followers())
	move_followers(prev);
    if (!this_player()->query_riding()) 
	if (random(100) > 60) add_sp(-1);

    if(effective_light(this_player()) < -2) {
	write("It is far too dark to see anything.\n");
    }
    else if (!present("blinder", this_player()))
	describe_current_room(verbose_moves);
    else {
	if (archp(this_player())) {
	    present("blinder", this_player())->remove();
	    describe_current_room(verbose_moves);
	    return;
	}
	message("info", "The light of the world is hidden from your eyes.", this_player());
    }
    this_object()->clean_up_attackers();
}

void create() {
    living::create();
    more::create();
    communication::create();
    position = "player";
    wielded = ([]);
    level = 1;
    set_riding(0);
    autosave = 500;
    set_internal_encumbrance(0);
    set_weight(500);
    set_max_internal_encumbrance(500);
    verbose_moves = 1;
    enable_commands();
}

void remove() {
    if(previous_object() != find_object("/d/nopk/standard/freezer"))
	if(previous_object() != this_object() &&
	  (query_verb() != "quit" && this_player() != this_object()) && 
	  archp(this_player())) return;
    destroy_autoload_obj();
    CHAT_D->remove_user(this_object()->query_channels());
    MULTI_D->quit(query_name());
    this_object()->tsh_cleanup();
    living::remove_living();
}

int quit(string str) {
    string msg;    
    if (str) {
	notify_fail("Quit what?\n");
	return 0;
    }
    if (this_object()->query_current_attacker()) {
	notify_fail("You cannot quit while in battle!\n");
	return 0;
    }
    if (this_object()->query_arena()) {
	get_object("/d/arena/bet")->arena_die(this_object());
	return 1;      
    }
    save_player( query_name() );
    IP_D->user_offline(this_object());
    if(wizardp(this_player())) IMSTAT_D->close_session(this_object());
    sync_msql(query_name(), QUIT);
    crash_money = 0;
    if (!this_object()->query_invis()) {
	CHAT_D->do_buddylist_line(this_object()->query_name(), this_object()->query_cap_name()+" has left the realm.");
	CHAT_D->do_enemylist_line(this_object()->query_name(), this_object()->query_cap_name()+" has left the realm.");
    }
    if(query_followers()) clear_followers();
    if (this_object()->query_class() !="mage")
	this_object()->set_gate();
    if (this_object()->query_invis() &&
      !wizardp(this_object())) this_object()->set_invis();
    message("environment",
      "Reality suspended.  See you another time!", this_object());
    if (query_riding()) query_riding()->remove_rider(this_object());
    remove_riding();
    if (sizeof(query_riders())) query_riders()->remove_riding();
    say(query_cap_name() + " is gone from our reality.");
    log_file("enter", query_name()+" (quit): "+ctime(time())+"\n");
    PLAYER_D->add_player_info();
    this_object()->move("/d/nopk/standard/void");
    if (!this_object()->query_invis()) {
	msg = (string)query_cap_name()+": exp:"+query_exp();
	CHAT_D->do_raw_chat("driver", "Exit <driver> "+msg);
    }
    remove();
    return 1;
}

void new_body() {
    mapping borg;
    string *zippo;
    int i, max;
    string tmp;

    init_limb_data();
    if(!race) return;
    tmp = race;
    set_vital_bonus();
    set_max_hp(50 + stats["constitution"] * 10);
    set_hp( (50 + stats["constitution"]*8)/2 );
    set_max_mp( (50 + stats["intelligence"]*10) );
    set_mp( 0 );
    set_max_sp(7*query_stats("dexterity"));
    set_sp(query_stats("dexterity"));
    set_heal_rate(2);
    borg = (mapping)RACE_D->body(this_object());
    for(i=0, max=sizeof(zippo=keys(borg)); i<max; i++) 
	add_limb(zippo[i], borg[zippo[i]]["limb_ref"],borg[zippo[i]]["max_dam"], 0, 0);
    set_wielding_limbs((string *)RACE_D->query_wielding_limbs(tmp));
    set_fingers((int)RACE_D->query_fingers(tmp));
}

void check_guild() {
    int o;
    if(catch(call_other(GUILD_D, "???"))) o=1;
    if(!o) if(GUILD_D->query_guild(this_object()->query_name())) 
	    guild=GUILD_D->query_guild(this_object()->query_name());
    if(!o) if(!GUILD_D->query_position(this_object()->query_name())) guild=0;
}
int query_noidle() { return no_idle; }

//  Whit - No Idle String for Arches
void noidle(int i) {
    if(!archp(this_object())) return;
    no_idle=i;
}

int in_setup() { return in_setup; }
void set_in_setup(int i) { in_setup=i; }

void set_initial_ip(string ip) {
    if(geteuid(previous_object()) != UID_ROOT) return;
    InitialIp = ip;
}

string query_initial_ip() { return InitialIp; }
void setup() {
    string tmp, dir, dir2;
    string msg;

    in_setup=1;
    set_living_name(query_name());
    seteuid(getuid());
    set_heart_beat(1);

    if(this_object()->query_class() != "mage") gate_marks=0;
    set_peace_area(1);

    if(!stats) init_stats();
    if(!skills) init_skills(0);
    this_object()->fix_skills();
    load_autoload_obj();
    init_living();
    if (!body) new_body();
    check_guild();

    this_object()->fix_vital_bonus();
    if(!proficiency) proficiency = ([]);
    this_object()->reset_terminal();
    if(member_array(query_position(), MORTAL_POSITIONS) == -1) {
	IMSTAT_D->init_session(this_object());
	enable_wizard();
    }
    init_living();
    basic_commands();
    ip = query_ip_name(this_object());
    if(!ConnectedIps) ConnectedIps=({});
    if(member_array(ip, ConnectedIps)==-1) ConnectedIps += ({ ip });
    last_on = ctime(time());
    time_of_login = time();
    if(!body) new_body();
    if(!birth) birth = time();
    fix_limbs();
    tsh::initialize();
    if (this_object()->query_invis() &&
      !wizardp(this_object())) this_object()->set_invis();
    if (!this_object()->query_invis())     {
	msg = (string)query_cap_name()+": exp:"+query_exp();
	CHAT_D->do_raw_chat("driver", "Enter <driver> "+msg);
	if(sizeof("/daemon/sameip"->get_one_ip_multi(query_ip_number(this_object())))) {
	    CHAT_D->do_raw_chat("system", "Multi <system> "+query_cap_name()+
	      " logged in with multiple characters online.  Users="+
	      identify("/daemon/sameip"->get_one_ip(query_ip_number(this_object()))) );
	    write("\nThere are multiple characters logged on from your ip address.  Please log off your other characters.");
	    seteuid("Log");
	    log_file("multiplay", "IP: "+query_ip_number(this_object())+". "+
	      identify("/daemon/sameip"->get_one_ip_multi(query_ip_number(this_object())))+"\n");
	}
	save_player(this_object()->query_name());  
    }
    register_channels();
    if(!sizeof(query_aliases())) {
	init_aliases();
	force_me("alias -reset");
    }
    set_property("light", -query_property("light"));
    if(race) set("race", race);
    if (!race) set("race", "none");
    if(query("race")=="none") move(ROOM_SETTER);
    else {
	sight_bonus = (int)RACE_D->query_sight_bonus(query("race"));
	if(!primary_start) primary_start = getenv("start");
	if(strlen(getenv("start")) >= 9)
	    if(getenv("start")[0..8] == "/d/tirun/") {
		tmp = getenv("start");
		tmp[0..8] = "/d/nopk/tirun/";
		primary_start = tmp;
		setenv("start", tmp);
	    }
	if(strlen(getenv("start")) >= 10)
	    if((string)getenv("start")[0..9] == "/d/guilds/") {
		if(sscanf(getenv("start"), "/d/guilds/%s/%s", dir, dir2))
                    if(this_object()->query_original_guild() != dir) {
			write("You are not allowed in this guild.");
			setenv("start", ROOM_START);
		    }
	    }
	if(!((tmp = getenv("start")) && stringp(tmp) && move(tmp)==MOVE_OK))
	    move(ROOM_START);
	setenv("start", primary_start);
    }
    write_messages();
    call_out("save_player", 2, query_name()); 
    PLAYER_D->add_player_info();
    log_file("enter", query_name()+" (enter): "+ctime(time())+" from "+
      query_ip_number()+"\n");
    if (!this_object()->query_invis()) {
	CHAT_D->do_buddylist_line(this_object()->query_name(), this_object()->query_cap_name()+" has entered the realm.");
	CHAT_D->do_enemylist_line(this_object()->query_name(), this_object()->query_cap_name()+" has entered the realm.");
    }
    NEWS_D->read_news();
    if(platinum || gold || silver || electrum || copper) {
	add_money("electrum", electrum);
	add_money("gold", gold);
	add_money("silver", silver);
	add_money("platinum", platinum);
	add_money("copper", copper);
	platinum = gold = electrum = silver = copper = 0;
    }
    sync_msql(query_name(), ONLINE);
    convert_kills();
    this_object()->fix_vital_bonus();
    if (file_size("/failed/"+this_player()->query_name())!=-1) {
	if (file_length("/failed/"+this_player()->query_name())!=failed_read) {
	    if (!failed_read) {
		failed_read = file_length("/failed/"+this_player()->query_name());
		write("%^RED%^%^BOLD%^"+read_file("/failed/"+this_player()->query_name())+"%^RESET%^");
	    } else {
		write("%^RED%^%^BOLD%^"+read_file("/failed/"+this_player()->query_name(), failed_read+1, file_length("/failed/"+this_player()->query_name()))+"%^RESET%^");
		failed_read = file_length("/failed/"+this_player()->query_name());
	    }
	}
    }
    IP_D->user_online(this_object());
    sync_msql(query_name(), ONLINE);
    in_setup=0;
}
void autosave_on() {
    autosave_off=0;
}
void autosave_off() {
    autosave_off=1;
}

void heart_beat() {
  object to = this_object();
  object *inv;

  if (!interactive(to))
    to->net_dead();

  /*
  if (query_trancing()) {
      t_time -= 2;
      if (t_time <= 0) {
          message("info", "Your trance over "+query_trancing()->query_cap_name()+
            " wears off.", this_object());
          query_trancing()->set_trance(0);
          set_trancing(0,0);
          set_trance(0);
      }
  }
  */

  if (player_age > autosave && !autosave_off)  {
    message("info", "Autosaving.", this_object());
    save_player(query_name());
    autosave = player_age + 500;
    /* this part should really be taken out
    crash_money = 0;
    foreach (object ob in deep_inventory(to))
      crash_money += (int)ob->query_value()/2;
    */
  }

  living::heart_beat();
  // calls to living.c
  if (!to) return;

  if (to->query_current_attacker() &&
      to->query_rest_type() == SLEEP)
        to->force_me("wake");

  if (query_invis() && query_sp() < 1 && !wizardp(to) )
    set_invis();

}

void change_net_died_here(string str) {
    if (!str || str==0) return 0;
    net_died_here = str;
}

int query_net_die_time() { return net_die_time; }

void net_dead() {
    string msg;

    p_md5 = 0;
    p_ver = 0;
    if (this_object()->query_arena())
	"/d/arena/bet"->arena_die(this_object());
    sync_msql(query_name(), NETDEAD);
    if (this_object()->query_invis() && !wizardp(this_object()) ) 
	this_object()->set_invis();

    if (this_object()->query_riding())
	this_object()->force_me("dismount "+this_object()->query_riding()->query_name());
    if(this_object()->query_mounted())
	this_object()->force_me("buck "+this_object()->query_mounted()->query_name());
    if(this_player()->query_mounting()) 
	force_me("dismount "+this_object()->query_mounting()->query_name());

    CHAT_D->remove_user(this_object()->query_channels());
    PARTY_D->remove_member(this_object());
    net_died_here = file_name(environment(this_object()));
    save_player(this_object()->query_name());
    if (!this_object()->query_invis()) {
	CHAT_D->do_buddylist_line(this_object()->query_name(), this_object()->query_cap_name()+" has gone link-dead.");
	CHAT_D->do_enemylist_line(this_object()->query_name(), this_object()->query_cap_name()+" has gone link-dead.");
    }
    this_object()->set_rest_type(0);
    if (!this_object()->query_invis()) {
	msg = (string)query_cap_name()+": exp:"+query_exp();
	CHAT_D->do_raw_chat("driver", "Inactive <driver> "+msg);

    } 
    if (!this_object()->query_invis()) {
	message("other_action", sprintf("%s suddenly disappears into a sea of "
	    "irreality.", query_cap_name()), environment(this_object()), ({ this_object() }));
    }
    move(ROOM_FREEZER);
    if(query_snoop(this_object()))
	tell_object(query_snoop(this_object()), capitalize(query_name())+
	  " has gone net-dead.");
    if(find_object("/cmds/mortal/_who")) "/cmds/mortal/_who"->update_online_who();
    net_die_time = time();
    set_heart_beat(0);
    if(wizardp(this_object())) IMSTAT_D->close_session(this_object());

}

void restart_heart() {
    string dead_ed;
    string msg;

    if(find_object("/cmds/mortal/_who")) "/cmds/mortal/_who"->update_online_who();
    sync_msql(query_name(), ONLINE);
    message("info", (wizardp(this_object()) &&
	file_size(dead_ed = user_path(getuid())+"dead.edit") > -1 ?
	"\nYour edit file was saved as: "+dead_ed+"\n" :
	"\nReconnected."), this_object());
    set_heart_beat(1);
    if (!this_object()->query_invis()) {
	CHAT_D->do_buddylist_line(this_object()->query_name(), this_object()->query_cap_name()+" is no longer link-dead.");
	CHAT_D->do_enemylist_line(this_object()->query_name(), this_object()->query_cap_name()+" is no longer link-dead.");
    }
    if(net_died_here) {
	if(load_object(net_died_here))
	    if(this_object()->query_sp() < 0) this_object()->set_sp(10);
	this_object()->move(net_died_here);
	this_object()->force_me("look");
    }
    if(wizardp(this_object())) IMSTAT_D->init_session(this_object());
    if(base_name(environment(this_object())) == ROOM_FREEZER)
	this_object()->move_player(ROOM_START);
    net_died_here = 0;
    if (!this_object()->query_invis()) {
	msg = (string)query_cap_name()+": exp:"+query_exp();
	CHAT_D->do_raw_chat("driver", "Active <driver> "+msg);
	say(query_cap_name()+" has rejoined our reality.");
    }
    net_die_time = 0;
    register_channels();
    save_player(this_object()->query_name());
    if(environment(this_player()) == find_object(ROOM_FREEZER) && 
      !wizardp(this_object()))
	this_object()->move(ROOM_START);
}

varargs nomask void die(mixed killer) {
    object to = this_object();
    object env = environment(to);
    object atck, tmp;
    int x;
    string *d;
    string myrace, hisrace;
    string area, deathroom;
    int pk;

    if (objectp(killer))
      atck = killer;
    else
      atck=this_object()->query_current_attacker();

    if (tmp = this_object()->query_riding())
        force_me("dismount "+tmp->query_name());

    if (tmp = this_object()->query_mounting())
        force_me("dismount "+tmp->query_name());

    if (tmp = this_object()->query_mounted())
        force_me("buck "+tmp->query_name());

    if (this_object()->query_arena()) {
        "/d/arena/bet"->arena_die(this_object());
        return;
    }

    if (wizardp(this_object()) && !query_killable()) {
        message("death", "You are immortal and cannot die.", this_object());
        add_hp(10000);
        return;
    }

    myrace = to->query_race();
    if (atck)
      hisrace = atck->query_race();

    if (myrace == "vampire") {
        message("death", "%^RED%^%^BOLD%^"+
          sprintf(vamp_death, this_object()->query_cap_name()),users());
        message("death", read_file("/news/vamp"), this_object());
        message("death", "A blinding flash of pain sears through your body, "
          "rendering you unconscious. Your eyes flicker and you find yourself in "
          "a strange place.", this_object());
        message("death", query_cap_name()+ " disappears in a flash of "
          "crimson winds and lightning.", environment());
        deathroom = "/d/aciri/vdeath/start";
        this_object()->set_sp(10);
        this_object()->set_mp(random(10));
        this_object()->set_hp(10);
        this_object()->set_property("no corpse", 1);
    }

    else if (myrace == "archangel" && hisrace != "demon" && random(100) >= 65) {
      message("death", "%^BOLD%^A hushed silence fills the realms at the"
        " death of "+this_object()->query_cap_name()+".%^RESET%^", users());
      message("death", "%^YELLOW%^"+this_object()->query_cap_name()+" skyrockets "
        "high into the sky, ascending into the heavens.%^RESET%^", users());
      this_object()->set_hp(10);
      this_object()->set_sp(0);
      this_object()->set_mp(-200);
      this_object()->set_paralyzed(query_level() + random(50)+50,
        "%^YELLOW%^Your body is recovering from severe shock.");
      deathroom = "/wizards/inferno/angel/east";
      to->set_property("no corpse", 1);
    }

    else {
        message("death", "%^RED%^%^BOLD%^"+
          sprintf( death_messages[random(sizeof(death_messages))],
            this_object()->query_cap_name() ),
          users());
        x=sizeof(d=get_dir("/news/death/"));
        message("death", read_file("/news/death/"+d[random(x)]), this_object());
        message("death",
          "You die.\n"
          "You feel the sensations of nothingness as you rise above your corpse.\n"
          "You arrive at a destination in a reality not like your own.",
          this_object());
        message("death", query_cap_name()+ " dies a horrible death.",
          environment());
        deathroom = "/d/nopk/standard/death/death_room";
        to->set_ghost(1);
        to->remove_property("no corpse");
    }
    // this calls make_corpse() which checks the "no corpse" property
    living::die(atck);

    // death penalties happen here
    if (this_object()->query_level() > 3) {

        this_object()->add_exp(-((int)this_object()->query_exp()/4));
        this_object()->reduce_stats();
        this_object()->reduce_skills();

        if (this_object()->query_level() >= 42)
          set_level(query_level()-3);

        else if (this_object()->query_level() >= 28)
          if (random(20) != 20) set_level(query_level()-2);

        else if (this_object()->query_level() >= 14)
          if (random(20) > 5) set_level(query_level()-1);

        else if (this_object()->query_level() >= 10)
          if (random(10) < 7) set_level(query_level()-1);

        if (query_level() < 20)
          setenv("TITLE", (string)ADVANCE_D->get_new_title(this_object()));
    }

    // checks for pk
    if (atck) {
      if (userp(to) && userp(atck)) {

        if (to->query_recent_outlaw()) {
          to->set_recent_outlaw(0);
          message("info", "For doing a good deed, here's "+
            (string)(to->query_level()*10)+" gold.", atck);
          atck->add_money("gold", to->query_level()*10);
        }

        if (!strsrch(file_name(env), "/d/freepk/") ||
            (myrace == "archangel" && hisrace == "demon") ||
            (myrace == "demon" && hisrace == "archangel") ||
            myrace == "vampire")
              pk = 0;
        else
          pk = 1;
      }
      else
        pk = 0;

      if (pk) {
        atck->add_outlaw("pk", 1);
        atck->set_last_pk(to->query_name());
        atck->set_last_pk_time(time());
        area = explode(base_name(environment(to)), "/")[1];
        if (area == "nopk" || area == "freepk")
          area = explode(base_name(environment(to)), "/")[2];
        log_file("pk", atck->query_name()+" PKed "+to->query_name()+" on "+
          ""+ctime(time())+" AREA="+area+"\n");
      }
    }

    if (this_object()->query_poisoning() > 0)
      add_poisoning(-(this_object()->query_poisoning()));
    this_object()->new_body();
    this_object()->fix_vital_bonus(query_level());
    this_object()->fix_skills();
    this_object()->set_recent_outlaw(0);

    to->move(deathroom);
    this_object()->describe_current_room(1);

    save_player(query_name());
    PLAYER_D->add_player_info();
}


void set_rname(string rname) {
    if(geteuid(previous_object()) != UID_ROOT && 
      geteuid(previous_object()) != UID_USERACCESS) return;
    real_name = rname;
}

int is_player() { return 1; }

string query_ip() { return ip; }

string query_email() { if (email) return email; return "???@" + ip; }

string query_rname() { return real_name ? real_name : "???"; }

string query_password() { return password; }

void set_password(string pass) {
    if(geteuid(previous_object()) != UID_ROOT &&
      file_name(previous_object()) != PASSWD_D) return 0;
    password = pass;
    save_player( query_name() );
}

void set_email(string e) {
    if(geteuid(previous_object()) != UID_ROOT && 
      geteuid(previous_object()) != UID_USERACCESS) return 0;
    if (this_player(1) != this_player()) return 0;
    email = e;
    save_player( query_name() );
}

int set_snoop() {
    if (getuid(previous_object()) != UID_ROOT) return 0;
    if(snoop) {
	message("my_action", "You are now secure from being snooped.",
	  this_object());
	snoop = 0;
	return 1;
    }
    else {
	message("my_action", "You can now be snooped by anyone.",
	  this_object());
	snoop = 1;
	return 1;
    }
}

int query_snoop() { return snoop; }

string get_path() { return cpath; }

void set_path(string path) {
    int foo;

    if(geteuid(previous_object()) != geteuid(this_object()))
	return;
    foo = strlen(path) - 1;
    if(path[foo] == '/') path = path[0..foo-1];
    cpath = path;
}

void write_messages() {
    mapping mail_stat;
    int i;

    message("login", sprintf("\n        >>> Terminal currently set to %s <<<",
	getenv("TERM")), this_object());
    mail_stat = (mapping)LOCALPOST_D->mail_status(query_name());
    if(mail_stat["unread"] > 0) {
	for (i = 7; i > 0; i--)
	    message("login", "%^BOLD%^%^GREEN%^YOU HAVE NEW MAIL!!!%^RESET%^", this_object());
    }
    if(query_invis()) message("login", "\n        You are currently "
	  "invisible.", this_object());
    if(wizardp(this_object())) {
	if(file_exists("/log/errors/"+query_name()))
	    message("login", "\n        >>> You have errors in /log/errors/"+
	      query_name()+" <<<", this_object());
	if(file_exists("/log/reports/"+query_name()))
	    message("login", "\n        >>> You have reports in "
	      "/log/reports/"+query_name()+" <<<", this_object());
    }
    if(file_exists("/log/adm/.harass") && member_group(this_object()->query_name(), "law")) 
	message("login", "\n       >>> %^BOLD%^%^RED%^There are logs in the harass log%^RESET%^ <<<",
	  this_object());
    if( !message ) return;
    for( i=0; i<sizeof(message); i++ )
	tell_object(this_object(), message[i]);
    message = ({ });
}

string query_title() {
    string str;
    string foo,fii;

    if(query_ghost()) 
    {
	str = "%^RESET%^%^WHITE%^%^BOLD%^The ghost of "+ query_cap_name()+"%^RESET%^";
	return str;
    }
    if(invis && wizardp(this_object())) return 0;
    str = getenv( "TITLE" );
    if( !str ) str = query_cap_name();
    else if( !sscanf(str, "%s$N%s", foo,fii) )
	str = query_cap_name() + " " + str;
    else
	str = substr( str, "$N", query_cap_name() );
    return str;
}

string query_short() {
    string st, team;
    mixed tmp;
    st = "";
    if (interactive(this_object()))

    {
        if (stringp(tmp = query_riders_list()) && strlen(tmp)) st += " (ridden by "+tmp+")";
        if (objectp(tmp = query_riding())) st += " (riding "+tmp->query_cap_name()+")";
	if ("/d/paintball/start"->query_paintball())
	    if (present("gun", this_object()))
	    {
		team = present("gun", this_object())->query_team();
		switch(team) {
		case "red"   : st += " %^RED%^[ Red ] "; break;
		case "green" : st += " %^GREEN%^[ Green ] "; break;
		case "yellow" : st +=" %^YELLOW%^[ Yellow ]"; break;
		case "blue"   : st +=" %^BLUE%^[ Blue ]"; break; 
		}
	    }
	return query_title()+st;
    }
    else
	return (query_title() + " (link-dead)");
}

mixed *local_commands() {
    return commands();
}

nomask string query_position() { return position; }

nomask int query_level() { return level; }

void set_position(string pos) {
    if (!archp(previous_object()) &&
      geteuid(previous_object()) != UID_ADVANCE &&
      geteuid(previous_object()) != UID_ROOT
    ) {
	message("info", "Permission denied", previous_object());
	log_file("/log/ILLEGAL", previous_object()->query_name()+" tried to change "+
	  ""+this_object()->query_name()+"'s to "+pos+" on "+ ctime(time())+".\n");
	return;
    }
    if(member_array(position, MORTAL_POSITIONS) != -1)
	if(member_array(pos, MORTAL_POSITIONS) == -1) enable_wizard();
    if(position == "high mortal" && pos != "high mortal")
	CASTLE_D->disable_high_mortal(this_object());
    init_path();
    position = pos;
    return;
} 

void set_level(int lev) {
    level = lev;

    if (lev < 0 || lev > 1000000)
	return;
    PLAYER_D->add_player_info();
    log_file("advance", this_object()->query_name()+" advanced to level "+lev+": "+ctime(time())+"\n");
    if(position == "high mortal" && level < 20) {
	position = "player";
	search_path -= ({ DIR_HM_CMDS });
	CASTLE_D->disable_high_mortal(this_object());
	set_env("start", ROOM_START);
	set_env("TITLE", "Mortal $N the fallen high mortal");
    }
    return;
}


void remove_guild() {
    if(!GUILD_D->query_guild(this_object()->query_name())) {
	guild=0;
	return;
    }
    GUILD_D->remove_player( this_object()->query_name(),
      GUILD_D->query_guild(this_object()->query_name()) );
    guild=0;
}

void set_guild(string str) {
    if(GUILD_D->query_guild(this_object()->query_name())) 
	this_object()->remove_guild();
    if(!str || str=="0" || str == "") { remove_guild(); return; }
    if(GUILD_D->add_player(this_object()->query_name(), str)) guild=str;
}
string query_guild() { 
    if(catch(call_other(GUILD_D, "???"))) return "Error loading GUILD_D";
    return GUILD_D->query_short_name(GUILD_D->query_guild(this_object()->query_name()));
}

string query_original_guild() { return guild; }

string query_kingdom() { return KINGDOM_D->query_kingdom(query_name()); }

void set_rolls(int x) { rolls = x; }

int query_rolls() { return rolls; }

string *query_mysites() {
    if(!mysites) mysites = ({});
    return mysites;
}

void set_mysites(string *borg) {
    if(!borg) return;
    if (getuid(previous_object()) != UID_ROOT) return;
    mysites = borg;
    return;
}

string *query_quests() {
    if(!quests) quests = ({});
    return quests;
}
int set_manual_quest(string str, int points) {
    if (!quests) quests = ({});
    if (member_array(str, quests) != -1) return 0;
    player_data["general"]["quest points"] += points;
    quests += ({ str });
    log_file("quests", query_name()+" completed "+str+"\n");
    return 1;
}
void remove_quest(string str) {
    if(!quests || sizeof(quests) < 1) return;
    quests -= ({str});
}
int set_quest(string str) {
    if(!quests) quests = ({});
    if(member_array(str, quests) != -1) return 0;
    player_data["general"]["quest points"] += (int)call_other(ROOM_QUEST, "query_quest_points", str);
    quests += ({ str });
    log_file("quests", query_name()+" completed "+str+": "+ctime(time())+"\n");
    return 1;
}

void return_to_death_site() {
    if(!died_here) this_object()->move(SQUARE_LOC);
    else this_object()->move(died_here);
}

void revive() {
    message("my_action", "You return from the dead!", this_object());
    message("other_action", query_cap_name()+ " returns from the dead!",
      environment(this_object()), this_object());
    new_body();
    this_object()->set_hp(5);
    ghost = 0;
    this_object()->fix_vital_bonus();
    save_player(query_name());
}

int query_ghost() { if(this_object()->query_race() == "vampire") return 0; else return ghost; }
int set_ghost(int i) { ghost =  i; }
int query_quest_points() {
    if(!player_data["general"]["quest points"]) return 0;
    else return player_data["general"]["quest points"];
}



void set_married(string str) {
    if(current_marriage) return;
    current_marriage = ({ lower_case(str), time() });
}

void divorce_me() {
    if(!current_marriage) return;
    if(!divorced) divorced = ({ ({ current_marriage[0], current_marriage[1], time() }) });
    else divorced += ({ ({current_marriage[0], current_marriage[1], time() }) });
    current_marriage = 0;
}

string query_married() {
    return (current_marriage && sizeof(current_marriage) ? 
      current_marriage[0] : 0);
}

mixed *query_current_marriage() { return current_marriage; }

mixed *query_divorced() { return divorced; }


void  fix_crash_victim() {
    int i;

    i= random(5);
    add_money(HARD_CURRENCIES[i], to_int(crash_money*currency_rate(HARD_CURRENCIES[i])));
    message("info", "You recover some of your lost money.", this_player());
    crash_money = 0;
}

int query_birthday() { return birth; }
int reset_birthday() { birth=0; }

void set_news(string which, int size) {
    if(!news) news = ([]);
    news[which] = size;
}

int query_news(string which) {
    if(!news) news = ([]);
    return news[which];
}

void hide(int x) {
    if(file_name(previous_object()) != "/cmds/adm/_haven") return;
    set_hide(x);
}

void set_race(string str) { 
    race = str;
    set("race", str);
    LANG_D->init_languages(this_object());
    //this_player()->new_body(); removed cause it seemed to be causing a bug..... will look into it -Dab
}

string query_race() { return race; }

int set_mini_quest(string str, int x, string desc) {
    if(!mini_quests) mini_quests = ([]);
    if(mini_quests[str]) return 0;
    else mini_quests[str] = ({ time(), desc });
    add_exp(x);
    log_file("quests", query_name()+" completed mini-quest "+str+" "+ctime(time())+" for "+x+" exp.\n");
    return 1;
}

string *query_mini_quests() {
    if(!mini_quests) return ({});
    else return keys(mini_quests);
}

mapping query_mini_quest_map() { return (mini_quests ? mini_quests : ([])); }

int query_login_time() { return time_of_login; }

void convert_kills() {
    int *tmp;
    int i;

    if(!player_data["kills"] || !sizeof(player_data["kills"]) ||
      intp(player_data["kills"][0])) return;
    tmp = ({});
    i = sizeof(player_data["kills"]);
    while(i--) tmp += ({ (int)PLAYER_D->add_kill(player_data["kills"][i]) });
    player_data["kills"] = tmp;
}

void set_name(string str) {
    if(geteuid(previous_object()) != UID_ROOT) return;
    ::set_name(str);
}

string query_first_site() { return original_site; }

void set_primary_start(string str) {
    object ob;

    if(!(ob = find_object_or_load(str))) return;
    if(clonep(ob) || virtualp(ob)) return;
    setenv("start", primary_start = str);
}

string query_primary_start() { return primary_start; }

void clean_net_dead() {
    if(base_name(previous_object()) != ROOM_FREEZER) return;
    this_object()->quit();
}

void set_killable(int x) {
    // remarked because imms should be able to handle this responsibly
    // if (!archp(this_object()) || archp(previous_object()))
    killable = x;
}

int query_killable() { return killable; }

string query_cap_name() {
    if (this_object()->query("bear"))
	return "A bear";
    if (this_object()->query("lion"))
        return "A lion";
    if (this_object()->query("wolf"))
        return "A wolf";
    if (query_name() == "wiz")
	return "wiz";
    if (query_name() == "ashadow")
	return "A shadow";
    return ::query_cap_name();
}
void save_player(string name) {
    ::save_player(name);
}
void sync_msql(string name, int i) {
    string SET, birthd, err;
    mixed *set;
#ifdef NO_MSQL
    return; 
#endif
    if (birth) {
	birthd = "Birthday: "+capitalize(month(birth))+" "+
	date(birth)+" "+((year(birth)-18))+" BN";
	SET = "";
	SET += "player_race='"+(query_race()?query_race():"none")+"',";
	SET += "player_level="+query_level()+",";
	SET += "player_alignment='"+query_al_title()+"',";
	SET += "player_class='"+(query_class()?query_class():"none")+"',";
	SET += "player_subclass='"+query_subclass()+"',";
	SET += "player_gender='"+query_gender()+"',";
	SET += "player_spouse='"+(query_married()?query_married():"single")+"',";
	SET += "player_guild='"+(query_guild()?query_guild():"none")+"',";
	SET += "player_quests="+sizeof(query_quests())+",";
	SET += "player_age="+(18 + (query_age()/4320000))+",";
	SET += "player_birthday='"+birthd+"',";
	if(archp(this_object()))
	    SET += "player_description='admin',";
	else 
	if (wizardp(this_object()))
	    SET += "player_description='wizard',";
	else
	    SET += "player_description='player',";
	SET += "player_state="+i;
	if (MSQL_D->msql_player_exist_in_database(name)) {
	    err= MSQL_D->msql_update("pd", "player_t", SET, "player_name='"+name+"'");
	} else {
	    set = ({ query_name(), (query_race()?query_race():"none"),query_level(),
	      query_al_title(), (query_class()?query_class():"none"), query_subclass(), query_gender(),
	      (query_married()?query_married():"single"), 
	      (query_guild()?query_guild():"none"), sizeof(query_quests()),
	      (18 + (query_age()/4320000)), birthd, "not implemented", i });
	    err =  MSQL_D->msql_insert("pd", "player_t", set);
	}
    }
    if (err) write(err);
}


