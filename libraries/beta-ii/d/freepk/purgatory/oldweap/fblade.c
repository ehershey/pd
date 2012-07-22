#include <std.h>
inherit WEAPON;
void create() {
    ::create();
    set_id(({"blade", "sword"}));
    set_name("%^BOLD%^%^BLACK%^Fo%^BOLD%^%^WHITE%^rb%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^dd%^BOLD%^%^BLACK%^en %^BOLD%^%^BLACK%^B%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^e");
    set_short("%^BOLD%^%^BLACK%^Fo%^BOLD%^%^WHITE%^rb%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^dd%^BOLD%^%^BLACK%^en %^BOLD%^%^BLACK%^B%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^e");
    set_long( "%^BOLD%^%^BLACK%^This %^BOLD%^%^BLACK%^B%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^e was forged by an insane smith using metals tainted by evil.");
    set_mass(75);
    set_curr_value("gold",100);
    set_wc(10);
    set_ac(2);
    //set("skill level", 200);
    set_type("blade");
    set_decay_rate(2000);
    set_wield("%^BOLD%^%^BLACK%^The sword quivers with evil and a cold chill creeps up your arm.");
    set_unwield("%^BOLD%^%^WHITE%^The chill receeds from your body as the sword releases you.");
   //set_hit((: this_object(), "weapon_hit" :));
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^BLACK%^Your %^BOLD%^%^BLACK%^Fo%^BOLD%^%^WHITE%^rb%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^dd%^BOLD%^%^BLACK%^en %^BOLD%^%^BLACK%^B%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^e rips the flesh of "+atk->query_cap_name()+".");
        say(""+(string)this_player()->query_cap_name()+"'s %^BOLD%^%^BLACK%^Fo%^BOLD%^%^WHITE%^rb%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^dd%^BOLD%^%^BLACK%^en %^BOLD%^%^BLACK%^B%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^e chops deeply into "+atk->query_cap_name()+".");
       
result= (random(80)+20);

    }
}
 int query_auto_load() { if (this_player()->query_level() > 45) return 1; }

int slap_on_the_wrist(string str) {

   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_level() > 40) return 0;
   write("Wielding this sword would not be a good idea.");
   say(this_player()->query_cap_name()+" looks confused.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wield");
}
