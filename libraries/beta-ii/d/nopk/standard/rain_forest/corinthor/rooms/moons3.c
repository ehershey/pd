//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The tree of Moons sits on the south side of Corinthor, it's branches are a silvery grey colour unlike most other trees, and they twist and curve forming strange weaves in the air. From here the south forest can be seen, and there is a bridge just to the west and extending south.");
     set_night_long("The tree of Moons sits on the south side of Corinthor, it's branches are a silvery grey colour that shine in the moonlight, they twist and curve forming strange weaves in the air. From here the south forest can be seen, and there is a bridge just to the west and extending south.");
     set_exits(([
  "northwest" : ELFROOM"moons4.c",
  "east" : ELFROOM"moons2.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
