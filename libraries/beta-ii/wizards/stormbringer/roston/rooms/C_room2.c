#include <roston.h>
#include <std.h>
inherit ROOM;
void create() {
::create();
    set_short("a huge cave");
    set_long("You are continuing down the rocky path through "
            "the cave. Stalagtites hang from the cieling. You have a "
            "strange feeling that you are being watched. The cave "
            "walls are covered completely with cobwebs and dust. "
            "The granite walls and ground make this area pretty "
            "cold.");
    set_items(([
        "walls" : "The walls are covered with cobwebs and dust.",
        "ground" : "The ground is a hard grante floor that "
	           "that seems to be covered with dust."]));
   set_property("light", 1);
 set_exits(([
     "north" : ROOMS"C_room1.c",
     "south" : ROOMS"C_room5.c"
      ]));
}
