#include <std.h>
inherit WEAPON;
 
create() {
::create();
    set_id(({"divine", "sword", "holy sword"}));
    set_name("holy sword");
    set_short("%^YELLOW%^H%^WHITE%^oly %^YELLOW%^S%^WHITE%^word%^RESET%^");
    set_long("%^BOLD%^WHITE%^This holy sword draws it's power from the divine energy within it's wielder.%^RESET%^");
    set_mass(20);
    set_curr_value("gold", 120);
    set_wc(9);           
    set_type("blade");
    set_hands(1);
    set_hit( (: this_object(),"weapon_hit" :) );  
}
 
int weapon_hit()
{
    int result, chance;
    object atkr, tp;
    atkr = this_player()->query_current_attacker();
    tp = this_player();
    if(random(100) < 30) {
      message("info", tp->query_cap_name()+"'s sword shines as it strikes.", environment(tp), ({tp, atkr }) );
      message("info", "%^BOLD%^WHITE%^Your sword shines as it strikes "+atkr->query_cap_name()+".%^RESET%^", tp, );
      message("info", tp->query_cap_name()+"'s sword shines as it strikes you!", atkr, );
      result=(100 - random(25));
      tp->heal(result);
      return result;
    }
}
int query_auto_load(){ 
        if (this_player()->query_guild()=="illuminati") return 1; 
}
