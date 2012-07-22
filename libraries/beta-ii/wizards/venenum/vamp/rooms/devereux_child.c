#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Study room");
    set_long("This room appears to be a child's bedroom, with light blue walls and the presence of several tiny beds as though for young children. Several enchantments have been placed upon the roof here, to the illusion of a galaxy of shining stars, twinkling high above the roof. The floor here consists of many polished wooden beams laid together and partially covered with a rug, the skin of a cheetah.");
    set_smell("default", "There are few smells here, apart from the faint smell of soil.");
    set_listen("default", "The house is quiet and peaceful.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_items(([
	({"roof", "enchantments"}) : "These enchantments create glowing lights seeming to emulate the effect of looking up at a dark night's sky. It seems in slow motion, slowly spinning around the room in a soothing way.",
	({"floor", "wood"}) : "The wood here is highly polished but seems to be scratched heavily, evidence of children living in this room.",
	({"rug", "cheetah"}) : "Underneath the cheetah skin is a series of small holes drilled into the ground. They are too dark to see down, although you can smell earth from down there."
      ]));
    set_exits(([
	"east" : ROOMS"devereux4.c",
      ]));
}

