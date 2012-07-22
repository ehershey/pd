inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("detach smacker");
   set_name("detach smacker");
   set_id( ({"sword"}) );
   set_long ("detach smacker ");
   set_weight(900);
   set_curr_value("gold", 121);
   set_wc(100);
   set_ac(2);
   set("skill level", 399);
   set_type("blade");
   set_hit((: this_object(), "weapon_hit" :));

   set_wield("Death to all Detach's!!");
   set_unwield("You wipe the blood of Detach off your sword...");
}

int weapon_hit(object ob)
{
 if ( ob->query_race() == "raknid" )
   {
    message("info",
      "The sword strains to reach one of Detach's vital organs.\n", environment(ob));
    return 50000;
   }
 return 1;
}
