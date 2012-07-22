// _shock.c
//      Mage ability
//      Written 131092 by Descartes of Borg

#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();

string type() { return "attack"; }

int cmd_shock(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i;
    string what;
    object *inv;

   if (!spell()) {
      return 0;
   }
    this_player()->set_magic_round();
    tp = this_player();
    if(tp->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if((string)tp->query_class() != "mage") {
        write("You mumble in confusion.");
        say(tp->query_cap_name()+" mumbles in confusion.", tp);
        return 1;
    }

    if (this_player()->query_disable())
       return notify_fail("You are busy.\n");

    if(environment(tp)->query_property("no magic") ||
       environment(tp)->query_property("no attack")) {
        notify_fail("Something seems to be blocking your concentration.\n");
        return 0;
    }
    if(tp->query_casting()) return 1;
    if((int)tp->query_mp() < 16) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            notify_fail("Shock what?\n");
            return 0;
        }
    }
    else {
        ob = present(str, environment(tp));
        if(!ob) {
            sscanf(str, "%s %d", what, which);
            inv = all_inventory(environment(tp));
            for(i=0, skip = 0; i<sizeof(inv) && !ob; i++) {
                if(inv[i]->id(what)) {
                    skip++;
                    if(skip == which) ob = inv[i];
                }
            }
            if(!ob) {
                notify_fail("No "+str+" here!\n");
                return 0;
            }
        }
    }
    if(!living(ob)) {
        notify_fail(ob->query_cap_name()+" is not a living thing!\n");
        return 0;
    }
    if(ob==tp) {
        notify_fail("Not a very bright idea.\n");
        return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
        notify_fail("You cannot attack link-dead players.\n");
        return 0;
    }
    if(ob->query_property("no shock")) {
      notify_fail(sprintf("%s is immune to electrical attacks.\n",
                  ob->query_cap_name()));
      return 0;
    }
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    attack = BALANCE_D->get_damage( tp, ob, 1, ({ "magic attack" }),
                                   ({ "wisdom" }) );
    if(attack < 1) attack = 1;

    write("%^ORANGE%^You cast shock.");
    tell_room(environment(tp), "%^ORANGE%^"+tp->query_cap_name()+
              " casts shock at " + (string)ob->query_cap_name() + ".",
              ({ ob, tp }));
    tell_object(ob, "%^ORANGE%^"+tp->query_cap_name()+
                " casts shock at you.");
    tp->set_casting(attack);
    tp->add_skill_points("magic attack",  (1+attack/25) * 2 );
    tp->add_mp(-attack/7);
    tp->set_disable();
    return 1;
}

void help() {
    write("Syntax: <shock [(living)]>\n"
        "Casts a shock at the living object named, or, if in "
        "battle and no arguments are used, at your current opponent.\n");
}

int spell() {
   object o;
   o = this_player();
   if (!o) return 0;
if(o->query_subclass() == "wizard") return 0;
   if (o->query_class() != "mage") return 0;
   if (o->query_subclass() != "wizard") return 0;
   if (o->query_level() < 2) return 0;
   return 1;
}

