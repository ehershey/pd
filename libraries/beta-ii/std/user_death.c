//      /std/user.c -- modified by seeker and rest of the staff
//  Code optimized by Whit - 12/24/03

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


#define NO_MSQL
#define ONLINE 1
#define QUIT 2
#define NETDEAD 3


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
inherit "/std/user/exprate";
inherit "/std/user/death";


// --- static vars are not saved to player files --- //

static int time_of_login, autosave;
static int net_die_time, in_setup;
static string net_died_here;
static object died_here;

// --- normal vars, these are saved --- //

int platinum, gold, electrum, silver, copper, crash_money;
int level, verbose_moves;
int autosave_off, autosave_silent, birth, pk_flag, pinvis;
int killable, remorted, wizpeace, failed_read, snoop;
int no_idle, maps, recent_outlaw;
string real_name, email, ip, last_on, password, cpath, race, original_site;
string guild, married, InitialIp;
string *ConnectedIps, *quests, *mysites;
private string position, primary_start;
mixed *current_marriage, *divorced;
mapping news, mini_quests, proficiency, outlaw;
mapping _PlayerData = ([
  "kills" : ({ }),
  "quest points" : 0,
]);


// --- function prototypes --- //

void basic_commands();
int in_setup();
void set_in_setup(int i);
void setup();
void write_messages();
string query_last_on();
int query_read();
void get_email(string e);
void remove();
int quit(string str);
void new_body();
void change_net_died_here(string str);
void clean_net_dead();
int query_net_die_time();
int query_login_time();
void restart_heart();
varargs void caught_theft(string type, int amt);
void set_recent_outlaw(int i);
void remove_outlaw(string str);
void add_outlaw(string str, int i);
void set_outlaw(string str, int i);
int query_outlaw(string str);
int query_recent_outlaw();
int query_pk_flag();
void set_pk_flag(int i);
int query_peace_area();
void set_peace_area(int x);
void describe_current_room(int verbose);
int query_verbose();
int set_brief();
varargs void move_player(mixed dest, string msg);
string query_title();
string *query_id();
string query_short_linkdead();
string query_short_riders();
string query_short_riding();
string query_short_paintball();
string query_short();
string query_cap_name();
int is_player();
int is_linkdead();
varargs nomask void die(mixed killer);
int query_can_arena();
int query_arena();
void set_maps(int i);
int query_remorted();
void set_remorted(int x);
int query_proficiency(string str);
int set_proficiency(string str, int x);
int force_me(string str);
void display_file(string str);
int query_player_invis();
void set_player_invis(int x);
void noidle(int i);
int query_noidle();
void set_initial_ip(string ip);
string query_initial_ip();
void autosave_on();
void autosave_off();
void set_autosave_silent(int x);
int query_autosave_silent();
void set_rname(string rname);
string query_ip();
string query_email();
string query_rname();
string query_password();
void set_password(string pass);
void set_email(string e);
int set_snoopable();
int query_snoopable();
string get_path();
void set_path(string path);
mixed *local_commands();
nomask string query_position();
nomask int query_level();
void set_position(string pos);
void set_level(int lev);
string query_kingdom();
string *query_mysites();
void set_mysites(string *borg);
string *query_quests();
int set_manual_quest(string str, int points);
void remove_quest(string str);
int set_quest(string str);
void set_quest_points(int q);
void add_quest_points(int q);
int query_quest_points();
int set_mini_quest(string str, int x, string desc);
string *query_mini_quests();
mapping query_mini_quest_map();
void set_married(string str);
void divorce_me();
string query_married();
mixed *query_current_marriage();
mixed *query_divorced();
int query_birthday();
int reset_birthday();
void set_news(string which, int size);
int query_news(string which);
void hide(int x);
int query_undead();
void set_race(string str);
string query_race();
void convert_kills();
void set_kills(int *k);
void clear_kills();
int *query_kills();
void add_kill(string str);
void remove_kill(int i);
void set_name(string str);
string query_first_site();
void set_primary_start(string str);
string query_primary_start();
void set_killable(int x);
int query_killable();
void save_player(string name);
void sync_msql(string name, int i);
void set_primary_char(string str);
string query_guild_position();
void check_guild();
void remove_guild();
void set_guild(string str);
string query_guild();
string query_original_guild();


// --- applies --- ///

void create() {
  living::create();
  more::create();
  communication::create();
  position = "player";
  wielded = ([]);
  level = 1;
  remove_riding();
  autosave = 500;
  set_internal_encumbrance(0);
  set_weight(500);
  set_max_internal_encumbrance(500);
  verbose_moves = 1;
  enable_commands();
  set_short_more( ({
    "query_short_rest",
    "query_short_linkdead",
    "query_short_riders",
    "query_short_riding",
    "query_short_paintball",
  }) );
}

void heart_beat() {
  object to = this_object();
  object *inv;
  int gtime = 0;

  if (!interactive(to))
    to->net_dead();

  if (player_age > autosave && !autosave_off)  {
    if (!in_input() && !autosave_silent) message("info", "Autosaving.", this_object());
    save_player(query_name());
    autosave = player_age + 500;
    receive("\0");
  }

  living::heart_beat();
  // calls to living.c
  if (!to) return;

  if (to->query_current_attacker() &&
      to->query_rest_type() == SLEEP)
    to->force_me("wake");

  if (query_invis() && query_sp() < 1 && !wizardp(to) )
    set_invis();

  gtime = (int)query_property("gagtime");
  if (gtime > 0 && query_idle(this_object()) < 60*7) {
    remove_property("gagtime");
    gtime -= 2;
    if (gtime < 1) {
      remove_property("gagged");
    }
    else if (query_property("gagged")) {
      set_property("gagtime", gtime);
    }
  }

}

void net_dead() {
  if (!this_object()) return;

  p_md5 = 0;
  p_ver = 0;

  net_die_time = time();
  if (environment(this_object()))
    net_died_here = file_name(environment(this_object()));
  
  sync_msql(query_name(), NETDEAD);

  if (this_object()->query_arena())
    ROOM_ARENA->arena_die(this_object());

  if (!wizardp(this_object()) ) 
    this_object()->set_invis(0);

  this_object()->dismount_all();

  CHAT_D->remove_user(this_object()->query_channels());
  PARTY_D->remove_member(this_object());
  
  save_player(this_object()->query_name());

  if (!this_object()->query_invis()) {
    CHAT_D->do_buddylist_line(this_object()->query_name(),
      capitalize(this_object()->query_name())+" has gone link-dead."
    );
    CHAT_D->do_enemylist_line(this_object()->query_name(),
      capitalize(this_object()->query_name())+" has gone link-dead."
    );
    CHAT_D->do_raw_chat("system", "Linkdead <system> "+
      capitalize((string)query_name())+" from "+query_ip()
    );
    if (environment()) {
      message("other_action", query_cap_name()+" suddenly disappears "
	"into a sea of irreality.", environment(), this_object() );
    }
  }

  this_object()->set_rest_type(0);

  move(ROOM_FREEZER);

  if (query_snoop(this_object())) {
    tell_object(query_snoop(this_object()),
      capitalize(query_name())+" has gone link-dead."
    );
  }

  if (find_object("/cmds/mortal/_who"))
    "/cmds/mortal/_who"->update_online_who();

  set_heart_beat(0);

  if (wizardp(this_object())) IMSTAT_D->close_session(this_object());
}

int id(string str) {
  if (!stringp(str)) return 0;
  return member_array(str, this_object()->query_id()) != -1 || ::id(str);
}


// --- login and disconnect related functions --- //

void basic_commands() {
  add_action("quit", "quit");
}

int in_setup() { return in_setup; }
void set_in_setup(int i) { in_setup=i; }

void setup() {
  int i;
  string tmp, dir;
  string *same;

  if (!sizeof(_PlayerData)) _PlayerData = ([]);
  if (!sizeof(_PlayerData["kills"])) _PlayerData["kills"] = ({});

  in_setup=1;
  set_living_name(query_name());
  seteuid(getuid());
  set_heart_beat(1);

  set_peace_area(1);

  if (!stats) init_stats();
  init_living();
  if (!body) new_body();
  fix_limbs();
  if (!skills) init_skills(0);
  this_object()->fix_skills();
  this_object()->fix_vital_bonus();

  load_autoload_obj();
  check_guild();

  if (!proficiency) proficiency = ([]);
  this_object()->reset_terminal();

  if (member_array(query_position(), MORTAL_POSITIONS) == -1) {
    IMSTAT_D->init_session(this_object());
    enable_wizard();
  }
  
  basic_commands();

  ip = query_ip_number(this_object());
  if (!ConnectedIps) ConnectedIps=({});
  if (member_array(ip, ConnectedIps)==-1) ConnectedIps += ({ ip });

  SAMEIP_D->add_ip(ip, query_name());

  last_on = ctime(time());
  time_of_login = time();
  if (!birth) birth = time();

  tsh::initialize();

  if (this_object()->query_invis() && !wizardp(this_object()))
    this_object()->set_invis();

  if (!this_object()->query_invis())     {
    CHAT_D->do_raw_chat("system",
      "Login <system> "+capitalize((string)query_name())+" from "+query_ip()
    );
    same = SAMEIP_D->get_one_ip_multi(ip);
    if (sizeof(same)) {
      CHAT_D->do_raw_chat("system", "Multi <system> "+query_cap_name()+
	  " logged in with multiple characters online. Users="+identify(same) );
      write("\nThere are multiple characters logged on from your ip address.  Please log off your other characters.");
      seteuid("Log");
      log_file("multiplay", "IP: "+ip+". "+identify(same)+"\n");
    }
    save_player(this_object()->query_name());  
  }

  register_channels();

  if (!sizeof(query_aliases())) {
    init_aliases();
    force_me("alias -reset");
  }

  remove_property("light");

  if (race)
    set("race", race);
  else
    set("race", "none");

  if (query("race") == "none")
    move(ROOM_SETTER);
  else {
    sight_bonus = (int)RACE_D->query_sight_bonus(query("race"));

    tmp = getenv("start");
    if (!tmp)
      tmp = ROOM_START;

    if (tmp[0..8] == "/d/tirun/")
      tmp[0..8] = "/d/nopk/tirun/";

    if (sscanf(tmp, "/d/guilds/%s/%*s", dir) == 2 &&
        this_object()->query_original_guild() != dir) {
          write("You are not allowed in this guild.");
	  tmp = ROOM_START;
    }

    setenv("start", tmp);
    if (!primary_start) primary_start = tmp;

    if (move(tmp) != MOVE_OK)
      move(ROOM_START);
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
  
  if (platinum || gold || silver || electrum || copper) {
    add_money("electrum", electrum);
    add_money("gold", gold);
    add_money("silver", silver);
    add_money("platinum", platinum);
    add_money("copper", copper);
    platinum = gold = electrum = silver = copper = 0;
  }
  
  sync_msql(query_name(), ONLINE);
  
  convert_kills();
  
  if (!wizardp(this_object())) this_object()->remove_property("passive");

  if ((i = file_length("/failed/"+this_player()->query_name())) != -1) {
    if (i != failed_read) {
      // read starting at line number failed_read, go to end of file
      write("%^RED%^%^BOLD%^"+read_file("/failed/"+this_player()->query_name(), failed_read)+"%^RESET%^");
      failed_read = i;
    }
  }

  IP_D->user_online(this_object());
  sync_msql(query_name(), ONLINE);
  IDENTITY_D->manage_identity(0, this_object(), "login check");
  NEWS_D->read_news();

  in_setup=0;
}

void write_messages() {
  mapping mail_stat;
  int tmp;

  message("login",
    "\n        >>> "
    "Terminal currently set to "+getenv("TERM")+
    " <<<",
    this_object()
  );

  mail_stat = (mapping)LOCALPOST_D->mail_status(query_name());
  if (mail_stat["unread"] > 0) {
    message("login",
      "        >>> "
      "%^BOLD%^%^GREEN%^You have "+mail_stat["unread"]+" new mails!"
      "%^RESET%^ <<<",
      this_object()
    );
  }

  if (query_invis()) {
    message("login",
      "        >>> "
      "%^BOLD%^%^WHITE%^You are currently invisible."
      "%^RESET%^ <<<",
      this_object()
    );
  }

  if (wizardp(this_object())) {
    /*
    if (file_exists("/log/errors/"+query_name())) {
      message("login",
        "        >>> "
	"You have errors in /log/errors/"+query_name()+
	" <<<",
	this_object()
      );
    }
    */
    if (file_exists("/log/reports/"+query_name())) {
      message("login",
	"        >>> "
	"You have reports in /log/reports/"+query_name()+
	" <<<",
	this_object()
      );
    }
  }

  if (member_group(this_object()->query_name(), "law")) {
    if (file_exists("/log/adm/.harass")) {
      message("login",
	"        >>> "
	"%^BOLD%^%^RED%^There are logs in the harass log."
	"%^RESET%^ <<<",
	this_object()
      );
    }
  }

  tmp = ADVANCE_D->query_exp_bonus();
  if (tmp != 100) {
    message("login",
      "        >>> "
      "%^YELLOW%^Experience point bonus active: "+tmp+"%!"
      "%^RESET%^ <<<",
      this_object()
    );
  }
}

string query_last_on() { return last_on; }
int query_read() { return failed_read; }

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

void remove() {
  if (previous_object() != find_object("/d/nopk/standard/freezer"))
    if (previous_object() != this_object() &&
	(query_verb() != "quit" && this_player() != this_object()) && 
	archp(this_player())) return;
  destroy_autoload_obj();
  CHAT_D->remove_user(this_object()->query_channels());
  SAMEIP_D->remove_ip(query_ip_number(this_object()), query_name());
  this_object()->tsh_cleanup();
  living::remove_living();
}

int quit(string str) {
  string msg;    
  if (str) {
    return notify_fail("Quit what?\n");
  }
  if (this_object()->query_current_attacker()) {
    return notify_fail("You cannot quit while in battle!\n");
  }
  if (this_object()->query_arena()) {
    ROOM_ARENA->arena_die(this_object());
    return 1;      
  }
  save_player( query_name() );
  IP_D->user_offline(this_object());
  if (wizardp(this_player())) IMSTAT_D->close_session(this_object());
  sync_msql(query_name(), QUIT);
  crash_money = 0;

  if (!this_object()->query_invis()) {
    CHAT_D->do_buddylist_line(this_object()->query_name(),
      this_object()->query_cap_name()+" has left the realm."
    );
    CHAT_D->do_enemylist_line(this_object()->query_name(),
      this_object()->query_cap_name()+" has left the realm."
    );
    CHAT_D->do_raw_chat("system", "Logout <system> "+
      capitalize((string)query_name())+" from "+query_ip()
    );
  }

  if (query_followers()) clear_followers();
  this_object()->dismount_all();

  if (!wizardp(this_object())) this_object()->set_invis(0);

  message("info", "Reality suspended.  See you another time!", this_object());
  say(query_cap_name() + " is gone from our reality.");

  log_file("enter", query_name()+" (quit): "+ctime(time())+"\n");
  PLAYER_D->add_player_info();
  this_object()->move(ROOM_VOID);
  remove();
  return 1;
}

void new_body() {
  mapping borg;
  string *zippo;
  int i, max;
  string tmp;

  init_limb_data();

  if (!race) return;

  tmp = race;
  set_heal_rate(2);
  borg = (mapping)RACE_D->body(this_object());
  for(i=0, max=sizeof(zippo=keys(borg)); i<max; i++) 
    add_limb(zippo[i], borg[zippo[i]]["limb_ref"],borg[zippo[i]]["max_dam"], 0, borg[zippo[i]]["ac"]);
  set_wielding_limbs((string *)RACE_D->query_wielding_limbs(tmp));
  set_fingers((int)RACE_D->query_fingers(tmp));

  fix_vital_bonus(query_level());
}

void change_net_died_here(string str) {
  if (!str || str==0) return 0;
  net_died_here = str;
}

void clean_net_dead() {
  if (base_name(previous_object()) != ROOM_FREEZER) return;
  this_object()->quit();
}

int query_net_die_time() { return net_die_time; }
int query_login_time() { return time_of_login; }

void restart_heart() {
  string dead_ed;
  string msg;
  object *pets;

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
  pets = this_object()->query_pets(all_inventory(environment()));
  if(this_object()->query_sp() < 0) this_object()->set_sp(10);
  if(net_died_here && (find_object(net_died_here) || (strsrch(net_died_here, "#", -1) == -1 && load_object(net_died_here)))) {
    this_object()->move(net_died_here);
    this_object()->force_me("look");
  }
  if(wizardp(this_object())) IMSTAT_D->init_session(this_object());
  if(base_name(environment(this_object())) == ROOM_FREEZER)
    this_object()->move_player(ROOM_START);
  net_died_here = 0;
  if (!this_object()->query_invis()) {
    msg = capitalize((string)query_name())+" from "+query_ip()+"";
    CHAT_D->do_raw_chat("system", "Reconnected <system> "+msg);
    say(query_cap_name()+" has rejoined our reality.");
  }
  net_die_time = 0;
  register_channels();
  save_player(this_object()->query_name());
  if(environment(this_player()) == find_object(ROOM_FREEZER) && 
      !wizardp(this_object()))
    this_object()->move(ROOM_START);
  if (sizeof(pets)) pets->move_player(environment(), "out");
}


// --- justice system related functions --- //

varargs void caught_theft(string type, int amt) {
  object to = this_object();
  mixed ret;

  if (environment(to)->query_zone() == "freepk")
    return;

  if (nullp(type)) type = "theft";
  if (nullp(amt)) amt = 1;

  ret = resolve_hooks("caught_theft", ({ type, amt }) );
  if (sizeof(ret) != 2) return;
  amt = ret[1];
  if (amt < 1) return;

  if (wizardp(to))
    message("info", "If you weren't immortal, you'd have gained "+
	(amt == 1 ? indefinite_article(type) : ""+amt)+" offense"+
	(amt == 1 ? "" : "s")+".", to);

  else
    to->add_outlaw(type, amt);
}

void set_recent_outlaw(int i) { recent_outlaw = i; }
void remove_outlaw(string str) { outlaw[str] = 0; }
void add_outlaw(string str, int i) {
  mixed ret;
  if (!str) return;
  ret = resolve_hooks("add_outlaw", ({ str, i }) );
  if (sizeof(ret) != 2) return;
  i = ret[1];
  if (i < 1) return;
  if(!outlaw) outlaw = ([]);
  if(!outlaw[str]) outlaw[str] = 0;
  if(outlaw[str]) outlaw[str] += i;
  else outlaw[str] = i;
  set_recent_outlaw(1);
}
void set_outlaw(string str, int i) {
  mixed ret;
  if (!str) return;
  ret = resolve_hooks("set_outlaw", ({ str, i }) );
  if (sizeof(ret) != 2) return;
  i = ret[1];
  if (i < 1) return;
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


// --- description related functions --- //

int query_peace_area() {
  return wizpeace;
}
void set_peace_area(int x) {
  wizpeace = x;
}

void describe_current_room(int verbose) {
  object to = this_object();
  object env;
  string desc, fulldesc;
  string file, light, peace;
  string exits, smell, listen;
  string liv, item;
  string msgclass;
  mixed tmp;
  int blm = 0;

  desc = fulldesc = file = light = peace = "";
  exits = smell = listen = liv = item = "";

  env = environment(this_object());
  if (!env) {
    message("room_description", "You are nowhere.", this_object());
    return;
  }

  if (verbose){
    if(maps && env->query_property("no map") != 1) {
      desc = (string)MAPPER_D->mapper(this_object());
      msgclass = "room_description";
    }
    else {
      desc = wrap((string)env->query_long(0)+" ");
      msgclass = "room_description";
    }

    exits = env->query_long_exits();

    tmp = env->query_smell("default");
    if (stringp(tmp)) smell = tmp;
    else if (functionp(tmp)) smell = (*tmp)("default");

    tmp = env->query_listen("default");
    if (stringp(tmp)) listen = tmp;
    else if (functionp(tmp)) listen = (*tmp)("default");

  }
  else {
    desc = (string)env->query_short(0) || "";
    desc += "\n"+env->query_short_exits();
  }

  liv = env->describe_living_contents( ({ to }) );
  item = env->describe_item_contents( ({}) );

  if (wizardp(this_object())) file = file_name(env)+"\n";

  if (!env->query_property("no attack") &&
      !env->query_property("no steal") &&
      query_peace_area()) {
    set_peace_area(0);
    peace = "%^ORANGE%^You feel the peace leave you.%^RESET%^\n";
  }
  else if (env->query_property("no attack") && env->query_property("no steal") && !env->query_property("no zone")) {
    set_peace_area(1);
    peace = "%^ORANGE%^You feel at peace here.%^RESET%^\n";
  }

  blm = env->query_block_light();

  if (!blm) {
    switch (effective_light(to)) {
      case 7..100:
	light = "It is too bright to see.\n";
	desc = "";
	break;
      case 6: light = "It is really bright.\n"; break;
      case 5: light = "It is very bright.\n"; break;
      case 3..4: light = "It is bright.\n"; break;
      case 1..2: light = ""; break;
      case -1..0: light = "It is dark.\n";
      case -3..-2: light = "It is quite dark.\n";
      case -5: light = "It is very dark.\n"; break;
      case -100..-6:
        light = "It is completely dark.\n";
        desc = "";
        break;
    }
  }

  if (to->query_blind()) {
    light = "You cannot see.\n";
    desc = liv = item = exits = "";
  }

  fulldesc = file+light+peace+desc+"\n";

  message("room_description", fulldesc, this_object());

  if (strlen(smell))
    message("smell", smell, to);
  if (strlen(listen))
    message("listen", listen, to);
  if (strlen(exits))
    message("room_exits", "\n"+exits+"\n", to);
  if (strlen(liv))
    message("living_item", liv+"\n", to);
  if (strlen(item))
    message("inanimate_item", item, to);

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
  string ridingmsg = "", ridermsg = "", outmsg, inmsg;
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
    if (userp(horse)) {
      write("You are not in control to move around.");
      return;
    }
    else {
      ridingmsg = userp(horse) ? horse->query_cap_name() : indefinite_article(horse->query_name());
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
  if( (a = move(dest)) != MOVE_OK && a != MOVE_REDIRECTED ) {
    if(wizardp(this_player())) temp5 = "a = "+(string)a; else temp5="";
    write("You remain where you are. "+temp5);
    return;
  }
  if(adj = use_stealth("move")) {
    add_skill_points("stealth", adj);
    adj += query_stats("dexterity");
    add_sp(-1);
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
    if (strlen(inmsg)) inmsg = this_player()->query_cap_name()+" rides in"+inmsg+".";
    else inmsg = query_min();
    inv = all_inventory(environment(this_object()));
    for(i=0, bzbd = sizeof(inv); i<bzbd; i++) {
      if(!living(inv[i])) continue;
      if(inv[i] == this_object()) continue;
      if (member_array(inv[i], query_riders()) != -1) continue;
      if(adj) tmp = (adj-(int)inv[i]->query_skill("perception") - (effective_light(inv[i])*4));
      else tmp = 0;
      if(tmp > random(101)) continue;
      if(!msg || msg == "") message("mmin",query_mmin(),inv[i]);
      else message("min", inmsg, inv[i]);
    }

  }
  /*
    if (query_followers())
      move_followers(prev);
  */
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

string query_title() {
  object to = this_object();
  string str;
  string foo,fii;
  string tmp;

  if (invis && wizardp(this_object())) return 0;
  if (to->query_ghost()) {
    str = "%^RESET%^%^WHITE%^%^BOLD%^The ghost of "+ query_cap_name()+"%^RESET%^";
    return str;
  }
  if (strlen(tmp = to->query_disguised_name()) && (!query_verb() || to->can_disguise(query_verb())) ) return tmp;
  str = getenv( "TITLE" );
  if ( !str ) str = query_cap_name();
  else if ( !sscanf(str, "%s$N%s", foo,fii) )
    str = query_cap_name() + " " + str;
  else
    str = substr( str, "$N", query_cap_name() );
  return str;
}

string *query_id() {
  string *i = ::query_id();
  if (sizeof(query_disguised_id()))
    i += query_disguised_id();
  return i;
}

string query_short_linkdead() {
  if (!interactive(this_object()))
    return " (link-dead)";
  return "";
}

string query_short_riders() {
  string tmp;
  if (stringp(tmp = query_riders_list()) && strlen(tmp))
    return " (ridden by "+tmp+")";
  return "";
}

string query_short_riding() {
  string tmp;
  object tmpob;
  if (objectp(tmpob = query_riding())) {
    if (userp(tmpob))
      tmp = tmpob->query_cap_name();
    else
      tmp = indefinite_article(tmpob->query_name());
    return " (riding "+tmp+")";
  }
  return "";
}

string query_short_paintball() {
  string tmp;
  object tmpob;
  if ("/d/paintball/start"->query_paintball() &&
      tmpob = present("gun", this_object())) {
    tmp = tmpob->query_team();
    return " %^"+upper_case(tmp)+"%^["+capitalize(tmp)+"]%^RESET%^";
  }
  return "";
}

string query_short() {
  object to = this_object();
  string tmp;
  if (strlen(tmp = to->query_disguised_short()))
    return tmp;
  else
    return to->query_title();
}

string query_cap_name() {
  if (strlen(query_disguised_name()) && (!query_verb() || this_object()->can_disguise(query_verb()) ))
    return query_disguised_name();
  return ::query_cap_name();
}


// --- misc functions --- //

int is_player() { return 1; }
int is_linkdead() { return !interactive(this_object()); }

varargs nomask void die(mixed killer) {
  // 'die' hooks can return -1 to prevent death
  mixed ret = resolve_hooks("die", killer);
  if (ret == -1)
    return;
  death::die(killer);
  living::die(killer);
  if (this_object()->query_subrace() == "vampire")
    VAMPIRE_D->die(this_object());
}

int query_can_arena() { return 1; }
int query_arena() {
  object env = environment(this_object());
  if (env)
    return env->query_arena();
  return 0;
}

void set_maps(int i) { maps = i; }

int query_remorted() { return remorted; }
void set_remorted(int x) { remorted = x; }

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

void display_file(string str) {
  message("info", read_file(str), this_object());
}
int query_player_invis() {
  return pinvis;
}
void set_player_invis(int x) {
  pinvis = x;
}

//  Whit - No Idle String for Arches
void noidle(int i) {
  if(!archp(this_object())) return;
  no_idle=i;
}
int query_noidle() { return no_idle; }

void set_initial_ip(string ip) {
  if(geteuid(previous_object()) != UID_ROOT) return;
  InitialIp = ip;
}
string query_initial_ip() { return InitialIp; }

void autosave_on() {
  autosave_off=0;
}
void autosave_off() {
  autosave_off=1;
}

void set_autosave_silent(int x) { autosave_silent = (x ? 1 : 0); }
int query_autosave_silent() { return autosave_silent; }

void set_rname(string rname) {
  if(geteuid(previous_object()) != UID_ROOT && 
      geteuid(previous_object()) != UID_USERACCESS) return;
  real_name = rname;
}

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

int set_snoopable() {
  if (getuid(previous_object()) != UID_ROOT) return 0;
  if (snoop) {
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

int query_snoopable() { return snoop; }

string get_path() { return cpath; }

void set_path(string path) {
  int foo;

  if(geteuid(previous_object()) != geteuid(this_object()))
    return;

  foo = strlen(path) - 1;
  if (path[foo] == '/') path = path[0..foo-1];
  cpath = path;
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

string query_kingdom() { return KINGDOM_D->query_kingdom(query_name()); }

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
  add_quest_points(points);
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
  add_quest_points((int)call_other(ROOM_QUEST, "query_quest_points", str));
  quests += ({ str });
  log_file("quests", query_name()+" completed "+str+": "+ctime(time())+"\n");
  return 1;
}

void set_quest_points(int q) { _PlayerData["quest points"] += q; }
void add_quest_points(int q) { set_quest_points(query_quest_points() + q); }
int query_quest_points() { return _PlayerData["quest points"]; }

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

void set_married(string str) {
  if(current_marriage && sizeof(current_marriage)) return;
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

int query_undead() { return RACE_D->query_undead(query_race()); }

void set_race(string str) { 

  // remove resistances from previous race, if any
  if (race) {
    foreach (string resistance, int value in RACE_D->query_resistances(race)) {
      int r = translate_define(resistance, "damage_types.h");
      if (member_array(r, this_object()->query_all_resistances()) != -1)
	this_object()->add_resistance(r, -value);
    }
    foreach (string prop, mixed value in RACE_D->query_properties(race))
      this_object()->remove_property(prop);
  }

  race = str;
  set("race", str);
  LANG_D->init_languages(this_object());

  // set new resistances for this race
  foreach (string resistance, int value in RACE_D->query_resistances(race))
    this_object()->add_resistance(translate_define(resistance, "damage_types.h"), value);
  foreach (string prop, mixed value in RACE_D->query_properties(race))
    this_object()->set_property(prop, value);

  //this_player()->new_body(); removed cause it seemed to be causing a bug..... will look into it -Dab
}

string query_race() { return race; }

void convert_kills() {
  int *tmp = ({});
  int *k;

  k = query_kills();
  if (!sizeof(k) || intp(k[0])) return;

  foreach (int kill in k) tmp += ({ (int)PLAYER_D->add_kill(k[kill]) });
  set_kills(tmp);
}
void set_kills(int *k) { _PlayerData["kills"] = copy(k); }
void clear_kills() { set_kills( ({}) ); }
int *query_kills() { return copy(_PlayerData["kills"]); }
void add_kill(string str) {
  int x;

  if (!str) return;

  if (!sizeof(query_kills())) clear_kills();

  x = (int)PLAYER_D->add_kill(str);
  if (x != -1 && member_array(x, query_kills()) == -1)
    _PlayerData["kills"] += ({ x });
}
void remove_kill(int i) { _PlayerData["kills"] -= ({ i }); }

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

void set_killable(int x) {
  // remarked because imms should be able to handle this responsibly
  // if (!archp(this_object()) || archp(previous_object()))
  killable = x;
}

int query_killable() { return killable; }

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
    if(admp(this_object()))
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

void set_primary_char(string str) { if (!_PlayerData) _PlayerData = ([]); _PlayerData["primary char"] = str; }
string query_primary_char() { return (sizeof(_PlayerData) ? _PlayerData["primary char"] : 0); }


// --- guild functions --- //

string query_guild_position() {
  if (!query_guild()) return "None";
  return GUILD_D->query_actual_position(query_name(), query_original_guild());
}

void check_guild() {
  int o;
  if(catch(call_other(GUILD_D, "???"))) o=1;
  if(!o) if(GUILD_D->query_guild(this_object()->query_name())) 
    guild=GUILD_D->query_guild(this_object()->query_name());
  if(!o) if(!GUILD_D->query_position(this_object()->query_name())) guild=0;
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

