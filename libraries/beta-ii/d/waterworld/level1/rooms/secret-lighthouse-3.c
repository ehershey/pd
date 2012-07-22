/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties(([
                        "light":3,"night light":3,"no bump":1,
                           "indoors":1
                         ]));
         set_listen("default","The din of machinery drowns out all other sounds....");

          set_smell("default","Sulphur and whale oil incense make for a strange mixture of aromas.");
         set_listen("captain","The captain says, 'The stockpile of whale oil is running dangerously low traveler. We are going to need another shipment of whale oil soon if this lighthouse is to remain operational!!'\n\nPelican Paul says,'Can you do me a favor and travel to Pelican Pete's bar and ask Pelican Patty for some whale oil for Pelican Paul? If you do this for me I will reward you once the oil is in those barrels over there.'\n\n");
         set_listen("sea captain","The captain says, 'The stockpile of whale oil is running dangerously low traveler. We are going to need another shipment of whale oil soon if this lighthouse is to remain operational!!'\n\nPelican Paul says,'Can you do me a favor and travel to Pelican Pete's bar and ask Pelican Patty for some whale oil for Pelican Paul? If you do this for me I will reward you once the oil is in those barrels over there.'\n\n");
          set_long(
               "The lighthouse beacon sits prominently in the center of this room. Its light radiates over the ocean to the west."
                " A few barrels of whale oil and some boxes are lined up against the far wall."
                 " A large desk sits against the wall next to the access door."
                 " A very large lounge chair rests near the glass overlooking the bay."
                    );

         set_exits(([
                   "out":ROOMS1+"secret-lighthouse-2.c"
                     ]));
         set_items(([
                 "panel":"It is the access panel for refueling the beacon with whale oil.",
                  "barrels":"Several empty barrels of whale oil.",
                  "bay":"An island shrouded in mist rests far to the west of here.",
                   "desk":"An old oak desk with several drawers in it."
                 ]));
}
void reset() {
          ::reset();
               if(!present("monster")) {new(MOB1"pelican_paul.c")->move(this_object()); }
         }
