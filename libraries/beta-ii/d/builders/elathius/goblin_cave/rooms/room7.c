#include <std.h>

#include <caves.h>

inherit ROOM;

void create() {
::create();
    set_short("The rundown encampment");
    set_day_long("Foot prints cover the ground, from what it seems whoever was staying here got out in a hurry. The old fireplace sits still as it withers away in time. A cold wind blows around there area bringing a wierd yet familiar scent to the nose.\n");
    set_night_long("Hard ground just seems to be around here. You knock your foot on what seems to be an old fireplace, now nothing just black charcol.\n");
    set_properties(([
	"light" : 1,
	"night light" : 0,
    ]));
    set_exits(([
	"east" : ROOMS "room6.c",
	"southeast" : ROOMS "room5.c",
	"south" : ROOMS "room4.c",
    ]));
    set_smell("default", "The smell of death passes your nose.");
    set_listen("default", "The sound of loud screams can be heard.");
}
