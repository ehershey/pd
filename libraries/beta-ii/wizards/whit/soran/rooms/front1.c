#include <std.h>
#include <soran.h>
inherit ROOM;

void create() {
    ::create(); 

    set_short("front lawns");
    set_long("The paths are made of a smooth stone.  "
      "The distance sound of running water can be heard "
      "from here.  The palace can be seen in broad "
      "view.  It stands ten stories high into the sky.");
    set_listen( "default","Sounds of joy and laughter "
      "come from inside the palace.");
    set_property("indoors",0);
    set_property("light",2);
    set_property("night light",3);
    set_exits(([
	"north": 	ROOMS "entrance.c",
	"east": 	ROOMS "front4.c",
	"south": 	ROOMS "bridge.c",
	"west": 	ROOMS "front2.c",
      ]));
}

