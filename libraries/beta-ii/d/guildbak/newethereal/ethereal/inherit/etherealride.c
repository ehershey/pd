//      /std/ride.c plus monster.c to remove the "monster" id
//      from the Nightmare mudlib
//      inheritable code for npc's
//      created by Descartes of Borg september 1992
//      added set_unique() - seeker
#include <std.h>
#include <move.h>
#include <objects.h>
#include <daemons.h>
#include <ether.h>

inherit LIVING;


int ethride,pet;
string pet_join_msg, pet_part_msg;
static object pl;

object tmp, exp_share, petowner,petname;
static status heart_beat_on;
float exp_share_perc;
int level, patrol, pon, pcnt, dragon_level, unique;
string *pdirs;
static int speed;
static int moving;
mapping emotes, speech, spells;
string body_type;
private static mixed __Die;
int swarm;
object __Rider;
int riding;
string mount, unmount;
int __Ride(string str);
int query_rideable();
int set_riding(int x);
int set_rider(object ob);
object query_rider();
void set_exp_share(object ob, float x);
void set_swarm(int x);
void die(object ob);
void set_unique(int x);
int test_heart();
void set_spell_chance(int x);
void set_spells(string *arr);
void set_race(string str);
void set_dragon_level(int x);
int query_dragon_level();
void set_patrol(int x, string *dirs);
void do_patrol();
string return_chat();
string return_achat();
void set_exp(int x);
void set_level(int x);
int query_level();
void move_around();
void set_emotes(int x, string *arr, int att);
void create() {
    ::create();
    emotes = ([]);
    speech = ([]);
    spells = ([]);
    enable_commands();
    seteuid(getuid(this_object()));
    init_limb_data();
    init_stats();
    init_skills(0);
    init_living();
    set_heart_beat(heart_beat_on = 1);
    speed = 0;
    set_gender("neuter");
    riding = 0;
    pl = this_player();
    petname = this_player();
    set_level(7);
    set_gender("male");
    set_alignment(300);
    set_property("no bump", 1);
    set_race("centaur");
    set_heart_beat(1);

}
int set_mount_message(string str)
{
    mount = str;
}
int set_unmount_message(string str)
{
    unmount = str;
}
int __Dismount(string str)
{
    if (__Rider != this_player()) return 0;
    if (!unmount)
	write("You dismount "+ capitalize(query_short())); 
    else
	write(unmount);
    say(this_player()->query_cap_name()+" dismounts "+capitalize(query_short())+".");
    __Rider = 0;
    this_player()->set_riding(0);
    return 1;
}
void set_ethride(int ethint) {
    ethride = ethint;
}
void set_ethpet(int ethintpet) {
    pet = ethintpet;
}
void set_petjoin(string str) {
    pet_join_msg = str;
}
void set_petpart(string str) {
    pet_part_msg = str;
}
int __Ride(string str)
{
    object oi;

    if (!str || str=="")
    {
	write("Ride what?");
	return 1;
    }
    oi = present(str, environment(this_player()));
    if (oi != this_object()) return 0;

    if (query_rider()) 
    {
	write("Somebody is already mouting that.");
	return 1;
    }

    if (this_player()->query_riding() || this_player()->query_mounting())
    {
	write("You are already riding.");
	return 1;
    }

    if (ethride != 1) {
	write("This pet is not mountable.\n");
	return 1;
    }
    if (petowner == this_player() && this_player()->query_guild() == "ethereal" ) {
	write("You mount your pet.\n");
	pl = this_player();
	petowner = pl;
	pet = 0;
    }
    if (petowner != this_player() && pet == 1 && this_player()->query_guild() == "ethereal") {
	write("You claim this pet as your own.\n");
	pl = this_player();
	petowner = pl;
	pet = 0;
    }
    if  (this_player()->query_guild() != "ethereal")  {
	if (this_player()->query_guild()) {
	    write("%^RED%^"+petname->query_cap_name()+" %^BOLD%^PUNCHES%^RESET%^%^RED%^ you in the face! \n%^RESET%^"
	      "%^CYAN%^"+petname->query_cap_name()+":%^RESET%^ "+this_player()->query_guild()+" huh? You're"
	      " way too weak to mount me!"
	    );
	    say("%^RED%^"+petname->query_cap_name()+" %^BOLD%^PUNCHES%^RESET%^%^RED%^ "+this_player()->query_cap_name()+" in the face! \n%^RESET%^"
	      "%^CYAN%^"+petname->query_cap_name()+":%^RESET%^ "+this_player()->query_guild()+" huh? You're"
	      " way too weak to mount me!"
	    );

	}
	if (!this_player()->query_guild()) {
	    write("%^RED%^"+petname->query_cap_name()+" %^BOLD%^PUNCHES%^RESET%^%^RED%^ you in the face! \n%^RESET%^"
	      "%^CYAN%^"+petname->query_cap_name()+":%^RESET%^ You are way too weak to mount me!"
	    );
	    say("%^RED%^"+petname->query_cap_name()+" %^BOLD%^PUNCHES%^RESET%^%^RED%^ "+this_player()->query_cap_name()+" in the face! \n%^RESET%^"
	      "%^CYAN%^"+petname->query_cap_name()+":%^RESET%^ You are way too weak to mount me!"
	    );
	}
	return 1;
    }
    if ( petowner != this_player() ) {
	write("%^CYAN%^"+petname->query_cap_name()+": %^RESET%^I cannot be mounted by you. "
	  "You are not my owner. Speak to "+petowner->query_cap_name()+".\n");
	return 1;
    }



    this_player()->set_riding(this_object());
    if (!mount)
	write("You mount "+capitalize(this_object()->query_short())+".");
    else
	write(mount);
    message("info", this_player()->query_cap_name()+ " mounts "+ capitalize(this_object()->query_short())+".\n", environment(this_player()), this_player());
    __Rider = this_player();
    return 1;
}
int query_rideable() { return 1; }

int set_riding(int x)
{
    riding = x;
}

int set_rider(object ob)
{
    if (__Rider) return 1;
    __Rider = ob;
    return 0;
}

object query_rider()
{
    return __Rider;
}

void set_exp_share(object ob, float x)
{
    exp_share = ob;
    exp_share_perc = x;
    set_exp(0);
}
void add_exp(int x)
{
    if (exp_share)
	exp_share->add_exp( to_int(x * 75/100)  );
    return ::add_exp(0);
}
void set_unique(int x)
{
    unique = x;
}
void set_swarm(int x)
{
    swarm = x;
}
int query_heart() { return query_heart_beat(); }
void init() {
    mixed tmp;
    ::init();
    add_action("__Ride", "ride");
    add_action("__Dismount", "dismount");
    add_action("cmd_follow", "petownmaster");
    add_action("cmd_die", "die");

    if(!heart_beat_on) set_heart_beat(heart_beat_on = 1);
    if(this_player()->query_invis()) {
	if(wizardp(this_player())) return;
	if(random(101) < (int)this_player()->query_level()) return;
    }
    if(this_player()->query_ghost()) return;
    if(this_player()->is_player()) {
	if(tmp = query("aggressive")) {
	    if(intp(tmp) && tmp > (int)this_player()->query_stats("charisma"))
		kill_ob(this_player(), 0);
	    else if(stringp(tmp)) call_other(this_object(), tmp);
	}
    }
}
void cmd_die(string str) {
    if (!str) return 0;
    if ((this_player() == petowner) && (str == petname->query_name())) {

	message("info",""+petname->query_cap_name()+" frowns.\n"
	  ""+petname->query_cap_name()+" finds a vial of poison and quaffs it down.\n"
	  ""+petname->query_cap_name()+" dies.\n",environment(this_object()));	
	this_object()->remove();
	return 1;
    }
}
void set_name(string str) {
    set_living_name(str);
    ::set_name(str);
    if(query_level() < 1) set_level(1);
}
void heart_beat() {
    string *langs;
    string lang, pre;
    object *ob;
    int i;
    if (!this_object()) return;
    if (this_object()->query_rest_type() && this_object()->query_current_attacker())
	this_object()->force_me("stand");
    if (swarm) {
	ob = all_inventory(environment(this_object()));
	i = sizeof(ob);
	while(i--)
	{
	    if (ob[i]->query_current_attacker() &&
	      member_array(ob[i], this_object()->query_attackers())==-1 &&
	      ob[i]->is_player())
		this_object()->force_me("kill "+ob[i]->query_name() );
	}
    }
    continue_attack();
    //   if (query_hp()<1) die(this_object()->query_last_attacker());

    player_age +=2;
    ok_to_heal ++;
    if(player_age > ok_to_heal) do_healing(calculate_healing());
    else calculate_healing();
    if (pdirs) do_patrol();
    if(speed && moving >= speed) move_around();
    else moving++;
    if (query_current_attacker() && query_rest_type()==1)
	this_object()->force_me("wake");
    if(!query_current_attacker()) pre = "";
    else pre = "attack ";
    if(emotes[pre+"chance"] > random(100))
	if(this_object())
	    message("environment", emotes[pre+"msg"][random(sizeof(emotes[pre+"msg"]))],
	      environment(this_object()), ({ this_object() }) );
    if(sizeof(langs = keys(speech))) {
	lang = langs[random(sizeof(langs))];
	if(this_object() && random(100) < speech[lang][pre+"chance"])
	    this_object()->force_me("speak in "+lang+" "+
	      speech[lang][pre+"msg"][random(sizeof(speech[lang][pre+"msg"]))]);
    }
    if (magic_round) magic_round--;
    if (!environment(pl)) this_object()->remove();
    if(pl) {
	if (environment(this_object()) != environment(pl)) {
	    message("info", (string)this_player()->query_cap_name()+" "+pet_part_msg+" "+pl->query_cap_name()+"\n", environment(this_object()));
	    this_object()->move(environment(pl));
	    message("info", (string)this_player()->query_cap_name()+" "+pet_join_msg+"\n", environment(pl));
	}
    }

    if(!test_heart()) set_heart_beat(heart_beat_on = 0);
}


int cmd_follow(string str) {
    string followwho;
    if (!str || sscanf(str, "allow %s", followwho)!=1) return;
    if (pet != 1 && pl) { 
	message("info","%^CYAN%^"+petname->query_cap_name()+": %^RESET%^I'm "+pl->query_cap_name()+"'s, go away!\n",environment(this_object())); 
	return 1;
    }
    if (!present(followwho, environment(this_object()))) return;
    pl = present(followwho, environment(this_object()));
    message("info","%^CYAN%^"+petname->query_cap_name()+": %^RESET%^Hi "+pl->query_cap_name()+".  I am now yours\:\) \n",environment(this_object()));
    pet = 0;
    petowner = pl;
    return 1;
}



void die(object ob) {
    object money_ob;
    object *contents;
    int i, tmp_size;
    string *currs;

    set_heart_beat(0);
    if(functionp(__Die)) {
	if(!((int)((*__Die)(ob)))) return;
    }
    else if(stringp(__Die))
	message("other_action",__Die,environment(this_object()),({this_object()}));
    else message("other_action", capitalize(query_name())+
	  " drops %^RED%^dead%^RESET%^ before you.", environment(this_object()),
	  ({ this_object() }));
    if (query_property("no_corpse")!=1)
    {
	tmp = new(OB_CORPSE);
	tmp->set_name(capitalize(query_name()));
	tmp->copy_body(this_object());
	tmp->move(environment(this_object()));
	tmp_size=sizeof(currs=query_currencies());
	if(tmp_size) {
	    money_ob = new("/std/obj/coins");
	    for(i=0; i<tmp_size; i++) {
		money_ob->add_money(currs[i], query_money(currs[i]));
		add_money(currs[i], -query_money(currs[i]));
	    }
	    money_ob->move(tmp);
	}
	contents = all_inventory(this_object());
	for(i=0;i<sizeof(contents);i++) {
	    if(contents[i]->move(tmp)) 
		if(!contents[i]->remove())
		    destruct(contents[i]);
	}
    }
    set_heart_beat(0);
    cease_all_attacks();
    this_object()->remove();
}
int query_npc() { return 1; }
void set_id(string *str)
{
    /* Didnt work....
     if(previous_object() != get_object("/std/ride"))
     str += ({ "monster" });
    */
    ::set_id(str);
}
varargs void move_player(mixed dest, string message) {
    object prev;
    string here,going,temp1,temp2,temp3;
    prev = environment(this_object());
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
		dest = going+"/"+temp1;
	    }
	}
    }
    if(move(dest) == MOVE_OK) {
	say("%^GREEN%^%^BOLD%^"+query_cap_name() + " arrives.%^RESET%^",this_object());
	tell_room(prev, "%^GREEN%^%^BOLD%^"+query_cap_name() + " leaves " + message + ".");
    }
}
/* Call_out taken out of move_around by Hanse 1/4/93 */
void move_around() {
    string *exits, exit;
    if(!this_object()) return;
    if (environment(this_object())->query_exits()==({})) return;
    if(environment(this_object()))
	exits = (string*)environment(this_object())->query_exits();
    else exits = 0;
    if (exits)   exit = exits[random(sizeof(exits))];
    if (exits)
	this_object()->force_me(exit);

    moving=0;
}
// Set_Patrol by seeker May 26 2000
void set_patrol(int x, string *dirs)
{

    if (!x)
	return;
    if (!dirs)
	return;
    pon = 0;     // direction currently on..
    pcnt = 0;    // game ticks waiting for move
    pdirs = dirs; // directions
    patrol = x;  // speed of patrolling
}
void do_patrol()
{
    if (pcnt < patrol)
    {
	pcnt++;
	return;
    }
    pcnt = 0;
    this_object()->force_me(pdirs[pon]);
    pon++;
    if (pon > sizeof(pdirs)-1)
    {
	pon = 0;
    }
}
void set_moving(int i) { moving = i; }
void set_speed(int i) { speed = i; }

string query_short()
{
    string seeker;
    int i;
    seeker = ::query_short();
    i = to_int(percent(query_hp(), query_max_hp()));
    if (i < 35)
    {
	seeker += " (dying)";
    } else
    if (i < 65)
    {
	seeker += " (bleeding)";
    } else
    if (i < 95)
    {
	seeker += " (injured)";
    }

    if (__Rider) seeker += " (ridden by "+__Rider->query_cap_name()+")";

    return seeker;
}
void set_level(int x) {
    float calc;
    if (!x) x = 1;
    level = x;
    calc = x;
    set_overall_ac(x + 9);
    set_skill("melee", (x*3));
    set_skill("attack", (x*4));
    set_skill("defense", (x*4));
    set_skill("blade", (x*4));
    set_skill("knife", (x*4));
    set_skill("blunt", (x*4));
    set_skill("projectile", (x*4));
    set_skill("two handed", (x*3));
    set_skill("axe", (x*4));
    set_skill("flail", (x*4));
    set_skill("magic attack", (x*4));
    set_skill("magic defense", ((x*2)+(x/2)));
    if (x <= 50) {
	set_stats("constitution", to_int(10+(4.5*pow(2.0, calc/15.0))));
	set_stats("strength", to_int(10+(4.5*pow(2.0, calc/15.0))));
	set_stats("intelligence", to_int(10+(4.5*pow(2.0, calc/15.0))));
	set_stats("wisdom", to_int(10+(4.5*pow(2.0, calc/15.0))));
	set_stats("dexterity", to_int(10+(4.5*pow(2.0, calc/15.0))));
	set_stats("charisma", to_int(10+(4.5*pow(2.0, calc/15.0))));
    }
    else {
	set_stats("constitution", to_int(35+(5*pow(2.0, calc/25.0))));
	set_stats("strength", to_int(35+(5*pow(2.0, calc/25.0))));
	set_stats("intelligence", to_int(35+(5*pow(2.0, calc/25.0))));
	set_stats("wisdom", to_int(35+(5*pow(2.0, calc/25.0))));
	set_stats("dexterity", to_int(35+(5*pow(2.0, calc/25.0))));
	set_stats("charisma", to_int(35+(5*pow(2.0, calc/25.0))));
    }
    if (x <= 20)
    {
	set_max_hp((x * (x-3))*4/2);
    }
    if ( x <= 10)
    {
	set_max_hp( (x * 20) + 64);
    }
    if (x >= 20)
	set_max_hp((x * (x-3))*4/2);
    set_hp(query_max_hp());
    set_max_mp(query_max_hp());
    set_mp(query_max_mp());
    set_max_sp(x*20);
    set_sp(query_max_sp());
    if(x > 24)
	set_exp( 2000 * x );
    else
	set_exp( (x*x*x*53) / 16 );
}
int query_level() { return level; }
// Added by Valodin, June 28, 1993
// Sets the body type to a certain race using the race daemon
void set_body_type(string str) {
    mapping monster_bod;
    int mag, max_mag;
    string *mon_limbs;
    int i, max;
    if(!str || !RACE_D->is_monster_race(str))
	str = "human";
    mag = query_mp();
    max_mag = query_max_mp();
    init_limb_data();
    monster_bod = (mapping)RACE_D->monster_body(str, query_max_hp());
    for(i = 0, max = sizeof(mon_limbs = keys(monster_bod)); i < max; i++)
	add_limb(mon_limbs[i], monster_bod[mon_limbs[i]]["limb_ref"], 
	  monster_bod[mon_limbs[i]]["max_dam"], 0, 0);
    set_wielding_limbs((string *)RACE_D->query_monster_wielding_limbs(str));
    set_fingers((int)RACE_D->query_monster_fingers(str));
    body_type = str;
    set_mp(mag);
    set_max_mp(max_mag);
}
string query_body_type()
{
    return body_type;
}
void set_spell_chance(int x) {
    if(!spells) spells = ([]);
    spells["chance"] = x;
}
void set_spells(string *arr) {
    if(!spells) spells = ([]);
    spells["commands"] = arr;
}
int query_spell_chance() { 
    if(spells) return spells["chance"];
    else return 0;
}
string *query_spells() {
    if(spells) return spells["commands"];
    else return 0;
}
string get_random_spell() {
    if(!spells) return 0;
    if(sizeof(spells["commands"]) <2) return spells["commands"][0];
    else return spells["commands"][random(sizeof(spells["commands"]))];
}
void set_exp(int x) {
    if( x > (int)ADVANCE_D->get_exp(level) )
	player_data["general"]["experience"] = (int)ADVANCE_D->get_exp(level);
    else player_data["general"]["experience"] = x;
}
// These two functions remain for backwards Nightmare 1.* and 2.* compat
void set_chats(int x, string *arr) { set_emotes(x, arr, 0); }
void set_achats(int x, string *arr) { set_emotes(x, arr, 1); }
void set_emotes(int x, string *arr, int att) {
    emotes[(att ? "attack chance" : "chance")] = x;
    emotes[(att ? "attack msg" : "msg")] = arr;
}
void set_speech(int x, string lang, string *arr, int att) {
    speech[lang] = ([ (att ? "attack chance" : "chance"): x,
      (att ? "attack msg" : "msg"): arr ]);
}
void set_alignment(int x) { player_data["general"]["alignment"] = x; }
string query_race() { return query("race"); }
int test_heart() {
    object env;
    object *inv;
    int i;
    if( (query_mp() < query_max_mp()) || (query_hp() < query_max_hp()) ||
      (query_sp() < query_max_sp()) ) return 1;
    if(!(env = environment(this_object()))) return 0;
    if (query_hp() < 1) return 1;
    if(query_current_attacker() || speed) return 1;
    i = sizeof(inv = all_inventory(env));
    while(i--) 
	if(interactive(inv[i]) || inv[i]->query("aggressive")) return 1;
    return 0;
}
int query_heart_status() { return heart_beat_on; }
void receive_message(string cl, string msg) {
    if ( function_exists("catch_tell", this_object() ) )
	this_object()->catch_tell(msg);
}
void set_languages(string *langs) {
    int i;

    i = sizeof(langs);
    while(i--) set_lang_prof(langs[i], 10);
}
void set(string str, mixed val) {
    ::set(str, val);
    if(str == "race") LANG_D->init_languages(this_object());
}
void set_die(mixed val) {
    if(functionp(val) && geteuid(this_object()) != geteuid(val)) return;
    __Die = val;
}
mixed query_die() { return __Die; }
void set_race(string str) { set("race", str); }
void set_dragon_level(int x) { dragon_level = x; }
int query_dragon_level() { return dragon_level; }
int is_monster() { return 1; }





