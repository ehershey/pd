#include <std.h>

#define TPQN this_player()->query_cap_name()

inherit OBJECT;

int loaded = 3;
string team, host = "";
string owner = "set";

void set_team(string str);
string query_team();
void set_host(string str);

int scope(string str);
int shoot(string str);
void reload_gun();

void create()
{
    ::create();
    set_name("gun");
    set_id(({ "gun", "paintball gun" }));
    set_short("%^BOLD%^YELLOW%^a gold paintball gun%^RESET%^");
    set_long("A small, gold paintball gun.  You could probably "
      "shoot someone with it.");
    set_heart_beat(1);
}

void init()
{
    add_action("scope", "scope");
    add_action("shoot", "shoot");
}

int scope(string str)
{
    object ob, env;
    tell_room(environment(this_player()), this_player()->query_cap_name()+
      " looks into the scope on "+this_player()->query_title_gender()+
      " paintball gun.", ({ this_player() }));
    if(!str) return notify_fail("Scope who?\n");

    if(!ob = find_player(str)) {
	write("%^GREEN%^You cannot see that in your scope.%^RESET%^");
	return 1;
    }
    if(ob->query_invis()) {
	write("%^GREEN%^You cannot see that in your scope.%^RESET%^");
	return 1;
    }
    if(member_array(ob, "/d/paintball/start"->query_players()) == -1) {
	write("%^GREEN%^You cannot see that in your scope.%^RESET%^");
	return 1;
    }
    env = environment(ob);
    write("%^GREEN%^You see "+ob->query_cap_name()+" in your scope at:%^BOLD%^ "
      +env->query_short()+"%^RESET%^\n");
    return 1;
}

int shoot(string str)
{
    object ob;

    if (!str || !(ob = find_player(str))) {
	return notify_fail("Shoot who?\n");
    }

    ob = present(str, environment(this_player()));

    if (!ob) {
	write("You do not see "+str+" here.");
	return 1;
    }

    if (!present("gun", ob)) {
	write(ob->query_cap_name()+" is not playing paintball tag!");
	ob->move("/d/standard/square");
	return 1;
    }

    if (!loaded) {
	write("You are still reloading");
	return 1;
    }

    if (ob->query_paralyzed()) {
	return notify_fail("That player has already been shot.\n");
	loaded = 0;
    }

    write("%^GREEN%^You shoot "+ob->query_cap_name()+"!%^RESET%^");
    tell_object(ob, ""+this_player()->query_cap_name() +" shoots you with a         paintball gun!");
    tell_room(environment(ob), this_player()->query_cap_name()+" shoots             "+ob->query_cap_name()+" with "+this_player()->query_title_gender()+"       paintball gun!", ({this_player(), ob }));
    if (present("gun", ob)->query_team() == team)
    {
	write("You shot your own team.  You lose points.");
	add_point(1);
    }
    else add_point(0);
    ob->set_paralyze("You are in pain from the shot.", 2);
    call_out("reload_gun", 5, this_player());
    return 1;
}

void reload_gun()
{
    tell_room(environment(this_player()), ""+this_player()->query_cap_name()+" reloads "+this_player()->query_title_gender()+ "paintball gun!"), ({this_player() });
    write("%^MAGENTA%^You reload your paintball gun.");
    loaded = 3;
}

void set_team(string str) { team = str; }

string query_team() { return team; }

void set_host(string str) { host = str; }
string query_host() { return host; }
void add_point(int i)
{
    object ob;

    if (host == "") {
	write("%^BOLD%^YELLOW%%^Could not find game host.%^RESET%^");
	this_player()->move("/d/standard/square");
	this_object()->remove();
	return;
    }
    ob = find_living(host);
    if (i) present("slab", ob)->do_points(team, 1);
    else
	present("slab", ob)->do_points(team, 0);
}

void heart_beat()
{
    if (environment() != find_player(owner))
    {
	message("tp", "%^BOLD%^MAGENTA%^The paintball gun returns to its Master.%^RESET%^", find_player(owner));
	this_object()->move(find_player(owner));
    }
}

int query_auto_load()
{
    if (this_player()->query_name() == "set")
    {
	return 1;
    }
}

