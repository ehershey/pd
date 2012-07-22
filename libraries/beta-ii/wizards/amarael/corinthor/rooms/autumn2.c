//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This part of the platform leads around the eastern edge of the tree of Autumn, and as many of the outer areas of Corinthor, offers a marvellous view of the forest. Leaves flutter down from above, littering the path below and giving it a funny patched look.");
     set_night_long("This part of the platform leads around the eastern edge of the tree of Autumn, and as many of the outer areas of Corinthor, offers an unobstructed view out into the forest, not much can be seen out there at night though. Leaves can be seen as dark shapes fluttering down from above, littering the path below and giving it a funny patched look.");
     set_exits(([
  "southwest" : ELFROOM"autumn3.c",
  "north" : ELFROOM"autumn1.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
