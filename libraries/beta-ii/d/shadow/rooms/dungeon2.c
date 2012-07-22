inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",0);
  set("short","Dungeon");
  set("long","The hallway passes a cell to the north as it slowly gets smaller "
    "and more confined.  Spiders, rats, and other rodents scurry away at the sound of your entrance.  "
    "A mysterious green ooze seeps from the cracks in the stone walls.  The floor "
    "is wet, and probably contributes the the rotting stench that permeates the air.");
  set_smell("default","The foul fumes singe your nose hairs.");
  set_listen("default","The slight sound of shuffling feet can be heard to the north.");
  set_items(([({"spiders","rats","rodents"}):"They're too fast for you to get a good look at them.",
    "wall":"The exposed stone is bare and cold.",
    "torches":"The torch flickers against the wall.",
    "ooze":"The pudrid, %^BOLD%^%^GREEN%^green%^RESET%^ ooze is quite disgusting.",
    "floor":"The floor is wet and slippery."]));
  set_exits((["west":ROOMS "dungeon1.c","north":ROOMS "dungeon4.c","east":ROOMS "dungeon3.c"]));
}
