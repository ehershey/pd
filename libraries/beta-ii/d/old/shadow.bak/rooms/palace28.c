inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","This hallway is quite plain and has mortar falling out of the "
    "cracks of the large blocks that form the walls.  There's a few weapons on "
    "racks that are against the wall.   The hall appears to have been used a lot"
    " in the past, but is currently in disuse.");
  set_smell("default","There is a fresh breeze in this part of the palace.");
  set_listen("default","It is fairly quiet here.");
  set_items(([({"rack","weapons"}):"The weapons are all old and rusty.  None are useful.",
    "wall":"The wall is quite plain here on the second floor."]));
  set_exits((["north":ROOMS "palace29.c","east":ROOMS "palace23.c"]));
}
