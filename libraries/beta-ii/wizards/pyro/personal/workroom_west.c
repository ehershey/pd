#include <std.h>

inherit ROOM;

void create() {
    ::create();

    set("short", "Room");
   set("long", "Sample 10\n");

    set_exits(([
       "east" : "/wizards/pyro/personal/workroom_main",
    ]));
}
