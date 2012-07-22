#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light": 2, "night light" : 1, "town" : 1]));
    set_name("Rhondale");
    set_short("Rhondale");
    set_day_long("Here, the west road of Rhondale leads out through large iron gates to the docks that serve the city. During the day traffic is pretty steady with people going in and out with loads of fish and supplies.");
    set_night_long("Here, the west road of Rhondale leads out through the large iron gates to the docks that serve the city. During the night almost no one passes through the gates, as all have finished their work for the day. The guardposts are usually manned at this hour, to monitor those passing by.");
    set_exits(([
	"east"                  : KEEPROOM"zvillage/outer0900.c",
	"gate"			: KEEPROOM"zvillage/dockroad1.c"
      ]));
}

void reset() {
    ::reset();
    if (!present("monster"))
	new(KEEPMOB"zvillage/gateguard.c")->move(this_object());
}
