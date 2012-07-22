// prep.c
#include <std.h>
#include <tirun.h>

inherit ROOM;

void execute_sentance(object tp, int sentance);

static object ob;
int count, sentance;
int drug;
int pk;
int oth1;
int oth2;
int theft;
int total;
/***********************************************
Sentances: 
1) 120 rounds in jail  ( 2 min )                        -- 1 --
2) 480 rounds in jail  ( 8 min )                        -- 3 --
3) 720 rounds in jail  (12 min ) [para]                  -- 5 --
4) 1020 rounds in jail (17 min ) [para]                 -- 6 --
5) All autoloading equipment is auctioned off,
   300 rounds (5 min) in jail [para]                     -- 2 --
6) 600 rounds in jail  (10 min ) [para],                 -- 4 --
   700 damage worth of a flogging
7) Five random autoloading objects are destroyed,
   all non autoloading equipment is destroyed,
   600 rounds in jail [no para], fine?                  -- 4 --
8) Beheaded in Tirun square, corpse is left there,
   along with your severed head 
9) Hanged, all equipment lost
***********************************************/

void create() {
    set_short("Entering a courtroom");
    set_properties(([
	"no attack" : 1, "no magic" : 1, "no teleport" : 1, "no gate" : 1
      ]));
    set_id(({ "lawless" }));
    set_items((["lawless":"bug preventer",]));
    set_heart_beat(0);
    count = 0;
    drug = 0;
    pk = 0;
    oth1 = 0;
    oth2 = 0;
    theft = 0;
}

void heart_beat() {
    string str;
    count++;
    switch (count) {
    case 1:
	message("info", "You find yourself in a large court room, it is "
	  "very drab and unwelcoming.\n\nA Judge, dressed in flowing "
	  "black robes steps into the room and sits at his high seat.",
	  ob);
	break;
    case 3:
	message("info", "%^RESET%^%^CYAN%^The Judge Speaks:%^RESET%^ "
	  "You have been charged with the following:", ob);
	pk = ob->query_outlaw("pk");
	if (pk >= 1)
	    message("info", "%^RESET%^%^CYAN%^The Judge Speaks:%^RESET%^ "
	      +(string)pk+" counts of cold blooded murder.", ob);
	drug = ob->query_outlaw("drug");
	if (drug >= 1)
	    message("info", "%^RESET%^%^CYAN%^The Judge Speaks:%^RESET%^ "
	      +(string)drug+" counts of intoxication, by use of "
	      "illegal substances.", ob);
	oth1 = ob->query_outlaw("other1");
	if (oth1 >= 1)
	    message("info", "%^RESET%^%^CYAN%^The Judge Speaks:%^RESET%^ "
	      +(string)oth1+" assorted minor offenses.", ob);
	oth2 = ob->query_outlaw("other2");
	if (oth2 >= 1)
	    message("info", "%^RESET%^%^CYAN%^The Judge Speaks:%^RESET%^ "
	      +(string)oth2+" assorted major offenses.", ob);
	theft = ob->query_outlaw("theft");
	if (theft >= 1)
	    message("info", "%^RESET%^%^CYAN%^The Judge Speaks:%^RESET%^ "
	      +(string)theft+" counts of theft.", ob);
	break;
    case 7:
	message("info", "The Judge shakes his head and frowns.",
	  ob);
	message("info", "%^RESET%^%^CYAN%^The Judge asks you:%^RESET%^ "
	  "What am I to do with you...?", ob);
	total = 0;
	total += drug;
	total += (oth1 * 2);
	total += (oth2 * 5);
	total += (pk * 10);
	total += (theft * 4);
	break;
    case 9:
	str = "%^RESET%^%^CYAN%^The Judge Speaks:%^RESET%^ "
	"After careful thought, I have found that I must "
	"sentence you to ";
	if (total == 1) {
	    sentance = 1;
	    str += "a category one stay in the Tirun Jail.";
	} else if (total <= 4)  { sentance = 2;
	    str += "a category three stay in the Tirun Jail.";
	} else if (total <= 6)  { sentance = 3;
	    str += "a category five stay in the Tirun Jail.";
	} else if (total == 7)  { sentance = 4;
	    str += "a category six stay in the Tirun Jail.";
	} else if (total == 8)  { sentance = 5;
	    str += "have all equipment of autoloading worth "
	    "auctioned, and a category two stay in the "
	    "Tirun Jail.";
	} else if (total == 9)  { sentance = 6;
	    str += "a category four stay in the Tirun Jail and "
	    "a public flogging.";
	} else if (total <= 20) { sentance = 7;
	    str += "have all items taken and sold to the shops, "
	    "and a "
	    "category four stay in the Tirun Jail.";
	} else if (total <= 39) { sentance = 8;
	    str += "be beheaded publicly in the Tirun Square.";
	} else { sentance = 9;
	    str += "be hanged publicly and have all personal items "
	    "confiscated.";
	}
        message("info", str, ob);
    case 10:
         message("info", "You are taken away.", ob);
         execute_sentance(ob, sentance);
	break;
    }
}

void execute_sentance(object tp, int sentance) {
    object *stuff;
    int i, time;
    switch(sentance) {
    case 1:
	time = 120;
	break;
    case 2:
	time = 480;
	break;
    case 3:
	time = 720;
	tp->set_paralyzed(720, "You have been bound and gagged.");
	break;
    case 4:
	time = 1020;
	tp->set_paralyzed(1020, "You have been bound and gagged.");
	break;
    case 5:
	message("info", "Your belongings are sold in a hasty auction to the local shops.", tp);
	stuff = all_inventory(tp);
	i = sizeof(stuff);
	while(i--) {
	    if(stuff[i]->is_weapon())
		stuff[i]->move(ROOMS"wstorage");
	    else if(stuff[i]->is_armour())
		stuff[i]->move(ROOMS"astorage");
	    else
		stuff[i]->move(ROOMS"storage");
	}
	time = 300;
	tp->set_paralyzed(300, "You have been bound and gagged.");
	break;
    case 6:
	time = 1020;
	message("info", "You are flogged severly before being thrown in jail!", tp);
	tp->add_hp(-700);
	if(tp->query_hp() > 0)
	    tp->set_paralyzed(1020, "You have been bound and gagged.");
	break;
    case 7:
	message("info", "Your belongings are sold in a hasty auction to the local shops.", tp);
	message("info", "A few of them broke in the process.", tp);
	stuff = all_inventory(tp);
	i = sizeof(stuff);
	while(i--) {
	    if(random(4) == 0) {
		stuff[i]->remove();
		continue;
	    }
	    if(stuff[i]->is_weapon())
		stuff[i]->move(ROOMS"wstorage");
	    else if(stuff[i]->is_armour())
		stuff[i]->move(ROOMS"astorage");
	    else
		stuff[i]->move(ROOMS"storage");
	}
	tp->add_money("gold",tp->query_money("gold"));
	time = 600;
	tp->set_paralyzed(600, "You have been bound and gagged.");
	break;
    case 8:
	message("info", "%^RED%^"+tp->query_cap_name()+" has been sentenced to death!", users());
	message("info", "As you are led to the square, you are knelt down in front of a"
	  " large stump...", tp);
	tp->set_paralyzed(4, "You are bound and gagged.");
	call_out("do_execute", 4, tp);
	break;
    case 9:
	message("info", "%^RED%^"+tp->query_cap_name()+" has been sentenced to death!", users());
	message("info", "You are led to the square, where your death awaits you.", tp);
	tp->set_paralyzed(4, "You are bound and gagged.");
	call_out("just_die", 4, tp);
	break;
    default:
	break;
    }
    if(sentance < 8) {
        load_object("/d/nopk/tirun/jail")->add_prisoner(tp, time);
    }
}

void do_execute(object tp) {
    tp->move(ROOMS"square");
    message("info", tp->query_cap_name()+" is executed by the guards.", environment(tp));
    tp->set_recent_outlaw(0);
    tp->set_hp(-10000);
}

void just_die(object tp) {
    object *stuff;
    int i;
    tp->move(ROOMS"square");
    message("info", tp->query_cap_name()+" is executed by the guards.", environment(tp));
    stuff = all_inventory(tp);
    i = sizeof(stuff);
    while(i--) {
	stuff[i]->move(get_object("/d/nopk/standard/void"));
    }
    tp->set_recent_outlaw(0);
    tp->set_hp(-10000);
}

int FilterMe(string str) {
    write("You may not move, speak, or perform any other action while "
      "being judged in court");
    if (!wizardp(this_player()))
	return 1;
    else return 0;
}

void start_sequence(object to) {
    ob = to;
    set_heart_beat(1);
}

void init() {
    ::init();
    add_action("FilterMe", "");
}
