#include <std.h>
#include <nwvforest1.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "northeast" : EROOMS"room47",
                "southwest" : EROOMS"room40",
  ]) );
}