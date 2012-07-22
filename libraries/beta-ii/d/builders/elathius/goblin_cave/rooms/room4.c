#include <std.h>

#include <caves.h>

inherit ROOM;

void create() {
::create();
    set_short("The cave entrace");
    set_day_long("By the looks of it you have stumbled across the entrance to a small cave it seems. On the ground you can make out many tracks from things moving in and out of the cave. A small little guard post sits just insdie the cave but with nothing guarding. There also appears to be a old encampment behind the cave.\n");
    set_night_long("A dim light can just be seen ahead of you, the source seems to be a small guard post. Just so it happens there is nothing ther guarding. The night sky is dark an apart from that light you can't see anything.\n");
    set_properties(([
	"light" : 1,
	"night light" : 0,
    ]));
    set_exits(([
	"inside" : ROOMS "cave1.c",
	"north" : ROOMS "room7.c",
	"east" : ROOMS "room5.c",
	"south" : ROOMS "room3.c",
    ]));
    set_smell("default", "The smell of the rotting animals hangs around.");
    set_listen("default", "Loud screams fill the air.");
}
