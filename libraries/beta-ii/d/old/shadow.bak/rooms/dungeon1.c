#include <std.h>;
#include <shadow.h>;
inherit VAULT;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",0);
  set("short","Dungeon");
  set("long","There is only one word to describe the dungeon here.  Creepy.  "
    "Spiders, rats, and other rodents scurry away at the sound of your entrance.  "
    "A mysterious green ooze seeps from the cracks in the stone walls.  The floor "
    "is wet, and probably contributes the the rotting stench that permeates the air.");
  set_smell("default","The foul fumes singe your nose hairs.");
  set_listen("default","Sounds of scurrying rodents echo against the walls.");
  set_items(([({"spiders","rats","rodents"}):"They're too fast for you to get a good look at them.",
    "wall":"The exposed stone is bare and cold.",
    "torches":"The torch flickers against the wall.",
    "ooze":"The pudrid, %^BOLD%^%^GREEN%^green%^RESET%^ ooze is quite disgusting.",
    "floor":"The floor is wet and slippery."]));
  set_door("door", ROOMS "palace05.c", "out", "dungeon key");
  set_exits((["east":ROOMS "dungeon2.c","out":ROOMS "palace05.c"]));
}
