//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This is the junction between both the Moons and Winter trees, but also Orn'Atar, the father tree of the ring of life. It is especially busy in this place as it is the quickest path from the entrance to Corinthor to anywhere else among the trees. Despite the shining sun it is dim and cold here, and there are few leaves on the trees.");
     set_night_long("This is the junction between both the Moons and Winter trees, but also Orn'Atar, the father tree of the ring of life. It is usually busy in the day as this is the main path between Orn'Atar and the entrance to Corinthor, hardly anyone passes through at night though. In the silvery light of the moons the trees take on a pleasant glow.");
     set_exits(([
  "north" : ELFROOM"spath2.c",
  "northeast" : ELFROOM"moons6.c",
  "northwest" : ELFROOM"winter6.c",
  "south" : ELFROOM"moons4.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
