inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("outdoors",0);
  set_property("light",0);
  set("short","Palace Wall");
  set("long","The wall of the Palace forms a large box around the city. "
    " The land surrounding the city can be seen from this height.  The wind"
    " whirls about up here.  The wall leads to the east and west.");
  set_smell("default","The air here is clear and refreshing.");
  set_listen("default","The soft sound of people talking can be heard below.");
  set_items((["sky":"The sky is dark as ever.",
    "turret":"The turret is where the archers hang out and protect the citizens of Tenebrae.",
    "wall":"The wall surrounds the city and connects the turrets"]));
  set_exits((["east":ROOMS "tower7.c","west":ROOMS "tower01.c"]));
}
