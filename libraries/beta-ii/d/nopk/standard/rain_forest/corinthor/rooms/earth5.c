//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This is the junction between not only the trees of Spring and Earth, but also Orn'Atar, the giant tree around which the Ring of Life stands. The junction is slightly busier than the rest of the village, with people using the passages through Orn'Atar as a shortcut to the other side of the Ring.");
     set_night_long("This is the junction between not only the trees of Spring and Earth, but also Orn'Atar, the giant tree around which the Ring of Life stands. The junction, although busy during the day, is not so now, as most of the elves that live here are already off to bed.");
     set_exits(([
  "east" : ELFROOM"wpath2.c",
  "northeast" : ELFROOM"spring4.c",
  "southeast" : ELFROOM"earth6.c",
  "west" : ELFROOM"earth4.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
