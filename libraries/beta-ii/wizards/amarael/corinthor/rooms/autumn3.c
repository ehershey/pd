//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The Autumn tree is filled with red and yellow leaves, nearly ready to fall to the ground ready for winter. There are always a few leaves floating down to the ground, but mysteriously very little are actually missing from the tree. The path here leads around the outer edge of the tree.");
     set_night_long("The Autumn tree is filled with red and yellow leaves, nearly ready to fall to the ground ready for winter. Dark shapes show several leaves falling to the ground, yet mysteriously there are no gaps through the tree to see the stars above.");
     set_exits(([
  "west" : ELFROOM"autumn4.c",
  "northeast" : ELFROOM"autumn2.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
