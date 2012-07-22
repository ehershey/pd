// Venenum

#include <std.h>
#include <venenum.h>
inherit MONSTER;

string *height = ({"five foot one", "five foot two", "five foot three", "five foot four", "five foot five", "five foot six", "five foot seven", "five foot eight", "five foot nine", "six foot one", "four foot nine"});
string *eyes = ({"dark, brooding red", "hot, fiery red", "malign, evil red", "scalding orange", "bright orange", "deep black", "light purple", "dark green"});
string mobheight;
string eyecolour;
string *wepstyles = ({"one sword", "two swords", "sword and shield", "spear", "one axe", "two axes", "katana", "daisho"});
string style;

void create() {
    ::create();

    swarm = 1;

    set_name("drow");
    set_short("Drow Soldier");
    set_id(({"drow", "drow soldier"}));
    set_level(75);
    set_race("drow");
    set_body_type("human");
    set_gender("male");
    set_spells(({"rush","slash"}));
    mobheight = height[random(sizeof(height))];
    eyecolour = eyes[random(sizeof(eyes))];
    set_long("This Dark Elven warrior stands at "+mobheight+", his skin as dark as charcoal and his hair white like new fallen snow. With "+eyecolour+" eyes set in a face partially hidden by a large cloak and hood, this drow shields his face from the burning light of the surface sky. His clothing is ornate and decorated, with a cloak of spiders webs worn with a gold spider clasp billowing over his back. His armour is an incredibly tiny weave of chain mesh, blackened with ashes to help camoflague it. The delicate, almost beautiful chain flows over his upper arms and thighs, with the torso covered by a tunic. The tunic bears a simplistic rendering of a arachnid of some discription, a red slit on it's abdomen designating this warrior as part of an invasion force or raiding party.");
    set_die( (: call_other, this_object(), "death_func":) );
    call_out("arm", 1);
}

int arm(){

    new(ARM"drow_chainmail.c")->move(this_object());
    new(ARM"drow_cloak.c")->move(this_object());
    new(ARM"drow_tunic.c")->move(this_object());
    new(ARM"drow_helm.c")->move(this_object());
    style = wepstyles[random(sizeof(wepstyles))];

    switch(style) {
    case "one sword":
	new(WEP"drow_sword.c")->move(this_object());
	break;
    case "two swords":
	new(WEP"drow_sword.c")->move(this_object());
	new(WEP"drow_sword.c")->move(this_object());
	break;
    case "sword and shield":
	new(WEP"drow_sword.c")->move(this_object());
	new(ARM"drow_shield.c")->move(this_object());
	break;
    case "spear":
	new(WEP"drow_spear.c")->move(this_object());
	break;
    case "one axe":
	new(WEP"drow_axe.c")->move(this_object());
	break;
    case "two axes":
	new(WEP"drow_axe.c")->move(this_object());
	new(WEP"drow_axe.c")->move(this_object());
	break;
    case "katana":
	new(WEP"drow_katana.c")->move(this_object());
	break;
    case "diasho":
	new(WEP"drow_katana.c")->move(this_object());
	new(WEP"drow_wakizashi.c")->move(this_object());
	break;
    }

    switch(style) {
    case "one sword":
	this_object()->force_me("wield sword");
	break;
    case "two swords":
	this_object()->force_me("wield sword");
	this_object()->force_me("wield sword 2");
	break;
    case "sword and shield":
	this_object()->force_me("wield sword");
	this_object()->force_me("wear shield");
	break;
    }

    this_object()->force_me("wear chainmail");
    this_object()->force_me("wear cloak");
    this_object()->force_me("wear tunic");
    this_object()->force_me("wear helm");

}

int death_func() {

    if (random(15) != 5)
    {
	message("say", "The drow slumps over, dark ichor spraying out from his various wounds. Within seconds a shimmering light envelops his body, then he is gone.", environment(this_object()));
	this_object()->move("/d/nopk/standard/void.c");
	return 1;
    }
    else
    {
	message("say", "The drow slumps over, dark ichor spraying out from his various wounds. He twitches then lays still.", environment(this_object()));
	return 1;
    }

}

int is_invincible() {

    if (this_player()->query_race() == "dragon")
    {
	message("say", "The drow blinks in disbelief, then growls.", environment(this_object()));
	this_object()->force_me("say I don't know how you escaped our purges, but you'll soon join your cousins in death's cold embrace!");
	return 0;
    }
    else
    {
	message("say", "The drow snarls angrily, rushing towards you.", environment(this_object()));
	this_object()->force_me("say Time to die, surfacer scum!");
	return 0;
    }
}

void init() {
    ::init();
    if(this_player())
	if (this_player()->query_race() == "drow")
	{
	    return 1;
	}
    if (this_player()->query_race() == "dragon")
    {
	message("say", "The drow blinks in disbelief, then growls.", environment(this_object()));
	this_object()->force_me("say I don't know how you escaped our purges, but you'll soon join your cousins in death's cold embrace!");
	this_object()->force_me("kill "+this_player()->query_name());
	return 1;
    }
    else
    {
	message("say", "The drow snarls angrily, rushing towards you.", environment(this_object()));
	this_object()->force_me("say Time to die, surfacer scum!");
	this_object()->force_me("kill "+this_player()->query_name());
	return 1;
    }
}
