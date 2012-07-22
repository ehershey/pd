#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Graveyard");
    set_day_long("So much death exists in the land of Tirun that an extention to the graveyard has been created. This extention is only a month or two old, but even so holds a large amount of bodies. This is a depressing place even in the daytime. There are a handful of graves here, along with a small tree.");
    set_night_long("So much death exists in the land of Tirun that an extention to the graveyard has been created. This extention is only a month or two old, but even so holds a large amount of bodies. This place is particularly spooky at night. There are a handful of graves here, along with a small tree.");
    set_smell("default", "It smells of earth and flowers.");
    set_listen("default", "As quiet as a grave.");

    set_items(([
	({"graves"}) : "These graves look to be only a month or two old. There are clumps of fresh flowers placed near every grave here.",
	({"tree"}) : "This elm tree is but a young sapling, placed here to grow upon the grave of a druidess which died of a sickness. The tree will keep her spirit strong forever.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"grave2.c",
	"northeast" : ROOMS"grave3.c",
	"southwest" : ROOMS"x.c", // This is the ne most grave in the Tirun graveyard.
      ]));
}
