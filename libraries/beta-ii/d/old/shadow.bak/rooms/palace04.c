inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the southern wing of the castle.  The wedding "
    "decorations are a bit more sparse here, but it is still well kept.  "
    "The main hall can be seen to the north, while the wing bends eastward.  "
    "This hallway seems fairly unused, with the exception of the single guard.");
  set_smell("default","The smell of a great feast wafts towards you.");
  set_listen("default","The sound of people talking and making merry can be heard.");
  set_items(([({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls.",
    "wall":"The wall is lined with various pictures and armour displays."]));
  set_exits((["east":ROOMS "palace09.c","north":ROOMS "palace03.c"]));
}

void reset() {
  ::reset();
  if(!present("guard")) {
    new(MOB "pguard")->move(this_object());
  }
}
