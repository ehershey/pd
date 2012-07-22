#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "southeast" : EROOMS"room3",
                "north" : EROOMS"room7",
  ]) );
}
