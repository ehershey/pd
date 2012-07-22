//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The Summer tree stands on the northern edge of Corinthor and gives a nice view of the palace, as well as much of the forest. This tree looks to be in it's prime, the leaves are a dark green and not a single one has been broken. The sun shines down from above making the area quite hot, even in the shade.");
     set_night_long("The Summer tree stands on the northern edge of Corinthor and gives a nice view of the palace, as well as much of the forest. This tree looks to be in it's prime, the leaves are a dark green and not a single one has been broken. The moons hang low in the sky and a warm breeze passes as though it were the middle of summer.");
     set_exits(([
  "east" : ELFROOM"summer2.c",
  "southwest" : ELFROOM"sun3.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
