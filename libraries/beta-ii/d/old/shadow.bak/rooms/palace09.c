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
    "The hall heads west and south.  This hall is adorned with pictures of royalty.  "
    "This hallway seems fairly unused, with the exception of the single guard.");
  set_smell("default","The smell of a great feast wafts towards you.");
  set_listen("default","The sound of people talking and making merry can be heard.");
  set_items(([({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls.",
    "wall":"The wall is lined with various pictures and armour displays.",
    "pictures":"The pictures are all grand, and likely bigger than life."]));
  set_exits((["west":ROOMS "palace04.c","south":ROOMS "palace10.c"]));
}
