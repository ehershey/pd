#include <std.h>
inherit ARMOUR;
string whohasme;
void create () {
	::create();
        set_properties(([ "no steal":1 ]));
}
void ethereal_security() {
        if (
		this_player()->query_guild() != "ethereal" && 
		this_player()->query_cap_name() != "Homer Simpson" && 
		this_player()->query_cap_name() != "The Cheat" && 
		this_player()->query_cap_name() != "Strongbad"
		) {
                  say(""+this_player()->query_cap_name()+" was injured as he tried to take Ethereal equipment!\n");
                  write(""+this_player()->query_cap_name()+", You know better than to try aquire Ethereal equipment!\n");
                  this_player()->do_damage("torso",10);
                  this_object()->remove();
        }
}
int move(mixed dest) {
    call_out("ethereal_security", 1);
    if (this_player()) {
	whohasme = this_player()->query_cap_name();
    }
    return ::move(dest);
}
int query_auto_load() {
    if(this_player()->query_guild() != "ethereal") return 0;
    return 1;
}
string checkowner() {
	return whohasme;
}
