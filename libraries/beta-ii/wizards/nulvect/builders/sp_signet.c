//// Armour for Waterworld level 1 -- Tirun bay
////

#include <std.h>
#include <waterworld.h>

inherit ARMOUR;

int extra_worn();
int extra_remove();

void create() {
       ::create();
             set_name("signet of the Screaming Pelicans");
             set_id(({"signet of the Screaming Pelicans","signet","ring","screaming pelicans' ring"}));
             set_short("Quest signet of the '%^RED%^%^BOLD%^Screaming Pelicans%^RESET%^' !!");
             set_long("This is the signet ring of the '%^RED%^%^BOLD%^Screaming Pelicans%^RESET%^' !!"
                 " It is rewarded for service to the %^RED%^BOLD%^Screaming Pelicans%^RESET%^. It takes a special type of adventurer to qin such a prized quest item.  Congratulations."
                  " This ring will increase your healing rate as long as you wear it.");
             set_type("ring");
             set_ac(1);
             set_weight(5+random(15));
             set_value(random(500));

             set_wear( (: extra_worn :) );
             set_remove( (: extra_remove :) );

       }
/// special affects

int extra_worn() {
        object tp;
        tp=this_player();

     if( (tp->query("screamingpelican"))==0) {

        tp->set("screamingpelican",1);
         message("info","Your %^BOLD%^aura%^RESET%^ glows under the power of the '%^RED%^%^BOLD%^Screaming Pelicans%^RESET%^'!! You feel totally %^ORANGE%^energized%^RESET%^!!",tp);
         message("info",(tp->query_cap_name())+" glows under the enchantments of the '%^RED%^BOLD%^Screaming Pelicans%^RESET%^'. They look totally energized !!",environment(tp),tp);
         call_out("healing_cycle",5,tp);
          return 1;
                 }
      else
          {
           message("info","Wearing two of this ring would nullify the affect......\n\n",tp);
           return 0;
            }
         }

int extra_remove() {

        object tp;

         tp=this_player();

        tp->set("screamingpelican",0);
         message("info","Your %^BOLD%^aura%^RESET%^ dims as the power of the '%^RED%^%^BOLD%^Screaming Pelicans%^RESET%^' leaves you....",tp);
         message("info",(tp->query_cap_name())+"'s aura dims as the enchantments of the '%^RED%^BOLD%^Screaming Pelicans%^RESET%^' leaves them...",environment(tp),tp);
         remove_call_out("healing_cycle");
          return 1;
       }

void healing_cycle(object tp) {
        int tp_mhp;
        int h_rate;

         tp_mhp=tp->query_max_hp();
         h_rate=((tp_mhp)/100);


         tp->add_hp(h_rate);
         call_out("healing_cycle",10,tp);
    }
