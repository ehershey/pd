#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Graveyard");
    set_long("This area of the graveyard is by far the most overcrowded, as it holds the poorest members of Tirun society. Even though the disadvantaged are generally more prone to expiration then the upper classes, the number of bodies put here in the last few months is absolutely staggering. There must be over a hundred here all up, crammed into this tiny space.");
    set_listen("default", "As quiet as a grave.");
    set_smell("default", "It smells strongly of freshly turned earth.");

    set_items(([
	({"graves"}) : "These graves are packed in like sardines. Most of them have sprung up in the last few months.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"south" : ROOMS"grave3.c",
	"southwest" : ROOMS"grave2.c"
      ]));
}
