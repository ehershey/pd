#include <std.h>
#include <cc2.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path through shrubs and trees");
    set_long("The trees and shrubs here seems to be thicker to the northwest and the southwest, but lighter to the east. Through several gaps in the trees and path, glimpses of the ocean can be caught. The path here becomes more gravel to the east, but more dirt to the southwest and northwest.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is fresh and crisp.");
    set_items(([
	({"ocean", "sea", "water"}) : "The water shimmers through gaps in the trees and shrubs.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"east" : ROOMS"cc13.c",
	"northwest" : ROOMS"cch.c",
	"southwest" : ROOMS"cc15.c",
      ]));
}
