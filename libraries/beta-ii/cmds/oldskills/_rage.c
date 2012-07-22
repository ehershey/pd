//    Zerker attack.
//    By Nightshade.
 
#include <std.h>
inherit DAEMON;
int abil();
 
int cmd_rage(string str) {

    if (!abil()) {
        write("What?\n");
        return 1;
    }
    if(this_player()->query_ghost()) {
        notify_fail("You won't be able to do much in that form.\n");
        return 0;
    }
    if (this_player()->query_disable()) {
        write("You are unable to concentrate enough.");
        return 1;
    }
    if(environment(this_player())->query_property("no attack")) {
        notify_fail("Greater powers prevent your malice.\n");
        return 0;
    }
    if((int)this_player()->query_sp() < 20) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    if(this_player()->query_skill_bonus("attack")) {
        notify_fail("You find yourself unable to bring yourself into a fury.\n");
        return 0;
    }
if (this_player()->query_level() > 49)
{
new("/wizards/hermes/greater.c")->move(this_player());
}
else
{
    new("/d/nopk/standard/obj/magic/zerk")->move(this_player());
}
    return 1;
}

void help() {
   write("Syntax: <rage>\n\n"
      "The ability of a berserker to fly into a fit of rage, 
enhancing the damage they can do.");
}

int abil() {
   object r;
   r = this_player();
   if (!r) return 0;
   if (r->query_subclass() == "berserker"  && r->query_level() >= 10) return 1;
   else return 0;
}
