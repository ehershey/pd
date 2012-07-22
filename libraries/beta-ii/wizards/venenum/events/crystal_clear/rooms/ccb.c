#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("A dead end");
    set_long("This short passage ends here, although it is not without detail. Evidence of a terrible battle is here- three halfling warriors lay in the corner here, cold and dead. However, at their feet are two dead Dark-elven warriors, their wounds matching the shape of the halfling's short swords.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is a little musty.");
    set_items(([
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"cc23.c",
      ]));
}

void reset()

{

    if (!present("body")) {
	new(ITEM"dead_halfling.c")->move(this_object());
	new(ITEM"dead_halfling.c")->move(this_object());
	new(ITEM"dead_drow_key.c")->move(this_object());
	new(ITEM"dead_drow.c")->move(this_object());
	new(ITEM"dead_drow.c")->move(this_object());

    }
}
