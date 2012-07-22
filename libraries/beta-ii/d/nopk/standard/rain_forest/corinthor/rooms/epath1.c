//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "night light": 1, "indoors" : 1 ]));
     set_short("Corinthor");
     set_day_long("This passage through Orn'Atar leads between the market of Corinthor and the eastern branches of the town. The walls and ceiling have been carefully carved from the tree and are a great work of art. The market is just a little further to the west. Sunlight can been seen far to the east.");
     set_night_long("This passage through Orn'Atar leads between the market of Corinthor and the eastern branches of the town. The walls and ceiling have been carefully carved from the tree and are a great work of art. The market is just a little further to the west.");
     set_exits(([
  "west" : ELFROOM"square.c",
  "east" : ELFROOM"epath2.c",
                ]));
}
