#include <std.h>
inherit DAEMON;
int spell();

int add_limb(object ob, string limb);

int cmd_replacin(string str) {
    string who, limb;
    string *missing;
    string *limbs;
    int healing;
    int cost;
    object tp, ob;
    tp = this_player();

    if(!spell())
      return notify_fail("What?\n");

    if(this_player()->query_ghost())
      return notify_fail("You cannot do that in your immaterial state.\n");

    if(!str)
      return notify_fail("Replace what?\n");

    if(!alignment_ok(tp))
      return notify_fail("You have betrayed the source of your powers!\n");

    if(sscanf(str, "%s %s", who, limb) != 2)
      return notify_fail("Correct syntax: <replace [player] [limb]>\n");

    if(who == "me") ob = tp;
    else ob = find_player(who);

    if(!ob || environment(ob) != environment(tp))
      return notify_fail(capitalize(who) + " is not here.\n");

    if(ob->query_ghost())
      return notify_fail("You cannot help the dead in that way.\n");

    if(!living(ob))
      return notify_fail(ob->query_cap_name()+" is not a living thing!\n");

    limbs = ob->query_limbs();
    missing = ob->query_severed_limbs();

    if(!ob->query_is_limb(limb)) {
      write("That is not a valid limb!");
      return 1;
      }

    if(!missing) {
      if(ob==tp) notify_fail("You are not missing any limbs!\n");
      else notify_fail(ob->query_cap_name()+" is not missing any limbs.\n");
      return 1;
      }

    if(member_array(limb, limbs) != -1) {
        if(tp==ob) notify_fail("You are not missing that limb!\n");
        else notify_fail(ob->query_cap_name()+" is not missing that limb.\n");
        return 1;
    }

    if(member_array(limb, missing) == -1) {
      if(tp==ob) notify_fail("You are not missing your that limb!\n");
      else notify_fail(ob->query_cap_name()+" is not missing that limb!\n");
      return 1;
      }

    tp->set_magic_round();
    healing = tp->query_skill("healing");
    healing -= random(101);
    if(tp==ob) cost = 120;
    else cost = random(100) + 20;

    if(tp->query_mp() < cost)
      return notify_fail("Not enough magical power.\n");

    tp->add_mp(-cost);

    if(healing < 1) {
      write("Your concentration is simply too weak.\n");
      say(tp->query_cap_name()+" loses "+tp->query_possessive()+" concentration while in prayer.\n", tp);
      tp->add_skill_points("healing", 10);
      return 1;
      }

    add_limb(ob, limb, tp, healing);
    return 1;
}

void add_limb(object ob, string limb, object tp, int healing) {
     object body;
     string *all, *wieldin, minor;
     int i;

     body = new(MONSTER);
     body->move("/d/nopk/standard/void.c");
     body->set_race(ob->query_race());
     body->set_body_type(ob->query_race());
     all = body->query_limbs();
     wieldin = body->query_wielding_limbs();

     if(member_array(limb, all) == -1) { write("Not a valid limb!"); body->remove(); return; }

     i = sizeof(all);
     while(i--) {
        if(body->query_reference(all[i]) == limb) {
          if(member_array(all[i], ob->query_limbs()) == -1) {
            write("You'll need to replace the "+all[i]+" first!");
            body->remove();
            return;
            }
          minor = "YES";
          }
       }
     if(!minor) {
       if(body->query_reference(limb) != "")
         minor = body->query_reference(limb);
       else
         minor = "NO";
       }

     if(minor == "NO")
       ob->add_limb(limb, "", ob->query_max_hp()/3, 0, 0);
     else if(minor == "YES")
       ob->add_limb(limb, "", ob->query_max_hp()/4, 0, 0);
     else
       ob->add_limb(limb, minor, ob->query_max_hp()/3, 0, 0);

     if(member_array(limb, wieldin) != -1)
       ob->add_wielding_limb(limb);

     if(tp==ob) {
       write("Your "+limb+" regenerates through prayer!");
       say(tp->query_cap_name()+"'s "+limb+" regenerates through prayer!", tp);
       tp->add_skill_points("healing", random(healing/2)*2);
       tp->add_exp(random(healing/2)*2);
       }

     else {
       write("You regenerate "+ob->query_cap_name()+"'s "+limb+" through prayer!\n");
       tell_object(ob, tp->query_cap_name()+" regenerates your "+limb+" through prayer!\n");
       tell_room(environment(tp), tp->query_cap_name()+" says a prayer that regenerates "+ob->query_cap_name()+"'s "+limb+".\n", ({ tp, ob }) );
       tp->add_skill_points("healing", healing);
       tp->add_exp(healing);
       tp->add_alignment(healing);
       }
     body->remove();
     return;
}

void help() {
    write("Syntax: <replace [player] [limb]>\n\n"+
        "A prayer to regenerate the missing limb of a player.\n");
}

int spell() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_subclass() != "cleric" && o->query_subclass() != "monk") return 0;
   if (o->query_skill("healing") < 30) return 0;
   if (o->query_level() < 10) return 0;
   if (!alignment_ok(o)) return 0;
   return 1;
}
