//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This tree always looks as though it is in the middle of Autumn, an odd effect caused by the flow of life travelling around these great trees. The leaves are all yellow and red, and quite a few have already fallen, given the platform a golden patchwork look in the sunlight.");
     set_night_long("This tree always looks as though it is in the middle of Autumn, an odd effect caused by the flow of life travelling around these great trees. The leaves have all turned from their original green, and many have fallen to create a silvery patchwork path under hte moonlight.");
     set_exits(([
  "northeast" : ELFROOM"stars5.c",
  "south" : ELFROOM"autumn5.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
