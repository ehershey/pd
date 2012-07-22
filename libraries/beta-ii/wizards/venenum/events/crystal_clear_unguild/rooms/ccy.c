#include <std.h>
#include <cc2.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("In a vast cave");
    set_long("This vast, perfect sphere is almost like a bubble of air within stone. A bloody, but quick, battle was waged here only seconds ago- the bodies of the drow elves are splayed out across the stone, with absolutely no explaination as to how they died.");
    set_listen("default", "There is absolutely no here.");
    set_smell("default", "The air is remarkably clear.");
    set_items(([
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));

    set_exits(([
	"portal" : ROOMS"ccp.c",
      ]));
}

void reset()

{
    if (!present("body")) {
	new(ITEM"dead_drow_shard.c")->move(this_object());
	new(ITEM"dead_drow.c")->move(this_object());
	new(ITEM"dead_drow.c")->move(this_object());
	new(ITEM"dead_drow.c")->move(this_object());
	new(ITEM"dead_drow.c")->move(this_object());
	new(ITEM"dead_drow.c")->move(this_object());
	new(ITEM"dead_drow.c")->move(this_object());
    }
}
