// a dungeonware.net revamp
// converted over to PD by stormbringer
//    A mage spell for listening in on what's going
//    on in a room.
//    by Kalinash@Nightmare April 17, 1994.

#include <std.h>
#include <common_fun.h>
inherit DAEMON;
int spell();
string type() { return "conjuring"; }
int cmd_ears() {
    object who, orb;
    int x, amt;
    string Class;

    who = TP;
    Class = who->QCL;
    if(!spell()) return 0;
    if(Class != "mage")
        return notify_fail("What?\n");
    if((int)who->QSK("conjuring") < 30)
        return notify_fail("You speak the arcane words of the spell but "
          "nothing happens.\n");
    if((int)who->query_mp() < 1)
        return notify_fail("Your mind is too fatigued.\n");
    x = who->QST("wisdom") + who->QSK("conjuring");
    amt = x / 10;
    amt = random(10 + amt);
    who->add_mp(-amt*2);
    who->add_skill_points("conjuring", amt/2);
    orb = new("/std/obj/ears_orb.c");
    orb->move(ENV(who));
    orb->set_caster(this_player());
    orb->set_caster_level((int)this_player()->query_level());
    orb->start_dest(amt);
    message("my_action", "As you complete the incantation, a small orb
appears and hovers about the area.", who);
    message("their_action", sprintf("%s chants some archane words.",
who->QCN), ENV(who), who);
    return 1;
}

void help() {
    message("help", "Usage : <ears>\n\nThis spell will allow you to conjure
up a Wizard's Ear to keep tabs on what is going on in a room.",
this_player());
}

int spell() {
   object tp;
   tp = this_player();
   if (!tp) return 0;
   if (tp->query_class() != "mage") return 0;
   if (tp->query_subclass() != "conjurer" && tp->query_subclass() != "illusionist") return 0;
   if (tp->query_level() < 2) return 0;
   return 1;

}
