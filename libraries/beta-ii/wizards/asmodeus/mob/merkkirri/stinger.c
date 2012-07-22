#include <mjungle.h>
#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"fang"}));
set_name("stinger");
set_short("a stinger");
set_long("A stinger.  If you have this, you shouldn't and you should report it to Armrha right after you bury it.");
set_value(0);
set_weight(1);
set_wc(15);
set_ac(1);
set_type("melee");
set_hit( (: this_object(), "weapon_hit" :) );
set_hands(2);
set_wield("You shouldn't have this.  Bury it now!");
}

void init() {
 ::init();
add_action("Destruct", "unwield");
}

int Destruct(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
   this_object()->remove();
   return 1;
}

int weapon_hit() {
   int result;
   object atk;
   atk = (object)this_player()->query_current_attacker();

if(random(100) > 75) {
result = (random(30))+((this_player()->query_level()));
atk->set_paralyzed(random(6));
atk->add_poisoning(15);
      return result;
   }
return 0;
}
