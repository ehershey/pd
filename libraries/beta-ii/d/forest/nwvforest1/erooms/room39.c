#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "northwest" : EROOMS"room43",
                "south" : EROOMS"room35",
  ]) );
}
