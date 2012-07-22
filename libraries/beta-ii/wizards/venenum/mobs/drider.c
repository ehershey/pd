// Venenum

#include <std.h>
#include <venenum.h>
inherit MONSTER;

string *height = ({"ten foot one", "ten foot two", "ten foot three", "ten foot four", "ten foot five", "ten foot six", "ten foot seven", "ten foot eight", "ten foot nine", "eleven foot one", "nine foot nine"});
string mobheight;
string *wepstyles = ({"four swords", "two spears", "four axes", "four katana", "dual diasho"});
string style;

void create() {
    ::create();

    swarm = 1;

    set_name("drider");
    set_short("Drider Calvalry");
    set_id(({"drider", "drider calvalry", "calvalry"}));
    set_level(60);
    set_race("drider");
    set_body_type("raknid");
    set_gender("neuter");
    set_spells(({"rush","slash"}));
    mobheight = height[random(sizeof(height))];
    set_long("This Drider forms the hard-hitting expendable calvalry of the Drow raiding force, towering over their drow masters at a fearsome "+mobheight+". The top half of their body resembles a Dark Elf, only swollen, bloated and dead- the lower half a giant spider. Driders are considered the lowest of the low by Drow standards, below even the various races whom they keep for fodder and slave labour. Their only redeaming features are that they are fearsome in battle with their four arms and spider body and provide a very visual example to those who fail the Dark Elven goddess Lloth.");
    set_die( (: call_other, this_object(), "death_func":) );
    call_out("arm", 1);
}

int arm(){

    new(ARM"drider_chainmail.c")->move(this_object());
    new(ARM"drow_helm.c")->move(this_object());
    style = wepstyles[random(sizeof(wepstyles))];

    switch(style) {
    case "four swords":
	new(WEP"drow_sword.c")->move(this_object());
	new(WEP"drow_sword.c")->move(this_object());
	new(WEP"drow_sword.c")->move(this_object());
	new(WEP"drow_sword.c")->move(this_object());
	break;
    case "two spears":
	new(WEP"drow_spear.c")->move(this_object());
	new(WEP"drow_spear.c")->move(this_object());
	break;
    case "four axes":
	new(WEP"drow_axe.c")->move(this_object());
	new(WEP"drow_axe.c")->move(this_object());
	new(WEP"drow_axe.c")->move(this_object());
	new(WEP"drow_axe.c")->move(this_object());
	break;
    case "four katana":
	new(WEP"drow_katana.c")->move(this_object());
	new(WEP"drow_katana.c")->move(this_object());
	new(WEP"drow_katana.c")->move(this_object());
	new(WEP"drow_katana.c")->move(this_object());
	break;
    case "dual diasho":
	new(WEP"drow_katana.c")->move(this_object());
	new(WEP"drow_wakizashi.c")->move(this_object());
	new(WEP"drow_katana.c")->move(this_object());
	new(WEP"drow_wakizashi.c")->move(this_object());
	break;
    }

    switch(style) {
    case "four swords":
	this_object()->force_me("wield sword");
	this_object()->force_me("wield sword 2");
	this_object()->force_me("wield sword 3");
	this_object()->force_me("wield sword 4");
	break;
    case "two spears":
	this_object()->force_me("wield spear");
	this_object()->force_me("wield spear 2");
	break;
    case "four axes":
	this_object()->force_me("wield axe");
	this_object()->force_me("wield axe 2");
	this_object()->force_me("wield axe 3");
	this_object()->force_me("wield axe 4");
	break;
    case "four katana":
	this_object()->force_me("wield katana");
	this_object()->force_me("wield katana 2");
	this_object()->force_me("wield katana 3");
	this_object()->force_me("wield katana 4");
	break;
    case "dual diasho":
	this_object()->force_me("wield katana");
	this_object()->force_me("wield wakizashi");
	this_object()->force_me("wield katana 2");
	this_object()->force_me("wield wakizashi 2");
	break;
    }

    this_object()->force_me("wear chainmail");
    this_object()->force_me("wear helm");

}

int death_func() {

    if (random(15) != 5)
    {
	message("say", "The drider falls and curls up into a ball, screaching in pain. Within seconds a shimmering light envelops it's body, then it is gone.", environment(this_object()));
	this_object()->move("/d/nopk/standard/void.c");
	return 1;
    }
    else
    {
	message("say", "The drider falls and curls up into a ball, screaching in pain. The horrible noise stops quickly.", environment(this_object()));
	return 1;
    }

}

int is_invincible() {

    if (this_player()->query_race() == "drow")
    {
	return 1;
    }
    else
    {
	message("say", "The drider hisses something unintelligable and lunges for you.", environment(this_object()));
	this_object()->force_me("kill "+this_player()->query_name());
	return 1;
    }
}

void init() {
    ::init();
    if(this_player())
	if (this_player()->query_race() == "drow")
	{
	    return 1;
	}
	else
	{
	    message("say", "The drider hisses something unintelligable and lunges for you.", environment(this_object()));
	    this_object()->force_me("kill "+this_player()->query_name());
	    return 1;
	}
}
