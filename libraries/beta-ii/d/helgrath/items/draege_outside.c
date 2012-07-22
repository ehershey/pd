#include <std.h>
#include <helgrath.h>

inherit VAULT;

void create() {
    ::create();
    set_property("light", 1);
    set_short("Helgrath Woods");
    set_long("At the bottom of a steep, jagged rock embankment, a massive iron-bound oak "
      "door, framed by dark, stone walls of the cave entrance comes into view directly to the north. "
      "A large, twisted tree hangs precariously from its perch atop the rock walls of the cave.");
    set_exits ( (["north" : ROOMS "draege_entrance.c",
      "east" : ROOMS "forest_lake_w01.c"]) );
    set_door("door", ROOMS "draege_entrance.c", "north", "dkey");
    set_locked("door", 1);
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "a faint humming noise emenates from the cavern walls." );
}
void reset() {
    if(this_player()->query_exit("north"))
	set_open("door", 0);
    set_locked("door", 1); 
}
