// skeleton for the raise spell
// a dungeonware.net production
#include <std.h>
#include <daemons.h>
inherit UNDEAD;
static string owner;
static object ob, pl;
void create() {
    ::create();
    ob = this_object();
    set_name("wight");
    set_id( ({ "wight undead", "wight", "undead" }) );
    set_gender("male");
    set_short("a wight");
    set("aggressive", 0);
    set_heart_beat(1);
    set_long("The wight looks as if it might have been tortured to death. It's body is "
      "all twisted with desiccated flesh pulled tight across the bones. It shows "
      "a mouth full of needle sharp teeth as it sneers.");
    set_body_type("human");
    set_alignment(-700);
    set("race", "undead");
    set_class("clergy");
    set_subclass("cleric");
    set_level(18);
    set_exp(1);
    set_hp(query_max_hp());
    set_mp(query_max_mp());
    set_sp(query_max_sp());
    set_skill("healing",4*18);
    set_skill("belief",4*18);
    set_spell_chance(25);
    set_spells( ({ "rot", "pain" }) );
}
void init() {
    ::init();
    add_action("command", "command");
}
int command(string str) {
    string order, tm;
    object oi;
    int x;
    if ((string)this_player() != owner) return 0;
    if (random(50) > (int)this_player()->query_skill("necromancy")) {
	x=random(20);
	switch (x) {
	case 1:
	    write("The wight ignores your command!");
	    return 1;
	    break;
	case 4:
	    write("The wight ignores your command!");
	    return 1;
	    break;
	case 10:
	    write("The wight breaks out of your control!");
	    this_object()->kill_ob(pl, 0);
	    owner = "blah";
	    pl = (object)"";
	    return 1;
	    break;
	case 15:
	    write("The wight ignores your command!");
	    return 1;
	    break;
	case 19:
	    write("The wight breaks out of your control!");
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
    if (present("gagger12345",this_player()) &&
        member_array(order[0..strsrch(order," ")-1],
        ({"say","yell","whisper","shout","tell","emote","emoteto","speak","reply"})) != -1 ||
        (int)sizeof(load_object(SOUL_D)->query_atmos(order[0..strsrch(order," ")-1])) >= 1) return 1;
    if (order == "reveal powers") {
	ob->force_me("say I know the following spells:");
	ob->force_me("say   rot and pain");
	ob->force_me("say I have the following special abilities:");
	ob->force_me("say   <reveal powers> and <return>");
	ob->force_me("say I am level 9");
	return 1;
    }
    if (order == "die" || order == "suicide") {
	tell_room(environment(ob), "The wight falls %^RED%^dead%^RESET%^ before you.\n"
	  "The corpse turn to dust and blows away.\n", ({ ob }));
	ob->remove();
	return 1;
    }
    if (order == "return") {
	tell_room(environment(ob), "%^BOLD%^The wight claws it's way into the ground!%^RESET%^\n", ({ ob }));
	ob->remove();
	return 1;
    }
    ob->force_me(order);
    return 1;
}
void set_owner(string str) {
    owner = str;
    pl = present(str, environment(this_object()));
    set_exp_share(pl, to_float(1/2));
}
void heart_beat() {
    object *shade;
    ::heart_beat();
    if (owner == "blah") return;
    if(!this_object() || !pl) return;
    if (environment(this_object()) != environment(pl)) {
	message("info", "A wight leaves following it's master.\n", environment(ob));
	this_object()->move(environment(pl));
	message("info", "A wight enters following it's master.\n",
	  environment((object)owner));
    }
    if(pl != (object)"")
	for(int i=0;i<sizeof(shade);i++)
	    if((shade[i]->id("wight undead")) && (shade[i] != this_object())) {
		message("info", "The wight cackles and attacks it's
owner!",environment(ob));
        this_object()->kill_ob(pl, 0);
        pl = (object)"";
        owner = "blah";
      }
}
