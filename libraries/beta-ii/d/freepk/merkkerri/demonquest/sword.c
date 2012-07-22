#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {
::create();
set_id(({"sword", "blade"}));
set_name("sword");
set_short("%^RESET%^BLUE%^S%^GREEN%^w%^BLUE%^or%^BOLD%^BLACK%^d%^RESET%^BLUE%^ of C%^GREEN%^h%^BLUE%^ao%^BOLD%^BLACK%^s%^RESET%^");
set_long("%^GREEN%^The Sword of Chaos is shaped much like an enlongated butcher knife with a silver-blue blade.  It's hilt is made of pure platinum and is adorned by two sapphires and an emerald.  A black star seems to float lazily inside the large emerald.%^RESET%^");
set_curr_value("gold",100);
set_weight(17);
set_wc(12);
set_ac(2);
set_type("blade");
set_hit( (: weapon_hit :) );
set_hands(1);
set_wield("Your mind is filled with %^RED%^c%^YELLOW%^o%^MAGENTA%^l%^ORANGE%^o%^BLUE%^r%^RED%^s%^RESET%^ that quickly melt and blend back into reality.");
set_unwield("%^YELLOW%^S%^RESET%^t%^YELLOW%^a%^RESET%^r%^YELLOW%^s%^RESET%^ momentarily flood your vision as you unwield sword.");
}

void init() {
 ::init();
   add_action("Destruct", "sell");
}

int Destruct(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
   write("%^YELLOW%^As you try to sell the sword, it disolves "
"in your hands!%^RESET%^");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
         "'s sword disovles as "+
         this_player()->query_subjective()
         +"tries to sell it!", ({ this_player() }));
   this_object()->remove();
   return 1;
}

int weapon_hit(object atk) {
   int result;

if(random(100) > 95) {
write("The sword flashes %^YELLOW%^brightly%^RESET%^ as it warps your foe's existence with %^BLUE%^c%^RESET%^GREEN%^h%^RESET%^BLUE%^ao%^RESET%^BOLD%^BLACK%^s%^RESET%^!");
say((string)this_player()->query_cap_name()+"'s sword flashes %^YELLOW%^brightly%^RESET%^, warping its victim's %^BLUE%^r%^RESET%^GREEN%^ea%^RESET%^BLUE%^lit%^RESET%^BLACK%^y%^RESET%^ as it strikes!");
result = ((random(20)+random(20)-random(15)+random(10))+((this_player()->query_level()/2)+1));
      result=random(result)+1;
this_player()->add_sp(result);
atk->add_sp(-result/2);
atk->add_mp(-result/2);
atk->set_paralyzed(1+random(3));
      return result;
   }
   return 0;
}
