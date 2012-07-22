#include <std.h> 
inherit DAEMON;
int abil();
int cmd_filch(string str) {
    object *inv, *bag;
    object victim, tp, ob, ob2;
    int i, skip, which;
    int steal, anti, x;
    int align_formula;
   if(!wizardp(this_player())) return 0;
 
    if(this_player()->query_ghost()) {
        notify_fail("You cannot do that in your immaterial state.\n");
         return 0;
    }
    if(environment(this_player())->query_property("no steal")) {
       notify_fail("A magic force prevents you from doing that!\n");
       return 0;
    }
    if(!str) {
       notify_fail("Filch whom?\n");
       return 0;
    }
    if(this_player()->query_disable()) return notify_fail("You "
      "are too disorientated to do that!\n");
    if(this_player()->query_current_attacker()) {
        notify_fail("You can't filch while in combat!\n");
        return 0;
    }
    if (this_player()->query_subclass() != "thief") {
        notify_fail("You may not filch!\n");
        return 0;
    }
    tp = this_player();
    victim = present(str, environment(tp));
    if(!victim) {
       notify_fail(capitalize(str)+" is not here!\n");
       return 0;
    }
    if(!living(victim)) {
       notify_fail(capitalize(str)+" is not a living thing!\n");
       return 0;
    }
    if(victim->is_player() && !interactive(victim)) {
        notify_fail("You cannot steal from link-dead players.\n");
        return 0;
    }
    tp->set_disable();
    if(wizardp(victim) && !wizardp(this_player())) {
        notify_fail("Ooooh, no.. You do NOT want to try that!\n");
        this_player()->set_paralyzed(5, "You fear the gods now, don't you?");
        return 0;
    }
    if((int)victim->query_level() <= 15 &&
       victim->is_player()) {
        notify_fail("Alas, it would be to easy!\n");
        return 0;
    }
    if(victim == tp) {
       notify_fail("Filch from yourself?\n");
       return 0;
    }
    inv = all_inventory(victim);
    for(i=0, skip=0; i<sizeof(inv) && !ob; i++) {
      if((inv[i]->id("bag") || inv[i]->id("diamond") || inv[i]->id("backpack") ) && !skip) {
      skip++;
      ob = inv[i];
      }
    }
    if(!skip) {
      write(victim->query_cap_name()+" does not have a bag!\n");
      return 1;
    }
    if(!ob->get()) {
        notify_fail("You cannot steal that!\n");
        return 0;
    }
    if(ob->query_property("no steal")) {
        notify_fail("You fail to steal "+victim->query_cap_name()+
           "'s "+ob->query_short()+
           ".\nYou are unsure if anyone noticed the attempt.\n");
        return 0;
    }
    steal = tp->query_skill("stealing") + tp->query_stats("charisma")/4
      + tp->query_stats("dexterity")/4;
    anti = victim->query_skill("perception") +
      victim->query_stats("dexterity") + (victim->query_level()/2);
    steal -= anti;
    if(steal < 0) steal = 1;
    x = random(101) + 20;
// If the theft is unoticed, exp is given based upon success.
    if((string)tp->query_subclass()!="thief") steal /= 2;
    if(steal > x) {
       bag = all_inventory(ob);
       if(!sizeof(bag)) {
         write("There is nothing in "+victim->query_cap_name()+"'s "+ob->query_short()+"\n");
         return 1;
       }
       i = random(sizeof(bag));
//  give a random object from the bag
       write("You successfully steal from "+victim->query_cap_name()+"'s "+
         ob->query_short()+" and receive "+bag[i]->query_name()+".\n"+
         capitalize((string)victim->query_subjective())+" does not even notice!");
        tp->add_alignment(- ((int)victim->query_alignment())/100);
        if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 10);
           tp->add_exp(800);
       if(bag[i]->move(tp)) {
           write("You cannot carry that!\nYou drop "+bag[i]->query_name()+".");
           say(tp->query_cap_name()+" drops "+bag[i]->query_name()+".", tp);
           bag[i]->move(environment(tp));
       }
       return 1;
    }
    x -= steal;
    if(x<10) {
       write("You successfully steal from "+victim->query_cap_name()+"'s "+
         ob->query_short()+" and receive "+bag[i]->query_name()+".\n"+
         ".\nYou are not sure if anyone noticed.");
       tell_room(environment(tp), tp->query_cap_name()+" steals a "
         +bag[i]->query_name()+" from "+victim->query_cap_name()+"'s "
         +ob->query_short()+".", ({ victim, tp }));
       tp->add_alignment( align_formula );
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 8);
           tp->add_exp(500);
       victim->add_skill_points("perception", x);
       if(bag[i]->move(tp)) {
           write("You cannot carry that!\nYou drop "+bag[i]->query_name()+".");
           say(tp->query_cap_name()+" drops "+bag[i]->query_name()+".", tp);
           bag[i]->move(environment(tp));
       }
       return 1;
    }
    if(x<20) {
       write("You successfully steal from "+victim->query_cap_name()+"'s "+
         ob->query_short()+" and receive "+bag[i]->query_name()+".\n"+
         ".\nYou are not sure if anyone noticed.");
       tell_object(victim, "You feel someone brush against you.");
       tell_room(environment(tp), tp->query_cap_name()+" slyly brushes by "
         +victim->query_cap_name()+" and steals a "+bag[i]->query_name()+
         " from "+possessive(victim)+" "+ob->query_short(),  ({ tp, victim }));
       tp->add_alignment( align_formula );
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 6);
           tp->add_exp(300);
       victim->add_skill_points("perception", x);
       if(bag[i]->move(tp)) {
           write("You cannot carry that!\nYou drop "+bag[i]->query_name()+".");
           say(tp->query_cap_name()+" drops "+bag[i]->query_name()+".", tp);
           bag[i]->move(environment(tp));
       }
       return 1;
    }
    if(x<30) {
       write("You successfully steal from "+victim->query_cap_name()+"'s "+
         ob->query_short()+" and receive "+bag[i]->query_name()+".\n"+
         ".\nYou are not sure if anyone noticed.");
       tell_object(victim, tp->query_cap_name()+" just stole your "+bag[i]->query_name()+
         " that was in your "+ob->query_short()+"!");
       tell_room(environment(tp), tp->query_cap_name()+" steals a "+
         bag[i]->query_name()+" from "+victim->query_cap_name()+"'s "+
         ob->query_short()+".", ({victim, tp}));
       tp->add_alignment( align_formula );
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 5);
           tp->add_exp(100);
       victim->add_skill_points("perception", x);
       if(!victim->is_player()) victim->kill_ob(tp, 0);
       if(bag[i]->move(tp)) {
           write("You cannot carry that!\nYou drop "+bag[i]->query_name()+".");
           say(tp->query_cap_name()+" drops "+bag[i]->query_name()+".", tp);
           bag[i]->move(environment(tp));
       }
       return 1;
    }
    if(x < 40) {
        write("You fail to steal from "+victim->query_cap_name()+"'s "+
          ob->query_short()+", but no one notices the attempt.");
       if((string)tp->query_class() != (string)victim->query_class())
           tp->add_skill_points("stealing", 4);
          if(victim->is_player())
           tp->add_outlaw("theft", 1);
           victim->add_skill_points("perception", x);
       return 1;
    }
    if(x < 50) {
       write("You fail to steal from "+victim->query_cap_name()+"'s "
         +ob->query_short()+".\nYou are unsure if anyone noticed the attempt.");
       tell_room(environment(tp), tp->query_cap_name()+" attempts to steal "
         "something from "+victim->query_cap_name()+"'s "+ob->query_short()
         +".", ({ victim, tp }));
       if((string)tp->query_class() != (string)victim->query_class())
          if(victim->is_player())
           tp->add_outlaw("theft", 1);
           tp->add_skill_points("stealing", 3);
           victim->add_skill_points("perception", x);
       return 1;
    }
    if(x < 60) {
       write("You fail to steal from "+victim->query_cap_name()+"'s "
         +ob->query_short()+".\nYou are unsure if anyone noticed the attempt.");
       tell_room(environment(tp), tp->query_cap_name()+" slyly brushes by "+
         victim->query_cap_name()+".", ({victim, tp}));
       tell_object(victim, "You feel someone brush against you.");
       if((string)tp->query_class() != (string)victim->query_class())
          if(victim->is_player())
           tp->add_outlaw("theft", 1);
           tp->add_skill_points("stealing", 2);
           victim->add_skill_points("perception", x);
       return 1;
    }
    write("You fail to steal from "+victim->query_cap_name()+"'s "+ob->query_short()+
      ".\nYou are unsure if anyone noticed the attempt.");
    tell_room(environment(tp), tp->query_cap_name()+" attempts to steal "
      "something from "+victim->query_cap_name()+"'s "+ob->query_short()+
      ", but fails.", ({victim, tp}));
    tell_object(victim, tp->query_cap_name()+" just tried to steal your "+
      bag[i]->query_name()+" from your "+ob->query_short()+
      "!\nLuckily, "+tp->query_subjective()+" failed!");
    if((string)tp->query_class() != (string)victim->query_class())
       tp->add_skill_points("stealing", 1);
      if(victim->is_player())
       tp->add_outlaw("theft", 1);
       victim->add_skill_points("perception", x);
    if(!victim->is_player()) victim->kill_ob(tp, 0);
    return 1;
}
 
void help() {
message("Ninfo", "Syntax: <Filch>\n"+
"This command will allow a theif to attempt to steal "
"something from a bag or pouch in someones inventory.  "
"", this_player());
}
int abil() {
 if (this_player()->query_level() < 20) return 0;
 if (this_player()->query_subclass() == "thief") return 1; 
}
