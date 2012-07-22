/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;


void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","The sound of the lighthouse's bells wash over this area."),
       set_long("A sizable lighthouse stands regally here at the exit of Tirun bay."
                " The lighthouse rests upon a tiny island (More of a pile of rocks than an island). The current around this area is extremely strong making travel to the west impossible.");

         set_exits(([
                 "east":ROOMS1"room-1b3.c",
                 "south":ROOMS1"room-1a4.c",
                 "north":ROOMS1"room-1a2.c"
                     ]));
         set_items(([
              "lighthouse":"It is a large %^BOLD%^white%^RESET%^ lighthouse that warns boats from entering Tirun Bay due to its shallow waters."
                     " The light is shining over an island in the ocean to the west",
               "rocks":"There is a collection of seaweed draped over them.",
                "seaweed":"The seaweed looks sturdy enough to climb."
                      ]));
             new(PEARLS"white_clam.c")->move(this_object());
}
void init() {
         ::init();
          add_action("secret","climb");
         }
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }

int secret(string input) {
           object tp=this_player();
           string name_tp=(tp->query_cap_name());

        if(!input) return notify_fail("You do your best impersonation of a mime climbing a rope.\n");

        if(input != "seaweed") return notify_fail("How do you intend to climb that?\n");

        message("info","You scale the seaweed and climb onto the lighthouse steps.",tp);
        message("info",name_tp+" scales the seaweed and climbs onto the lighthouse steps.",environment(tp),tp);
        tp->move(ROOMS1"secret-lighthouse.c");

        message("info",name_tp+" scales the seaweed and climb onto the lighthouse steps.",environment(tp),tp);
    tp->describe_current_room(1);

      return 1;
}
