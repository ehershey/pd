/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
        set_long("This section of the beach is deserted. There is a jette reaching to the south of here and a line of trees barring passage to the north."
                 " It appears this area was the nesting grounds to a few species of birds."
                 " There are a multitude of empty bird nests here too.");

         set_exits(([
                 "west":ROOMS1"room-1f1.c",
                 "south":ROOMS1"room-1g2.c",
        "north":"/d/nopk/tirun/beach/6,1,0",
        "east":"/d/nopk/tirun/beach/7,2,0",
                 "southwest":ROOMS1"room-1f2.c"
                     ]));
         set_items(([
                  "nests":"They're full of cracked egg shells. Seems they're old and abandoned nests.",
                   "trees":"Just a bunch of palm trees and other foliage."
                 ]));
             new(PEARLS"white_clam.c")->move(this_object());
}
