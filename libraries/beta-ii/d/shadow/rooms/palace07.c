inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the northern wing of the castle.  The walls here are "
    "cold, undecorated stone.  The fancy candles that adorned previous rooms "
    "have been replaced by crude torches.  The floor seems to slope downward "
    "to the north.  A cheery glow emanates from the west.");
  set_smell("default","A slight odor seems to seep in from the north.");
  set_listen("default","The sound of people talking is muffled.");
  set_items(([({"decorations","wedding decorations"}):"The decorations here are completely gone.",
    "wall":"The exposed stone is bare and cold."]));
  set_exits((["west":ROOMS "palace02.c","north":ROOMS "palace06.c"]));
}
