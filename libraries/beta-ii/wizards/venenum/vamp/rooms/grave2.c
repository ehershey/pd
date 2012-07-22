#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Graveyard");
    set_long("This part of the graveyard seems to hold the bodies of the higher class, richer citizens of Tirun. The gravestones here are more expensive and elaborate then in other parts of the graveyard and while race, the bunches of flowers that are laid here are likewise more expensive. There are fewer graves here; it would appear that rich people are just not dying recently.");
    set_smell("default", "It smells of earth and flowers.");
    set_listen("default", "As quiet as a grave.");

    set_items(([
	({"graves"}) : "These graves look to be only a month or two old. There are clumps of fresh flowers placed near every grave here.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"south" : ROOMS"grave1.c",
	"east" : ROOMS"grave3.c",
	"northeast" : ROOMS"grave4.c",
	"north" : ROOMS"tomb.c",
      ]));
}
