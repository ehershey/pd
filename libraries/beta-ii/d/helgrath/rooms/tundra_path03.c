#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Neverending Tundra");
    set_day_long("All along the road, mounds of icy white snow shift in the wind. Large chunks "
      "of frozen rain hail down from above at random, causing small craters in the snow wherever "
      "the impact. The sun beats down intensely, but does nothing to calm the rabid bite of the arcitc "
      "wind. Vast tundra stretches off to the horizon in every direction. " );
    set_night_long("All along the road, mounds of icy white snow shift in the wind. Large chunks "
      "of frozen rain hail down from above at random, causing small craters in the snow wherever "
      "the impact. The moon reflects easily off of the frozen snow covering the ground. "
      "The numbing cold of the tundra theatens to stop blood flow. Vast tundra "
      "stretches off to the horizon in every direction. " );
    set_exits( ([ "north" : ROOMS "tundra_path02.c",
      "south" : "/d/helgrath/tundra/rooms/room1" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A fierce wind howls across the tundra.");

}
