#include <std.h>

#include <caves.h>

inherit ROOM;

void create() {
::create();
    set_short("Bone pile");
    set_day_long("Bones ... rats and other vermin scurry around this huge bone pile. From Dragon skulls to dead bodies of a 
deer this does seem to be very unwelcoming place.\n");
    set_night_long("Many glowing red eyes of small rats and other vermin can be seen moving around. The shadows around here 
seem even more darker then what it was back on the old path.\n");
    set_properties(([
	"light" : 1,
	"night light" : 0,
    ]));
    set_exits(([
	"north" : ROOMS "room6.c",
	"west" : ROOMS "room4.c",
	"northwest" : ROOMS "room7.c",
    ]));
    set_smell("default", "The smell of the rotting animals hangs around.");
    set_listen("default", "The sound of bones clanking ring in your ears.");
}

void reset() {
    if(!present("rats"))
	new(MONSTERS"rats.c") ->move(this_object());
	new(MONSTERS"rats.c") ->move(this_object());
	new(MONSTERS"rats.c") ->move(this_object());
}
