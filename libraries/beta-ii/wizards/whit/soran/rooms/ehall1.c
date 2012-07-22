#include <std.h>
#include <soran.h>
inherit ROOM;

void create() {
    ::create(); 

    set_short("Entrance Hall to Soran");
    set_long("The inside of the palace was as beautiful as that "
      "on the outside.  Huge tapestries depicting heroic "
      "battles hang from the 2 story high room.  Balconies "
      "stretch around the top of the room.  A large circle of "
      "roof is made from glass allowing light to enter.  Green "
      "carpets cover the halls floor.");
    set_property("indoors",0);
    set_property("light",2);
    set_property("night light",3);
    set_exits(([
	"north": 	ROOMS "ehall2.c",
	"south": 	ROOMS "entrance.c",
      ]));
}

