#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Boneyard");
    set_long("Scales, bones and hunks of dragon flesh lay scattered around the earth here, a testament to the abject cruelty of the dark elven raiders. The remains of dragons of every colour are present here, every usable piece of the great beasts robbed from their bodies, leaving only bones and sinew. Dark blood stains the land here, pooling in dark puddles or seeping into the ground, flowing freely from the slaughtered draconic bodies.");
    set_smell("default", "The stench of death is unbearable.");
    set_listen("default", "This place is eeriely quiet.");

    set_items(([
	({"bone", "bones"}) : "These bones are thick and white, with most of the meat hacked from them. They have been left to bleach in the sun.",
	({"scales", "scale"}) : "There are thousands of scales, or hunks of scales, laying about- although all the useful ones were collected by the Dark Elves.",
	({"flesh", "dragon flesh", "hunks of dragon flesh"}) : "These macabre hunks of flesh are just flung about and left to rot. Their stench is overpowering.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"east" : ROOMS"whatever.c",
      ]));
}
