//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("Here the Summer and Sun are joined to create the warmest place of the forest. The sun shines right through the treetops to bring warmth to the entire place. The leaves here are always full and green. A single plank of wood extends south into the father tree.");
     set_night_long("Here the Summer and Sun are joined to create the warmest place of the forest. Even in the night the heat of the sun can be felt, keeping the entire place in warmth. The leaves here are always full and green. A single plank of wood extends south into the father tree.");
     set_exits(([
  "south" : ELFROOM"npath2.c",
  "southeast" : ELFROOM"summer6.c",
  "southwest" : ELFROOM"sun5.c",
  "north" : ELFROOM"sun3.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
