//      /bin/user/_stealth.c
//      from the Nightmare mudlib
//      rogue ability
//      created by Descartes of Borg 10 april 1993
#include <std.h>
int abil();
inherit DAEMON;
int cmd_stealth(string str) {
    int stealth, dex;
   if (str == "off") {
     if (!this_player()->query_property("stealth"))
       return notify_fail("You are not hiding.\n");
     write("You step out of the shadows.");
     this_player()->remove_property("stealth");
     say(this_player()->query_cap_name()+" steps out of the shadows.",
       this_player());
     return 1;
   }
   if (!abil()) {
      notify_fail("What?\n");
      return 0;
   }
    if(this_player()->query_ghost()) return 0;
    stealth = (int)this_player()->query_skill("stealth");
    dex = (int)this_player()->query_stats("dexterity");
    if(stealth < 15) {
        notify_fail("You are not quite sly enough to do that.\n");
        return 0;
    }
    if((int)this_player()->query_sp() < 30) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    this_player()->set_property("stealth", stealth+(dex/2));
    write("You blend in with your surroundings to move with stealth.\n");
    return 1;
}
void help() {
    write("Syntax: <stealth>\n\n"
      "Allows you to move without being noticed by other players.\n"
    );
}
int abil() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_class() != "rogue") return 0;
   if((int)this_player()->query_skill("stealth") < 15) return 0;
   return 1;
}
