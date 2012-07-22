#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Inside the Mausoleum entrance");
    set_long("The tomb is crammed full of blood red roses from the floor to the roof. Bunches and bunches of finely cut roses pack the small tomb, almost obscuring the spiral staircase to one side. The walls, floor and ceiling of the tomb are crafted from large slabs of marble, something which must have cost a fortune to make. Despite the huge numbers of flowers here, they all appear to be perfectly fresh.");
    set_smell("default", "There is an overpowering smell of roses here.");
    set_listen("default", "As quiet as a grave.");

    set_items(([
	({"flower", "flowers", "rose", "roses"}) : "There must be hundred and hundreds of these roses dangling from the roof, littering the floor and scattered all over the stairway.",
	({"staircase"}) : "This staircase is almost completely blocked up with rose flowers and petals.",
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"out" : ROOMS"tomb.c",
	"down" : ROOMS"tomb2.c",
      ]));
}
