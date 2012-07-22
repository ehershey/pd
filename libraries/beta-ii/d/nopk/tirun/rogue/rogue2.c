#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "A dank hallway");
    set("long",
        "A spiraling flight of stairs leads up to the rogue hall. "
        "This seems to be part of an old sewer system. Tunnels lead "
        "north, south, east, and west");
    set_exits( ([
                "north" : ROOMS"rogue/thug/thug_join.c",
                "up" : ROOMS"rogue_hall",
                "south" : ROOMS"rogue/assassin/assassin_join.c",
                "east" : ROOMS"rogue/scout/scout_join.c",
               "west" : ROOMS"rogue/thief/thief_join.c",
    ]) );
    set_items(
        (["stairs" : "They spiral up and down."]) );
    set_property("no castle", 1);
    set_property("no scry", 1);
    set_property("no teleport", 1);
}
