//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This is the joining not only between the trees of Stars and Autumn, but also Orn'Atar, with a branch stretching out to an entrance in the side of that tree. The leaves here are nearly all faded to yellow and red, and some have already fallen to the ground. The sun manages to shine through a few gaps in the trees.");
     set_night_long("This is the joining not only between the trees of Stars and Autumn, but also Orn'Atar, with a branch stretching out to an entrance in the side of that tree. The leaves here are nearly all faded to yellow and red, and some have already fallen to the ground. The stars above shine in through a few gaps in the trees.");
     set_exits(([
  "west" : ELFROOM"epath2.c",
  "southwest" : ELFROOM"autumn6.c",
  "northwest" : ELFROOM"stars6.c",
  "east" : ELFROOM"stars4.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
