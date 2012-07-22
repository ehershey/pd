//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The tree of Moons is not partial to the day, and seems to suck the light right out of the air. The tree's silvery grey branches have been chosen as the home for the Mages guild of Corinthor, with the entrance just west of here. Many leaves have fallen from this tree, and they spread scross the ground.");
     set_night_long("The tree of Moons is a part of the night, and seems to glow and the moonlight. The tree's silvery grey branches have been chosen as the home for the Mages guild of Corinthor, with the entrance just west of here. Many leaves have fallen from this tree, and they spread scross the ground.");
     set_exits(([
  "southwest" : ELFROOM"moons2.c",
  "north" : ELFROOM"autumn4.c",
  "west" : ELFROOM"mageguild.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
