#define PAINT "/d/paintball/"
#include <std.h>
inherit ROOM;
void find_short();
void find_exits();
static int dig1, dig2;

void create() {
 ::create();
   find_short();
   set_long("%^BOLD%^%^GREEN%^You are at coordinates: ("+dig1+","+dig2+")\n"
       "%^BLACK%^You are on top of a giant "
       "grid or matrix of some sort. The lines that make up the grid "
       "are green and the ground they are on is black. The grid continues "
       "almost as far as you can see in every direction.");
   set_items(([ "grid" : "It is the paintball warfare arena." ]));
   find_exits();
}

void find_short() {
   string fname;
   fname = file_name(this_object());
   sscanf(fname, "/d/paintball/%d,%d", dig1, dig2);
   set_short("("+dig1+","+dig2+")");
}

void find_exits() {
   int xu, yd, yu;
   string south, east, north;
//   xd = dig1 - 1;
   xu = dig1 + 1;
   yd = dig2 - 1;
   yu = dig2 + 1;
//   west = (string)xd+","+(string)dig2;
   east = (string)xu+","+(string)dig2;
   north = (string)dig1+","+(string)yu;
   south = (string)dig1+","+(string)yd;
   set_exits(([
      "south": PAINT+south,     // x    ,   down
      "north": PAINT+north,      // x    ,   up
      "east" : PAINT+east      // up   ,   x
//      "west" : PAINT+west      // down ,   x
   ]));
}
