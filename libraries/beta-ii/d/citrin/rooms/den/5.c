//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("a cave");
    set_short("a cave");
    set_long("Darkness seems to be everywhere.  The ground is covered "
      "with a green mold from the dampness of the cave.  The "
      "walls of the cave are damp.  Water drips constantly "
      "from the ceiling.");
    set_items(([
      ]));
    set_exits(([
	"east":DEN"4",
	"north":DEN"6",
      ]));
    set_properties((["light":1,"night light":1,"cave":1,"indoors":1,]));
}
