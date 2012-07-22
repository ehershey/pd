//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "night light": 1, "indoors" : 1 ]));
     set_short("Corinthor");
     set_day_long("This is the southern entrance to Orn'Atar, the 'father tree' of the elves. This passage has been hollowed out of the trunk of the tree with great care, with the wood in perfect condition. The floor has been worn smooth by the passage of elves in and out of the town's heart. Sunlight can be seen outside to the south.");
     set_night_long("This is the southern entrance to Orn'Atar, the 'father tree' of the elves. This passage has been hollowed out of the trunk of the tree with great care, with the wood in perfect condition. The floor has been worn smooth by the passage of elves in and out of the town's heart.");
     set_exits(([
  "south" : ELFROOM"moons5.c",
  "north" : ELFROOM"spath1.c",
                ]));
}
