#include <locations.h>
#include <locations.h>
//      /std/user.c -- modified by seeker and rest of the crew
// all your #defines are belong to wiz
// all your base are belong to us (Inferno)
// no you are not leet enough

#undef NO_MSQL

#include <config.h>
#include <rooms.h>
#include <security.h>
#include <daemons.h>
#include <move.h>
#include <objects.h>
#include <money.h>
#include <flags.h>
#include <user.h>
#include <dirs.h>
#include <council.h>
#include <rest.h>

inherit "/std/user/more";

#define ALL_GUILDS ({ "darksoul", "guardian",\
        "lightsoul", "dragon", "assassin",\
        "berserker" })
#define ALL_LAW ({ "chromium" })

#define ONLINE 1
#define QUIT 2
#define NETDEAD 3
#define death_messages ({ "Silence overcomes the land as %s dies.",\
                            "A scream is heard across the land as %s dies.",\
                            "The world darkens for a second as %s dies.",\
                            "You hear a terrible howl as %s is slain.",\
                            "A flash of lightning mourns the death of %s.",\
                            "No stuck pig has squeeled like %s in death."})
#define vamp_death "Blood red winds and lightning ravage the multiverse "\
			"as %s is stricken down in battle."
#define OVERRIDE_IGNORE_MSG ({ "broadcast", "info", "more", "room_description", "room_exits","smell","listen","write","say", "system", "prompt", "inanimate_item", "living_item"})
int platinum, gold, electrum, silver, copper, level, dragon_level, ghost,
    crash_money, rolls, verbose_moves, autosave_off,birth, pk_flag, pinvis, 
    killable, remorted, wizpeace, failed_read;
static int disable, time_of_login, autosave;
static mixed arena;
mapping blocked, news, line_colours, gate_marks, mini_quests, proficiency, allowed_mount, outlaw;
status snoop, earmuffs;
string  real_name, email, ip, last_on, password, cpath, race, original_site;
private string position, primary_start;
private static string *channels;
string *quests, *mysites, *message, guild, married;
mixed *current_marriage, *divorced;
static string net_died_here, current_short;
static mapping term_info;
static object died_here;
object mounted, mounting;
int maps;

void set_maps(int i);
int query_peace_area();
void set_peace_area(int x);
int query_killable();
void set_killable(int x);
void update_channels();
void sync_msql(string name, int i);
int query_dragon_level();
int set_dragon_level(int x);
void add_exp(int x);
int query_blocked(string str);
int set_mini_quest(string str, int x, string desc);
int set_quest(string str);
int set_manual_quest(string str, int points);
string *query_mini_quests();
void reset_terminal();
void convert_kills();
mapping get_mini_quest_map();
string *query_quests();
private static void register_channels();
string *query_mysites();
void set_mysites(string *str);
void set_guild(string str);
void set_position(string pos);
void set_level(int x);
void fix_crash_victim();
nomask int query_level();
string query_guild();
void get_email(string e);
int query_ghost();
nomask void die();
void save_player(string name);

void set_maps(int i) { maps = i; }

int set_disquised_short(string str) { current_short = str; }
int remove_disquised_short() { current_short = ""; }
string query_disquised_short() { return current_short; }

int query_remorted() { return remorted; }
void set_remorted(int x) { remorted = x; }

void write_messages();
string query_email();
nomask string query_position();
void set_line_color(string line, string color);
string query_line_color(string line);


int query_allowedmount(object ob)
{
 if (allowed_mount[ob]) return 1;
   else return 0;
}
int query_read() { return failed_read; }
int set_allowedmount(object ob)
{
 allowed_mount[ob] = 1;
 call_out("remove_mount", 60, ob);
}
int remove_mount(object ob)
{
 map_delete(allowed_mount, ob);
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
int query_proficiency(string str)
{
 if (!str || str == "") return -1;
 return proficiency[str];
}

int set_proficiency(string str, int x)
{
 if (!str || str == "" || !x) return -1;
 proficiency[str] = x;
}

int force_me(string str)
{
 if (!this_player()) return ::force_me(str);
 
 if ((this_player()->is_player() && this_player()!=this_object()) &&
      archp(this_object()))
   return -5;
 return ::force_me(str);
}
void set_gate(mapping t)
{
 gate_marks = t;
}
mapping query_gate()
{
 if (!gate_marks) gate_marks = ([]);
 return gate_marks;
} 
void set_line_color(string line, string color)
{
 if (!line_colours) line_colours = ([]);
 line_colours[line] = color; 
}
string query_line_color(string line)
{
 if (!line_colours) return "";
 return line_colours[line];
}
void display_file(string str)
{
 message("info", read_file(str), this_object());
}
int query_player_invis()
{
 return pinvis;
}
void set_player_invis(int x)
{
 pinvis = x;
}
void remove_outlaw(string str) { map_delete(outlaw, str); }
void add_outlaw(string str, int i) {
   if (!str) return;
   if (outlaw[str]) outlaw[str] += i;
   else outlaw[str] = i;
}
void set_outlaw(string str, int i) {
   if (!str) return;
   if (outlaw[str]) outlaw[str] += i;
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
int query_outlaw(string str) { return outlaw[str]; }
int query_pk_flag()
{
 return pk_flag;
}
void set_pk_flag(int i)
{
 pk_flag = i;
}
void set_arena(mixed blah) { arena = blah; }
mixed query_arena() { return arena; }
int query_peace_area()
{
return wizpeace;
}
void set_peace_area(int x)
{
 wizpeace = x;
}
int query_dragon_level()
{
 return dragon_level;
}
int set_dragon_level(int x)
{
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

// wiz - blame it on him
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
         borg += (string)MAPPER_D->mapper(this_object())+" ";
      else
         borg += (string)env->query_long(0)+" ";
   }
     else
      borg += (string)env->query_short(0);
    
    message("room_description", borg, this_object());
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
      message("living_item", tmp, this_object());
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
    string here,going,temp1,temp2,temp3, temp4;
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
    if (query_mounting())
       {
        write("You are not in control to move around.");
        return;
        }
     if (query_mounted())
       {
        temp4 = msg;
        msg = "with "+query_mounted()->query_cap_name()+" on their back "+temp4+".";
        message("info","%^GREEN%^%^BOLD%^You ride "+temp4+" on "+this_player()->query_cap_name()+"'s back.", query_mounted());
        query_mounted()->move(dest);
// wiz Fri Mar 16 10:47:43 HST 2001
//      query_mounted()->force_me("look");
// forcing the user to look is lame, whoever put that there is a lamer
        query_mounted()->describe_current_room(query_mounted()->query_verbose());
// this is leeter, checks for brief/verbose, whoever put this in is leet (me) 
       }
    horse = query_riding();
    if (horse)
     horse->move(dest);   
     temp4 = msg;
       if (horse) {
        if (horse->is_living())
         msg = this_player()->query_cap_name()+" leaves on a mount "+temp4+".";
        else
         msg = this_player()->query_cap_name()+" leaves on "+
           a_or_an(horse->query_name())+" "+horse->query_name()+" "+temp4+".";
       }
    if( (a = move(dest)) != MOVE_OK ) {
	write("You remain where you are. a = "+(string)a);
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
    if(!query_invis() && !hiddenp(this_object())) {
      inv = all_inventory(prev);
      for(i=0, bzbd = sizeof(inv); i<bzbd; i++) {
	if(!living(inv[i]) || inv[i] == this_object()) continue;
	if(adj) tmp = (adj-(int)inv[i]->query_stats("wisdom"));
	else tmp = 0;
	if(tmp > random(101)) continue;
	if(effective_light(inv[i])-(query_skill("stealth")/17) < 0) continue;
/*
        temp4 = msg;
       if (horse)
         write(" temp4 = "+temp4);         
         msg = this_player()->query_cap_name()+" leaves on a mount "+temp4+".";
*/
	if(!msg || msg == "" && !horse) message("mmout", query_mmout(),inv[i]);
	else if (!horse) message("mout", query_mout(msg), inv[i]);
          else  message("mout", msg, inv[i]);
      }
      inv = all_inventory(environment(this_object()));
      for(i=0, bzbd = sizeof(inv); i<bzbd; i++) {
	if(!living(inv[i])) continue;
	if(inv[i] == this_object()) continue;
	if(adj) tmp = (adj-(int)inv[i]->query_stats("wisdom"));
	else tmp = 0;
	if(tmp > random(101)) continue;
	if(effective_light(inv[i])-(query_skill("stealth")/17) < 0) continue;
        if (horse) {
         if (horse->is_living())
          msg = this_player()->query_cap_name()+" rides in on a mount.";
         else
          msg = this_player()->query_cap_name()+" rides in on "+

            a_or_an(horse->query_name())+" "+horse->query_name()+".";
        }
	if(!msg || msg == "") message("mmin",query_mmin(),inv[i]);
	else if (!horse) message("min", query_min(), inv[i]);
         else message("min", msg, inv[i]);
      }
	
    }
    if (query_followers())
      move_followers(prev);
    if (!this_player()->query_riding()) 
      if (random(100) > 60) add_sp(-1);

   if (!present("blinder", this_player()))
    describe_current_room(verbose_moves);
   else {
    if (archp(this_player())) {
       present("blinder", this_player())->remove();
       describe_current_room(verbose_moves);
       return;
    }
    message("info", "The light of the world is hidden from your eyes.", this_player());
   }
}

void create() {
    more::create();
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
  
    if(previous_object() != this_object() &&
      (query_verb() != "quit" && this_player() != this_object())) return;
    destroy_autoload_obj();
    CHAT_D->remove_user(channels);
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
      if (this_player()->query_arena())
     {
      "/d/arena/bet"->arena_die(this_object());
      return 1;      
     }
   save_player( query_name() );
   sync_msql(query_name(), QUIT);
    crash_money = 0;
    if(query_followers()) clear_followers();
    if (this_object()->query_invis() &&
        !wizardp(this_object())) this_object()->set_invis();
    message("environment",
      "Reality suspended.  See you another time!", this_object());
    // tell_object(this_object(),"Reality suspended.  See you another time!\n");
    set_riding(0);
    say(query_cap_name() + " is gone from our reality.");
    log_file("enter", query_name()+" (quit): "+ctime(time())+"\n");
    PLAYER_D->add_player_info();
    this_player()->move("/d/standard/void");
    if (!this_object()->query_invis())
    {
   
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
/*	set_max_internal_encumbrance((stats["strength"] * 11)*2); */
}

void setup() {
    string tmp;
    string msg;
    
    set_living_name(query_name());
    seteuid(getuid());
    set_heart_beat(1);

// for the peace messages, this cant be null or it will screw up
// so assuming everyone starts in a peace area, this should be ok
// -wiz
    set_peace_area(1);

    load_autoload_obj();
    if(!stats) init_stats();
    if(!skills) init_skills(0);
   
    if(!proficiency) proficiency = ([]);
    if(member_array(query_position(), MORTAL_POSITIONS) == -1)
     enable_wizard();
    init_living();
    basic_commands();
    ip = query_ip_name(this_object());
    last_on = ctime(time());
    time_of_login = time();
    if(!body) new_body();
    if(!birth) birth = time();
    fix_limbs();
    tsh::initialize();
    if (this_object()->query_invis() &&
        !wizardp(this_object())) this_object()->set_invis();
    if (!this_object()->query_invis())
   {
    msg = (string)query_cap_name()+": exp:"+query_exp();
    CHAT_D->do_raw_chat("driver", "Enter <driver> "+msg);
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
	if(!((tmp = getenv("start")) && stringp(tmp) && move(tmp)==MOVE_OK))
	  move(ROOM_START);
	setenv("start", primary_start);
    }
    if(!stringp(tmp = getenv("TERM"))) setenv("TERM", tmp = "unknown");
    term_info = (mapping)TERMINAL_D->query_term_info(tmp);
    write_messages();
     call_out("save_player", 2, query_name()); 
    PLAYER_D->add_player_info();
    log_file("enter", query_name()+" (enter): "+ctime(time())+" from "+
	query_ip_name()+" with\n"+
	query_exp()+" exp, "+
	query_money("platinum")+" pl, "+
	query_money("gold")+" gd, "+
	query_money("electrum")+" el, "+
	query_money("silver")+" sl, "+
	query_money("copper")+" cp\n");
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
 // if (wizardp(this_player())) this_object()->force_me("home");
   // this_object()->force_me("wear all");
  this_object()->fix_vital_bonus();
 if (file_size("/failed/"+this_player()->query_name())!=-1)
  {
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
}
void autosave_on()
{
 autosave_off=0;
}
void autosave_off()
{
 autosave_off=1;
}
void heart_beat() {
    object *inv;
    int i;
    player_age += 2;
    ok_to_heal ++;

    if(!interactive(this_object())) {
        this_object()->net_dead();
    }
    if(disable) disable--;
    if (present("sleep_pillow", this_object()) &&
        this_object()->query_current_attacker()) {
      this_player()->force_me("wake");
    }
   if (!present("sleep_pillow", this_object())
       && query_rest_type()==1)
     set_rest_type(0);

    if (player_age > autosave && !autosave_off)  {
	message("environment", "Autosaving.", this_object());
	inv = all_inventory(this_object());
	for(i=0, crash_money =0; i<sizeof(inv); i++)
	    crash_money += (int)inv[i]->query_value()/2;
	save_player(query_name());
	autosave = player_age + 500;
    }
    if(!disable && !query_rest_type()) continue_attack();
                                       
    if (magic_round) magic_round--;
    if(player_age > ok_to_heal) do_healing(calculate_healing());
    else calculate_healing();
/*  
  if(query_idle(this_object()) >= 3600 &&
       !wizardp(this_object()) ) {
	this_object()->move_player(ROOM_IDLE_SHOP);
	this_object()->force_me("sell all");
	this_object()->force_me("quit");
    }
*/
    if(query_invis() && query_sp()<0 && !wizardp(this_player()) ) set_invis();

    if (this_object()->query_hp() < 1 && !this_object()->query_ghost())
      {
//       call_out("die", 0);
       die();
      this_player()->fix_vital_bonus();
       save_player(query_name());
      }
}

void change_net_died_here(string str)
{
 if (!str || str==0) return 0;
 net_died_here = str;
}

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
      this_object()->force_me("dismount");

   CHAT_D->remove_user(channels);
   channels = ({});
   net_died_here = file_name(environment(this_object()));
   save_player(this_object()->query_name());
   this_object()->set_rest_type(0);
    if (!this_object()->query_invis())
   {
   /* msg = (string)this_object()->query_cap_name() + " is now link-dead.";
    CHAT_D->do_info_line(msg); */
    msg = (string)query_cap_name()+": exp:"+query_exp();
    CHAT_D->do_raw_chat("driver", "Inactive <driver> "+msg);

    } 
   if (!this_object()->query_invis())
   {
    message("other_action", sprintf("%s suddenly disappears into a sea of "
      "irreality.", query_cap_name()), environment(this_object()), ({ this_object() }));
    }
    move(ROOM_FREEZER);
    if(query_snoop(this_object()))
      tell_object(query_snoop(this_object()), capitalize(query_name())+
	" has gone net-dead.");
    set_heart_beat(0);
}

void restart_heart() {
    string dead_ed;
    string msg;

    sync_msql(query_name(), ONLINE);
    message("write", (wizardp(this_object()) &&
      file_size(dead_ed = user_path(getuid())+"dead.edit") > -1 ?
      "\nYour edit file was saved as: "+dead_ed+"\n" :
      "Reconnected."), this_object());
    set_heart_beat(1);
    if(net_died_here) this_object()->move_player(net_died_here);
    else this_object()->move_player(ROOM_START);
    net_died_here = 0;
    if (!this_object()->query_invis())
   {
    msg = (string)query_cap_name()+": exp:"+query_exp();
    CHAT_D->do_raw_chat("driver", "Active <driver> "+msg);

    say(query_cap_name()+" has rejoined our reality.");
}
    register_channels();
    save_player(this_object()->query_name());
}


nomask void die() {
    object ob;
    object corpse;
    object money_ob;
    object *stuff;
    string *currs;
    int tmp;
    int i;
    
  
   if (this_player()->query_arena()) 
     {
      "/d/arena/bet"->arena_die(this_player());
      return;
     }
   stuff = all_inventory(this_object());
   tmp = sizeof(stuff);
   while(tmp--)
    {
     if (function_exists("set_die", stuff[tmp]) )
       {
        stuff[tmp]->set_die();
        return;
       }
    }
   stuff = ({});
   tmp = 0;         
    if(wizardp(this_object()) && !query_killable()){
      message("death", "You are immortal and cannot die.", this_object());
      return;
     }
   if (this_object()->query_race() == "archangel" && random(100) >= 60) {
     message("death", "%^BOLD%^A hushed silence fills the realms at the would-"
       "be death of "+this_object()->query_cap_name()+".%^RESET%^", users());
     message("death", "%^YELLOW%^"+this_object()->query_cap_name()+" skyrockets "
       "high into the sky, ascending into the heavens.%^RESET%^", users());
     this_object()->set_hp(10);
     this_object()->add_poisoning(-9999);
     this_object()->move("/wizards/inferno/angel/east");
     this_object()->set_sp(0);
     this_object()->set_mp(-200);
     this_object()->set_paralyzed(query_level() + 100, "%^YELLOW%^"
       "Your body is recovering from severe shock.");
     return;
   }
    i = random(sizeof(death_messages));
    if (i > 0) i--;
    if (this_object()->query_race() != "vampire") {
      message("shout", "%^RED%^%^BOLD%^"+
       sprintf(death_messages[i], this_object()->query_cap_name()),users());
    } else {
      message("shout", "%^RED%^%^BOLD%^"+
       sprintf(vamp_death, this_object()->query_cap_name()),users());
    }
  if (query_riding()) this_object()->force_me("dismount");
  if (this_object()->query_race() != "vampire")
  message("die", read_file("/news/ghost"), this_object());
  else
  message("die", read_file("/news/vamp"), this_object());
  ob = this_object();
  died_here = environment(ob);
  if (this_object()->query_race() != "vampire") {
  message("death", "You die.\nYou feel the sensations of nothingness " +
   "as you rise above your corpse.\nYou arrive at a destination in a reality " +
  "not like your own.", this_object());
  message("death", query_cap_name()+ " dies a horrible death.",
    environment());
  } else {
  message("death", "A blinding flash of pain sears through your body, "
   "rendering you unconcious. Your eyes flicker and you find yourself in "
   "a strange place.", this_object());
  message("death", query_cap_name()+ " disapears in a flash of "
   "crimson winds and lightning.", environment());
  }
//  tell_room(environment(this_object()), query_cap_name()+" dies a horrible death.\n", ob);
  if((int)this_object()->query_level() > 3) {
    this_object()->add_exp(-((int)this_object()->query_exp()/4));
    this_object()->reduce_stats();
    this_object()->fix_vital_bonus();
    reduce_skills();

   if (this_object()->query_level() >= 40)
      set_level(query_level()-3); 
   else 
   if (this_object()->query_level() >= 28)
     if (random(20) != 20) set_level(query_level()-2);
    else
   if (this_object()->query_level() >= 14)
     if (random(20) > 5) set_level(query_level()-1);
   else
  if (this_object()->query_level() >= 10) 
    {
     if (random(10) < 7) set_level(query_level()-1);
    }   
    this_player()->fix_vital_bonus(query_level());
    if(query_level() < 20)setenv("TITLE", (string)ADVANCE_D->get_new_title(this_object()));
   }
   if (this_object()->query_race() != "vampire") {
    corpse = new(OB_CORPSE);
    corpse->set_name(query_cap_name());
    corpse->set_race(this_player()->query_race());
    corpse->move(environment(this_object()));
    corpse->is_player_corpse(1);
    money_ob = new("/std/obj/coins");
    currs = query_currencies();
    for(i=0, tmp= sizeof(currs); i<tmp; i++) {
	money_ob->set_money(currs[i], query_money(currs[i]));
	add_money(currs[i], -query_money(currs[i]));
    money_ob->move(corpse);
    stuff = all_inventory(this_object());
    for(i=0;i<sizeof(stuff);i++)
    if(!stuff[i]->drop()) stuff[i]->move(corpse);
    }
   }
    if (this_object()->query_race() != "vampire")
    this_object()->move("/d/standard/death/death_room");
    else { this_object()->move("/d/aciri/vdeath/start");
	   this_object()->force_me("look");
// inferno,
// maybe you should use the line below as opposed to force_me("look"),
// they could be paralyzed or something, and not be able to look?
//  this_object()->describe_current_room(this_object()->query_verbose());
// unless, of course.. you want that kind of effect. just a friendly suggestion =)
// -wiz
	   this_object()->set_sp(10);
	   this_object()->set_mp(random(10));
           this_object()->set_hp(4); }
    cease_all_attacks();
    this_object()->new_body();
   if (this_object()->query_poisoning() > 0)
    add_poisoning(-(this_object()->query_poisoning()));
    if (this_object()->query_race() != "vampire")
    ghost = 1;
    if (this_object()->query_race() == "vampire") {
      stuff = all_inventory(this_object());
      i = sizeof(stuff);
      while(i--) {
	if (stuff[i]->is_virus()) stuff[i]->remove();
      }
    }
    save_player(query_name());
    PLAYER_D->add_player_info();
    this_player()->fix_vital_bonus();
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
	if(mail_stat["unread"]) {
	  message("login", sprintf("\n        >>> %d of your %d %s are "
	    "unread! <<<", mail_stat["unread"], mail_stat["total"],
	    (mail_stat["total"]>1 ? "letters" : "letter")), this_object());
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
  st = "";
    if (interactive(this_object()))
	
       {
 if (query_mounted()) st += " (mounted by "+query_mounted()->query_cap_name()+")";
 if (query_mounting()) st += " (mounting "+query_mounting()->query_cap_name()+")";
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
    if(geteuid(previous_object()) != UID_ROOT &&
      geteuid(previous_object()) != UID_USERACCESS) {
     message("my_action", "You aren't authorized to check this information.",
       this_object());
     return ({});
   }
  return commands();
}
 
nomask string query_position() { return position; }

nomask int query_level() { return level; }

void set_position(string pos) {
   if (geteuid(previous_object())=="seeker") 
{
}
else
    if(geteuid(previous_object()) != UID_ADVANCE &&
      geteuid(previous_object()) != UID_ROOT)  return;
   
 
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
    if(position == "high mortal" && level < 15) {
	position = "player";
	search_path -= ({ DIR_HM_CMDS });
	CASTLE_D->disable_high_mortal(this_object());
	set_env("start", ROOM_START);
	set_env("TITLE", "Mortal $N the fallen high mortal");
    }
    return;
}


int set_earmuffs() {
    if( earmuffs )
    {
	earmuffs = 0;
	message("my_action", "Your earmuffs are now off.",
	  this_object());
    }
    else
    {
	message("my_action", "Your earmuffs are now on.", this_object());
	earmuffs = 1;
    }
    return earmuffs;
}

void receive_message(string msg_class, string msg) {
    string pas;
    string str, pre, post;
    int x;

    if (!interactive(this_object())) return;
    if (query_prompt())
      {
       set_prompt(0);
       message("prompt", "\n", this_object());
      }
    if(!stringp(str=getenv("SCREEN"))) str = "79";
    x = atoi(str);
      if(msg_class != "Nsystem" &&
         msg_class != "snoop"   &&
         msg_class != "Nwrite"  &&
         msg_class != "prompt"  &&
         msg_class != "talk"    &&
         msg_class != "no_wrap") msg = wrap(msg, x);
    if (p_ver && msg_class != "html") msg = modify_output(msg);
    if(msg_class == "system" || msg_class == "help" || msg_class == "more"){
      receive(msg);
      return;
    }
    if (msg_class == "info_line" && query_blocked("info")) return;
    if(query_blocked(msg_class) &&
      member_array(msg_class, OVERRIDE_IGNORE_MSG) == -1) return;
    switch(msg_class) {
      case "room_exits": msg = "%^GREEN%^"+msg; break;
      case "smell": msg = "%^ORANGE%^"+msg; break;
      case "listen": msg = "%^CYAN%^"+msg; break;
      case "snoop":
        pas = "%^RED%^%^BOLD%^%%^RESET%^";
        msg = TERMINAL_D->no_colours(msg);
        msg = pas+msg;
        break;
      case "tell": 
	if(sscanf(msg, "%s:%s", pre, post) == 2)
	  msg = "%^BOLD%^RED%^"+pre+":%^RESET%^"+post;
	break;
      case "shout":
	if(sscanf(msg, "%s:%s", pre, post) == 2)
	  msg = "%^BOLD%^BLUE%^"+pre+":%^RESET%^"+post;
	break;
      case "mmin": case "min": case "mmout": case "mout":
	msg = "%^BOLD%^GREEN%^"+msg; break;
      case "living_item": msg = "%^BOLD%^RED%^"+msg; break;
      case "inanimate_item": msg = "%^BOLD%^MAGENTA%^"+msg; break;
    }
    if(!term_info) reset_terminal();

/*
    for(i=0, max=sizeof(words=explode(msg, "%^")); i<max; i++)
      if(term_info[words[i]]) words[i] = term_info[words[i]];
*/
   msg = terminal_colour(msg, term_info);
 //   receive(implode(words, "")+term_info["RESET"]);
   receive(msg+term_info["RESET"]);
}

static void receive_snoop(string str) 
{ 
receive_message("snoop", str);
}

void catch_tell(string str) {

    if(earmuffs) {
      if(sscanf(str, "%*s shouts %*s")) return;
    }

    receive(str);
}

void set_guild(string str) {
    guild = str;
    if(!guild) guild = str;
}

string query_guild() { return guild; }

void set_rolls(int x) { rolls = x; }

int query_rolls() { return rolls; }

void set_blocked(string str) {
    if(!blocked) blocked = ([]);
    blocked[str] = !blocked[str];
    if(blocked[str]) message("info", "You are now blocking "+str+".",
      this_object());
    else message("info", "You are no longer blocking "+str+".",this_object());
}

int query_blocked(string str) {
    if(!blocked) blocked = ([]);
    if(blocked["all"]) return blocked["all"];
    else return blocked[str];
}

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
int set_manual_quest(string str, int points)
{
 if (!quests) quests = ({});
 if (member_array(str, quests) != -1) return 0;
 player_data["general"]["quest points"] += points;
 quests += ({ str });
 log_file("quests", query_name()+" completed "+str+"\n");
 return 1;
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
    save_player(query_name());
}

int query_ghost() { return ghost; }
int set_ghost(int i) { ghost =  i; }
int query_quest_points() {
    if(!player_data["general"]["quest points"]) return 0;
    else return player_data["general"]["quest points"];
}

void set_disable(int x) { 
    if(x) disable = x;
    else disable = 1;
}

int query_disable() { return disable; }

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

void reset_terminal() {
    term_info = (mapping)TERMINAL_D->query_term_info(getenv("TERM")); 
}

void set_name(string str) {

    if(geteuid(previous_object()) != UID_ROOT) return;

    ::set_name(str);
}

nomask string *query_channels() { return channels; }

void update_channels() { register_channels(); }

void register_channels() {
//used to be static private void funcion
    channels = ({ "newbie", "auction" });
    if(wizardp(this_object()))
      channels += ({ "cleric","fighter","kataan","mage","monk","rogue","clergy",
                     "pyromancer","necromancer","wizard","druid","scout",
                     "sorceror","illusionist","knight","warrior","paladin",
                     "antipaladin","ranger","assassin","thief","thug",
                     "priest","gypsy","bard","jester","wanderer","swashbuckler" });
    else channels += (query_class() ? ({ query_class() }) : ({}));
    if (query_name()=="wiz") channels += ({ "driver" });
    if (member_array(query_name(), ALL_LAW) != -1 || wizardp(this_player()))
       channels += ({ "reg" });
    if (query_guild()) channels += ({ query_guild() });
    if (query_subclass()) channels += ({ query_subclass() });
    if (wizardp(this_object())) channels += ALL_GUILDS;
    if(wizardp(this_object()) || high_mortalp(this_object())) channels += ({ "hm" });
    else if(query_level() < 6) channels += ({ "newbie" });
    if(wizardp(this_object())) channels += ({ "cre", "intercre", "pd", "driver"});
    channels += ({ "gossip" });
    if(wizardp(this_object()) || this_object()->query_level() > 49)
         channels += ({ "elite" });
    if(archp(this_object())) channels += ({ "admin" });
    if(this_object()->query_race() == "demon" || wizardp(this_object())) channels += ({ "demon" });
    if(this_object()->query_race() == "lich" || wizardp(this_object())) channels += ({ "lich" });
    if(wizardp(this_object()) || leaderp(this_object()))
	  channels += ({ "council" });
    CHAT_D->add_user(channels);
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
    this_object()->remove();
}

void set_killable(int x) { killable = x; }

int query_killable() { return killable; }

string query_cap_name() {
   object ob;
   if (!(ob = present("paradox_-ring-_paradox", this_object())))
     return ::query_cap_name();
   if (!ob->query_worn() || ob->query_cap() == "" || !ob->query_cap())
     return ::query_cap_name();
   return ob->query_cap();
}
void save_player(string name)
{
 ::save_player(name);
 sync_msql(name ,ONLINE);
}
void sync_msql(string name, int i)
{
 string SET, birthd;
 int c;
 mixed *set;
#ifdef NO_MSQL
 return; 
#endif
 if (birth) {
 birthd = "Birthday: "+capitalize(month(birth))+" "+
          date(birth)+" "+((year(birth)-18))+" BN";
 SET = "";
 SET += "player_title='"+TERMINAL_D->no_colours(query_title())+"',";
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
 SET += "player_description='not implemented',";
 SET += "player_state="+i;
 if (MSQL_D->msql_player_exist_in_database(name)) {
  MSQL_D->msql_update("mud", "player_t", SET, "player_name='"+name+"'");
 } else {
 set = ({ query_name(), query_title(), (query_race()?query_race():"none"),query_level(),
          query_al_title(), (query_class()?query_class():"none"), query_subclass(), query_gender(),
          (query_married()?query_married():"single"), 
          (query_guild()?query_guild():"none"), sizeof(query_quests()),
          (18 + (query_age()/4320000)), birthd, "not implemented", i });
 c =  MSQL_D->msql_insert("mud", "player_t", set);
  if (this_object()->query_name()=="seeker") write(c);
  }
}
}
