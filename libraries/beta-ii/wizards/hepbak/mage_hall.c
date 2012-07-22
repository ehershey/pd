#include <std.h>
#include <rooms.h>
#include <council.h>
#include <daemons.h>
#define FAULT "A magical force holds you back."
#include <sindarii.h>
inherit ROOM;

#define MAGEH ROOMS+ "mage/"

string get_new_title(object tp);
string get_male(int lev);
string get_female(int lev);
string previous_title(object tp);
int get_cost(string which, int lev);
int inf(string where);
int becomeSubclass(string str);
int check_sub(string str);
int goWizard();
int goDruid();
int goSorceror();
int choose(string what);
int goPyromancer();
int goNecromancer();
int goConjurer();

int becomeSubclass(string str)
{

if(str!="druid"&&str!="sorceror"&&str!="wizard"&&str!="pyromancer"&&
str!="conjurer"&&str!="necromancer") {
   message("subclass","That is not a valid subclass.", this_player());
   return 1;
 }
 if (this_player()->query_subclass()!="none") return 1;
 this_player()->set_subclass(str);
 CHAT_D->do_raw_chat("mage", "%^BOLD%^"+this_player()->query_cap_name()+" has chosen to follow the path of the %^RESET%^%^RED%^"+str+"%^WHITE%^%^BOLD%^.%^RESET%^\n"); 
 return 1;
}
int goDruid()
{
//    if (this_player()->query_subclass()=="none")
//      becomeSubclass("druid");
    if (this_player()->query_subclass()=="druid")
      this_player()->move_player(MAGEH+"druid","druid");     
   else
  message("info", FAULT, this_player());
  return 1;
}
int goSorceror()
{
/*    if (this_player()->query_subclass()=="none")
      becomeSubclass("sorceror");*/
    if (this_player()->query_subclass()=="sorceror")
      this_player()->move_player(MAGEH+"sorceror","sorceror");
   else
  message("info", FAULT, this_player());
  return 1;
}
int goWizard()
{
//    if (this_player()->query_subclass()=="none")
//      becomeSubclass("wizard");
    if (this_player()->query_subclass()=="wizard")
      this_player()->move_player(MAGEH+"wizard","wizard");
   else
  message("info", FAULT, this_player());
  return 1;
}
int goPyromancer()
{
//    if (this_player()->query_subclass()=="none")
//      becomeSubclass("pyromancer");
    if (this_player()->query_subclass()=="pyromancer")
      this_player()->move_player(MAGEH+"pyromancer","pyromancer");
   else
  message("info", FAULT, this_player());
  return 1;
}
int goConjurer()
{
//    if (this_player()->query_subclass()=="none")
//      becomeSubclass("conjurer");
    if (this_player()->query_subclass()=="conjurer")
      this_player()->move_player(MAGEH+"conjurer","conjurer");
   else
  message("info", FAULT, this_player());
  return 1;
}
int goNecromancer()
{
//    if (this_player()->query_subclass()=="none")
//      becomeSubclass("necromancer");
    if (this_player()->query_subclass()=="necromancer")
      this_player()->move_player(MAGEH+"necromancer","necromancer");
   else
  message("info", FAULT, this_player());
  return 1;
}
void create() {
    object ob;

    ::create();
    set_property("no attack",1);
    set_property("no magic", 1);
    set_property("no teleport", 1);
    set_property("no bump", 1);
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The inner sanctum of the tree of the mages");
    set("long",
        "Welcome into the heart of the mage tree! "
	"Mages come here to advance their knowledge of the magical arts.  "
	"The available commands are <cost>, <advance>, <list (number)>, "
	"<improve stat>, <train skill amount>, and <roll stats>.  Up "
	"through a stairway "
	"guarded by a shimmering %^BLUE%^blue%^RESET%^ light is the "
	"entrance to the tree.  "
	"<help skills> will list all skills with their full, proper names."
        "  You can choose a subclass here.");
    set_exits( 
	      (["up" : ROOMS "mage_join",
		"east" : ROOMS "mage_vote",
                "druid": ROOMS "mage/druid",
                "sorceror" : ROOMS "mage/sorceror",
                "wizard" : ROOMS "mage/wizard",
                "pyromancer" : ROOMS "mage/pyromancer",
                "conjurer" : ROOMS "mage/conjurer",
                "necromancer" : ROOMS "mage/necromancer"]) );

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "crystal board", "bulletin board"}) );
    ob->set_board_id("mage_board");
    ob->set_max_posts(25);
    ob->set_edit_ok(MAGE_COUNCIL);
    ob->set_location(ROOMS "mage_hall");
    ob->set("short", "the Crystal Board of Mages");
    ob->set("long",
	"It is a huge slab of crystal into which mages have the power "
	"to cast their thoughts about the class of mages.\n");
}

void init() {
    ::init();
/*    add_action("cost","cost"); */
    add_action("roll","roll");
    add_action("train", "train");
    add_action("improve", "improve");
    add_action("advance","advance");
    add_action("list","list");
    add_action("inf", "go");
    add_action("goDruid", "druid");
    add_action("goSorceror", "sorceror");
    add_action("choose", "choose");
    add_action("goWizard", "wizard");
    add_action("goPyromancer", "pyromancer");
    add_action("goConjurer", "conjurer");
    add_action("goNecromancer", "necromancer");
  }

int choose(string what) {
   if (!what) {
      write("Choose what?");
      return 1;
   }
   if (what != "necromancer" && what != "conjurer" && what != "pyromancer"
    && what != "wizard" && what != "sorceror" && what != "druid") {
      write("You cannot choose that!");
      return 1;
   }
 if (what=="necromancer") this_player()->set_alignment(-1500);

   becomeSubclass(what);
   return 1;
}

int inf(string where) {
   if (!where) return 0;
   switch (where) {
      case "druid":
         return goDruid();
      case "sorceror":
         return goSorceror();
      case "wizard":
         return goWizard();
      case "pyromancer":
         return goPyromancer();
      case "necromancer":
         return goNecromancer();
      case "conjurer":
         return goConjurer();
      default:
         return 0;
   }
}

int roll(string str) {
    if(str != "stats") {
        notify_fail("Correct syntax: <roll stats>\n");
        return 0;
    }
    ROOM_SETTER->do_rolls();
    return 1;
}

string get_male(int lev) {
    string *male_title_str;

    if(!male_title_str) male_title_str = allocate(20);
        male_title_str[19]      ="the new high mortal mage";
        male_title_str[18]      ="the high mage warlock";
        male_title_str[17]      ="the master warlock";
        male_title_str[16]      ="the elder warlock";
        male_title_str[15]      ="the warlock";
        male_title_str[14]      ="the lesser warlock";
        male_title_str[13]      ="the master mage";
        male_title_str[12]      ="the elder mage";
        male_title_str[11]      ="the mage";
        male_title_str[10]      ="the low mage";
	male_title_str[9]	="the grand high enchanter";
	male_title_str[8]	="the high enchanter";
	male_title_str[7]	="the enchanter";
	male_title_str[6]	="the low enchanter";
	male_title_str[5]	="the grand master conjurer";
	male_title_str[4]	="the master conjurer";
	male_title_str[3]	="the conjurer";
	male_title_str[2]	="the apprentice conjurer";
	male_title_str[1]	="the inexperienced magic user";
	male_title_str[0]	="the novice mage";
    return male_title_str[lev-1];
}

string get_female(int lev) {
    string *female_title;

    female_title = ({
	"the new high mortal mage",
	"the high mage witch",
	"the master witch",
	"the elder witch",
	"the witch",
	"the lesser witch",
	"the master mage",
	"the elder mage",
	"the mage",
	"the low mage",
	"the grand high enchantress",
	"the high enchantress",
	"the enchantress",
	"the low enchantress",
	"the grand master conjuress",
	"the master conjuress",
	"the conjuress",
	"the apprentice conjuress",
	"the inexperienced magic user",
	"the novice mage"
    });
    if(lev>20) lev = 20;
    return female_title[20-lev];
}

int advance() { return (int)ADVANCE_D->advance(); }

int train(string str) {
    string which, which_tmp;
    int amount;

    if(!str) {
	notify_fail("Corract syntax: <train skill amount.\n");
	return 0;
    }
    if(sscanf(str, "%s %s %d", which, which_tmp, amount) == 3) which = which +" "+ which_tmp;
    else if(sscanf(str, "%s %d", which, amount) !=2) {
	notify_fail("Correct syntax: <train skill amount>\n");
	return 0;
    }
    which = lower_case(which);
    if(!this_player()->skill_exists(which)) {
	notify_fail("No such skill.\n");
	return 0;
    }
    return (int)ADVANCE_D->train_player(this_player(), which, amount);
}

int improve(string str) {
    string *stats;
    int stat_cost;

    stats = ({ "strength", "intelligence", "wisdom", "dexterity", "constitution", "charisma" });
    if(!str) {
        notify_fail("Improve what?\n");
        return 0;
    }
    str = lower_case(str);
    if(member_array(str, stats) == -1) {
	notify_fail("You have no such stat.\n");
	return 0;
    }

    stat_cost = get_cost(str, (int)this_player()->query_base_stats(str)+1);
/*
    if( (int)this_player()->query_exp()-stat_cost < (int)ADVANCE_D->get_exp( (int)this_player()->query_level() ) ) {
	notify_fail("You are not experienced enough to improve yourself in that way.\n");
	return 0;
    }
*/

    if ((int)this_player()->query_exp()-stat_cost < 1)
      {
       notify_fail("You are not experienced enough to improve yourself in that way\n");
       return 0;
      }

    this_player()->set_stats(str, (int)this_player()->query_base_stats(str) + 1);
    this_player()->add_exp(-stat_cost);
    message("no_wrap","You feel much ", this_player());
    say(this_player()->query_cap_name()+" looks much ");
    if(str == "strength") tell_room(this_object(), "stronger.\n");
    else if(str == "intelligence") tell_room(this_object(), "more intelligent.\n");
    else if(str == "wisdom") tell_room(this_object(), "wiser.\n");
    else if(str == "dexterity") tell_room(this_object(), "more nimble.\n");
    else if(str == "constitution") tell_room(this_object(), "sturdier.\n");
    else tell_room(this_object(), "more attractive.\n");
    return 1;
}

int get_cost(string stat, int lev) {
    switch(stat) {
  	case "intelligence": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
	case "constitution": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
	case "wisdom": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
  	default: return (int)ADVANCE_D->get_stat_cost(2, lev, stat); break;
    }
}

int cost(string str) {
    int bing;
 
    write("Costs for advancement, training, and improvement:\n");
    bing = (int)ADVANCE_D->get_exp( (int)this_player()->query_level() + 1 );
    if(bing < 1) write("level:\t\tIt will cost you nothing to advance.");
    else write("level:\t\t"+bing+"\n");
    write("\nskills: You train by spending the amount of experience you
desire.\n");
    write("\n");
    write("strength:\t\t" + get_cost("strength",
(int)this_player()->query_base_stats("strength")) +
"\t\tconstitution:\t\t" + get_cost("constitution",
(int)this_player()->query_base_stats("constitution")) );
    write("intelligence:\t\t" + get_cost("intelligence",
(int)this_player()->query_base_stats("intelligence")) +
"\t\tdexterity:\t\t" + get_cost("dexterity",
(int)this_player()->query_base_stats("dexterity")) );
    write("wisdom:\t\t" + get_cost("wisdom",
(int)this_player()->query_base_stats("wisdom")) +
"\t\tcharisma:\t\t" + get_cost("charisma",
(int)this_player()->query_base_stats("charisma")) );
    return 1;
}

int list(string str) {
    int x;

    if(!str) ROOMS+"quest_room"->list_quests(this_player(), 0);
    else {
	if(sscanf(str, "%d", x) != 1) {
	     notify_fail("You must give the number of the quest you want listed.\n");
	    return 0;
	}
	if(x<1) {
	    notify_fail("No such quest.\n");
	    return 0;
	}
	ROOMS +"quest_room"->list_quests(this_player(), x);
    }
    return 1;
}

void reset()
{
 if (!present("mage"))
   new(MOB "mage")->move(this_object());
}
