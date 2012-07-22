//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The south side of the Earth tree comes around quite close to the Winter tree, although not quite close enough to jump between them. It offers a fairly good view of the southwestern part of the forest, but large trees block any other view.");
     set_night_long("Although dark, there is some light from hidden lanterns among the Earth and Winter trees. The slight moonlight offers a great view of the forest and many night animals can be heard among the forest below.");
     set_exits(([
  "northwest" : ELFROOM"earth2.c",
  "east" : ELFROOM"winter4.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
