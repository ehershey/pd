//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The Spring tree is large and full of fresh smelling and bright leaves like those found in the springtime. The tree lets off a pleasing aroma of fresh sap and the sound of birds singing can be heard all around you. This is a very pleasant spot to be standing and the thought of leaving saddens the heart.");
     set_night_long("Although very dark, the Spring tree lets of a warm glow that subtly lights the area. The tree lets off a nice aroma and soft leaves are scattered over the walkway. Young elves come here to learn about the spring season, although all are in bed at this time of night.");
     set_exits(([
  "north" : ELFROOM"spring2.c",
  "southeast" : ELFROOM"earth4.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
