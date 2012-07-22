#include <std.h>
#include <guild.h>

inherit MONSTER;

static object food, drink;

#define SIGN "The sign reads: \n" \
             "-----------------------------------------\n" \
             "Cake:  10 gold peices.\n" \
             "Ale :  15 gold peices.\n" \
             "-----------------------------------------\n"

void create() {
    ::create();
    set_name("");
    set_short("invisible barkeeper");
    set_long("The barkeeper wheres a long, black cloak making it hard to "
      "see him in the darkness.");
    set_invis();
    set_race("scorpion");
    set_body_type("human");
}

void init() {
    ::init();
    add_action("buy", "buy");
    add_action("read", "read");
}

int read(string str) {
    if(str != "sign") return 0;
    write(SIGN); return 1;
}

int buy(string str) {
    if(!str) {
	this_object()->force_me("say What is it that you would like to buy?");
	return 1;
    }
    switch(str) {
    case "cake":
	if(this_player()->query_money("gold") < 10 ) return
	    notify_fail("You cannot afford a peice of cake.\n");
	this_object()->force_me("say There is your cake for 10 gold.");
	write("A shadow gives you a peice of cake.\n");
	say("A shadow gives "+this_player()->query_cap_name()+" a peice of cake.");
	new(SCORPIO"cake")->move(this_player());
	this_player()->add_money("gold", -10);
	return 1;
	break;
    case "ale":
	if(this_player()->query_money("gold") < 15 ) return
	    notify_fail("You cannot afford a glass of ale.\n");
	this_object()->force_me("say There is your ale for 15 gold.");
	write("A shadow gives you some ale.\n");
	say("A shadow gives "+this_player()->query_cap_name()+" some ale.");
	new(SCORPIO"ale")->move(this_player());
	this_player()->add_money("gold", -15);
	return 1;
	break;
    default: 
	this_object()->force_me("say I do not sell that!\n");
	return 1;
    }
    return 1;
}

