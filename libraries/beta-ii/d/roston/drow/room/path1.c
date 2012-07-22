#include <std.h>
#include <roston.h>
inherit ROOM;

void create() {
  ::create();
set_name("Drow Camp");
set_items((["snow"   : "A deep white snow",
            "dirt"  : "A dark brown mixture"]));
set_properties((["light":2, "night light":3]));
set_short("camp");
set_long("The area is dark and cluttered with various sized rocks and "
         "boulders. The ground is uneven in places and several large "
         "holes are scattered about. A large camp dominates the northern "
         "area of the cave.");

set_exits( ([ "north" : DROWROOM"room1",
              "dig" : "/d/zolenia/rooms/1.c",
              "south" : ROOMS "roston35"]));
}                                                         
