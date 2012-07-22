//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "night light": 1, "indoors" : 1 ]));
     set_short("Corinthor");
     set_day_long("The north entrance into Orn'Atar, the 'father tree', is the closest to the Corinthian palace. The hollowed out passageway leads south deeper into the tree, or north to the northern branches and, of course, the palace. Small amounts of sunlight shine in from outside.");
     set_night_long("The north entrance into Orn'Atar, the 'father tree', is the closest to the Corinthian palace. The hollowed out passageway leads south deeper into the tree, or north to the northern branches and, of course, the palace. It is quite dark with it being night outside.");
     set_exits(([
  "south" : ELFROOM"npath1.c",
  "north" : ELFROOM"sun4.c",
                ]));
}
