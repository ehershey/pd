#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("A dead end");
    set_long("The tunnel ends suddenly here, finishing with a perfectly square carved stone wall. The outline of a door-like rectangle are carved into the stone here and a great many symbols have been inscribed into the surface of this piece of stone. There is a strong sense of magic about but nothing appears to be activated.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is reasonably musty.");
    set_items(([
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"east" : ROOMS"ccx.c",
      ]));
}

void init() 

{
    ::init();
    add_action("zebulbai", "zebulbai");
}

int zebulbai()
{
    write("The portal springs to life with a flash of blue light.");
    add_exit(ROOMS"ccy.c","portal");
    return 1;
}
