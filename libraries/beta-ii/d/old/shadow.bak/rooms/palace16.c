inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the northern wing of the castle.  The wedding "
    "decorations line the wall, but are a little less to the west.  "
    "The west hall seems to be unoccupied, and fairly unused.  "
    "The main hall is to the north.");
  set_smell("default","The smell of a great feast wafts towards you.");
  set_listen("default","The sound of people talking and making merry can be heard.");
  set_items(([({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls.",
    "wall":"The wall is lined with various pictures of royalty and armour displays."]));
  set_exits((["north":ROOMS "palace15.c","west":ROOMS "palace10.c","east":ROOMS "palace19.c"]));
}

void reset() {
  ::reset();
  if(!present("servant")) {
    new(MOB "fservant")->move(this_object());
  }
  if(!present("bridesmaid")) {
    new(MOB "bridesmaid")->move(this_object());
  }
}
