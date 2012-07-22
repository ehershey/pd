#include <std.h>

#include <caves.h>

inherit ROOM;

void create() {
::create();
    set_short("Small pathway");
    set_day_long("Along the path bones of dead animals are scatterd about. The small dark entrance seems to be getting closer with each step.\n");
    set_night_long("Not much can be seen at all really not even the moon from the night sky.\n");
    set_properties(([
	"light" : 1,
	"night light" : 0,
    ]));
    set_exits(([
	"north" : ROOMS "room3.c",
	"south" : ROOMS "room1.c",
    ]));
    set_smell("default", "The smell of the rotting animals hangs around.");
    set_listen("default", "Loud screams fill the air.");
}
