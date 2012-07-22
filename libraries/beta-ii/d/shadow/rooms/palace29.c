inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","Palace");
  set("long","This hallway is quite plain and has mortar falling out of the "
    "cracks of the large blocks that form the walls.  There's a few weapons on "
    "racks that are against the wall.   The hall appears to have been used a lot"
    " in the past, but is currently in disuse.  The hall appears to be darker to"
    " the north.");
  set_smell("default","There is a fresh breeze in this part of the palace.");
  set_listen("default","A gust of cool air enters from the north.");
  set_items(([({"rack","weapons"}):"The weapons are all old and rusty.  None are useful.",
    "wall":"The wall is quite plain here on the second floor."]));
  set_exits((["north":ROOMS "palace30.c","south":ROOMS "palace28.c"]));
}
