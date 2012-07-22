// assassin demon for the summon spell
// a dungeonware.net collaboration with
// -(Inferno)-
// Epiton Roston Verlin Drannor 
#include <std.h>
#include <sindarii.h>
#include <daemons.h>
inherit MONSTER;
static string owner;
static object ob, pl;
int knife_wielded=0;
void create() {
    ::create();
    ob = this_object();
    set_name("assassin");
    set_id( ({ "abyss demon", "assassin", "demon", "assassin demon" }) );
    set_gender("male");
    set_short("an assassin demon");
    set("aggressive", 0);
    set_heart_beat(1);
    set_level(22);
    set_exp(0);
    set_long("The assassin demon looks like a human with oil "
      "black skin and blazing white eyes. Two horns jut "
      "out of it's head, leading down it's spine.");
    set_body_type("human");
    set_alignment(-1000);
    set("race", "demon");
    set_hp(query_max_hp());
    set_mp(query_max_mp());
    set_sp(query_max_sp());
    set_class("rogue");
    set_spell_chance(40);
    set_spells( ({ "stab" }) );
    new(ROOMS"abyss/obj/ak")->move(ob);
    set_skill("murder", 100);
    set_skill("knife", 80);
    set_stats("dexterity", 50);
    set_stats("strength", 40);
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
    if (random(90) > (int)this_player()->query_skill("faith")) {
	x=random(20);
	switch (x) {
	case 1:
	    write("Assassin ignores your command!");
	    return 1;
	    break;
	case 4:
	    write("Assassin ignores your command!");
	    return 1;
	    break;
	case 10:
	    write("Assassin breaks out of your control!");
	    this_object()->kill_ob(pl, 0);
	    owner = "blah";
	    pl = (object)"";
	    return 1;
	    break;
	case 15:
	    write("Assassin ignores your command!");
	    return 1;
	    break;
	case 19:
	    write("Assassin breaks out of your control!");
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
	ob->force_me("say   stab");
	ob->force_me("say I have the following special abilities:");
	ob->force_me("say   <reveal powers>, <assassinate>");
	ob->force_me("say  <assassinate [logged_on_player]>");
	ob->force_me("say I am level 20");
	return 1;
    }
    if (order == "die" || order == "suicide") {
	tell_room(environment(ob), "%^BOLD%^%^BLACK%^Assassin turns a pale grey "+
	  "and slumps down dead before you.\n", ({ ob }));
	ob->die();
	return 1;
    }
    if (sscanf(order, "backstab %s", victim)==1) { 
	return 1;
    }
    if (sscanf(order, "assassinate %s", victim)==1) { 
	if (present(victim, environment(this_object()))) {
	    val = sprintf("kill %s", victim);
	    ob->force_me(val);
	    return 1;
	} else {
          if (this_player()->query("summon_assassin_time")+60 > time()) return 1;
          this_player()->set("summon_assassin_time", time());
	    if (!(oi=find_living(victim = lower_case(victim)))) {
		write("<assassinate [logged_on_player]>");
		return 1;
	    }
	    owner = "blah";
	    pl = (object)"";
	    if (oi->query_level() < 20) {
                this_object()->set_hp(-1000);
		return 1;
	    }
            this_object()->move(environment(oi));
	    val = sprintf("kill %s", victim);
	    this_object()->force_me(val);
	    return 1;
	}
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
    if (!this_object() || !environment() || !pl) return;
    if (!knife_wielded) 
    {
	this_object()->force_me("wield knife in right hand");
	knife_wielded=1;
    }
    if (owner == "blah") return;
    if(!pl) this_object()->remove();
    if(!interactive(pl)) this_object()->remove();
    if(!this_object()) return;
    if (environment(this_object()) != environment(pl)) {
	if(file_name(environment(pl))[0..8] == "/d/arena/") {
	    message("", "The demon turns to dust.\n", environment(this_object()));
	    this_object()->remove();
	    return;
	}        
	message("info", "%^BOLD%^%^BLACK%^Assassin follows its master.%^RESET%^\n", environment(ob));
	this_object()->move(environment(pl));
	message("info", "%^BOLD%^%^BLACK%^Assassin enters, with a wicked grin spread across his face.%^RESET%^\n", environment((object)owner));
    }
    shade = all_inventory(environment(this_object()));
    if(pl != (object)"")
	for(int i=0;i<sizeof(shade);i++)
	    if((shade[i]->id("abyss demon")) && (shade[i] != this_object())) {
		message("info", "The assassin leers at the other demon and revolts!",environment(ob));
		this_object()->kill_ob(pl, 0);
		pl = (object)"";
		owner = "blah";
	    }
}
