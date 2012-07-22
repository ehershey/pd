//// Armour for Waterworld level 1 -- Tirun bay
////

#include <std.h>
#include <waterworld.h>

inherit ARMOUR;

int wear_ok;
int extra_worn();
int extra_remove();

int tempo;


void create() {
       ::create();
             set_name("signet of the Screaming Pelicans");
             set_id(({"signet of the Screaming Pelicans","signet","ring","screaming pelicans' ring"}));
             set_short("Quest signet of the '%^RED%^%^BOLD%^Screaming Pelicans%^RESET%^'");
             set_long("This is the signet ring of the '%^RED%^%^BOLD%^Screaming Pelicans%^RESET%^'"
                 " It is rewarded for service to the %^RED%^BOLD%^Screaming Pelicans%^RESET%^. A special type of adventurer is needed to win such a prized item.  Congratulations."
                    );
             set_type("ring");
             set_ac(1);
             set_weight(random(5));

             set_heart_beat(1);
             set_wear( (: extra_worn :) );
             set_remove( (: extra_remove :) );
             set("read","Thank you for your loyal service to us.\n\nThe %^RED%^Screaming Pelicans%^RESET%^ of Tirun Bay.\n");

                     }

/// special effects

int extra_worn() {
        object tp;
        tp=this_player();

     if(member_array("Order of the Screaming Pelicans",(tp->query_quests())) ==  -1)
         {
           this_object()->remove();
            message("info","You have not honored the %^RED%^Screaming Pelicans%^RESET%^ by completing their quest\n\nThe signet %^MAGENTA%^EXPLODES%^RESET%^ in your hand!",tp);
            message("info","\n\nThe signet of the %^RED%^Screaming Pelicans%^RESET%^ explodes in "+(tp->query_cap_name())+"'s hand\n\n",environment(tp),tp);
           return 0;
              }
     else if( (tp->query("screamingpelican"))==0) {

        tp->set("screamingpelican",1);
         message("info","Your %^BOLD%^aura%^RESET%^ glows under the power of the %^RED%^%^BOLD%^Screaming Pelicans%^RESET%^\nYou feel totally %^ORANGE%^energized%^RESET%^",tp);
         message("info",(tp->query_cap_name())+" glows under the enchantments of the '%^RED%^BOLD%^Screaming Pelicans%^RESET%^'. They look totally energized",environment(tp),tp);
         return 1;
         }
      else
          {
           message("info","Wearing two of this ring would nullify the effect.\n",tp);
           return 0;
            }

    }
int extra_remove() {

        object tp;

         tp=this_player();

        tp->set("screamingpelican",0);
         message("info","Your %^BOLD%^aura%^RESET%^ dims as the power of the '%^RED%^%^BOLD%^Screaming Pelicans%^RESET%^' leaves you.",tp);
         message("info",(tp->query_cap_name())+"'s aura dims as the enchantments of the '%^RED%^BOLD%^Screaming Pelicans%^RESET%^' leaves "+tp->query_objective()+".",environment(tp),tp);
          return 1;
       }

void heart_beat() {
        object tp;
        int tp_mhp;
        int h_rate;
        int CYCLES=3; // NOTE---This controls the speed of the healing

        if(this_object()->query_worn() && tempo==CYCLES ) {
               tp=this_object()->query_worn();
                tp_mhp=tp->query_max_hp();
                h_rate=((tp_mhp)/100);

                tp->add_hp(h_rate);
                tempo=0;
              }
       else tempo +=1;
}

mixed *query_auto_load() {
       if(member_array("Order of the Screaming Pelicans",(this_player()->query_quests())) == -1)
           { return 0;}
       else
         {
       return ({ARMOR1+"sp_signet.c",({}) });
       }
}
