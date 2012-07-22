#include <std.h>
#include <daemons.h>
inherit DAEMON;

int spell();

int cmd_inferno(string str) {
    int dmg;
    object ob, tp, env;

    if (!spell()) return 0;
    tp = this_player();
    env = environment(tp);
    if (!str) ob = tp->query_current_attacker();
    else ob = present(str, env);

    if (!ob) {
	if (!str)
	    notify_fail("You do not see "+str+" here.\n");
	return 0;
    }
    if (tp->query_class() != "mage" || tp->query_subclass() != "pyromancer")
	return notify_fail("What?\n");

    if (this_player()->query_disable())
	return notify_fail("You are busy.\n");

    if (tp->query_level() < 25)
	return notify_fail("You cannot cast this.\n");

    if (env->query_property("no attack") || env->query_property("no magic"))
	return notify_fail("Greater powers prevent your malice.\n");

    if (!living(ob))
	return notify_fail("Syntax: <inferno [living]>\n");

    if (tp->query_skill("pyromancy") < 100)
	return notify_fail("Your conjuring is not strong enough.\n");

    if (ob == tp)
	return notify_fail("The flames will not turn upon it's caster\n");

    if (tp->query_mp() < 100) 
	return notify_fail("Your spell fails, due to lack of magic.\n");

    if(!this_player()->kill_ob(ob)) {
	write(ob->query_cap_name()+" can't be attacked by you yet.");
	return 1;
    }
    dmg = tp->query_skill("magic attack")/2 + tp->query_skill("pyromancy");
    dmg += tp->query_stats("wisdom")/2;
    dmg -= ob->query_stats("wisdom");
    dmg -= ob->query_skill("magic defense")/2;
    dmg *= 3/2;
    if (dmg < 1) {
	write("Your spell fails.");
	tell_room(env, tp->query_cap_name()+"'s spell fails.", ({ tp }));
	return 1;
    }
    tell_room(env, "%^RED%^"+tp->query_cap_name()+" magically turns "
      "into a raging inferno"+ob->query_cap_name()+"!%^RESET%^", ({ ob, tp }));
    write("%^RED%^You magically create a raging inferno around
"+ob->query_cap_name()+"!%^RESET%^");
   tell_object(ob, "%^RED%^"+tp->query_cap_name()+" magically turns "
     "you into a flaming inferno!%^RESET%^");
   tp->add_mp(-dmg/7);
   tp->set_casting(dmg + random(tp->query_level()/2));
   tp->set_disable();
   return 1;
}

void help() {
write("
Syntax: <inferno [victim]>
This powerful pyromancer attack spell which turns their opponent
into a raging inferno.
");
}

int spell() {
   object o;
   o = this_player();
   if ((o) && (o->query_subclass() == "pyromancer") && (o->query_level() >= 25) && (o->query_skill("pyromancy") >= 100))
     return 1;
 return 0;
}
