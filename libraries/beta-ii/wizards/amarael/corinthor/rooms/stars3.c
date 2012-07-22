//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The leaves of the Stars tree are gradully turning to yellow and red, and are nearly ready to fall. The view of the eastern forest is spectacular, with dozens of birds an animals peaefully moving about unawares of any watchers. The sun shines high overhead.");
     set_night_long("The tree of Stars offers a spectacular view at night, not just of the forest, but of the tree itself. Thousands of points of light are constantly fading in and out, as the move up and down the tree. The glow shows that the leaves here are turning to yellow and red, ready to fall.");
     set_exits(([
  "southwest" : ELFROOM"stars4.c",
  "north" : ELFROOM"stars2.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
