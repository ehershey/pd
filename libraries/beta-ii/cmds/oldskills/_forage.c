//Forage command by Stormbringer
//Redone by Nightshade
//11-10-01
int abil();
int cmd_forage(string str) {
    object tp, herb;
    int nat, sum;
    string *forest = ({"nut","fruit","egg","root","large fruit","melon","large egg"});
    string *mountain = ({"nut","berry","egg","root","large root","melon","large egg"});
    string *swamp = ({"garlic","berry","egg","moss","large root","bulb","large egg"});
    string *plains = ({"garlic","berry","egg","root","large root","onion","large egg"});
    string *beach = ({"shrimp","berry","egg","kelp","fish","clam","crab"});
    tp = this_player();
    if (!abil()) return notify_fail("What?\n");
    if (tp->query_level() < 5) {
        notify_fail("You can't do this.\n");
        return 0;
    }
    if(!str) {
        notify_fail("Syntax: forage [item]\n");
        return 0;
    }
    if(tp->query_ghost()) return 0;
    lower_case(str);
    if(tp->query_subclass() != "ranger") {
        notify_fail("What?\n");
        return 0;
    }
    if((int)tp->query_sp() < 45) {
        notify_fail("You're to tired.\n");
        return 0;
    }
    nat = (int)tp->query_skill("nature");
    if(nat < 25) {
        notify_fail("Your not yet knowledgable in this.\n");
        return 0;
    }
    if(tp->query_disable()) {
      notify_fail("You are busy.\n");
      return 0;
    }
    if(environment(tp)->query_property("indoors")) {
        notify_fail("You can't forage indoors.\n");
        return 0;
    }
    if(environment(tp)->query_property("town")) {
        notify_fail("You can't forage in town.\n");
        return 0;
    }
    if(!(environment(tp)->query_property("forest") ||
           environment(tp)->query_property("mountain") ||
           environment(tp)->query_property("swamp") ||
           environment(tp)->query_property("plains") ||
           environment(tp)->query_property("beach"))) {
        write("You cannot forage here.\n");
        return 1;
    }
    if(!environment(tp)->do_forage()) {
        write("The resouces here have been exhausted.");
        return 1;
    }
// --------------------<Mud is below here>----------------------
    if (str == "mud") {
       sum = random(20);
       tp->add_sp(-((sum)*5/2));
       tp->add_skill_points("nature", random(10));
       tp->set_disable();
       if (random(sum) > random(nat*2)) {
           write("You find nothing in your search.\n");
           say(tp->query_cap_name()+" forages the area.", tp);
           return 1;
       }
       if (sum > 5) {
           write("You dig up some mud.\n");
           say(tp->query_cap_name()+" digs up some mud.", tp);
           new("/d/nopk/standard/obj/misc/forage/mud")->move(tp);
           return 1;
       }
    }
// --------------------<Wood is below here>----------------------
    if (str == "wood") {
       sum = random(20);
       tp->add_sp(-((sum)*5/2));
       tp->add_skill_points("nature", random(10));
       tp->set_disable();
       if (random(sum) > random(nat*2)) {
           write("You find nothing in your search.\n");
           say(tp->query_cap_name()+" forages the area.", tp);
           return 1;
       }
       if (sum > 5) {
           herb = new("/d/nopk/standard/obj/misc/forage/wood");
           if(nat > 100)
               sum = random(100);
           else
               sum = random(nat);
           if(sum > 97) {
               herb->set_short("a fine board of cedar");
               herb->set_long("This is a fine board of cedar.");
               herb->set_id(({"wood","board","firewood","finecedar"}));
           }
           else if(sum > 80) {
               herb->set_short("a thick redwood branch");
               herb->set_long("This is a thick branch of redwood.");
               herb->set_id(({"wood","branch","stick","firewood","redwood"}));
           }
           else if(sum > 60) {
               herb->set_short("a branch from a pine");
               herb->set_long("This branch came from a pine tree.");
               herb->set_id(({"wood","stick","firewood","branch","pine"}));
           }
           else if(sum > 35) {
               herb->set_short("a long stick");
               herb->set_long("Yep. It's definately a stick.");
               herb->set_id(({"wood","stick","firewood"}));
           }
           else {
               herb->set_short("a small twig");
               herb->set_long("A pitifully small twig.");
               herb->set_id(({"wood","stick","firewood","twig"}));
           }
           write("You find "+herb->query_short()+".\n");
           say(tp->query_cap_name()+" gathers some wood for a fire.", tp);
           herb->move(tp);
           return 1;
       }
    }
// --------------------<Herbs are below here>----------------------
    if (str == "herbs") {
       if(nat < 50) {
           write("You are not knowledgeable enough about plants.");
           return 1;
       }
       sum = random(20);
       tp->add_sp(-((sum)*5/2));
       tp->add_skill_points("nature", random(10));
       tp->set_disable();
       if ((random(sum) > random(nat*2)) || (random(20) > 12)) {
           write("You find nothing in your search.\n");
           say(tp->query_cap_name()+" forages the area.", tp);
           return 1;
       }
       if (sum > 5) {
           write("You manage to gather some herbs.\n");
           say(tp->query_cap_name()+" picks some herbs.", tp);
           herb = new("/d/nopk/standard/obj/misc/forage/herb");
           sum = random(50);
           if(sum <= 10)
               herb->set_type("poison");
           else if(sum <=30)
               herb->set_type("healing");
           else
               herb->set_type("antidote");
           herb->move(tp);
           return 1;
       }
    }
// --------------------<Food is below here>----------------------
    if (str == "food") {
       sum = random(15);
        tp->add_sp(-((sum)*3/2));
        tp->add_skill_points("nature", random(10));
        tp->set_disable();
        if (random(sum) > random(nat*2)) {
            write("You find nothing in your search.\n");
            say(tp->query_cap_name()+" forages the area.", tp);
            return 1;
        }
        sum = sum/5;
        if((sum >= 7) || (random(20) > 10)) {
            write("You find nothing in your search.\n");
            return 1;
        }
        if(environment(tp)->query_property("forest")) {
            write("You manage to find a "+forest[sum]+".");
            say(tp->query_cap_name()+" finds a "+forest[sum]+".");
            if(forest[sum][0..4] == "large")
                forest[sum] = forest[sum][6..sizeof(forest[sum])];
            new("/d/nopk/standard/obj/misc/forage/"+forest[sum])->move(tp);
            return 1;
        }
        if(environment(tp)->query_property("mountain")) {
            write("You manage to find a "+mountain[sum]+".");
            say(tp->query_cap_name()+" finds a "+mountain[sum]+".");
            if(mountain[sum][0..4] == "large")
                mountain[sum] = mountain[sum][6..sizeof(mountain[sum])];
            new("/d/nopk/standard/obj/misc/forage/"+mountain[sum])->move(tp);
            return 1;
        }
        if(environment(tp)->query_property("swamp")) {
            write("You manage to find a "+swamp[sum]+".");
            say(tp->query_cap_name()+" finds a "+swamp[sum]+".");
            if(swamp[sum] == "egg")
                swamp[sum] = "aegg";
            if(swamp[sum][0..4] == "large")
                swamp[sum] = swamp[sum][6..sizeof(swamp[sum])];
            new("/d/nopk/standard/obj/misc/forage/"+swamp[sum])->move(tp);
            return 1;
        }
        if(environment(tp)->query_property("plains")) {
            write("You manage to find a "+plains[sum]+".");
            say(tp->query_cap_name()+" finds a "+plains[sum]+".");
            if(plains[sum][0..4] == "large")
                plains[sum] = plains[sum][6..sizeof(plains[sum])];
            new("/d/nopk/standard/obj/misc/forage/"+plains[sum])->move(tp);
            return 1;
        }
        if(environment(tp)->query_property("beach")) {
            write("You manage to find a "+beach[sum]+".");
            say(tp->query_cap_name()+" finds a "+beach[sum]+".");
            if(beach[sum] == "egg")
                beach[sum] = "aegg";
            if(beach[sum][0..4] == "large")
                beach[sum] = beach[sum][6..sizeof(beach[sum])];
            new("/d/nopk/standard/obj/misc/forage/"+beach[sum])->move(tp);
            return 1;
        }
    }
    if(str != "herbs" && str != "food" && str != "wood" && str != "mud")
        write("Forage what?");
    return 1;
}
void help() {
    write("Syntax: <forage [item]>\n\n"
      "This ability allows a ranger to forage for materials from "
      "outdoor areas. The name of the items to be foraged must "
      "be be used. If food is used, the ranger will forage for food. "
      "You can forage for mud, wood, herbs and food.");
}
int abil() {
 if (this_player()->query_level() < 5) return 0;
 if (this_player()->query_subclass()=="ranger") return 1; }