#include <std.h>
inherit DAEMON;
int spell();

void send_messages(object tp, object ob, string clas, string limb);

int cmd_heal(string str) {
    string whom, limb, clas;
    int amount, cost, healing, i, wisdom;
    object tp, ob;
    string * limbs;

   if (!spell()) {
      write("What?\n");
      return 1;
   }
    if(!str) {
        notify_fail("Heal whom?\n");
        return 0;
    }
    tp = this_player();
    if(tp->query_casting()) {
        notify_fail("You are in the middle of another spell!\n");
        return 0;
    }
    if(!alignment_ok(this_player())) {
        notify_fail("You have betrayed the source of your powers.\n");
        return 0;
    }
    healing = (int)tp->query_skill("healing");
    wisdom = (int)tp->query_stats("wisdom");
    clas = (string)tp->query_subclass();
    if(str == "me" || str == "myself") ob = tp;
    else ob = present(str, environment(tp));
    if(!ob) {
        if(sscanf(str, "%s %s", whom, limb) != 2) {
            notify_fail("Correct syntax: <heal [who] [(limb)]\n");
            return 0;
        }
        if(whom == "me" || whom == "myself") ob = tp;
        else ob = present(whom, environment(tp));
    }
    if(!ob) {
        notify_fail("Heal whom?\n");
        return 0;
    }
    if(!limb) cost = 22;
    else if(limb == "all") cost = 44;
    else if(member_array(limb, (string *)tp->query_limbs()) == -1) {
        notify_fail("You do not have a "+limb+".\n");
        return 0;
    }
    else cost = 14;
    if(ob != tp) cost = random(cost);
    if((int)tp->query_mp() < cost) {
        notify_fail("Too low on magic power.\n");
        tp->add_mp(-cost);
        return 0;
    }
    this_player()->set_magic_round(1);
    tp->add_mp(-cost);
    if(healing < 5) amount = 0;
    else amount = random(wisdom + (healing/10));
    if(!amount) {
        write("You do not have the skill to do that.");
        return 1;
    }
    if(tp == ob) tp->add_skill_points("healing", amount);
    else {
        tp->add_skill_points("healing", amount * 2);
        tp->add_alignment(amount);
        tp->add_exp(random((amount/2)+2));
    }
    if(!limb) {
        ob->add_hp(amount);
        send_messages(tp, ob, clas, 0);
    }
    else if(limb == "all") {
        limbs = (string *)ob->query_limbs();
        for(i=0; i<sizeof(limbs); i++) {
            ob->heal_limb(limbs[i], (amount / 2));
        }
        ob->add_hp(amount / 2);
        send_messages(tp, ob, clas, limb);
    }
    else {
        ob->heal_limb(limb, amount);
        send_messages(tp, ob, clas, limb);
    }
    return 1;
}

void send_messages(object tp, object ob, string clas, string limb) {
    string what, thing;

    if(clas == "monk" || clas == "cleric") {
        thing = "prayer";
        what = "a prayer of healing";
    }
    else if(tp->query_class() == "mage") {
        thing = "magic";
        what = "a spell of healing";
    }
    else {
        thing = "nonsense";
        what = "nonsense";
    }
    if(tp == ob) {
     tell_object(tp, "You heal your own wounds through " + thing + ".");
    tell_room(environment(tp), tp->query_cap_name() +
      " mutters " + what + ".", ({ tp }) );
    }
    else {
      tell_object(tp, "You heal " + ob->query_cap_name() +
        "'s wounds through " + thing + ".");
     tell_object(ob, tp->query_cap_name() + " heals your wounds through " +
       thing + ".");
     tell_room(environment(tp), tp->query_cap_name() + " mutters " +
        what + ".", ({ tp, ob }) );
    }
}


void help() {
    write("Syntax: <heal [player] [(limb)]>\n\n"+
        "Heals the player named.  If no limb is given, then\n"+
        "it heals hp.  Otherwise it heals the limb named.  The arg \"all\"\n"+
        "is a valid arg for the limb.\n");
}

int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (!alignment_ok(tp)) return 0;
   if (tp->query_level() < 4) return 0;
   if (tp->query_subclass() != "cleric" && tp->query_subclass() != "monk")
     return 0;
   return 1;
}