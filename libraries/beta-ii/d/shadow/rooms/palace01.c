inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","Palace");
  set("long","The entryway of the palace is awe-inspiring.  "
    "Wedding decorations line the walls.  "
    "Marble steps lead up to the main hallway, east.  "
    "The only other exit is to the west.");
  set_smell("default","The smell of a great feast wafts towards you.");
  set_listen("default","The sound of people talking and making merry can be heard.");
  set_items(([({"steps","stairs"}):"The steps are made of fine marble, imported from distant lands.",
    ({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls and steps."]));
  set_exits((["east":ROOMS "palace03.c","west":ROOMS "tene24.c"]));
}

void reset() {
  ::reset();
  if(!present("knight")) {
    new(MOB "pknight")->move(this_object());
    new(MOB "pknight")->move(this_object()); 
  }
}
