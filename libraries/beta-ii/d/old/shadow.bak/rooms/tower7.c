inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("outdoors",0);
  set_property("light",0);
  set("short","Palace Wall");
  set("long","This is one of the turrets along the outer wall of the palace. "
    " The land surrounding the city can be seen from this height.  The wind"
    " whirls about up here.  The turret has exits to the west and north.");
  set_smell("default","The air here is clear and refreshing.");
  set_listen("default","The soft sound of people talking can be heard below.");
  set_items((["sky":"The sky is dark as ever.",
    "turret":"The turret is where the archers hang out and protect the citizens of Tenebrae."]));
  set_exits((["north":ROOMS "tower6.c","west":ROOMS "tower8.c"]));
}

void reset() {
  ::reset();
  if(!present("archer")) {
    new(MOB "archer")->move(this_object());
  }
}
