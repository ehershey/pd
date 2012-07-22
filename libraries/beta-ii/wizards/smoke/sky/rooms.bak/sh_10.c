#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 1, "mountains" : 1, "town" : 1]) );
  set_short("Platinum Street - Steel Hammer Village");
  set_long(
   "Platinum Street continues east and west. An intersection "
   "with Gold Street is just to the west of here. Steps "
   "lead up to a monastery on the north side of the road "
   "and there is a large jail on the south side. Lots of "
   "small houses can be seen closer to the enterance of "
   "the village. Dwarves can be seen hustling around "
   "doing whatever it is that they do. Large mountains "
   "totally surround the village.");
  set_items(([
    "mountains" : "The mountains stretch in all directions. They "
    "surround the small village. ",
    "gates" : "There are big, iron gates leading into the mountains.",
    "houses" : "Small stone buildings that have been carved from the "
    "mountains lie ahead to the west. They're all in different "
    "shapes and sizes, but they are all pretty small.",
    "road" : "A very interesting design. The road is stone, carved "
    "from the mountain, and into various designs. The designs "
    "are very artistic and beautiful.",
    "path" : "The path leads west through the mountains. ",
    "dwarves" : "Lots of small dwarves are running through "
    "the village.",
    "steps" : "Lots of steps lead up to an enormous monastery.",
    "monastery" : "This building is huge! It's covered in stone "
    "artwork that must have taken forever to carve. It lies "
    "on the north side of the road.",
    "jail" : "On the southern side of the road is a jail. Bars "
    "cover the small windows, helping to prevent any "
    "escape from a prisoner."
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "The solf rumble of the village drones the air.");
  set_exits( ([ 
    "west" :  ROOMS "sh_9",
    "north" : ROOMS "mon1",
    "enter jail" : ROOMS "jail1",
    "east" :  ROOMS "sh_11"]));
}
void reset() {
  ::reset();
  if(!present("child")) new(MOB"dwarfboy1.c")->move(this_object());
}
