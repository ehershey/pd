//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This is the closest part of Earth to Orn'Atar, the giant trunk of that tree just several feet away. The platform leading around this tree is made of solid planks of wood placed between strong branches, all amazingly at the same height.");
     set_night_long("This is the closest part of Earth to Orn'Atar, the giant trunk of that tree just several feet away. The platform leading around this tree is made of solid planks of wood placed between strong branches, all amazingly at the same height.");
     set_exits(([
  "south" : ELFROOM"winter5.c",
  "northwest" : ELFROOM"earth5.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
