inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("%^BOLD%^%^BLACK%^Skull Sword%^RESET%^");
   set_name("%^BOLD%^%^BLACK%^Skull Sword%^RESET%^");
   set_id( ({"sword", "skull sword"}) );
   set_long ("%^BOLD%^%^BLACK%^This huge, one-handed sword is crafted out of a mystical dark metal. Its blade is serrated and razor-sharp, and is engraved with skulls along its length. Its long handle is as strong as iron, and appears to be the legbone of some creature. A small skull is set in the pommel.%^RESET%^");
   set_weight(90);
   set_curr_value("gold", 121);
   set_wc(9);
   set_ac(2);
   set("skill level", 250);
   set_type("blade");
   set_hit((: this_object(), "weapon_hit" :));
   set_wield("%^BOLD%^%^WHITE%^Your flesh tingles as you grip the hilt of the sword.");
   set_unwield("You sigh in relief as you let go of the sword.");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^BLACK%^The sword cleaves through flesh and bone as it strikes "+atk->query_cap_name()+".");
        say("%^BOLD%^%^BLACK%^"+(string)this_player()->query_cap_name()+" cleaves through flesh and bone as they strike "+atk->query_cap_name()+".");
       
result=(random(55)+80)+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 60) return 1; }
