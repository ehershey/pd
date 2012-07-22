inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","Palace");
  set("long","The second floor here seems cramped compared to the immense "
    "first floor, although it is still quite spacious.  A red carpet leads "
    "north along the hallway which is lined with small tables and pillars with "
    "curious objects on them.  The hallway is well kept, but seemingly unused.");
  set_smell("default","There is a fresh breeze in this part of the palace.");
  set_listen("default","It is fairly quiet here.");
  set_items(([({"table","pillar"}):"They come up to your waist and have strange objects on them.",
    "wall":"The wall is quite plain here on the second floor.",
    "objects":"They must be family heirlooms and gifts from foreign countries.",
    "stairs":"They lead down to the ground floor.",
    "carpet":"The %^RED%^crimson carpet%^RESET%^ leads north."]));
  set_exits((["north":ROOMS "palace23.c","down":ROOMS "palace11.c"]));
}
