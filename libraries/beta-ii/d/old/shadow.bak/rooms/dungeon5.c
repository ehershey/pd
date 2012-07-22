inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",0);
  set("short","Dungeon");
  set("long","This cell is terrible.  The mere sight of it would cause those "
    "with a weak stomach to vomit.  Not to mention the smell.  Filth is smeared "
    "all over the walls and hangs from the ceiling.  What kind of animal could live "
    "like this??");
  set_smell("default","The foul fumes singe your nose hairs.");
  set_listen("default","Drip, drip, drip.");
  set_items(([({"spiders","rats","rodents"}):"They're too fast for you to get a good look at them.",
    "wall":"The exposed stone is bare and cold.",
    "torches":"The torch flickers against the wall.",
    "ooze":"The pudrid, %^BOLD%^%^GREEN%^green%^RESET%^ ooze is quite disgusting.",
    "floor":"The floor is wet and slippery.",
    "filth":"Why on earth would you look at that??"]));
  set_exits((["south":ROOMS "dungeon3.c"]));
}

void reset() {
  ::reset();
  if(!present("prisoner")) {
    new(MOB "prisoner2")->move(this_object());
  }
}
