//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The Winter tree is bare and skeletal, all its leaves are on the walkway creating a carpet effect. The tree looks like it is in the middle of winter, ice hanging off its skeletal branches. The tree gives off a sweet smell and several small elven children are seen sitting around the trunk giggling.");
     set_night_long("The Winter tree looks like a giant skeleton reaching up to the moons. A sweet smell is givin off by the tree and there are patches of wet leaves on the ground. Ice can be seen hanging in the braches, illuminated by the soft light coming from hidden lighting. ");
     set_exits(([
  "west" : ELFROOM"winter2.c",
  "northeast" : ELFROOM"moons4.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
