//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This part of the tree of Moons is the most southeasterly point of Corinthor, leaving a huge open view of the forest. The tree has lost nearly all of it's leaves, and any that are left have faded to a very dark red. Many of the fallen leaves are still on the path here making an odd carpet effect.");
     set_night_long("This part of the tree of Moons is the most southeasterly point of Corinthor, leaving a huge open view of the forest. The tree itself glows in the moonlight, and it has lost nearly all of it's leaves, any that are left have faded to a very dark red. Many of the fallen leaves are still on the path here making an odd carpet effect.");
     set_exits(([
  "west" : ELFROOM"moons3.c",
  "northeast" : ELFROOM"moons1.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
