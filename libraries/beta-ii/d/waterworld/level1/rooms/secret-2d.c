/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","The sounds of a whale chuckling as the barnacles are scraped off his belly can be heard nearby.");
        set_smell("default","The overbearing smell of whale oil and a sweaty manatee fills the room.");
         set_long(
             "This is the personal office of %^GREEN%^%^BOLD%^Manatee Mike%^RESET%^."
              " Several barrels with shipping labels on them line the wall to the south."
              " A large, heavy%^BLACK%^%^BOLD%^ solid platinum%^RESET%^ desk sits in the middle of the room."
              " A large podium is positioned next to the desk."
               " One large bay window lines the northern wall, next to Mike's desk."
                  );

         set_exits(([
              "out":ROOMS1"secret-2c.c"
                     ]));
         set_items(([
             "barrels":"Several large barrels line the back of the office. They have large orange packing labels on them.",
              "labels":"They show the contents of the barrels ____ (Whale Oil == 50 pounds)",
              "desk":"It is a %^BLACK%^%^BOLD%^SOLID platinum%^RESET%^ desk. Apparently Mike has a very profitable operation here.",
              "podium":"This 'chair' is where Mike sits when he is at his desk.",
              "window":"You see several octopi stripping barnacles and oil off of a whale's hide in the bay next to the office."
                 ]));
}
void reset()
      {::reset();
          if(!present("clam")) {
             new(PEARLS"blood_clam.c")->move(this_object());
                             }
          if(!present("monster")) {
             new(MOB1"manatee_mike.c")->move(this_object());
                                 }
}
