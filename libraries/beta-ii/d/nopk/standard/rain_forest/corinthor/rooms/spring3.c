//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The north side of Spring comes around quite close to the Sun tree, although not quite close enough to jump between them. It offers a fairly nice view out to the northwest of the forest, with dozens of tall trees blocking off the view quite quickly. The forest floor below can be seen during the day.");
     set_night_long("The north side of Spring comes around quite close to the Sun tree, although not quite close enough to jump between them. It offers a fairly nice view out to the northwest of the forest, with dozens of tall trees blocking off the view even before the darkness does. The forest floor is lost in the shadows of moonlight.");
     set_exits(([
  "east" : ELFROOM"sun7.c",
  "southwest" : ELFROOM"spring2.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
