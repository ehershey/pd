#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "northwest" : WROOMS"room11", 
                "northeast" : WROOMS"room12",
                "south" : WROOMS"room7",
  ]) );
}