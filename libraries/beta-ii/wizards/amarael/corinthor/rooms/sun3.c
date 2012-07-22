//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("Where the trees of Sun and Summer are joined is a place of great warmth and joy. At all times of the year is this place filled with green leaves in the prime of their life. To the north a bridge extends to the Corinthian palace, and to the south a path into Orn'Atar is visible.");
     set_night_long("Where the trees of Sun and Summer are joined is a place of great warmth and joy. At all times of the year is this place filled with green leaves in the prime of their life. To the north a bridge extends to the Corinthian palace, and to the south a path into Orn'Atar is barely visible in the moonlight.");
     set_exits(([
  "north" : ELFROOM"bridge1-3.c",
  "northeast" : ELFROOM"summer1.c",
  "south" : ELFROOM"sun4.c",
  "northwest" : ELFROOM"sun2.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
