//  _burn.c
//      Mage ability
//      Written 15194 by Bohemund
//      base upon _missile.c
#include <std.h>
inherit DAEMON;
int spell();
int cmd_burn(string str) {
    object tp, ob;
    int attack, wisdom, skip, which, i, x;
    string what, oi;
    object *inv;
   if (!spell()) {
      notify_fail("What?\n");
      return 0;
   }
    this_player()->set_magic_round();
    tp = this_player();
    if(tp->query_ghost()) {
        notify_fail("Your voice is hollow.\n");
        return 0;
    }
    if((string)tp->query_class() != "mage") {
        notify_fail("You feel confused.\n");
        return 0;
     }
if((string)tp->query_subclass() != "pyromancer" && (string)tp->query_subclass() != "sorceror") {
      notify_fail("You feel confused.\n");
      return 0;
    }
    if (this_player()->query_disable())
       return notify_fail("You are busy.\n");
    if(environment(tp)->query_property("no magic")) {
        notify_fail("Something seems to be blocking your concentration.\n");
        return 0;
    }
    if(tp->query_casting()) return 1;
    if((int)tp->query_mp() < 15+ random(10)) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            notify_fail("Burn what?\n");
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
        notify_fail("Not an incredibly intelligent idea.\n");
        return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
        notify_fail("You cannot attack link-dead players.\n");
        return 0;
    }
    if(ob->query_property("no magic")) {
      notify_fail(sprintf("%s is immune to such magic.\n",
                  ob->query_cap_name()));
      return 0;
    }
    attack = ((int)tp->query_skill("magic attack") + (int)tp->query_skill("wisdom")/2);
    if (tp->query_subclass() != "pyromancer")
        attack *= 3/2;
    wisdom = (int)ob->query_stats("wisdom")/2 + (int)ob->query_skill("magic defense")/2;
    attack -= wisdom;
    if(attack < 1) attack = 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    write("%^RED%^You attempt to burn your opponent!");
    tell_room(environment(tp), "%^RED%^%^BOLD%^"+(string)ob->query_cap_name()+
              " screams in agony as "+ob->query_title_gender()+
              " skin begins to smoke!\n%^RESET%^", ({ ob, tp }));
    tell_object(ob, "%^RED%^%^BOLD%^"+tp->query_cap_name()+
                " grins as you begin to sweat!");
    x = (int)ob->query_hp();
    tp->set_casting(attack + (random(tp->query_level())/2));
    tp->add_skill_points("magic attack", attack/20 + 2);
    tp->add_mp(-attack /7);
    tp->set_disable();
   if ((x - attack) < 1) {
   if ((string)ob->query_gender() == "male") {
    oi = "his";
   } else oi = "her";
    tell_room(environment(tp), "%^BOLD%^%^RED%^"+
              (string)ob->query_cap_name()+
              " releases a piercing scream as "+
              oi+
              " body bursts into flames!%^RESET%^", ({ ob }));
   }
    return 1;
}
void help() {
    write("Syntax: <burn [(living)]>\n"
        "This spells causes your opponents body heat to rise, thereby causing "
        "spontanious combustion.\n");
}
int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_class() != "mage") return 0;
   if (tp->query_subclass() != "pyromancer" && tp->query_subclass() != "sorceror") return 0;
   if (tp->query_level() < 2) return 0;   
   return 1;
}
