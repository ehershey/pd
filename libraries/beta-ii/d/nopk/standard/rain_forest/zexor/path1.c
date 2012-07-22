#include <std.h>
#include <zexor.h>
inherit ROOM;

void create() {
   ::create();
   set_short("Entrance");
   set_long("This area is covered by trees and bushes of all sizes. "
        "There is one tree that seems to have a low hanging branch "
       "with foot-marks all over it.");
   set_items((["trees" : "There are trees of many different sizes",
       "bushes" : "Just ordinary bushes.",
       "tree" : "This has a low hanging branch",
       "branch" : "This branch has foot prints all over it",
       ({"foot-marks", "foot prints", "prints"}) : "These are many footprints covering a low hanging branch"]));
   set_exits((["northeast" : "/d/standard/rain_forest/dirtsw.c",
       "southwest" : ROOMS"path2",
       "south" : ROOMS"path7",
       "southeast" : ROOMS"path10"]));
}

void reset() {
   ::reset();
   if(!present("amazon"))
     new(MOB"entrancea")->move(this_object());
}
