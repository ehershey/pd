#include <std.h>
#include <arlonpath.h>

inherit VIRTUALMAP;

void create() {
  set_mapfile(ARLONPATH+"map");
  set_descfile(ARLONPATH+"descs");
  set_compact(1);
  ::create();

set_special_exits("0,0,0", ([ "west" : "/d/nopk/tirun/beach/9,4,0" ]) );
set_special_exits("22,5,0", ([ "east" : FARM3"room/farmyard" ]) );
set_special_exits("22,30,0", ([ "south" : "/d/nopk/newarlon/rooms/roads/18" ]) );
}
