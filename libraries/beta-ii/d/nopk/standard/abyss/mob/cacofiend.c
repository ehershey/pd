// assassin demon for the summon spell
// a dungeonware.net collaboration with
// -(Inferno)-
// Epiton Roston Verlin Drannor 
#include <std.h>
inherit MONSTER;

static string owner;
static object ob, pl;
int knife_wielded=0;
void create() {
    ::create();
    ob = this_object();
    set_name("cacofiend");
    set_id( ({ "abyss demon", "cacofiend", "demon", "lord" }) );
    set_gender("male");
    set_short("a cacofiend");
    set("aggressive", (this_player()->query_stats("charisma")/2));
    set_heart_beat(1);
    set_level(30);
    set_long("A horrid sight, the monsterous worm is a second "
      "demon lord of the third layer of the abyss. The "
      "beast is about a hundred feet long, but can never "
      "be stronger than it's caster. It's brilliant yellow "
      "eyes glare evilly.");
    set_body_type("worm");
    set_alignment(-10000);
    set("race", "worm");
    set_hp(query_max_hp());
    set_mp(query_max_mp());
    set_sp(query_max_sp());
    set_class("mage");
    set_subclass("conjurer");
    set_spell_chance(60);
    set_spells( ({ "bolt", "shock", "blast", "liquify", "focus" }) );
    set_skill("conjuring", (this_player()->query_skill("conjuring")*2));
    set_stats("wizdom", (this_player()->query_stats("wisdom")*2));
    set_stats("dexterity", (this_player()->query_stats("dexterity")));
    set_skill("magic attack", 100);
}

void init() {
    ::init();
    add_action("command", "command");
}

int command(string str) {
    string order, tm,  victim, val;
    int x;
    object oi;
    if ((string)this_player() != owner) return 0;
    if (random(160) > (int)this_player()->query_skill("faith")) {
	x=random(20);
	switch (x) {
	case 1:
	    write("Cacofiend ignores your command!");
	    return 1;
	    break;
	case 4:
	    write("Cacofiend ignores your command!");
	    return 1;
	    break;
	case 10:
	    write("Cacofiend breaks out of your control!");
	    this_object()->kill_ob(pl, 0);
	    owner = "blah";
	    pl = (object)"";
	    return 1;
	    break;
	case 15:
	    write("Cacofiend ignores your command!");
	    return 1;
	    break;
	case 19:
	    write("Cacofiend breaks out of your control!");
	    this_object()->kill_ob(pl, 0);
	    owner = "blah";
	    pl = (object)"";
	    return 1;
	    break;
	default:
	    break;
	}
    }
    if (!str || sscanf(str, "%s to %s", tm, order)!=2) {
	write("Syntax: <command [monster] to [command]>\n");
	return 0;
    }
    oi = present(tm, environment(this_player()));
    if (oi != this_object()) return 0;
    if (order == "reveal powers") {
	ob->force_me("say I know the following spells:");
	ob->force_me("say   bolt, shock, blast, liquify and focus");
	ob->force_me("say I have the following special abilities:");
	ob->force_me("say   <reveal powers>, <destroy>");
	ob->force_me("say  <destroy [logged_on_player]>");
	ob->force_me("say I am level 30");
	return 1;
    }
    if (order == "die" || order == "suicide") {
	tell_room(environment(ob), "%^BOLD%^%^BLACK%^Assassin turns a pale grey "+
	  "and slumps down dead before you.\n", ({ ob }));
	ob->die();
	return 1;
    }
    if (sscanf(order, "destroy %s", victim)==1) {
	if (present(victim, environment(this_object()))) {
	    val = sprintf("liquify %s", victim);
	    ob->force_me(val);

	    return 1;
	} else {
	    if (!(oi=find_living(victim = lower_case(victim)))) {
		write("<destroy [logged_on_player]>");
		return 1;
	    }
	    owner = "blah";
	    pl = (object)"";
	    this_object()->move(environment(oi));
	    val = sprintf("liquify %s", victim);
	    this_object()->force_me(val);
	    tell_room(environment(ob), "%^BOLD%^%^GREEN%^Cacofiend departs.\n", ({ ob }) );
	    destruct(ob);
	    return 1;
	}
    }
    ob->force_me(order);
    return 1;
}

void set_owner(string str) {
    owner = str;
    pl = present(str, environment(this_object()));
}

void heart_beat() {
    object *shade;
    ::heart_beat();

    if (owner == "blah") return;
    if (environment(this_object()) != environment(pl)) {
	if(file_name(environment(pl))[0..8] == "/d/arena/") {
	    message("", "The cacofiend turns to dust.\n", environment(this_object()));
	    this_object()->remove();
	    return;
	}        
	message("info", "%^BOLD%^%^BLACK%^A wave of relief overcomes you a cacofiend exits.%^RESET%^\n",environment(ob));
	this_object()->move(environment(pl));
	message("info", "%^BOLD%^%^BLACK%^The ground shakes as a cacofiend enters!%^RESET%^\n",environment((object)owner));
    }
    shade = all_inventory(environment(this_object()));
    if(pl != (object)"")
	for(int i=0;i<sizeof(shade);i++)
	    if((shade[i]->id("abyss demon")) && (shade[i] != this_object())) {
		message("info", "The cacofiend roars furiously at the other demon!",environment(ob));
		this_object()->kill_ob(pl, 0);
		pl = (object)"";
		owner = "blah";
	    }
}

