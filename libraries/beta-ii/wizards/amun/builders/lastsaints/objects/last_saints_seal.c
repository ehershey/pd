#include <std.h>
#include <amun.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("seal");
    set_short("%^BOLD%^%^BLACK%^Seal of the Last Saints%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This is a flexible disc that has a picture of the Last Saints guild hall on it.");
    set_weight(1);
    set_curr_value("gold", 200);
    set_id(({ "seal", "last saints seal", "last saint seal" }));
    set_property("magic item", ({"break"}) );
}
void init() {
    ::init();
    add_action("crack", "break");
}
int crack(string str) {
    object tp;
    tp = this_player();
    if (tp->query_guild() != "last saints") return 0;
    if (str != "seal") return 0;
    if (environment(tp)->query_property("no teleport")) return notify_fail("You cannot do that here.\n");
    if (tp->query_current_attacker()) return notify_fail("You cannot do that in battle!\n");
    if (tp->query_arena()) return notify_fail("You cannot do that in the arena!");
    write("%^BOLD%^%^WHITE%^A white light surrounds you, pulling you in!%^RESET%^\n");
    tell_room(environment(tp), "$%BOLD%^%^WHITE%^A white light surrounds "+this_player()->query_cap_name()+" and pulls them in!\n", ({ this_player() }));
    remove_action("crack", "break");
    call_out("goingalready", 6, tp);
    return 1;
}
int goingalready(object tp) {
    int sps;
    write("\n%^BOLD%^%^YELLOW%^Welcome to the Last Saints guild hall!\n");
    message("info", ""+tp->query_cap_name()+" says, 'BYE BYE!'", environment(tp), tp);
    if((sps = this_player()->query_sp()) < 0)
	this_player()->set_sp(20);
    this_player()->move_player(GUILDROOM"level1_1", "ninja like!");
    this_player()->set_sp(sps);
    this_object()->remove();
    return 1;
}
int query_auto_load() {
    if(this_player()->query_guild() == "last saints")
	return 1;
    return 0;
}
