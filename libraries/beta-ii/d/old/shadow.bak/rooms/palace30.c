inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",0);
  set("short","Palace");
  set("long","This hallway is quite plain and has mortar falling out of the "
    "cracks of the large blocks that form the walls.  There's a few weapons on "
    "racks that are against the wall.   The hall appears to have been used a lot"
    " in the past, but is currently in disuse.  There is a large hole that is "
    "open to the sky directly overhead.");
  set_smell("default","There is a fresh breeze in this part of the palace.");
  set_listen("default","A gust of cool air enters from the north.");
  set_items(([({"hole","ceiling"}):"The dark, overcast sky can be seen through the large hole in the ceiling.  It is out of your reach.",
    "wall":"The wall is quite plain here on the second floor."]));
  set_exits((["south":ROOMS "palace29.c"]));
}
