#define PAINT "/d/paintball/"
#include <std.h>
inherit ROOM;
void find_short();
void find_exits();
static int dig1, dig2, nx;

void create() {
 ::create();
/*   set_short("(0,0)"); */
   find_short();
   set_long("%^BOLD%^%^GREEN%^You are at coordinates: ("+nx+","+dig2+")\n"
       "%^BLACK%^You are on top of a giant "
       "grid or matrix of some sort. The lines that make up the grid "
       "are green and the ground they are on is black. The grid continues "
       "almost as far as you can see in every direction.");
   set_items(([ "grid" : "It is the paintball warfare arena." ]));
/*   set_exits(([
      "south": PAINT"0,-1",	// x    ,   down
      "north": PAINT"0,1",	// x    ,   up
      "east" : PAINT"1,0",	// up   ,   x
      "west" : PAINT"n1,0"	// down	,   x
   ])); */
   find_exits();
}

void find_short() {
   string fname;
   fname = file_name(this_object());
   if (sscanf(fname, "/d/paintball/n%d,%d", nx, dig2)==2) {
      nx = nx * -1;
   } else {
   if (sscanf(fname, "/d/paintball/%d,%d", dig1, dig2))
      nx = dig1;
   }
   set_short("("+nx+","+dig2+")");
}

void find_exits() {
   int xd, xu, yd, yu, x, i;
   string str, south, west, east, north;
   xd = dig1 - 1;
   xu = dig1 + 1;
   yd = dig2 - 1;
   yu = dig2 + 1;
   if (xd < 0) {
      str = (string)xd;
      sscanf(str, "-%d", xd);
      west = "n"+(string)xd+","+(string)dig2;
   } else west = (string)xd+","+(string)dig2;
   if (xu < 0) {
      str = (string)xu;
      sscanf(str, "-%d", xu);
      east = "n"+(string)xu+","+(string)dig2;
   } else east = (string)xu+","+(string)dig2;
   if (dig1 < 0) {
      str = (string)dig1;
      sscanf(str, "-%d", i);
      north = "n"+(string)i+","+(string)yu;
   } else north = (string)dig1+","+(string)yu;
   if (dig1 < 0) {
      str = (string)dig1;
      sscanf(str, "-%d", x);
      south = "n"+(string)x+","+(string)yd;
   } else south = (string)dig1+","+(string)yd;
   set_exits(([
      "south": PAINT+south,     // x    ,   down
      "north": PAINT+north,      // x    ,   up
      "east" : PAINT+east,      // up   ,   x
      "west" : PAINT+west      // down ,   x
   ]));
}
