#include <std.h>
#include <vplain.h>

inherit VIRTUALROOM;

void create() {
  set_server(VPSERVER);
  ::create();

  set_day_long(get_object(VPSERVER)->get_day_long()+"Cheese.");
  set_night_long(get_object(VPSERVER)->get_night_long()+"Blarf.");
  set_exits(([
    "south" : VPROOMS "p1_2",
    "southeast" : VPROOMS "p2_2"
  ]));
}
