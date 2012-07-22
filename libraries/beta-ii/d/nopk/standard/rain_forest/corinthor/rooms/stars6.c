//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The tree of Stars comes quite close to Orn'Atar here, close enough that some branches actually reach out and touch the father tree. Many of the leaves of Stars are turning yellow, as though ready to fall before the winter months.The sun shines in the sky above.");
     set_night_long("The tree of Stars comes quite close to Orn'Atar here, close enough the same of the branches actuallyr each out and touch the father tree. The trunk and branches of Stars are alive with thousands of lights fading in and out, travelling up and down, casting the area in a peaceful glow.");
     set_exits(([
  "north" : ELFROOM"summer5.c",
  "east" : ELFROOM"weaponshop.c",
  "southeast" : ELFROOM"stars5.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
