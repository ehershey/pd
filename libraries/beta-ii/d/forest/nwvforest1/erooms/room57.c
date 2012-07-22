#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "southwest" : EROOMS"room56",
                "east" : "/d/nopk/forest/forest50",
  ]) );
}