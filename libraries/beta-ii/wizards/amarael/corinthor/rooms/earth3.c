//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The Earth tree is large and gnarled with large knobs of wood sticking out at different angles. The tree looks as if it belongs in the mountains and lets off a musty smell which is pleasant to the nose. Some of the branches look as if they could be used as seating.");
     set_night_long("The Earth tree appears to be a large and menacing shape in the dark but the musty aroma states otherwise. Soft lights glow from hidden sources and give the area a morning effect. There are a few elven children wandering around talking quietly.");
     set_exits(([
  "northeast" : ELFROOM"earth4.c",
  "south" : ELFROOM"earth2.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
