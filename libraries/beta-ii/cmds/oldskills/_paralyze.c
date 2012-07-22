//      /bin/user/_paralyze.c
//      from the Nightmare mudlib
//      paralyzes an opponent
//      created by Descartes of Borg 18 april 1993
//      a dungeonware.net mod by: Stormbringer 12:25 PM 9/6/2002
#include <std.h>
inherit DAEMON;
int spell();
int cmd_paralyze(string str) {
    object ob;
    int healing, mag, dam, def, time;
    if (!spell()) {
        return notify_fail("What?\n");
    }
    if(environment(this_player())->query_property("no magic") &&
      !wizardp(this_player())) {
        notify_fail("A magic force prevents you from doing that.\n");
        return 0;
    }
    if(!str) ob = (object)this_player()->query_current_attacker();
    else ob = present(lower_case(str), environment(this_player()));
    if(!ob && str) ob = parse_objects(environment(this_player()), lower_case(str));
    if(!ob) {
        notify_fail("Paralyze whom?\n");
        return 0;
    }
    if(!living(ob)) {
        notify_fail("Ok, the "+str+" is paralyzed.\n");
        return 0;
    }
    if(this_player()->query_ghost()) {
        notify_fail("You howl instead of pray.\n");
        return 0;
    }
    if(!this_player()->ok_to_kill(ob)) {
        notify_fail("You cannot attack them.\n");
        return 0;
    }
    if (this_player()->query_disable())
      return notify_fail("You are busy.\n");
    if(this_player()->query_casting()) {
        notify_fail("Your words become jumbled.\n");
        return 0;
    }
    dam = (int)this_player()->query_skill("belief")/2 - (int)ob->query_skill("wisdom")/2;
    if(!alignment_ok(this_player()) && !wizardp(this_player())) {
        notify_fail("You have betrayed the source of your powers.\n");
        return 0;
    }
    if (dam < 10) def = 2; else
    if (dam < 55) def = 3; else
    if (dam < 110) def = 4; else
    if (dam < 165) def = 5; else
    if (dam < 220) def = 6; else
    if (dam >= 220) def = 7;
    time = 3+random(def);
    if (def = 0) {
        write("You fail to paralyze anyone.");
        return 1;
    }
    if((int)this_player()->query_mp() < dam/7) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    if(ob->query_paralyzed()) {
        write("Your paralyze backfires.");
        this_player()->set_paralyzed(time);
        return 1; 
    }
    this_player()->add_mp(-(dam/5+random(30)));
    this_player()->set_disable();
    if(random(time)>2) {
      ob->set_paralyzed(time);
      this_player()->add_skill_points("belief", dam/25);
      write("You mutter a prayer of paralyzation.\n");
      say(this_player()->query_cap_name()+" prays for the paralyzation of "+ob->query_cap_name()+".\n", ob);
      tell_object(ob, this_player()->query_cap_name()+" paralyzes you!\n");
    }
    else {
      write("The gods refuse your call for paralyzation!");
    }
    return 1;
}
void help() {
    write("Syntax: <paralyze [enemy]>\n\n"
      "Paralyzes a player or monster for a short period of time,\n"
      "making it impossible for it to move, fight, or otherwise\n"
      "issue commands.\n"
    );
}
int spell() {
    object j;
    j = this_player();
    if (!j) return 0;
    if (j->is_monster()) return 1;
    if (wizardp(this_player())) return 1;
    if (j->query_subclass() != "cleric") return 0;
    if (j->query_level() < 10) return 0;
    if (j->query_skill("belief") < 40) return 0;
    return 1;
}
