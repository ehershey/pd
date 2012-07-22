#define PAINT "/d/paintball/"
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("(0,10)");
   set_long("%^BOLD%^%^GREEN%^You are at coordinates: (0,10)\n"
       "%^BLACK%^You are on top of a giant "
       "grid or matrix of some sort. The lines that make up the grid "
       "are green and the ground they are on is black. The grid continues "
       "almost as far as you can see in every direction.");
   set_items(([ "grid" : "It is the paintball warfare arena." ]));
   set_exits(([
      "north": PAINT"0,11",
      "south": PAINT"0,9",	// x    ,   down
      "east" : PAINT"1,10",	// up   ,   x
   ]));
}