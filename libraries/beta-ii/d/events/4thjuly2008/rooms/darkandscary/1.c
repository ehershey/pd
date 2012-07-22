#include <std.h>
#include <id4.h>
inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "no teleport" : 1, "light" : 0, "night light" : 0]) );
    set_smell("default", "The tunnel has a stagnant, stale stench to it.");
    set_listen("default", "Echos near and far can be heard throughout the tunnels.");
    set_short("venturing through tunnels");
    set_long("The dark tunnels steer in many directions, hopelessly leading to nowhere. The air is composed of a sickening mixture of humid and stale. A dark rock falls from the ceiling, causing a thump that carries throughout the tunnels. A pile of bones rests lazily between two jagged rocks. The ground is covered in jagged stones of different sizes, scattered randomly throughout the dirt.");
    set_items(([
	"dark" : "Although you can't see it, the darkness is very dark.",
	"dirt" : "The dirt of the tunnels floats through the stagnant air.",
	"ground" : "The ground covered in rocks and dirt, and looks fairly tricky to walk through.",
	({"rock", "rocks"}) : "The rocks are jagged and large for the most part, and seem to make travel difficult.",
      ]));
    set_exits(([ "west" : ROOMS "/white_entrance", "east" : ROOMS "/darkandscary/2.c",]));
}

void reset() {
    object ob;
    ::reset();
    if (!present("ogre 3")) {
	new(MOBS+"greenogre")->move(this_object());
	new(MOBS+"greenogre")->move(this_object());
	new(MOBS+"ogre")->move(this_object());
    }
    if (!present("white portal")) {
	ob = new("/d/events/4thjuly2008/items/white");
	ob->set_destination("/d/events/4thjuly2008/rooms/icystuff/final");
	ob->move(this_object());
    }
}

