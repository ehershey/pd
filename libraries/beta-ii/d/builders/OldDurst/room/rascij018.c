#include <std.h>
#include <durst.h>
inherit ROOM;
void create() {
   ::create();
	set_name("Rascij");
	set_short("Small Camp");
	set_properties(([
        "light"       : 2,        
        "night light" : 1,
        ]));
	set_day_long("To the north is a small clearing in the forest. It looks like there are some small tents that have been set up there. The forest is very dense, it makes it very hard to see very far in any direction. Small animals can be seen in every direction doing thier daily tasks.");
	set_night_long("Darkness is everywhere, the only thing that can be seen is a small flickering light to the north. Not even the ground can be seen in this blackness.");
	set_exits( ([
	"south"  : ROOMS"rascij019.c",
	"north" : ROOMS"rascij012.c",
	
	]) );
	add_pre_exit_function("south", "go_south");
}
int go_south() {
  if(!this_player()->is_player()) return 0;
  return 1;
}
