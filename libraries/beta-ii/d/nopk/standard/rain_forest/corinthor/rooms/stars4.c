//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This is the outer joining the trees Stars and Autumn. The trees split apart to the northeast and southeast, and in between them directly to the east the forest stretches far away. golden beams of line shine on down from the Sun above. ");
     set_night_long("This is the outer joining the trees Stars and Autumn. The trees split apart to the northeast and southeast, and in between them directly to the east the dark forest stretches on. The trunk of Stars, to the north, shines with thousands of tiny lights constantly moving around.");
     set_exits(([
  "southeast" : ELFROOM"autumn1.c",
  "west" : ELFROOM"stars5.c",
  "northeast" : ELFROOM"stars3.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
