#include <std.h>
#include <locations.h>
inherit OBJECT;
object ob, env;
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
ob = this_object();
set_property("magic item", ({"seal"}) );
if(!ok)
  ok = 0;
}
void init() {
   ::init();
     add_action("markamon", "mark");
     if (ok == 1) {
        add_action("breakingz0r", envname);
        }
}
int markamon(string str) {
    object tp, env;
    tp = this_player();
    if (!str || str == "") {
       write("You must give a name for the location.");
       return 1;
       }
    if (environment(this_player())->query_property("no teleport")) return notify_fail("You cannot make a seal of this spot.\n");
    envname = str;
    env = environment(tp);
    envlong = env->query_long();
    add_action("breakingz0r", envname);
    remove_action("markamon", "seal");
    write("\n%^BOLD%^WHITE%^You mark the wax with a location.\n%^RESET%^");
    ob->set_short("A seal marked with "+envname+".");
    ob->set_long("A small hardened wax seal marked with the location of "+envname+".\n");
    ob->set_id(({"seal", "marked seal", envname}));
    envpath = base_name(env);
    ok = 1;
    return 1;
}
int breakingz0r(string str) {
    object tp, env;
    tp = this_player();
    if (!str || str != "break") {
       write("%^BOLD%^BLACK%^You must break the seal.%^RESET%^");
       return 1;
       }
    if (environment(this_player())->query_property("no teleport")) return notify_fail("You cannot break a seal here.\n");
    if (this_player()->query_current_attacker()) return notify_fail("You cannot do this in battle!\n");
    if (this_player()->query_arena()) return notify_fail("You cannot do this in the arena!");
    env = find_object(envpath);
    write("%^BOLD%^GREEN%^Mystical energies engulf you!\n%^RESET%^");
    message("info", "%^BOLD%^GREEN%^Mystical energies engulf "+this_player()->query_cap_name()+"!\n", environment(tp), tp);
    remove_action("breakingz0r", envname);
    this_object()->move(TEMP_LOC);
    call_out("goingalready", 3, tp);
    return 1;
}
int goingalready(object tp) {
    message("info", "%^BOLD%^WHITE%^A white mist engulfs "+tp->query_cap_name()+"!%^RESET%^", environment(tp), tp);
    tp->move_player(env);
    message("info", "%^BOLD%^GREEN%^"+tp->query_cap_name()+" vanishes from sight!", env, );
    ob->remove();
    return 1;
}
mixed *query_auto_load() {
    if (this_player()->query_level() > 19)
      return ({"/wizards/stormbringer/seal_blank.c", ({envname, envlong, envpath, ok}) });
    else
      return 0;
}
void init_arg(mixed *stuff) {
    envname = stuff[0];
    envlong = stuff[1];
    envpath = stuff[2];
    ok = stuff[3];
    if(ok) {
    ob->set_short("A seal marked with "+envname+".");
    ob->set_long("A small hardened wax seal marked with the location of "+envname+".\n");
    ob->set_id(({"seal", "marked seal", envname}));
    }
}
