//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("Here the tree of Moons comes right up against Orn'Atar, the father tree of the ring of life, upon which Corinthor stands. The tree itself is nearly bare of foliage, and any leaves still attached are withered and brown. Many of those that have fallen still sit upon the path, making the place rather pretty.");
     set_night_long("Here the tree of Moons comes right up against Orn'Atar, the father tree of the ring of life, upon which Corinthor stands. The tree itself glows in hte light of the moons, and is nearly bare of foliage. Any leaves still attached are withered and brown, and many of those that have fallen still sit upon the path, making the place rather pretty.");
     set_exits(([
  "east" : ELFROOM"autumn5.c",
  "southwest" : ELFROOM"moons5.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
