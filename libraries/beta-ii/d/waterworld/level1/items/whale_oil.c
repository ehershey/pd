///
/// Object file for Tirun Bay
/// by ironman

#include <std.h>
#include <waterworld.h>

inherit ITEMS1+"barrel_oil.c";

void create()
      {::create();
         set_name("barrel");
         set_id(({"whale oil barrel","label","whale oil","barrel"}));
         set_short("A barrel of whale oil");
         set_long("A '%^ORANGE%^Screaming Pelicans%^RESET%^' brand barrel of whale oil."
               " Its label says it has fifty gallons of Whale Oil. Perhaps you can %^YELLOW%^jump%^RESET%^ into the %^YELLOW%^barrel%^RESET%^.");
          set_weight(100);
          set_value(1000);
          set_your_mess("You jump into the barrel of %^ORANGE%^Screaming Pelican%^RESET%^ whale oil and soak for awhile then jump out.");
          set_their_mess(""," jumps into the barrel of %^ORANGE%^Screaming Pelican%^RESET%^ whale oil and soaks "," wounds.");
          set_heal_mess("A whale swims through the room by magic, licks you in the face and swims away merrily. Your wounds glow and close some.");
           set_uses(50+random(random(25)));
          set_action("jump");

           set("read",
          "\n\nIt reads:\n\n%^RED%^Screaming Pelicans%^RESET%^ brand whale oil....Harvested daily from fresh whales!!"
          "\n\n%^ORANGE%^%^BOLD%^NOTICE%^RESET%^--- No whales were harmed in the making of this product.\n\n");
}
