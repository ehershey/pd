#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "night light": 1, "indoors" : 1 ]));
     set_short("Corinthor");
     set_day_long("Here is the western entrance into the Orn'Atar, the 'father tree'. This passage has been carefully carved out of the inside of the tree, and leads east further inside. To the west the passage leads on to the outside platforms, where daylight can be seen.");
     set_night_long("Here is the western entrance into the Orn'Atar, the 'father tree'. This passage has been carefully carved out of the inside of the tree, and leads east further inside. To the west the passage leads on to the outside platforms, where it is rather dark at night.");
     set_exits(([
  "east" : ELFROOM"wpath1.c",
  "west" : ELFROOM"earth5.c",
                ]));
}
