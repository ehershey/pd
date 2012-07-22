// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
    ::create();
    set_name("A long path");
    set_long("The path ends abruptly and can be traveled no "
      "further.  Several acorns lay about the ground.  A tree stands "
      "to the south.  The tree has been carved with several markings "
      "of unknown origin.  Wood chips lay about the ground from when "
      "the tree was carved.");
    set_properties(([ "light" : 0, "night light" : 0, "forest" : 1 ]));
    set_items(([

	"path" : "Several footprints of small animals cover the path.",
	(({ "wood chips", "chips" })) : "They have been carved from the tree.",
	"tree" : "The tree is old.  Several markings have been scratched into it.",
      ]));

    set_exits(([

	"northeast" : ROOM2"17.c",
      ]));
}
