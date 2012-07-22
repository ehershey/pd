//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The sun shines brightly in the sky overhead, dancing shadows through the leaves above. On the easter side of the tree of Stars there is a msot excellent view of the forest stretching on and on, eventually being blocked by the hundreds of forest trees. Animals scurry about on the forest floor below.");
     set_night_long("At night the tree of Stars is an enchanted place. All along the tree's trunk and branches tiny points of light fade in and out, slowly moving up and down the trunk in intricate patterns. The lights give this place a peaceful glow. The stars above allow a view of the forest out to the east.");
     set_exits(([
  "south" : ELFROOM"stars3.c",
  "northwest" : ELFROOM"stars1.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
