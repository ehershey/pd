//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The Sun tree sits on the northern edge of the ring of life, and gives an unobstructed view of the palace to the north. All around the forest stretches out under the bright light of the sun. The Leaves here are green and full of life. To the south is the entrance of an elven home.");
     set_night_long("The Sun tree sits on the northern edge of the ring of life, and gives an unobstructed view of the palace to the north. The Leaves here are green and full of life. The forest stretches out into the darkness of the night, and to the south can be seen the entrance to an elven home.");
     set_exits(([
  "south" : ELFROOM"sunhome1.c",
  "west" : ELFROOM"sun1.c",
  "southeast" : ELFROOM"sun3.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
