/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

object humpy,blueboy;
object oscar,orvis;
void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","The deafening roar of machinery echos throughout the cavern!!");
        set_smell("default","The smell of sweaty animals fill the area.....");
        set_long(
              "A large underground warehouse is set up in this cavern."
               " Mountains of barrels, crates, boxes and piles of animal pelts line the docks."
              " Several docks spread out into the western section of the underground lagoon."
               " Several whales await their turns at the docks."
               " Multiple octopi work here moving cargo around with their mighty tentacles!!"
                 );

         add_invis_exit("passageway");
         set_exits(([
               "out":ROOMS1"secret-2b.c",
               "passageway":ROOMS1"secret-2d.c"
                     ]));
         set_items(([
              "barrels":"There are barrels of barnacles and whale oil. Both empty and filled for shipment.",
              "crates":"Crates and crates filled with tools and supplies.",
              "docks":"Several docking bays for the whales to rest in while awaiting their turns with the octopi.",
              "octopi":"Multiple octopi are scrambling around in haste trying to take care of the whales' needs.",
              "passageway":"There is a small passageway leading to Manatee Mike's office."
                 ]));
             new(PEARLS"black_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
        ::reset();
      if(!present("monster")) {

           new(MOB1"humpy.c")->move(this_object());
           new(MOB1"blue_boy.c")->move(this_object());
           new(MOB1"oscar.c")->move(this_object());
           new(MOB1"orvis.c")->move(this_object());
}
}

void remote_control(string pname) {
          blueboy=present("blueboy");
          humpy=present("humpy");
          orvis=present("orvis");
          oscar=present("oscar");

          if(humpy != 0) {humpy->force_me("kill "+pname); }
          if(blueboy != 0) {blueboy->force_me("kill "+pname); }
          if(oscar != 0) {oscar->force_me("kill "+pname); }
          if(orvis != 0) {orvis->force_me("kill "+pname); }
      }
