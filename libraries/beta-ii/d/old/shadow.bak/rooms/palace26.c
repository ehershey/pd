inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","The hallway dead ends right here.  There is nothing but brick "
    "wall to the east, west and north.  The only option is to head back.");
  set_smell("default","There is a fresh breeze in this part of the palace.");
  set_listen("default","The sound of footsteps can be heard from above.");
  set_items((["wall":"The wall is quite plain here on the second floor."]));
  set_exits((["south":ROOMS "palace25.c"]));
}
