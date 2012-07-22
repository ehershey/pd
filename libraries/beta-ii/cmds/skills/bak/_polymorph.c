//      _polymorph.c
//      Mage ability
//      written by Daboura, hope it works :P

#include <daemons.h>
#include <std.h>
#include <rest.h>
inherit DAEMON;

void make_mon(object, object, object);
void set_chicken_type(object);

int spell();

string type() { return "other"; }

int cmd_polymorph(string str) {
    object tp, ob;
    int i, which, skip, attack;
    object *inv;
    string what;

   if (!spell()) {
      return 0;
   }

    this_player()->set_magic_round();

    tp = this_player();

    if(tp->query_ghost()) {
        notify_fail("You emit a ghostly moan.\n");
        return 0;
    }
    
    if (tp->query_disable())
        return notify_fail("You are too busy to cast this spell.\n");
    
    if(environment(tp)->query_property("no magic")
       || environment(tp)->query_property("no attack")) {
        notify_fail("Something seems to be blocking your concentration.\n");
        return 0;
    }
    
    if(tp->query_casting()) return notify_fail("You are already casting a spell!");
    
    if((int)tp->query_mp() < 75) {
        notify_fail("Too low on magic power.\n");
        return 0;
    }
    
    if(!str) {
        ob = (object)tp->query_current_attacker();
        if(!ob) {
            return notify_fail("What did you want to alter?\n");
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
        notify_fail("Your spell fails due to lack of intelligence.\n");
        return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
        notify_fail("You cannot morph link-dead players.\n");
        return 0;
    }
    if(ob->query_property("no polymorph") || ob->query_property("no magic")) {
      notify_fail(sprintf("%s is immune to such magic.\n",
                  ob->query_cap_name()));
      return 0;
    }
    
    if(!ob->is_monster())
    {
        return notify_fail("Your spell bounces off of "+ob->query_cap_name()+"!\n");
    }
    if(ob->query_skill("magic defense") > tp->query_skill("conjuring"))
    {
        return notify_fail("Your spell bounces off of "+ob->query_cap_name()+"!\n");
    }
    if(3*(ob->query_stats("wisdom"))/2 > tp->query_stats("wisdom"))
    {
        return notify_fail("Your spell bounces off of "+ob->query_cap_name()+"!\n");
    }
    
   
    write("%^ORANGE%^You move your hands in an %^BOLD%^%^WHITE%^in%^RESET%^%^CYAN%^tr%^BOLD%^%^WHITE%^ic%^RESET%^%^CYAN%^ate%^RESET%^%^ORANGE%^ pattern, and suddenly a cloud of %^BOLD%^%^BLACK%^smoke%^RESET%^%^ORANGE%^ appears around "
        +ob->query_cap_name()+ " then fades away!");
    
    message("room","%^ORANGE%^" +tp->query_cap_name()+ 
        " moves " 
        +tp->query_possessive()+   
        " hands in an %^BOLD%^%^WHITE%^in%^RESET%^%^CYAN%^tr%^BOLD%^%^WHITE%^ic%^RESET%^%^CYAN%^ate%^RESET%^%^ORANGE%^ pattern, and suddenly a cloud of %^BOLD%^%^BLACK%^smoke%^RESET%^%^ORANGE%^ appears around "
        +ob->query_cap_name()+ " then fades away!"
        , environment(tp), ({tp,ob}));            
    
    ob->move("/d/nopk/standard/void.c");
    make_mon(ob,tp,environment(tp));   
    if (ob->query_rest_type() == SLEEP && present("sleep_pillow", ob)) present("sleep_pillow", ob)->remove();
    ob->remove();
    
    tp->add_skill_points("conjuring", 2 + random(3));
    tp->add_skill_points("wizardry", 2 + random(3));    

    tp->add_mp(-(this_player()->query_skill("wizardry")/5 + (1+random(this_player()->query_stats("wisdom")/2))));
    
    tp->set_disable();
    
    return 1;
}

void make_mon(object ob, object tp, object rm)
{
    object newob;
    
    if(!ob) return;
    
    newob = new(MONSTER);
    newob->set_level(4*ob->query_level()/5);
    newob->set_body_type("foul");                         
    newob->set_race("chicken");     
    newob->set_gender(ob->query_gender()); 
    newob->set_alignment(ob->query_alignment());
    newob->set("aggressive", 2);    
    
    set_chicken_type(newob);
    
    newob->move(rm);
                               
}

void set_chicken_type(object ob)
{
    if(ob->query_level() <= 10)
    {
        ob->set_name("%^YELLOW%^chick%^RESET%^");                               
        ob->set_id( ({ "chick", "chicken" }) );    
        ob->set_short("%^YELLOW%^chick%^RESET%^");                     
        ob->set_long("A very small and young chick, it looks so cute and cuddly.");           
    }
    if(ob->query_level() >10 && ob->query_level() <= 30)
    {
        if(ob->query_gender() == "male")
        {
            ob->set_name("rooster");                               
            ob->set_id( ({ "rooster", "chicken" }) );    
            ob->set_short("%^BOLD%^%^RED%^R%^BLACK%^o%^RED%^o%^BLACK%^s%^RED%^t%^BLACK%^e%^RED%^r%^RESET%^");                     
            ob->set_long("A small rooster stand here, perhaps looking for a mate."); 
        }
        else if(ob->query_gender() == "female")
        {
            ob->set_name("hen");                               
            ob->set_id( ({ "chicken", "hen" }) );    
            ob->set_short("%^BOLD%^%^WHITE%^H%^RED%^e%^WHITE%^n%^RESET%^");                     
            ob->set_long("A small regular hen, perhaps looking for a place to lay eggs.");         
        }
        else
        {
            ob->set_name("chicken");                               
            ob->set_id( ({ "chicken" }) );    
            ob->set_short("%^BOLD%^%^WHITE%^Ch%^RED%^i%^WHITE%^c%^RED%^k%^WHITE%^en%^RESET%^");                     
            ob->set_long("A confused looking chicken.");          
        }
    }
    if(ob->query_level() >30 && ob->query_level() < 50)
    {
        if(ob->query_gender() == "male")
        {
            ob->set_name("large rooster");                               
            ob->set_id( ({ "rooster", "large rooster", "chicken" }) );    
            ob->set_short("Large %^BOLD%^%^RED%^r%^BLACK%^o%^RED%^o%^BLACK%^s%^RED%^t%^BLACK%^e%^RED%^r%^RESET%^");                     
            ob->set_long("A larger rooster, he searches for food."); 
        }
        else if(ob->query_gender() == "female")
        {
            ob->set_name("large hen");                               
            ob->set_id( ({ "chicken", "large hen", "hen" }) );    
            ob->set_short("Large %^BOLD%^%^WHITE%^h%^RED%^e%^WHITE%^n%^RESET%^");                     
            ob->set_long("A larger looking hen, looking for food to gather.");         
        }
        else
        {
            ob->set_name("chicken");                               
            ob->set_id( ({ "chicken" }) );    
            ob->set_short("Large %^BOLD%^%^WHITE%^ch%^RED%^i%^WHITE%^c%^RED%^k%^WHITE%^en%^RESET%^");                     
            ob->set_long("A confused looking large chicken.");          
        }
    }   
    if(ob->query_level() >= 50 && ob->query_level() < 100)
    {
        if(ob->query_gender() == "male")
        {
            ob->set_name("mutant rooster");                               
            ob->set_id( ({ "rooster", "mutant rooster", "chicken" }) );    
            ob->set_short("Mutant %^BOLD%^%^GREEN%^r%^BLACK%^o%^GREEN%^o%^BLACK%^s%^GREEN%^t%^BLACK%^e%^GREEN%^r%^RESET%^");                     
            ob->set_long("A mutant rooster, he looks hungry for meat!"); 
        }
        else if(ob->query_gender() == "female")
        {
            ob->set_name("mutant hen");                               
            ob->set_id( ({ "hen", "mutant hen", "chicken" }) );    
            ob->set_short("Mutant %^BOLD%^%^WHITE%^h%^GREEN%^e%^WHITE%^n%^RESET%^");                     
            ob->set_long("A mutant hen, she looks hungry for blood!");         
        }
        else
        {                               
            ob->set_name("mutant chicken");
            ob->set_id( ({ "chicken", "mutant chicken" }) );    
            ob->set_short("Mutant %^BOLD%^%^WHITE%^ch%^GREEN%^i%^WHITE%^c%^GREEN%^k%^WHITE%^en%^RESET%^");                     
            ob->set_long("A confused looking mutant chicken, it's not sure what it wants.");          
        }
        
    }  
    
    if(ob->query_level() >= 100)
    {
        if(ob->query_gender() == "male")
        {
            ob->set_name("king rooster");                               
            ob->set_id( ({ "rooster", "king rooster", "chicken" }) );    
            ob->set_short("King %^BOLD%^%^CYAN%^r%^BLACK%^o%^CYAN%^o%^BLACK%^s%^CYAN%^t%^BLACK%^e%^CYAN%^r%^RESET%^");                     
            ob->set_long("The king rooster, he watches all over other roosters."); 
        }
        else if(ob->query_gender() == "female")
        {
            ob->set_name("queen hen");                               
            ob->set_id( ({ "hen", "queen hen", "chicken" }) );    
            ob->set_short("Mutant %^BOLD%^%^WHITE%^h%^CYAN%^e%^WHITE%^n%^RESET%^");                     
            ob->set_long("The queen hen, she watches over all hens.");         
        }
        else
        {
            ob->set_name("jester chicken");                               
            ob->set_id( ({ "chicken", "jester chicken" }) );    
            ob->set_short("Jester %^BOLD%^%^WHITE%^ch%^CYAN%^i%^WHITE%^c%^CYAN%^k%^WHITE%^en%^RESET%^");                     
            ob->set_long("A confused looking jester chicken, it just likes to play around.");          
        }
    }     
}   


void help() {
    write("Syntax: <polymorph [(living)]>\n"
        "A powerful wizard can transform a creature "
        "into a less fearsome beast with this strange "
        "and old spell.\n");
}
int spell() {
    object tp;
    tp = this_player();
    if (!tp) return 0;
    if (tp->query_subclass() != "wizard") return 0;
    if (tp->query_level() < 35) return 0;
    if (tp->query_skill("conjuring") < 157) return 0;
    if (tp->query_skill("wizardry") < 210) return 0;
    
    
   return 1;
}
