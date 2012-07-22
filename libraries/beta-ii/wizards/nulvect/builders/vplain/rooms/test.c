#include <std.h>
#include <vplain.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_day_long(get_object(VFSERVER)->get_day_long()+
    " A river flows along to the east and north.");
  set_night_long(get_object(VFSERVER)->get_night_long()+
    " A river flows along to the east and north.");
  set_items(get_object(VFSERVER)->get_items()+
    (["river" : "The river looks kind of shallow to the east, it might be possible to wade through.",
      "east" : "The back of a house can be seen across the river.",
      "north" : "Many trees and an occaisonal glimpse of the river."]));
  set_listen("default","Water flowing.");
  set_exits(([
    "south" : VPROOMS "f8_9",
    "west" : VPROOMS "f7_8",
    "wade" : VPROOMS "town9_8"
  ]));
  add_invis_exit("wade");  
}
