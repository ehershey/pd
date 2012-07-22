inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",0);
  set_property("light",1);
  set("short","Palace");
  set("long","The second floor here seems cramped compared to the immense "
    "first floor, although it is still quite spacious.  A red carpet turns "
    "to the east along the hallway which is lined with small tables and pillars with "
    "curious objects on them.  The hallway is well kept, but seemingly unused."
    "  To the west, the hall is quite barren and lacking any decoration.");
  set_smell("default","There is a fresh breeze in this part of the palace.");
  set_listen("default","It is fairly quiet here.");
  set_items(([({"table","pillar"}):"They come up to your waist and have strange objects on them.",
    "wall":"The wall is quite plain here on the second floor.",
    "objects":"They must be family heirlooms and gifts from foreign countries.",
    "carpet":"The %^RED%^crimson carpet%^RESET%^ leads eastward."]));
  set_exits((["south":ROOMS "palace22.c","west":ROOMS "palace28.c","east":ROOMS "palace24.c"]));
}
