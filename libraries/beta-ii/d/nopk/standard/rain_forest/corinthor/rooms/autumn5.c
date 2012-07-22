//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The leaves here have all faded to to red and brown, and quite a few have fallen to the ground. This is the joining of Autumn and Moons, and is symbolic of the passing of life. It is where elves come to remember old wars and tragic deaths. Many dead leaves scatter across the path under the daytime sun.");
     set_night_long("The leaves here have all faded to to red and brown, and quite a few have fallen to the ground. This is the joining of Autumn and Moons, and is symbolic of the passing of life. In the night, few elves can be seen remembering the death of someone they cherished, and some even offer prayers for mortal souls.");
     set_exits(([
  "west" : ELFROOM"moons6.c",
  "north" : ELFROOM"autumn6.c",
  "southeast" : ELFROOM"autumn4.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
