#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "no teleport" : 1, "light" : 1, "no teleport" : 1, "no teleport" : 1, "night light" : 1]) );
    set_smell("default", "The tunnel has a stagnant, stale stench to it.");
    set_listen("default", "Echos near and far can be heard throughout the tunnels.");
    set_short("a dark cavern");
    set_long("A large pile of blackened bones lies in one corner of the cavern. "
      "The floor is very flat in the center of this open area, but around "
      "the perimeter there are jagged rocks everywhere. Small glowing stones "
      "in the walls emit a bit of light.");
    set_items(([
	"dark" : "Although you can't see it, the darkness is very dark.",
	"dirt" : "The dirt of the tunnels floats through the stagnant air.",
	"ground" : "The ground covered in rocks and dirt, and looks fairly tricky to walk through.",
	({"rock", "rocks"}) : "The rocks are jagged and large for the most part, and seem to make travel difficult.",
      ]));
    set_exits(([
	"east" : ROOMS "/darkandscary/f1",
	"west" : ROOMS "/darkandscary/f2",
	"southeast" : ROOMS "/darkandscary/f3",
	"southwest" : ROOMS "/darkandscary/f4",
	"north" : ROOMS "/darkandscary/30.c",]));
    set_no_clean(1);
}

void reset() {
    ::reset();
    /*
  if (!present("cage") && !query_property("finished_quest")) {
  new(ITEMS+"cage")->move(this_object());
  }
  */
}

