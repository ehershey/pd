//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "night light": 1, "indoors" : 1 ]));
     set_short("Corinthor");
     set_day_long("This is the eastern entrance to Orn'Atar, the 'father tree' of Corinthor. The floor of the hollowed out passage is perfectly smooth after centuries of use, and continues west, moving deeper into the tree, or east, leading back to the outside world. Small amounts of daylight seep in from outside.");
     set_night_long("This is the eastern entrance to Orn'Atar, the 'father tree' of Corinthor. The floor of the hollowed out passage is perfectly smooth after centuries of use, and continues west, moving deeper into the tree, or east, leading back to the outside world.");
     set_exits(([
  "west" : ELFROOM"epath1.c",
  "east" : ELFROOM"stars5.c",
                ]));
}
