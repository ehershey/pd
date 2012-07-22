#include <std.h>

#include <caves.h>

inherit ROOM;

void create() {
::create();
    set_short("Bone pile");
    set_day_long("To the south a large bone pile can be seen and to the west a small emptied out encampment seems to be there withering away.\n");
    set_night_long("Darkness consumes this place and you really can't see anything, not even the moon itself.\n");
    set_properties(([
	"light" : 1,
	"night light" : 0,
    ]));
    set_exits(([
	"south" : ROOMS "room5.c",
	"west" : ROOMS "room7.c",
    ]));
    set_smell("default", "The smell of the rotting animals hangs around.");
    set_listen("default", "The sound of bones clanking ring in your ears.");
}
