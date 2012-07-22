//      /d/standard/bank.c
//      from the Nightmare mudlib
//      banking room
//      created by Descartes of Borg 28 february 1993

#include <std.h>
#include <daemons.h>
#include <money.h>
#include <bank.h>
#include <tirun.h>

#define BANK_ID "tirun"

inherit VAULT;

string center_str(string str, int size) {
    int a, b, c;
    string out;
    if(!size) size = 80;
    a = strlen(str);
    b = (size - a) / 2;
    c = b;
    out = "";
    while(b--) out += " ";
    out += str;
    while(c--) out += " ";
    return out;
}

string align(string what, int x) {
    int y;
    string out;
    out = "";
    if(!what) return 0;
    y = strlen(what);
    out += what;
    if(y>x) {
	out = what[0..x-1] + " ";
	return out;
    }
    x = x-y;
    if(x<1) return out;
    for(y=0; y<=x; y++) out += " ";
    return out;
}

void init() {
    ::init();
    add_action("Bugga", "Bugga");
    add_action("read", "read");
    add_action("open", "open");
    add_action("close", "close");
    add_action("deposit", "deposit");
    add_action("withdraw", "withdraw");
    add_action("balance", "balance");
    add_action("exchange", "exchange");
}

void lookatvault() {

    write("A huge, secure door that protects the banks money.");
    if(query_open("vault"))
	write("But someone has managed to get it open!");
    else write("It is sealed shut right now."); 

}

void create() {
    ::create();

    set_property("magic hold", 10);
    set_property("no castle", 1);
    set_property("light", 2);
    set_property("night light", 2);
    set_short("The Merchant's Bank of Tirun");
    set_long("%^GREEN%^The Bank of Tirun%^RESET%^\n"
      "The bank is well kept by the Tirunian government, but is pretty "
      "old.  Both the walls and floor are a uniform white, with very "
      "little furnishing in the room at all.  Citizens of Tirun come "
      "here to deposit their life savings.  A sign by the teller "
      "details all commands.");
    set_items(
      (["bank" : "You are in its huge lobby. There is a counter in "
	"front of you\nand an exit behind you.",
	"citizens" : "They are wandering about aimlessly.",
	"account" : "Youre a damn loon.",
	"sign" : "Reading it will give you a list of commands.",
	"teller" : "The teller looks at you impatiently.",
	"counter" : "A teller waits behind it for you to do something.",
	"exit" : "It leads out into the alley.",
	"vault" : (: lookatvault :)
      ]) );
    set_exits(
      (["enter":ROOMS"bank_vault",
        "out": ROOMS"square6"]) );

    cover_exit_with_door("enter", "tirunbankvaultdoor");
    set_door_name("tirunbankvaultdoor", "vault");
    set_door_func("tirunbankvaultdoor", "unlock", "do_drunkard");
    set_key("tirunbankvaultdoor", "bank key");
//    set_door("vault", ROOMS"bank_vault", "enter", "bank key");
//    set_func("vault", "unlock", "do_drunkard");
    present("guard")->force_me("close vault");
    present("guard")->force_me("lock vault with key");

}

void reset() {
    object mon, weapon, key;

    ::reset();
    if(!present("guard")) {
	mon = new(MONSTER);
	mon->set_name("guard");
	mon->set_id( ({ "guard", "bank guard", "big ogre" }) );
	mon->set("race", "ogre");
	mon->set_gender("male");
	mon->set("short", "Bank guard");
	mon->set("long", "A big ogre hired to guard the bank.\n");
	mon->set_level(14);
	mon->set_body_type("human");
	mon->set_hp(500 + random(100));
	mon->set_class("fighter");
	mon->set_spell_chance(10);
	mon->set_spells( ({ "parry", "Bugga" }) );
	mon->set_skill("defense", 70);
	mon->set_skill("blade", 90);
	mon->set_emotes(9, 
	  ({ "The guard looks around.",
	    "The guard grunts.",
            "%^CYAN%^The guard says: %^RESET%^Thieves disgust me.",
	    "The guard looks you over."}), 1);
	mon->set_emotes(3,
	  ({ "The guard concentrates on a shadow.", 
	    "%^CYAN%^The guard says: %^RESET%^I hate rogues." }), 0);
	mon->set_wielding_limbs( ({ "right hand", "left hand" }) );
	mon->move(this_object());
	weapon = new(WEAPON);
	weapon->set_name("broadsword");
	weapon->set_id( ({ "broadsword", "sword" }) );
	weapon->set("short", "Broadsword");
	weapon->set("long", "A huge broadsword.");
	weapon->set_wc(13);
	weapon->set_type("blade");
	weapon->set_weight(7);
	weapon->set_value(9);
	weapon->move(mon);
	mon->force_me("wield broadsword in right hand");
	key = new(OBJECT);
	key->set_name("key");
	key->set_id( ({ "bank key", "key", "bronze key" }) );
	key->set("short", "Bronze key");
	key->set("long", "An unremarkable bronze key.");
	key->set_weight(2);
	key->set_value(1);
	key->move(mon);
    }
    if(query_reset_number() != 1) {
	present("guard")->force_me("close vault");
	present("guard")->force_me("lock vault with key");
    }
}

int do_drunkard() {
    if(present("guard") && !this_player()->query_invis()) {
	present("guard")->force_me("kill "+(string)this_player()->query_name());

	//        this_player()->add_follower(present("guard"));
	write("The guard foils you before you can slip the key in!");
	say(this_player()->query_cap_name()+" is foiled trying to break "
	  "into the vault!");
	return 0;
    }
    if(this_player()->query_intox()) {
	write("You are fumble around drunkenly with the bank key.");
	say(this_player()->query_cap_name()+" fiddles around drunkenly "
	  "with the bank key.");
	return 0;
    }
    return 1;
}

int exchange(string str) {
    string from, to;
    int amount;

    if(!str) {
	notify_fail("Correct syntax: <exchange # type for type>\n"+
	  "ex: <exchange 100 gold for copper>\n");
	return 0;
    }
    if(sscanf(str, "%d %s for %s", amount, from, to) !=3) {
	notify_fail("Correct syntax: <exchange # type for type\nex: "
	  "<exchange 100 gold for copper>\n");
	return 0;
    }
    if(amount < 1) {
	notify_fail("That would be a nifty trick indeed!\n");
	return 0;
    }
    if((int)this_player()->query_money(from) < amount) {
	notify_fail("You do not have that much of that currency.\n");
	return 0;
    }
    if(member_array(from, HARD_CURRENCIES) == -1)
	return notify_fail("The bank does not support "+from+".\n");
    if(member_array(to, HARD_CURRENCIES) == -1)
	return notify_fail("The bank does not support "+to+".\n");
    this_player()->add_money(from, -(to_int(amount*0.01)+amount));
    switch(from) {
    case "platinum": amount = amount*10;
    case "gold": amount = amount*10;
    case "electrum": amount = amount*5;
    case "silver": amount = amount*2;
    case "copper": break;
    default: write("Invalid currency.");
    }
    switch(to) {
    case "platinum": amount = amount/10;
    case "gold": amount = amount/10;
    case "electrum": amount = amount/5;
    case "silver": amount = amount/2;
    }
    this_player()->add_money(to, amount);
    message("my_action", "You exchange your "+from+" coins for "+amount+" "+to,
      this_player());
    message("other_action", (string)this_player()->query_cap_name()+
      " exchanges some money.", this_object(), ({ this_player() }));
    return 1;
}

int close(string str) {
    int i;
    mapping money;

    if(!str || str != "account") return 0;
    money = (mapping)BANK_D->query_balance(
      (string)this_player()->query_name(), BANK_ID
    );
    if(!money || money == ([])) {
	write("The teller says: You have no account here to close!");
	say(this_player()->query_cap_name()+" tries to close a "
	  "non-existent account!");
	return 1;
    }
    for(i=0; i<sizeof(HARD_CURRENCIES); i++) {
	if(money[HARD_CURRENCIES[i]]) 
	    this_player()->add_money(HARD_CURRENCIES[i], money[HARD_CURRENCIES[i
		]]);
    }
    write("The teller hands you all your money.");
    say(sprintf("%s collects all %s money from the teller.",
	(string)this_player()->query_cap_name(), possessive(this_player())));
    BANK_D->close_account((string)this_player()->query_name(), BANK_ID);
    return 1;
}

int open(string str) {
    int x;

    if(!str || str != "account") return 0;
    x = (int)BANK_D->open_account((string)this_player()->query_name(), BANK_ID);


    if(x != TRANSACTION_OK) {
	write("You already have an account here!");
	return 1;
    }
    write("You open up an account at the Tirun Merchants Bank.");
    say(this_player()->query_cap_name()+" opens an account.");
    return 1;
}

int balance(string str) {
    mapping account;
    int i;
    int total;
    string out;

    account = (mapping)BANK_D->query_balance(
      (string)this_player()->query_name(), BANK_ID
    );
    if(!account || account == ([])) {
	write("The teller says: You have no account here!");
	return 1;
    }
    say(this_player()->query_cap_name()+" asks for account information.");
    i = sizeof(HARD_CURRENCIES);
    out = "\n%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+%^BOLD%^("
    "%^RESET%^%^BOLD%^Bank of Tirun%^BOLD%^%^BLUE%^)"
    "%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n";
    while(i--) {
	out += align(capitalize(HARD_CURRENCIES[i]), 9)+": "+
	account[HARD_CURRENCIES[i]]+" coins.\n";
    }
    total = account["gold"];
    total += account["platinum"]*10; 
    total += account["electrum"]/10;
    total += account["silver"]/500;
    total += account["copper"]/1000;
    if(total>0) out += "\nTotal: "+total+" in gold.\n";
    else out += "\nYour account is empty!\n";
    out += "%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
    "+=+=+=+=+=+=+=+=+=+=%^RESET%^";
    write(out);
    return 1;
}

int deposit(string str) {
    string type, *cur;
    mapping money;
    int x, amount;

    if(!str) {
	notify_fail("Correct syntax: <deposit [amount] [type]>\n");
	return 0;
    }
    if (str=="all")
    {
	money = (mapping)BANK_D->query_balance(
	  (string)this_player()->query_name(), BANK_ID
	);
	if (!money || money == ([]) )
	    return notify_fail("You do not have an account here.\n");
	money = ([]);
	cur = this_player()->query_currencies();
	if (!sizeof(cur)) return notify_fail("You do not have any money!\n");
	x = sizeof(cur);
	while(x--)
	{
	    this_player()->force_me("deposit "+this_player()->query_money(cur[x]
	      )+" "+cur[x]);
	}
	return 1;
    }
    if(sscanf(str, "%d %s", amount, type) != 2) {
	notify_fail("Correct syntax: <deposit [amount] [type]>\n");
	return 0;
    }
    if((int)this_player()->query_money(type) < amount) {
	notify_fail("The teller says: You do not have that much money!\n");
	return 0;
    }
    x = (int)BANK_D->deposit(
      (string)this_player()->query_name(), BANK_ID, amount, type
    );
    if(x != TRANSACTION_OK) {
	switch(x) {
	case NO_ACCOUNT:
	    notify_fail("The teller says: You have no account here!\n");
	    break;
	case BAD_MONEY:
	    notify_fail("The teller says: That is not a real money type!\n");
	    break;
	default: notify_fail("The teller says: You cant do that!\n");
	}
	return 0;
    }

    this_player()->add_money(type, -amount);
    write("The teller takes your "+amount+" "+type+" coins.");
    say(this_player()->query_cap_name()+" deposits some money.");
    return 1;
}

int withdraw(string str) {
    string type;
    int x, amount;

    if(!str) {
	notify_fail("Correct syntax: <withdraw [amount] [type]>\n");
	return 0;
    }
    if(sscanf(str, "%d %s", amount, type) != 2) {
	notify_fail("Correct syntax: <withdraw [amount] [type]>\n");
	return 0;
    }
    if(amount < 0) {
	notify_fail("The teller says: That would be a neat trick!\n");
	return 0;
    }
    x = (int)BANK_D->withdraw(
      (string)this_player()->query_name(), BANK_ID, amount, type
    );
    if(x != TRANSACTION_OK) {
	switch(x) {
	case NO_ACCOUNT:
	    notify_fail("The teller says: You have no account here!\n");
	    break;
	case BAD_MONEY:
	    notify_fail("The teller says: That is not a real money type!\n");
	    break;
	default: notify_fail("The teller says: You cant do that!\n");
	}
	return 0;
    }
    this_player()->add_money(type, amount);
    write("The teller gives you your "+amount+" "+type+" coins.");
    say(this_player()->query_cap_name()+" withdraws some money.");
    return 1;
}

int read(string str) {
    if(str != "sign") return notify_fail("Read what?\n");
    message("info",
      "You may do any of the following at Tirun Merchants Bank:\n"
      "<open account>\nWill open an account for you. "
      "\n\n"
      "<close account>\nCloses your account.\n\n"
      "<balance>\nGives you account balance information.\n\n"
      "<deposit [#] [type]>\nDeposits # of currency of type.\n\n"
      "<withdraw [#] [type]>\nWithdraws # of currency of type.\n\n"
      "<exchange [#] [type1] for [type2]>\nExchanges currencies.\n"
      "There is a 10% charge.", this_player());
    return 1;
}

int pick_lock(string str) {
    if(present("guard") && this_player())
	present("guard")->force_me("kill "+(string)this_player()->query_name());

    //    this_player()->add_follower(present("guard"));
    return ::pick_lock(str);
}

int Bugga(string str) {
    string limb;
    object ob;
    int amount;

    if(this_player()->is_player()) return 0;
    ob = (object)this_player()->query_current_attacker();
    if(!ob) return 1;
    limb = (string)ob->return_limb();
    if((string)ob->query_class() == "rogue") amount = 24 + random(30);
    else amount = 20 + random(20);
    ob->do_damage(limb, amount);
    tell_object(ob, "The guard bashes your "+limb+"!");
    tell_room(this_object(), "The guard bashes "+ob->query_cap_name()+"'s "+
      limb+"!", ({ ob }));
    return 1;
}