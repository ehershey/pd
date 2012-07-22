#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Graveyard");
    set_long("This area of the graveyard is the final resting place for the deceased middle class citizens of Tirun. The graves are modest here, with elegant flowers and genuine messages of sadness placed on the tombstones of most of the graves. There are a modest amount of graves here, all of them relatively new.");
    set_smell("default", "It smells of earth and flowers.");
    set_listen("default", "As quiet as a grave.");

    set_items(([
	({"graves"}) : "These graves look to be only a month or two old. There are clumps of fresh flowers placed on most graves here.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"grave4.c",
	"southwest" : ROOMS"grave1.c",
	"east" : ROOMS"grave5.c",
      ]));
}
