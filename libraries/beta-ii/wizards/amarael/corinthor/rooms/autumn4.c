//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This is the joining between the trees of Autumn and Moons. The leaves are all faded to red and brown, and many have already fallen, creating a soft golden carpet upon which to tread. The two trees together are symbolic of the passing of life, and this is the chosen place for people to mourn.");
     set_night_long("This is the joining between the trees of Autumn and Moons. The leaves are all faded to red and brown, and many have already fallen, making a soft carpet to walk upon. This place is symbolic of life passing, and several elves are out at night, praying for mortals souls no longer of this realm.");
     set_exits(([
  "south" : ELFROOM"moons1.c",
  "northwest" : ELFROOM"autumn5.c",
  "east" : ELFROOM"autumn3.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
