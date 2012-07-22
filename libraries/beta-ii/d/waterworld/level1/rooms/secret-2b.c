/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

object money;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
        set_long(
               "The wreckages of several unfortunate vessels litter the entrance to this underwater cavern."
               " The walls of the cavern are a virtual museum of different minerals and gems."
                " An odd looking clam is lying in the middle of the room.");

         set_listen("default","The sound of machinery can be heard from nearby.");
         set_listen("machinery","The sound is coming from a passage hidden in the wall!!");
         add_invis_exit("passage");
         set_exits(([
                 "passage":ROOMS1"secret-2c.c",
                  "up":ROOMS1"room-1c4.c"
                     ]));
         set_items(([
                "minerals":"There are chunks of iron, copper, coal and other minerals scattered around the cave.",
                 "gems":"A pile of precious gems are stacked in the corner!!"
                 ]));
             new(PEARLS"rose_clam.c")->move(this_object());
      if(!present("money")) {
        money = new("/std/obj/coins");
         money->set_money("platinum", random(5));
         money->set_money("gold", random(50));
         money->set_money("silver", random(200));
         money->move(this_object());
}
}
// Mob regeneration
void reset() {
         ::reset();
           MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
                      }
