#include <std.h>
inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "indoors" : 1]));
  set_short("a workroom");
  set_long("This is a default workroom.");
  set_smell("default","New car smell.");
  set_listen("default","It's pretty quiet in here.");
  set_exits(([ "square" : "/d/nopk/tirun/square" ]));
}

