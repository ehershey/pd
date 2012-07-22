#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Market Road");
    set_long("Near the edge of the inner city, this area is thoroughly less traversed. "
      "The few pedestrians in the area hurry about their tasks with hardened determination, "
      "one eye always searching the deeply shadowed alleys and nearby passageways. " );
    set_exits( ([ "west" : ROOMS "marketrd_e04.c",
      "east" : ROOMS "marketrd_egate.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "a slight breeze is barely audible over the sounds of nearby labor.");

}
