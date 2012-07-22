inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the northern wing of the castle.  The walls here are "
    "cold, undecorated stone.  The fancy candles that adorned previous rooms "
    "have been replaced by crude torches.  The floor seems to slope downward "
    "to the north.  There seems to be some bustling about to the east, while the "
    "north is dark and ominous.");
  set_smell("default","The smell of something rotting seeps in from the north.");
  set_listen("default","The sound of servants running about echos in from the east.");
  set_items(([({"decorations","wedding decorations"}):"The decorations here are completely gone.",
    "wall":"The exposed stone is bare and cold.",
    "torches":"The torch flickers against the wall."]));
  set_exits((["south":ROOMS "palace07.c","north":ROOMS "palace05.c","east":ROOMS "palace12.c"]));
}
