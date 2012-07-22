#include <std.h>
#include <locations.h>
inherit OBJECT;
string envname, envlong, envpath;
int ok;
void create() {
    ::create();
    set_id(({"wax", "ball", "ball of wax"}));
    set_name("can of wax");
    set_long("A can of %^GREEN%^Tourtoise%^RESET%^ wax.");
    set_short("a can of wax");
    set_weight(4);
    set_curr_value("gold", 1000);
    set_property("magic item", ({"mark","break"}) );
    if(!ok)
	ok = 0;
}
void init() {
    ::init();
    if( environment( this_object() ) )
	if( present( "ball of wax 31", environment( this_object() ) ) )
	    call_out( "meld_seal", 1 );
    add_action("markamon", "mark");
    if (ok == 1) {
	add_action("breakingz0r", "break");
    }
}
int markamon(string str) {
    object tp, env;
    tp = this_player();
    if (!str || str == "") {
	write("You must give a name for the location.");
	return 1;
    }
    if(sscanf(str,"%*s %*s") == 2) {
	notify_fail("Use only one word to mark the seal with.\n");
	return 0;
    }
    env = environment(tp);
    if (env->query_property("no teleport")) { write("You cannot make a seal of this spot.\n"); return 1;}
    envname = str;
    envlong = env->query_long();
    add_action("breakingz0r", "break");
    remove_action("markamon", "mark");
   write("\n%^BOLD%^%^WHITE%^You make a marking of this location inside the can of wax.%^RESET%^");
   set_short("A can of Tourtoise wax with a marking of "+envname);
   set_long("A can of Tourtoise wax with %^CYAN%^"+envname+"%^RESET%^ etched into the wax inside.");
    set_id(({"can","tourtoise wax","wax", envname}));
    envpath = base_name(env);
    ok = 1;
    return 1;
}
int breakingz0r(string str) {
    object tp, env;
    tp = this_player();
    if (!str || str != envname) {
	notify_fail("%^BOLD%^RED%^You must break "+envname+".%^RESET%^\n");
	return 0;
    }
    if (environment(this_player())->query_property("no teleport")) { write("You cannot break a seal here.\n"); return 1;}
    if (this_player()->query_current_attacker()){ write("You cannot do this in battle!\n"); return 1;}
    if (this_player()->query_arena()) { write("You cannot do this in the arena!"); return 1;}
    env = load_object(envpath);
    write("%^BOLD%^%^GREEN%^Mystical energies engulf you!\n%^RESET%^");
    tell_room(environment(tp), "%^BOLD%^%^GREEN%^Mystical energies engulf "+this_player()->query_cap_name()+"!\n%^RESET%^", ({ this_player() }));
    remove_action("breakingz0r", "break");
    this_object()->move(TEMP_LOC);
    call_out("goingalready", 6, tp);
    return 1;
}
int goingalready(object tp) {
    object env;
    env = load_object(envpath);
    write("\n%^BOLD%^GREEN%^You appear in a new location!\n%^RESET%^");
    message("info", "%^BOLD%^%^GREEN%^"+tp->query_cap_name()+" vanishes from sight!%^RESET%^", environment(tp), tp);
    tp->move_player(env);
    this_object()->remove();
    return 1;
}
mixed *query_auto_load() {
    if (this_player()->query_level() >= 20)
	return ({"/d/nopk/tirun/obj/misc/seal_blank.c", ({envname, envlong, envpath, ok}) });
    else
	return 0;
}
void init_arg(mixed *stuff) {
    envname = stuff[0];
    envlong = stuff[1];
    envpath = stuff[2];
    ok = stuff[3];
    if(ok) {
        set_short("A can of Tourtoise Wax with "+envname+" engraved inside the wax.");
	set_long("A can of Tourtoise Wax marked with the location of "+envname+".\n");
    set_id(({"can","tourtoise wax","wax", envname}));
    }
}

void meld_seal() {
   write("The can of Tourtoise Wax melts from your hands.");
    this_object()->remove();
}

