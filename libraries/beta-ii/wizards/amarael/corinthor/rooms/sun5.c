//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The Sun tree takes an inward swing here, bringing it quite close to Orn'Atar, the father tree. The giant trunk of that tree stretches far into the sky above, clearly lit in the daytime sun. The leaves of this tree are a deep green and full of the life provided by the sun.");
     set_night_long("The Sun tree takes an inward swing here, bringing it quite close to Orn'Atar, the father tree. The giant trunk of that tree stretches far into the sky above, disappearing in the darkness of night. The leaves of this tree are a deep green and full of the life provided by the sun.");
     set_exits(([
  "northeast" : ELFROOM"sun4.c",
  "west" : ELFROOM"sun6.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
