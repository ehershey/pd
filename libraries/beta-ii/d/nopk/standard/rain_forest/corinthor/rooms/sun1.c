//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The northwestern edge of the Sun tree gives a completely unobstructed view of the forest, and is most magnificent during the day with the bright golden beams of sunlight shining down from above. The leaves of this tree are lush and green and full of life. The path continues east and southwest.");
     set_night_long("The northwestern edge of the Sun tree gives a completely unobstructed view of the forest, though it does not do much good during the night as the moons offer little light compared to the sun. The leaves of this tree here are lush and green, full of life granted by the sun.");
     set_exits(([
  "southwest" : ELFROOM"sun8.c",
  "east" : ELFROOM"sun2.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
