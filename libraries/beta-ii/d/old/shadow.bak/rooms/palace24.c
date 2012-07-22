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
    "back to the north along the hallway which is still lined with small tables and pillars with "
    "curious objects on them.  The hallway is well kept, but seemingly unused."
    "  The stairs back down are to the west.");
  set_smell("default","There is a fresh breeze in this part of the palace.");
  set_listen("default","It is fairly quiet here.");
  set_items(([({"table","pillar"}):"They come up to your waist and have strange objects on them.",
    "wall":"The wall is quite plain here on the second floor.",
    "objects":"They must be family heirlooms and gifts from foreign countries.",
    "carpet":"The %^RED%^crimson carpet%^RESET%^ covers the ground."]));
  set_exits((["north":ROOMS "palace25.c","west":ROOMS "palace23.c"]));
}
