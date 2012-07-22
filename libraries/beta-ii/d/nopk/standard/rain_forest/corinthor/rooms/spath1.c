//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "night light": 1, "indoors" : 1 ]));
     set_short("Corinthor");
     set_day_long("The passage inside Orn'Atar continues south, eventually leading out of the great tree, and north, to the heart of the elven town. The floor has been worn perfectly smooth over the centuries by footsteps of the elves and their visitors. Small amounts of daylight creep in from the entrance far to the south.");
     set_night_long("The passage inside Orn'Atar continues south, eventually leading out of the great tree, and north, to the heart of the elven town. The floor has been worn perfectly smooth over the centuries by footsteps of the elves and their visitors.");
     set_exits(([
  "north" : ELFROOM"square.c",
  "south" : ELFROOM"spath2.c",
                ]));
}
