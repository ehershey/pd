//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The trees of Summer and Stars are joined here, and the place is filled with a most peaceful aura. A summer breeze rustles the deep green leaves, dancing the shadows of the sun. This area is filled with caring, and many fall in love here.");
     set_night_long("The trees of Summer and Stars are joined here, and the place is filled with a most peaceful aura. A summer breeze whistles silently by in the night, rustling the thousands of leaves, and dancing the light of the stars. This area is filled with caring, and many fall in love here.");
     set_exits(([
  "south" : ELFROOM"stars6.c",
  "northeast" : ELFROOM"summer4.c",
  "west" : ELFROOM"summer6.c",
  "east" : ELFROOM"armourshop.c",
  "north" : ELFROOM"objectshop.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
