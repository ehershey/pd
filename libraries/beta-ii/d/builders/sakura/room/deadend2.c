#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The cavern twists and winds, then opens up into a dead end. A large and ornately decorated chest sits in plain sight at the very end of this passage of tunnel, with no apparent locking mechanism. This area is almost completely white limestone except for the floor, which has a large stain of blood around the area where the chest sits.");
    set_smell("default", "The air here is somewhat fresher then further back along the tunnel.");
    set_listen("default", "All is quiet here.");

    set_items(([
	({"stain", "blood", "bloodstain"}) : "This bloodstain is very old but looks to have been refreshed several times, making a permenent stain on the previously white limestone.",
      ]));
    set_properties(([
	"light" : -2,
	"night light" : -3,
      ]));
    set_exits(([
	"south" : ROOMS"deadend1.c",
      ]));
}

void reset() {
    if(!present("chest"))

	set_long("The cavern twists and winds, then opens up into a dead end. A large and ornately decorated chest sits in plain sight at the very end of this passage of tunnel, with no apparent locking mechanism. This area is almost completely white limestone except for the floor, which has a large stain of blood around the area where the chest sits.");
    set_smell("default", "The air here is somewhat fresher then further back along the tunnel.");

    new(OBJ"chest.c")->move(this_object());
}


