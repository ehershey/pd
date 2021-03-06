#include <std.h>
#include <locations.h>
inherit OBJECT;
string envname, envlong, envpath;
int ok;
void create() {
::create();
set_id(({"wax", "ball", "ball of wax"}));
set_name("ball of wax");
set_long("A small ball of wax used to make a seal.");
set_short("a ball of wax");
set_weight(2);
set_curr_value("gold", 1000);
set_property("magic item", ({"mark","break"}) );
if(!ok)
  ok = 0;
}
void init() {
   ::init();
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
    env = environment(tp);
    if (env->query_property("no teleport")) return notify_fail("You cannot make a seal of this spot.\n");
    envname = str;
    envlong = env->query_long();
    add_action("breakingz0r", "break");
    remove_action("markamon", "mark");
    write("\n%^BOLD%^WHITE%^You mark the wax with a location.\n%^RESET%^");
    set_short("A seal marked with "+envname+".");
    set_long("A small hardened wax seal marked with the location of "+envname+".\n");
    set_id(({"seal", "marked seal", envname}));
    envpath = base_name(env);
    ok = 1;
    return 1;
}
int breakingz0r(string str) {
    object tp, env;
    tp = this_player();
    if (!str || str != envname) {
       write("%^BOLD%^RED%^You must break "+envname+".%^RESET%^");
       return 1;
       }
    if (environment(this_player())->query_property("no teleport")) return notify_fail("You cannot break a seal here.\n");
    if (this_player()->query_current_attacker()) return notify_fail("You cannot do this in battle!\n");
    if (this_player()->query_arena()) return notify_fail("You cannot do this in the arena!");
    env = find_object(envpath);
    write("%^BOLD%^%^GREEN%^Mystical energies engulf you!\n%^RESET%^");
    tell_room(environment(tp), "%^BOLD%^%^GREEN%^Mystical energies engulf "+this_player()->query_cap_name()+"!\n%^RESET%^", ({ this_player() }));
    remove_action("breakingz0r", "break");
    this_object()->move(TEMP_LOC);
    call_out("goingalready", 3, tp);
    return 1;
}
int goingalready(object tp) {
    object env;
    env = find_object(envpath);
    write("\n%^BOLD%^GREEN%^You appear in a new location!\n%^RESET%^");
    message("info", "%^BOLD%^%^GREEN%^"+tp->query_cap_name()+" vanishes from sight!%^RESET%^", environment(tp), tp);
    tp->move_player(env);
    this_object()->remove();
    return 1;
}
mixed *query_auto_load() {
    if (this_player()->query_level() >= 20)
      return ({"/d/tirun/obj/misc/seal_blank.c", ({envname, envlong, envpath, ok}) });
    else
      return 0;
}
void init_arg(mixed *stuff) {
    envname = stuff[0];
    envlong = stuff[1];
    envpath = stuff[2];
    ok = stuff[3];
    if(ok) {
    set_short("A seal marked with "+envname+".");
    set_long("A small hardened wax seal marked with the location of "+envname+".\n");
    set_id(({"seal", "marked seal", envname}));
    }
}
