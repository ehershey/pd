/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
     set_listen("","");
      set_smell("","");
        set_long(
             "The Ol' Tirun Lighthouse towers above this spot."
              " Some seaweed is draped over the walkway's railing and decends into the sea below."
              " There is a massive door in the side of the lighthouse."
               " The lighthouse's beacon shines brightly into the distance from high above."
                  );

         set_exits(([
              "down":ROOMS1"room-1a3.c",
               "enter":ROOMS1"secret-lighthouse-2.c"
                     ]));
         set_items(([
            "door":"The door is wide open and inviting!!",
            "seaweed":"The seaweed is torn to shreds and matted down from someone climbing on it.",
            "railing":"What remains of the railings and walkway are sturdy. However most of the lower steps have been washed away.\nA person can climb down but, it's impossible to make it back up here with the stairs."
                 ]));
             new(PEARLS"purple_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
