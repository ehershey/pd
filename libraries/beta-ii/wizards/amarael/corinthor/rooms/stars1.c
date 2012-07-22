//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The tree of Stars is quite the enchanted place. Some of the leaves are turning from their green colour, making the treetop look like a strange green sky with yellow stars. The path heads off west where this tree connects to that of Summer. The forest stretches out to the northeast.");
     set_night_long("The tree of Stars is quite the enchanted place. Even in the night it can be seen that some of the leaves are turning from their green colour. The trunk of the tree itself has hundreds of glowing points of light that move all up and down it. The lights fade in and out slowly as they move.");
     set_exits(([
  "southeast" : ELFROOM"stars2.c",
  "west" : ELFROOM"summer4.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
