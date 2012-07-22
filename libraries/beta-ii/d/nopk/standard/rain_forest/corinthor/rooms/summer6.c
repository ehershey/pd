//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The Summer tree's leaves are a deep emerald green colour, and sway in a hot breeze. The plat is clear of any dead foliage, and comes quite close to the father tree of the ring of life, Orn'Atar. The trunk of that tree stretching up forever into the sky. Several elven children run by as they play under the sun.");
     set_night_long("The Summer tree's leaves are a deep emerald green colour, and sway in a hot breeze. The plat is clear of any dead foliage, and comes quite close to the father tree of the ring of life, Orn'Atar. The trunk of that tree stretching up forever into the dark night sky. A few elven children rush by, hurrying home after a day of play.");
     set_exits(([
  "east" : ELFROOM"summer5.c",
  "northwest" : ELFROOM"sun4.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
