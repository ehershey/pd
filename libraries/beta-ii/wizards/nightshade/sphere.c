#include <std.h>
#include <locations.h>
inherit OBJECT;
string envname, envlong, envpath;
int ok;

void create() {
::create();
set_id(({"sphere", "glass", "glass sphere"}));
set_name("glass sphere");
set_long("A perfect sphere of glass. The inside is flawless and so clear as to be almost invisible.");
set_short("Glass sphere (blank)");
set_weight(5);
set_curr_value("gold", 250);
if(!ok)
  ok = 0;
this_object()->remove();
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
    env = environment(tp);
    if (env->query_property("no teleport")) {
       write("%^BOLD%^%^BLACK%^You concentrate, but the sphere cannot focus.%^RESET%^");
       return 1;
       }
    envname = str;
    envlong = env->query_long();
    add_action("breakingz0r", envname);
    remove_action("markamon", "mark");
    write("\n%^BOLD%^%^WHITE%^You focus on the sphere and it slowly fills with a light "
          "mist.%^RESET%^\n");
    set_short("Glass sphere ("+envname+")");
    set_long("A perfect sphere of glass. The inside is filled with a white "
                            "mist, it slowly coalesces into an image:\n\n"+envlong+"\n");
    set_id(({"sphere", "glass", "glass sphere", envname}));
    envpath = base_name(env);
    ok = 1;
    return 1;
}

int breakingz0r(string str) {
    object tp, env;
    tp = this_player();
    if (!str || str != "smash") {
       write("%^BOLD%^%^BLACK%^You must smash the sphere.%^RESET%^");
       return 1;
       }
    if (environment(tp)->query_property("no teleport") || tp->query_arena()) {
       write("%^BOLD%^%^BLACK%^You cannot use the sphere in this place.%^RESET%^");
       return 1;
       }
    if (tp->query_current_attacker()) {
       write("%^BOLD%^%^BLACK%^You are too busy fighting!%^RESET%^");
       return 1;
       }
    env = find_object(envpath);
    write("%^BOLD%^%^WHITE%^You heft the sphere above your head, then smash it on the ground.%^RESET%^");
    message("info", "%^BOLD%^%^WHITE%^"+tp->query_cap_name()+" holds a glass sphere over his head, then abruptly smashes it on the ground.%^RESET%^", environment(tp), tp);
    message("info", "%^BOLD%^%^WHITE%^A white mist begins to form.%^RESET%^", env, );
    remove_action("breakingz0r", envname);
    this_object()->move(TEMP_LOC);
    call_out("goingalready", 3, tp);
    return 1;
}

int goingalready(object tp) {
    object env;
    env = find_object(envpath);
    message("info", "\n%^BOLD%^%^WHITE%^A white mist engulfs you!%^RESET%^\n", tp);
    message("info", "%^BOLD%^%^WHITE%^A white mist engulfs "+tp->query_cap_name()+"!%^RESET%^", environment(tp), tp);
    tp->move_player(env);
    message("info", "%^BOLD%^%^WHITE%^The mist subsides.%^RESET%^", env, );
    this_object()->remove();

    return 1;
}

mixed *query_auto_load() {
    return ({"/wizards/nightshade/sphere.c", ({envname, envlong, envpath, ok}) });
}

void init_arg(mixed *stuff) {
    envname = stuff[0];
    envlong = stuff[1];
    envpath = stuff[2];
    ok = stuff[3];
    if(ok) {
        set_short("Glass sphere ("+envname+")");
        set_long("A perfect sphere of glass. The inside is filled with a white "
                 "mist, it slowly coalesces into an image:\n\n"+envlong+"\n");
        set_id(({"sphere", "glass", "glass sphere", envname}));
    }
}
