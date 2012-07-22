#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("whistle");
    set("id", ({"whistle"}) );
    set_short("%^BOLD%^BLACK%^Death%^RESET%^ Whistle");
    set_long("This is something special for you.");
}

void init() {
    add_action("blow", "blow");
}

int query_auto_load()
{
    if (this_player()->query_name() == "bellos") return 1;
}

int blow(string str) {
    object ob;

    if (str == "whistle") {
	write("You blow on the whistle and summon forth a hellhound!");
	ob = new("/std/monster.c");
	ob->set_name("hellhound");
	ob->set_short("%^RED%^H%^RED%^BOLD%^e%^RESET%^RED%^l%^RED%^BOLD%^l%^RESET%^RED%^h%^RED%^BOLD%^o%^RESET%^RED%^u%^RED%^BOLD%^n%^RESET%^RED%^d");
	ob->set_long("This hellhound was sent straight from hell to serve his master.");
	ob->set_gender("male");
	ob->set_race("demon");
	ob->set_body_type("canine");
	ob->move(environment(this_player()));
	return 1;
    }
}



