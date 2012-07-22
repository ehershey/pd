inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the northern wing of the castle.  The wedding "
    "decorations line the wall, but abruptly end to the west.  "
    "The west hall is dark and unfriendly, while east and south are well "
    "decorated and friendly.  The main hall is to the south.");
  set_smell("default","The smell of a great feast wafts towards you.");
  set_listen("default","The sound of people talking and making merry can be heard.");
  set_items(([({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls.",
    "wall":"The wall is lined with various pictures of royalty and armour displays."]));
  set_exits((["south":ROOMS "palace13.c","west":ROOMS "palace06.c","east":ROOMS "palace17.c"]));
}

void reset() {
  ::reset();
  if(!present("servant")) {
    new(MOB "mservant")->move(this_object());
  }
}
