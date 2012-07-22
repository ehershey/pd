#include <std.h>
#include <guild.h>
inherit "/std/vendor";

void
create() {
    ::create();
    set_name("demon");
    set_id(({ "shopkeeper", "stuck demon", "demon" }));
    set_short("%^BOLD%^%^WHITE%^A stuck demon");
    set_long("It looks as though he is part of the finger, all his body except his feet made it through, thus entrapping him for life...");
    set_languages(({ "farsi" }));
    set_gender("male");
    set_alignment(-420);
    set_race("demon");
    set_body_type("demon");
    set_storage_room("/d/guilds/unholy/storage_room.c");
    set_currency("gold");
    set_skill("bargaining", 75);
}
void init()
{
    ::init();
    add_action("cmd_bottle", "bottle");
}

int cmd_bottle(string str) {
    int numba;
    object oil;

    if (!str) {  
	force_me("say what would you like to bottle?");
	return 1;
    }
    if (str == "breath") {
	if (this_player()->query_money("gold") < 20) {
	    force_me("say You don't have that much money!");
	    return 1;
	}
	this_player()->add_money("gold", -20);
	write("The demon hands you a breath of Asmodeus.");
	new("/d/guilds/unholy/breath")->move(this_player());
	return 1;
    }
    if (strsrch(str, " breath") != -1 && sscanf(str, "%d breath", numba) == 1) {
	if (numba < 1 || numba > 999) {
	    force_me("say That is an invalid amount!");
	    return 1;
	}
	if (this_player()->query_money("gold") < 20*numba) {
	    force_me("say You don't have enough gold to buy that many.");
	    return 1;
	}
	this_player()->add_money("gold", -20*numba);
	write("The demon hands you "+(string)numba+" breaths of Asmodeus.");
	while(numba > 0) {
	    oil = new("/d/guilds/unholy/breath");
	    if(numba >= 15)
		oil->set_uses(15);
	    else
		oil->set_uses(numba);
	    numba -= 15;
	    oil->move(this_player());
	} 
	return 1;

    }
    force_me("say I dont have that for sale.");
    return 1;
}
