inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",0);
  set("short","Palace Wall");
  set("long","The wall of the Palace forms a large box around the city. "
    " The land surrounding the city can be seen from this height.  The wind"
    " whirls about up here.  The wall leads to the north and south.  A large"
    " shelter is to the east on this section of the wall.  It appears to be"
    " a headquarters for the archers.");
  set_smell("default","The air here is clear and refreshing.");
  set_listen("default","The soft sound of people talking can be heard below.");
  set_items((["sky":"The sky is dark as ever.",
    "turret":"The turret is where the archers hang out and protect the citizens of Tenebrae.",
    "wall":"The wall surrounds the city and connects the turrets",
    "shelter":"The shelter looks nice and warm"]));
  set_exits((["north":ROOMS "tower5.c","south":ROOMS "tower7.c","enter":ROOMS "tower9.c"]));
}
