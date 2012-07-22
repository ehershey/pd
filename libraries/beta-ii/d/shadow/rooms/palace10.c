inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the southern wing of the castle.  The wedding "
    "decorations are a bit more sparse here, but it is still well kept.  "
    "The hall heads west and south.  This hall is adorned with pictures of royalty.  "
    "There are some even finer decorations to the south.");
  set_smell("default","The air has an antique odor about it.");
  set_listen("default","It is fairly quiet here.");
  set_items(([({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls.",
    "wall":"The wall is lined with various pictures and armour displays.",
    "pictures":"The pictures are all grand, and likely bigger than life."]));
  set_exits((["north":ROOMS "palace09.c","south":ROOMS "palace11.c","east":ROOMS "palace16.c"]));
}
