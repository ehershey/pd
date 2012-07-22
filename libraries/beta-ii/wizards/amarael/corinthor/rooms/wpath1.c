//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "night light": 1, "indoors" : 1 ]));
     set_short("Corinthor");
     set_day_long("The inside of Orn'Atar is not as cramped as one would expect. The passages are quite spcious, enough for 5 people to walk abreast, and tall enough even to fit a giant, just. Directly to the east of here is the town market, and the passage continues west back out of the tree, were daylight can barely be seen.");
     set_night_long("The inside of Orn'Atar is not as cramped as one would expect. The passages are quite spcious, enough for 5 people to walk abreast, and tall enough even to fit a giant, just. Directly to the east of here is the town market, and the passage continues west back out of the tree.");
     set_exits(([
  "east" : ELFROOM"square.c",
  "west" : ELFROOM"wpath2.c",
                ]));
}
