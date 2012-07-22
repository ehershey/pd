inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",0);
  set("short","Dungeon");
  set("long","The cell is small and cramped even for 2 people, let alone "
    "four.  Surprisingly though, it appears that the prisoners have adapted "
    "quite well.  They've fashioned a broom type object, and keep the cell tidy.  "
    "It seems as if they use the hall for a bathroom, which would explain the wet floor...");
  set_smell("default","The foul fumes singe your nose hairs.");
  set_listen("default","The prisoners whisper quitely amongst themselves.");
  set_items(([({"spiders","rats","rodents"}):"They're too fast for you to get a good look at them.",
    "wall":"The exposed stone is bare and cold.",
    "torches":"The torch flickers against the wall.",
    "ooze":"The pudrid, %^BOLD%^%^GREEN%^green%^RESET%^ ooze is quite disgusting.",
    "floor":"The floor is fairly dry here...",
    "broom":"Fashioned from hay and threads from their clothes, the broom is an essential part of this clean room."]));
  set_exits((["south":ROOMS "dungeon2.c"]));
}

void reset() {
  ::reset();
  if(!present("prisoner")) {
    new(MOB "prisoner")->move(this_object());
    new(MOB "prisoner")->move(this_object());
    new(MOB "prisoner")->move(this_object());
    new(MOB "prisoner")->move(this_object());
  }
}
