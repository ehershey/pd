//Valleyman

#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
  room::create();

  set_properties( ([ "light" : 2, "night light" : 1, "indoors" : 1, ]) );
  set_short("Farmhouse");
  set_day_long("A dark hallway, even during the daytime, it leads to the single bedroom east, and the kitchen to the west. Pictures hang along the walls and there is a trapdoor in the roof for access to the attic. It is cool in this part of the house as there are no windows.");
  set_night_long("The hallway is slightly illuminated from the ovens in the kitchen to the west. There is a bedroom to the east and a trapdoor above for access to the attic. It is very dark in here as no moonlight reaches here as there are no windows.");

  set_items( ([
    "pictures" : "Pictures of family members and the husband and wife",
    ({"door", "trapdoor", "roof"}) : "The door is the same colour as the roof and very hard to see. There is a small ladder hanging from the roof.",
    "ladder" : "The ladder is used for getting into and out of the attic.",
   ]));

  set_exits(([
    "west" : ROOMS"house2.c",
    "enter" : ROOMS"bedroom.c",
    "up" : ROOMS"attic.c",
   ]));

}
