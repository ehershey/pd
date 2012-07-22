#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path through the trees");
    set_long("This section of the forest appears to have been cut through recently. The stumps are cleanly cut and the path is quite wide, suggesting either a skilled team of loggers or some magical effect was at work here. To the southwest, the entrance to a cave can be seen.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is fresh and crisp.");

    set_items(([
	({"bushes"}) : "There are an abnormal amount of bushes here.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"cc18.c",
	"southwest" : ROOMS"cc22.c",
      ]));
}

void reset()

{

    if (!present("drow")) {
	new(MOB"wounded_drow.c")->move(this_object());
    }
}
