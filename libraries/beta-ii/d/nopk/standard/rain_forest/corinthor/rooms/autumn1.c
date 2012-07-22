//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("Golden leaves flutter down on to the path from the branches above, finally parting from the tree in preparation for a winter that never seems to come. A few of the leaves are scattered across the path and the rest must have been blown eastwards out to the open forest.");
     set_night_long("The dark shapes of leaves flutter down on to the path from the branches above, finally parting from the tree in preparation for a winter that never seems to come. A few of the leaves are scattered across the path and the rest must have been blown eastwards out to the open forest.");
     set_exits(([
  "south" : ELFROOM"autumn2.c",
  "northwest" : ELFROOM"stars4.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
