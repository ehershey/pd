#include <std.h>
inherit ROOM;

void create(){
   ::create();
   set_short("%^BOLD%^%^RED%^A Strange Path");
   set_long(
      "%^BOLD%^RED%^A Strange Path\n"
   "%^BOLD%^%^BLUE%^You are still on the same path, and don't seem to be getting any closer to the end."
   "%^BOLD%^%^BLUE%^ A small hill seems to extend upwards from here.");
   set_exits(([
     "east" : "/wizards/morgoth/room/strange1.c",
     "up" : "/wizards/morgoth/room/hill1.c",
     "west" : "/wizards/morgoth/room/strange3.c",
   ]));
    }
