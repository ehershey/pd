//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("Here the trees of Sun and Spring have grown together to create a wondrous effect. The bright Sun shines down from overhead upon the bright new leaves of the Spring. Vines and creepers all over the trees are flowering. This is where the elves often come to meditate and relax.");
     set_night_long("Here the trees of Sun and Spring have grown together to create a wondrous effect. The bright Sun shines down from overhead upon the bright new leaves of the Spring. Vines and creepers all over the trees are flowering, and many elves come here to meditate. Not so much at night though.");
     set_exits(([
  "west" : ELFROOM"spring3.c",
  "north" : ELFROOM"sun8.c",
  "southeast" : ELFROOM"sun6.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
