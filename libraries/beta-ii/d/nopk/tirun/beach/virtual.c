#include <std.h>
#include <tirunbeach.h>

inherit VIRTUALMAP;

void create() {
  set_mapfile(TIRUNBEACH+"map");
  set_descfile(TIRUNBEACH+"descs");
  set_compact(1);
  ::create();

set_virtual_room("1,1,0-6,1,0", TIRUNBEACH+"fishingroom");
set_virtual_room("7,1,0-7,6,0", TIRUNBEACH+"fishingroom");
set_special_exits("0,0,0", ([ "up" : "/d/nopk/tirun/pier" ]) );
set_special_exits("1,1,0", ([ "south":"/d/waterworld/level1/rooms/room-1a1" ]) );
set_special_exits("2,1,0", ([ "south":"/d/waterworld/level1/rooms/room-1b1" ]) );
set_special_exits("3,1,0", ([ "south":"/d/waterworld/level1/rooms/room-1c1" ]) );
set_special_exits("4,1,0", ([ "south":"/d/waterworld/level1/rooms/room-1e1" ]) );
set_special_exits("5,1,0", ([ "south":"/d/waterworld/level1/rooms/room-1f1" ]) );
set_special_exits("6,1,0", ([ "south":"/d/waterworld/level1/rooms/room-1g1" ]) );
set_special_exits("7,2,0", ([ "west":"/d/waterworld/level1/rooms/room-1g1" ]) );
set_special_exits("7,3,0", ([ "west":"/d/waterworld/level1/rooms/room-1g2" ]) );
set_special_exits("7,4,0", ([ "west":"/d/waterworld/level1/rooms/room-1g3" ]) );
set_special_exits("7,5,0", ([ "west":"/d/waterworld/level1/rooms/room-1g4" ]) );
set_special_exits("7,6,0", ([ "west":"/d/waterworld/level1/rooms/room-1g5" ]) );
set_special_exits("9,4,0", ([ "east":"/d/nopk/arlon_path/0,0,0" ]) );
}
