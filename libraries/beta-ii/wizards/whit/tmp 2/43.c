#include <std.h>
#include <event.h>
inherit ROOM;

void create() {
    ::create();
    set_name("tunnels beneath the enchanted well");
    set_long("The tunnel again seperates into 3 more tunnels "
      "all leading further back into the deep darkness "
      "of the tunnels.");
    set_short("tunnels beneath the enchanted well");
    set_exits(([ "southwest":ROOMS"50", "northwest":ROOMS"40",
	"south":ROOMS"51", "southeast":ROOMS"52",]));
}

