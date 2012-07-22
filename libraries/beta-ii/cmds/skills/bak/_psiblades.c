#include <std.h>

mapping shielded;
int onOff;
int spell();
string type() { return "conjuring"; }
void create()
{
    shielded = ([]);

}
int query_shielded(object ob) { return shielded[ob]; }

int cmd_psiblades( string str )
{
    int md, aero, power, def, time;
    object tp, ob;
    
    tp = this_player();
    
    if (!spell()) return notify_fail("What?\n");
    
    if (this_player()->query_ghost())
        return notify_fail("You appear to be dead.\n");
        
    if (this_player()->query_disable())
        return notify_fail("You are busy.\n");
    
    if (environment(this_player())->query_property("no magic"))
        return notify_fail("Something seems to be blocking your concentration.\n");
     
    if (this_player()->query_mp() < 50)
        return notify_fail("Too low on magic power.\n");

    if (!str || str == "" || !(ob = present(str, environment(this_player())))
        || str == "me" || str == "myself")
            ob = this_player();
            
    if (!ob)
        return notify_fail("Psiblades shield whom?\n");
 
    if (shielded[ob])
        return notify_fail(ob->query_cap_name()+" already has a psishield.\n");
        
    md = this_player()->query_skill("magic defense");
    aero = this_player()->query_skill("psionics");
    
    shielded[ob] = md;
    
    if (md < 80)  def = 1; else
    if (md < 95) def = 2; else
    if (md < 120) def = 3; else
    if (md < 160) def = 4; else
    if (md < 200) def = 5; else
    if (md >= 200) def = 6;
    time = (def*100)+random(def*5);
    
    if (aero < 60)  power = 1; else
    if (aero < 80) power = 2; else
    if (aero < 120) power = 3; else
    if (aero < 160) power = 4; else
    if (aero < 200) power = 5; else
    if (aero >= 200) power = 6;
    
    power = power + random(power);

    call_out("being_arm", 5, ob, power, time);
    
    message("info", "The air around you begins to swirl.\n", ob);
    tell_room(environment(tp), "The air around " +ob->query_cap_name() + 
        " begins to swirl.\n", ({ ob }));
    
    this_player()->add_mp(-(100 + power + random(40)) );
    tp->add_skill_points("magic defense", time/50 + 2);
    tp->add_skill_points("psionics", power/50 + 2);
    
    return 1;
    
}




int being_arm(object ob, int power, int time)
{   
    string gen;
    object n;
    
    if(ob->query_gender() == "male") gen = "him";
    else gen = "her";
    
    if (this_player()!=ob) {
        write("%^BOLD%^%^CYAN%^Bright blue shards of energy surround "+ob->query_cap_name() +"%^RESET%^");
        message("info", "%^BOLD%^%^CYAN%^" +this_player()->query_cap_name()
            +" many bright blue shards of energy around "
            +ob->query_cap_name()+"%^RESET%^", environment(ob), ({ ob, this_player() }) );  
        message("info", "%^BOLD%^%^CYAN%^"+this_player()->query_cap_name()
            +" creates many bright blue shards of energy that surround your body!%^RESET%^", ob);
    } 
    else {
        write("%^BOLD%^%^CYAN%^Bright blue shards of energy surround you!%^RESET%^");
        message("info", "%^BOLD%^%^CYAN%^"+this_player()->query_cap_name()
        +" creates many bright blue shards of energy around " +gen +"self.%^RESET%^"
        , environment(this_player()), this_player());
    }
    n = new("/wizards/daboura/obj/blades_object.c");

    n->move(ob);

    call_out("remove_prot", time, ob, n);
}

int remove_prot(object ob, object n)
{
    if(!ob) return 0;
    message("info", "The blades fall to the ground and vanish.\n", ob);
    message("info", "The blades around "+ob->query_cap_name()+" fall to the ground and vanish.", environment(ob), ob);
    map_delete(shielded, ob);
    if(n)
    n->object_gone();
}


void help() {
    write("Syntax: <psiblades>\n\n"+
      "Talented Sorcerors have been known to craft blades of pure energy using
nothing but their own minds as the source. The blades appear to be bright blue
shards of energy which whirl around the caster at high speeds, damaging anyone
they come into contact with. The blades themselves do not do much damage, but
once created a sorcerer is free to engage in any other spellcasting he or she
wishes. To dispell the blades, one simply needs to envoke the spell again.");
}



int spell() {
    if (!this_player()) return 0;
    if (this_player()->query_subclass() != "sorceror") return 0;
    if (this_player()->query_level() < 40) return 0;
    return 1;
}


