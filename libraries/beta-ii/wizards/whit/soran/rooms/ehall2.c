#include <std.h>
#include <soran.h>
inherit ROOM;

void create() {
    ::create(); 

    set_short("");
    set_long("The inside of the palace was as beautiful "
      "as that on the outside.  Huge tapestries "
      "depicting heroic battles hang from the 2 "
      "story high room.  Balconies stretch around "
      "the top of the room.  A large circle of roof "
      "is made from glass allowing light to enter.  "
      "Green carpets cover the halls floor.  Two grand "
      "staircases lead up the east and west side of the "
      "hall.");
    set_property("indoors",0);
    set_property("light",2);
    set_property("night light",3);
    set_exits(([
	"south": 	ROOMS "ehall1.c",
      ]));
}

void reset() {
    ::reset();
    if (!present("noble")) {
	new(MON "noble.c")->move(this_object());
	new(MON "noble.c")->move(this_object());
    }
}


