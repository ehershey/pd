inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","This is the northern wing of the castle.  The wedding "
    "decorations are a bit more sparse here, and the materials start to become "
    "a bit more rough.  The walls seem more cold, and the room isn't lit as well as the others.  "
    "The main hall can be seen to the south, while the wing bends eastward.  "
    "This hallway seems fairly unused, with the exception of the single guard.");
  set_smell("default","The smell of a great feast wafts towards you.");
  set_listen("default","The sound of people talking and making merry can be heard.");
  set_items(([({"decorations","wedding decorations"}):"Flowers and fine silk decorations line the walls.",
    "wall":"The wall is scantily decorated and seems cold."]));
  set_exits((["east":ROOMS "palace07.c","south":ROOMS "palace03.c"]));
}

void reset() {
  ::reset();
  if(!present("guard")) {
    new(MOB "pguard")->move(this_object());
  }
}
