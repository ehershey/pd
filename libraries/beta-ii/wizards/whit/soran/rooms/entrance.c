#include <std.h>
#include <soran.h>
inherit ROOM;

void create() {
    ::create(); 

    set_short("Entrance to Soran");
    set_long("The entrance to the palace lies to the north.  "
      "Large, brass hinged doors stand as the barrier from "
      "the outside world and that of which is inside.  The "
      "paths continue on around winding through the trees.");
    set_property("indoors",0);
    set_property("light",2);
    set_property("night light",3);
    set_exits(([
	"north": 	ROOMS "ehall1.c",
	"east": 	ROOMS "front5.c",
	"south": 	ROOMS "front1.c",
	"west": 	ROOMS "front3.c",
      ]));
    set_pre_exit_functions( ({"north"}), ({"go_north"}) );
}

void reset() {
    ::reset();
    if (!present("guard")) {
	new(MON "palaceguard.c")->move(this_object());
	new(MON "palaceguard.c")->move(this_object());
    }
}

int go_north() {
    if(present("guard")) {
	if(this_player()->query_alignment() > 250) {
	    present("guard")->force_me("say Your passage has been granted.");
	    return 1;
	}
	present("guard")->force_me("say You may not pass!");
	return 0;
    }
    return 1;
}

