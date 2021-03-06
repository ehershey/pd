#include <std.h>
#include <amun.h>
#include <locations.h>
inherit OBJECT;
string envname, envlong, envpath;
int ok;
void create() {
    ::create();
    set_id(({"compass", "saints", "saints compass"}));
    set_name("Saints Compass");
    set_long("%^RESET%^%^ORANGE%^This Compass is a copper color except the middle, there is a %^BOLD%^%^WHITE%^clear misty center %^RESET%^%^ORANGE%^where it will flash the area it is marked for.%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^S%^WHITE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^t%^WHITE%^s %^RESET%^%^ORANGE%^C%^BOLD%^%^WHITE%^o%^RESET%^ORANGE%^m%^BOLD%^%^WHITE%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^s%^RESET%^");
    set_weight(1);
    set_curr_value("gold", 500);
    set_property("magic item", ({"direct", "crack"}) );
}
void init() {
    ::init();
    if(ok)
	add_action("breakin", "crack");
    else
	add_action("markin", "direct");
}
int markin(string str) {
    object tp, env;
    tp = this_player();
    if(tp->query_guild() != "last saints")
	return 0;
    if(environment(this_object()) != tp)
	return notify_fail("You have to get the compass first.\n");
    if(!str || str == "")
	return notify_fail("You must give a name for the location.\n");
    if(sscanf(str,"%*s %*s") == 2)
	return notify_fail("Use only one word to direct the compass.\n");
    env = environment(tp);
    if(env->query_property("no teleport"))
	return notify_fail("You attempt to direct the compass but it cannnot find its way.\n");
    envname = str;
    envlong = env->query_long();
    add_action("breakin", "crack");
    remove_action("markin", "direct");
    message("info", "\n%^BOLD%^%^WHITE%^You direct the compass and it finds its way.%^RESET%^\n", tp, );
    set_short("a %^BOLD%^%^BLACK%^S%^WHITE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^t%^WHITE%^s %^RESET%^%^ORANGE%^C%^BOLD%^%^WHITE%^o%^RESET%^ORANGE%^m%^BOLD%^%^WHITE%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^s%^RESET%^ ("+envname+")");
    set_long("%^RESET%^%^ORANGE%^This Compass is a copper color except the middle, there is a %^BOLD%^%^WHITE%^clear misty center %^RESET%^%^ORANGE%^where it will flash the area it is marked for:\n\n"+envlong+"\n");
    set_id(({"compass", "saints", "saints compass", envname}));
    envpath = base_name(env);
    ok = 1;
    return 1;
}
int breakin(string str) {
    object tp, env;
    tp = this_player();
    if(tp->query_guild() != "last saints")
	return 0;
    if(environment(this_object()) != tp)
	return notify_fail("You have to get the compass first.\n");
    if(present(str, tp) != this_object())
	return notify_fail("Smash what?");
    if(environment(tp)->query_property("no teleport") || tp->query_arena())
	return notify_fail("You cannot use the compass here.\n");
    if(tp->query_current_attacker())
	return notify_fail("You are too busy fighting!");
    env = load_object(envpath);
    message("info", "%^BOLD%^%^WHITE%^You take the compass in both your hands and crack it.%^RESET%^", tp, );
    message("info", ""+tp->query_cap_name()+" %^BOLD%^%^WHITE%^takes the compass both thier hands and cracks it.%^RESET%^", environment(tp), tp);
    message("info", "%^BOLD%^%^YELLOW%^You are pulled into the light.", env, );
    remove_action("breakin", "crack");
    this_object()->move(TEMP_LOC);
    call_out("goingalready", 6, tp);
    return 1;
}
int goingalready(object tp) {
    object env;
    env = load_object(envpath);
    message("info", "\n%^BOLD%^%^YELLOW%^The bright light surrounds you!\n", tp);
    message("info", "%^BOLD%^%^YELLOW%^A bright light surrounds "+tp->query_cap_name()+"!", environment(tp), tp);
    tp->move_player(env);
    message("info", "The light dims down.", env, );
    this_object()->remove();
    return 1;
}
mixed *query_auto_load() {
    if (this_player()->query_level() >= 20 && this_player()->query_guild() == "last saints")
	return ({GUILDOBJ+"saints_compass.c", ({envname, envlong, envpath, ok}) });
    else
	return 0;
}
void init_arg(mixed *stuff) {
    envname = stuff[0];
    envlong = stuff[1];
    envpath = stuff[2];
    ok = stuff[3];
    if(ok) {
	set_short("%^BOLD%^%^BLACK%^S%^WHITE%^a%^BLACK%^i%^WHITE%^n%^BLACK%^t%^WHITE%^s %^RESET%^%^ORANGE%^C%^BOLD%^%^WHITE%^o%^RESET%^ORANGE%^m%^BOLD%^%^WHITE%^p%^RESET%^%^ORANGE%^a%^BOLD%^%^WHITE%^s%^RESET%^%^ORANGE%^s%^RESET%^ ("+envname+")");
	set_long("%^RESET%^%^ORANGE%^This Compass is a copper color except the middle, there is a %^BOLD%^%^WHITE%^clear misty center %^RESET%^%^ORANGE%^where it will flash the area it is marked for:\n\n"+envlong+"\n");
	set_id(({"compass", "saints", "saints compass", envname}));
    }
}
int is_sphere() {
    return 1;
}

mixed *query_props() {
    mixed *vars;
    vars = ({envname, envlong, envpath, ok });
    return vars;
}
