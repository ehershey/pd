#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 1,
      "indoors" : 1
    ]));
    set_short("Cavern of the Black Sorceror");
    set_long("The air in this room is remarkably stale. Large tapestries decorate the stone walls. " );
    set_exits( ([ "south" : ROOMS "draege_entrance.c" ]));
    set_smell("default", "The smell of burnt flesh lingers in the air.");
    set_listen("default", "a faint humming noise can be heard.");

}
