//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "night light": 1, "indoors" : 1 ]));
     set_short("Corinthor");
     set_day_long("The passage leads north and south through Orn'Atar. At this point the town market is directly to the south, with the passage cotinuing on to the north eventually leading to hte palace. The walls are kept in perfect condition, while the floor is kept smooth by the hundreds of people walking through. Daylight can barely be seen far to the north.");
     set_night_long("The passage leads north and south through Orn'Atar. At this point the town market is directly to the south, with the passage cotinuing on to the north eventually leading to hte palace. The walls are kept in perfect condition, while the floor is kept smooth by the hundreds of people walking through.");
     set_exits(([
  "south" : ELFROOM"square.c",
  "north" : ELFROOM"npath2.c",
                ]));
}
