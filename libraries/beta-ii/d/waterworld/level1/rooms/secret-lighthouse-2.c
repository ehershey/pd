/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","The churning of the lighthouse machinery echos off the walls with a deafening roar!!");
       set_smell("default","The strange mixture of fish and smoldering dust fills the air...");
       set_long(
                "The interior of the lighthouse is well lit from the backwash of the beacon above."
                 " Several ropes, pails, fishing poles and other boating accesories adorn the walls."
                " A simple cot and dresser rest in the corner."
                " There is a set of stairs leading up to the beacon."
                 );

         set_exits(([
              "out":ROOMS1"secret-lighthouse.c",
              "up":ROOMS1"secret-lighthouse-3.c"
                     ]));
         set_items(([
               "ropes":"Good sturdy ropes for tying up boats.",
                "pails":"They have fresh fish in them. Apparently someone was here recently...",
                "cot":"It is well groomed with fresh sheets and a fluffy pillow."
                 ]));
             //new(PEARLS"purple_clam.c")->move(this_object());
}
