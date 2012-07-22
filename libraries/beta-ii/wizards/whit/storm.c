//  Dacra
//  Whit

#include <std.h>

inherit OBJECT;

static object ob;

void create() {
    ::create();
    set_name("dacra");
    set_short("a small dacra");
    set_long("This is a small dacra.  Only the ones with the gift "
      "may use this.  It is thought that one who picked it up without "
      "the gift would die.");
    set_id(({ "dacra", "small dacra" }));
}

void init() {
    ::init();
    if(this_player()->is_player())
	if(!archp(this_player()) && this_player()->query_name() != "whit" && this_player()->query_name() != "azire" ) {
	    write("Just as you touch the dacra,  smoke pours from it and "
	      "disappears.");
	    this_object()->remove();
	}
    add_action("stab", "stab");
    add_action("flash", "flash");
}

int stab(string str) {

    if(!archp(this_player()) && this_player()->query_name() != "whit" && this_player()->query_name() != "azire" ) {
	write("Just as you touch the dacra,  smoke pours from it and "
	  "disappears.");
	this_object()->remove();
    }
    if(!str) return notify_fail("Stab who?\n");
    if(!ob=present(str,environment(this_player()))) return notify_fail("You do not "
	  "notice your victim here.\n");
    if(!wizardp(ob)) return notify_fail("You may only take wizard's lifes.\n");
    write("You lunge at "+ob->query_cap_name()+" with stunning speed.\n");
    tell_object(ob, this_player()->query_cap_name()+" lunges at you with "
      "stunning speed.  As it hits you, you feel your life force drain from "
      "your body.\n");
    message("", this_player()->query_cap_name()+" lunges at "+ob->query_cap_name()+
      " with stunning speed.\n", environment(this_player()), ({this_player(), ob}) );
    this_player()->paralyze(5,"The dacra has stunned you.","");
    call_out("finish",5);
    return 1;
}

void finish() {
    ob->set_killable(1);
    ob->die();
    ob->set_killable(0);
}

int flash(string str) {
    object ob;

    if(!archp(this_player()) && this_player()->query_name() != "whit" && this_player()->query_name() != "azire" ) {
	write("Just as you touch the dacra,  smoke pours from it and "
	  "disappears.");
	this_object()->remove();
    }
    if(!ob=present(str, environment(this_player()))) return notify_fail("You do "
	  "not see your victim.\n");
    write("You flash your dacra at "+ob->query_cap_name()+".\n");
    tell_object(ob, this_player()->query_cap_name()+" flashs his dacra at "
      "you causing terrifying paralyzation.\n");
    message("", this_player()->query_cap_name()+" flashes his dacra at "+ob->query_cap_name()+
      " with paralyzing fear.\n", environment(this_player()), ({this_player(), ob}) );
    ob->set_paralyzed(10, "You are in a trance of the dacra.", "You suddenly come back "
      "to reality.\n");
    return 1;
}

