//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The tree of Earth is huge, with large, crooked branches that spread out at odd angles. There are hundreds of tiny little leaves that are only just growing from out of the  depths of winter. The tree itself is cool to the touch, even in the direct sunlight.");
     set_night_long("The tree of Earth is huge, with large, crooked branches that spread out at odd angles. There are hundreds of tiny little leaves that are only just growing from out of the  depths of winter. The tree itself is quite cold to the touch, as though it has never seen the sun.");
     set_exits(([
  "north" : ELFROOM"earth3.c",
  "southeast" : ELFROOM"earth1.c",
  "east" : ELFROOM"earthhome1.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
