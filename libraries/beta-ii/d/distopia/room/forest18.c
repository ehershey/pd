#include <std.h>
#include <hermes.h>
inherit VIRTUALROOM;
void create() {
  set_server(ROOMS"server");
  ::create();
set_exits(([
           "west" : ROOMS"forest19", 
            "southeast" :ROOMS"forest6",
            ]));
}