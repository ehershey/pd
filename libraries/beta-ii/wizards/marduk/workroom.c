#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("lost in a penthouse");
    set_day_long("This is the fabled home of your god Marduk. "
		"It is identical to the Playboy Mansion.  Pictures of "
		"naked chicks line the walls. He even has a few naked "
		"female servant's wandering around somewhere...");
    set_night_long("This is the fabled home of your god Marduk. "
		"It is identical to the Playboy Mansion.  Pictures of "
		"naked chicks line the walls. He even has a few naked "
		"female servant's wandering around somewhere...");
    set_items(([
	"pictures" : "This is a picture of breasts. (.) (.)",
	"servant" : "She is tall sexy and blond, she waits for your command.",
	"walls" : "The walls are covered with porn.",
    ]));
    set_properties(([
	"light" : 2,
	"night light" : 2,
    ]));
    set_exits(([
	"out" : "/d/standard/square.c",
    ]));
}
void reset() {
    if(!present("elf"))
	new("/wizards/marduk/slave.c")->move(this_object());
}
