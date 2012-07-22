inherit VAULT;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("indoors",1);
  set_property("light",1);
  set("short","Palace");
  set("long","This room explains why this hall is well kept, yet mostly "
    "unused.  On the east wall is a large set of double doors, engraved with intricate "
    "symbols.  The decorations abruptly end here, while the hall continues north.  "
    "The red carpet leads right up to the doors.  This room must belong to royalty.");
  set_smell("default","There is a fresh breeze in this part of the palace.");
  set_listen("default","It is fairly quiet here.");
  set_items((["wall":"The wall is quite plain here on the second floor.",
    "doors":"The immense doors have been carved with great care.",
    "decorations":"They stop abruptly after the room to the east.",
    "carpet":"The %^RED%^crimson carpet%^RESET%^ covers the ground."]));
  set_door("door", ROOMS "palace27.c", "enter", "bedroom key");
  set_open("door", 1);
  set_locked("door", 0);
  set_exits((["north":ROOMS "palace26.c","south":ROOMS "palace24.c","enter":ROOMS "palace27.c"]));
}

void reset() {
  ::reset();
  set_open("door", 1);
  set_locked("door", 0);
  "/d/shadow/rooms/palace27.c"->set_open("door", 1);
  "/d/shadow/rooms/palace27.c"->set_locked("door", 0);
}
