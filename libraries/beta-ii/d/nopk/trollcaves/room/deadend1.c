#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The smaller passage seems a lot rougher then earlier passages. The stone here makes a return to the white limestone, with the grey stone seen elsewhere almost gone here. This passage constricts even further, and seems to turn very sharp corners. Strangely, the air here is less stagnant then in earlier passages, and it could be assumed that several of the holes that dot the walls and ceiling may lead to the surface, or another cave higher up.");

    set_items(([
	({"stone"}) : "This stone is almost entirely the chalk-white limestone.",
	({"holes", "hole"}) : "These holes, about the size of a cricket ball, have slight breezes wafting in through them and although no light can be seen through them they could very well lead to the surface."
      ]));
    set_properties(([
	"light" : -1,
	"night light" : -2,
      ]));
    set_exits(([
	"northwest" : ROOMS"cave7.c",
	"north" : ROOMS"deadend2.c"
      ]));
}
