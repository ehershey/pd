//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The Sun Tree platfrom curves around to the northeast and south from here. To the east is an elven home, but there is no way to get in from here. A few small animals scurry about the tree looking for food while the sun shines down from on high.");
     set_night_long("The platform of the Sun Tree curves around to the northeast and south from this spot. To the east can be seen the glow from the window of an elven home, although it is impossible to reach it from here. Everything is cast in the silvery glow of the moons.");
     set_exits(([
  "northeast" : ELFROOM"sun1.c",
  "south" : ELFROOM"sun7.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
